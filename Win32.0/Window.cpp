#include "Window.h"
#include "Win32Helper.h"
#include <GdiPlus.h>
#include <Windowsx.h>


Window::Window(int width, int height)
{
    // 查询屏幕DPI
    int dpix, dpiy;
    GetScreenDpi(dpix, dpiy);
    // 窗口大小
    m_width = (int)(width*dpix / 96.0f);
    m_height = (int)(height*dpiy / 96.0f);
}


Window::~Window()
{
}


bool Window::Initialize()
{
    // 注册窗口类
    WNDCLASSEX wcex = { sizeof(WNDCLASSEX) };
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = Window::WindowProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = sizeof(LONG_PTR);
    wcex.hInstance = HINST_THISCOMPONENT;
    wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wcex.lpszMenuName = NULL;
    wcex.hCursor = LoadCursor(NULL, IDI_APPLICATION);
    wcex.lpszClassName = L"窗口类名";

    RegisterClassEx(&wcex);


    // 创建窗口
    m_hwnd = CreateWindow(
        L"窗口类名",
        L"窗口标题",
        WS_POPUP,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        m_width,
        m_height,
        NULL,
        NULL,
        HINST_THISCOMPONENT,
        this
        );

    return m_hwnd != NULL;
}


// 设置布局
void Window::setLayout(ILayout *pLayout)
{
    m_pLayout = pLayout;
    m_pLayout->setPos(0, 0, m_width, m_height);
}


void Window::Run()
{
    // 显示窗口
    if (m_hwnd != NULL)
    {
        ShowWindow(m_hwnd, SW_SHOWNORMAL);
        MoveToCenter();
        UpdateWindow(m_hwnd);
    }

    // 消息循环
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}


LRESULT CALLBACK Window::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static Window *pWindow = nullptr;
    PAINTSTRUCT ps;
    HDC dc;

    switch (message)
    {
    case WM_CREATE:
    {
        LPCREATESTRUCT pcs = (LPCREATESTRUCT)lParam;
        pWindow = (Window *)pcs->lpCreateParams;
        break;
    }

    case WM_PAINT:
        if (pWindow != nullptr)
        {
            dc = BeginPaint(hWnd, &ps);

            pWindow->onPaint(dc);

            EndPaint(hWnd, &ps);
        }
        break;

    case WM_MOUSEMOVE:
        if (pWindow != nullptr)
        {
            int xPos = GET_X_LPARAM(lParam);
            int yPos = GET_Y_LPARAM(lParam);
            pWindow->onMouseMove(xPos, yPos);
        }
        break;

        /*case WM_NCHITTEST:
            if (pWindow != nullptr)
            {
                int xPos = GET_X_LPARAM(lParam);
                int yPos = GET_Y_LPARAM(lParam);
                POINT p;
                p.x = xPos;
                p.y = yPos;
                ::ScreenToClient(hWnd, &p);
                if (pWindow->ifMouseOnControl(p.x, p.y))
                {
                    return HTCLIENT;
                }
                else
                {
                    return HTCAPTION;
                }
            }
            return HTCAPTION;*/

    case WM_LBUTTONDOWN:
        if (pWindow != nullptr)
        {
            int xPos = GET_X_LPARAM(lParam);
            int yPos = GET_Y_LPARAM(lParam);
            if (pWindow->ifMouseOnControl(xPos, yPos))
            {
                pWindow->onLButtonDown(xPos, yPos);
            }
            else
            {
                SendMessage(hWnd, WM_NCLBUTTONDOWN, HTCAPTION, 0);
            }
        }
        break;

    case WM_LBUTTONUP:
        if (pWindow != nullptr)
        {
            int xPos = GET_X_LPARAM(lParam);
            int yPos = GET_Y_LPARAM(lParam);
            pWindow->onLButtonUp(xPos, yPos);
        }
        break;

    case WM_NCLBUTTONDOWN:
        break;

    case WM_NCLBUTTONUP:
        break;

    case WM_CLOSE:
        DestroyWindow(hWnd);
        break;

    case WM_DISPLAYCHANGE:
        InvalidateRect(hWnd, NULL, FALSE);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

   
    }

    return DefWindowProc(hWnd, message, wParam, lParam);;
}


void Window::MoveToCenter()
{
    int srcWidth = GetSystemMetrics(SM_CXSCREEN);
    int srcHeight = GetSystemMetrics(SM_CYSCREEN);

    int left = (srcWidth - m_width) / 2;
    int top = (srcHeight - m_height) / 2;

    MoveWindow(m_hwnd, left, top, m_width, m_height, false);
}


// 绘制
void Window::onPaint(HDC dc)
{
    // 创建内存兼容DC，准备双缓冲
    HDC hMemDC = CreateCompatibleDC(dc);
    HBITMAP hMemBitMap = CreateCompatibleBitmap(dc, m_width, m_height);
    SelectObject(hMemDC, hMemBitMap);
    // 根据内存DC创建GDI+绘制对象
    Gdiplus::Graphics graphics(hMemDC);
    // 设置反走样
    graphics.SetSmoothingMode(Gdiplus::SmoothingModeHighQuality);

    // 清理背景
    Gdiplus::SolidBrush whiteBrush(Gdiplus::Color(255, 255, 255));
    graphics.FillRectangle(&whiteBrush, -1, -1, m_width+1, m_height+1);

    // 绘制控件
    m_pLayout->draw(graphics);

    // 复制到目标DC
    BitBlt(dc, 0, 0, m_width, m_height, hMemDC, 0, 0, SRCCOPY);

    DeleteDC(hMemDC);
}


// 判断鼠标位置是否在某个控件上
bool Window::ifMouseOnControl(int x, int y)
{
    return m_pLayout->hitTest(x, y) != nullptr;
}


// 对鼠标移到消息的响应
void Window::onMouseMove(int x, int y)
{
    auto var = dynamic_cast<IControl*>(m_pLayout->hitTest(x, y));

    if (var == m_pControlCaptureMouse)
    {
        return;
    }

    if (m_pControlCaptureMouse != nullptr)
    {
        m_pControlCaptureMouse->mouseMoveOut();
        InvalidateRect(m_hwnd, NULL, false);
    }

    if (var != nullptr)
    {
        var->mouseMoveIn();
        InvalidateRect(m_hwnd, NULL, false);
    }

    m_pControlCaptureMouse = var;
}


// 响应鼠标左键按下消息
void Window::onLButtonDown(int x, int y)
{
    auto var = dynamic_cast<IControl*>(m_pLayout->hitTest(x, y));

    if (var != nullptr)
    {
        var->LMBDown();
        InvalidateRect(m_hwnd, NULL, false);
    }
    // 如果是新的控件，则转换焦点
    if (var != m_pControlGotFocus)
    {
        if (var != nullptr)
        {
            var->getFocus();
            InvalidateRect(m_hwnd, NULL, false);
        }

        if (m_pControlGotFocus != nullptr)
        {
            m_pControlGotFocus->loseFocus();
            InvalidateRect(m_hwnd, NULL, false);
        }

        m_pControlGotFocus = var;
    }
    //UpdateWindow(m_hwnd);
}


// 响应鼠标左键弹起消息
void Window::onLButtonUp(int x, int y)
{
    // 判断鼠标弹起时，鼠标位置是否在一个控件上
    auto var = dynamic_cast<IControl*>(m_pLayout->hitTest(x, y));

    // 如果在
    if (var != nullptr && var == m_pControlGotFocus)
    {
        var->LMBUp();
        InvalidateRect(m_hwnd, NULL, false);
    }
}
