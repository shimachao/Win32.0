#pragma once
#include <Windows.h>
#include "ILayout.h"

#ifndef HINST_THISCOMPONENT
EXTERN_C IMAGE_DOS_HEADER __ImageBase;
#define HINST_THISCOMPONENT ((HINSTANCE)&__ImageBase)
#endif

// ������
class Window
{
public:
    Window() = delete;
    Window(int width, int height);
    ~Window();

    // ��ʼ��
    bool Initialize();
    // ���ò���
    void setLayout(ILayout *pLayout);
    // �������Ƶ���Ļ�м�
    void MoveToCenter();
    // ����
    void Run();

private:
    // ���ڹ��̺���
    static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    // ����
    HWND    m_hwnd;     //  ���ھ��
    int     m_width;    // ���ڿ�ȣ���λΪ����
    int     m_height;   // ���ڸ߶ȣ���λΪ����
    ILayout *m_pLayout = nullptr; // ���ڲ���
};

