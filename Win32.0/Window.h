#pragma once
#include <Windows.h>
#include "ILayout.h"

#ifndef HINST_THISCOMPONENT
EXTERN_C IMAGE_DOS_HEADER __ImageBase;
#define HINST_THISCOMPONENT ((HINSTANCE)&__ImageBase)
#endif

// 窗口类
class Window
{
public:
    Window() = delete;
    Window(int width, int height);
    ~Window();

    // 初始化
    bool Initialize();
    // 设置布局
    void setLayout(ILayout *pLayout);
    // 将窗口移到屏幕中间
    void MoveToCenter();
    // 运行
    void Run();

private:
    // 绘制
    void onPaint(HDC dc);
    // 响应鼠标左键按下消息
    void onLButtonDown(int x, int y);
    // 判断鼠标位置是否在某个控件上
    bool ifMouseOnControl(int x, int y);

private:
    // 窗口过程函数
    static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    // 变量
    HWND    m_hwnd;     //  窗口句柄
    int     m_width;    // 窗口宽度，单位为像素
    int     m_height;   // 窗口高度，单位为像素
    ILayout *m_pLayout = nullptr; // 窗口布局
};

