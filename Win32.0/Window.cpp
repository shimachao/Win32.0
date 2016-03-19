#include "Window.h"
#include "Win32Helper.h"


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
    wcex.cbWndExtra = 0;
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

    switch (message)
    {
    case WM_CLOSE:
        DestroyWindow(hWnd);
        break;

    case WM_DISPLAYCHANGE:
        InvalidateRect(hWnd, NULL, FALSE);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}


void Window::MoveToCenter()
{
    int srcWidth = GetSystemMetrics(SM_CXSCREEN);
    int srcHeight = GetSystemMetrics(SM_CYSCREEN);

    int left = (srcWidth - m_width) / 2;
    int top = (srcHeight - m_height) / 2;

    MoveWindow(m_hwnd, left, top, m_width, m_height, false);
}
