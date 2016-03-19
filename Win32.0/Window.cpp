#include "Window.h"
#include "Win32Helper.h"


Window::Window(int width, int height)
{
    // ��ѯ��ĻDPI
    int dpix, dpiy;
    GetScreenDpi(dpix, dpiy);
    // ���ڴ�С
    m_width = (int)(width*dpix / 96.0f);
    m_height = (int)(height*dpiy / 96.0f);
}


Window::~Window()
{
}


bool Window::Initialize()
{
    // ע�ᴰ����
    WNDCLASSEX wcex = { sizeof(WNDCLASSEX) };
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = Window::WindowProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = HINST_THISCOMPONENT;
    wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wcex.lpszMenuName = NULL;
    wcex.hCursor = LoadCursor(NULL, IDI_APPLICATION);
    wcex.lpszClassName = L"��������";

    RegisterClassEx(&wcex);


    // ��������
    m_hwnd = CreateWindow(
        L"��������",
        L"���ڱ���",
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
    // ��ʾ����
    if (m_hwnd != NULL)
    {
        ShowWindow(m_hwnd, SW_SHOWNORMAL);
        MoveToCenter();
        UpdateWindow(m_hwnd);
    }

    // ��Ϣѭ��
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
