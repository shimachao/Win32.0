#include "Graph.h"
#pragma comment(lib,"Gdiplus.lib")

Graph::Graph()
{
    Gdiplus::GdiplusStartup(&m_gdiplusToken, &m_gdiplusStartupInput, NULL);
    // 设置字体属性
    blackPen.SetAlignment(Gdiplus::PenAlignmentInset);
    // 文字属性
    stringFormat.SetAlignment(StringAlignmentCenter);
    stringFormat.SetLineAlignment(StringAlignmentCenter);
    
}

Graph::~Graph()
{
    Gdiplus::GdiplusShutdown(m_gdiplusToken);
}

Pen blackPen(Gdiplus::Color::Black, 2.0f);

FontFamily fontFamily(L"Consolas");
Gdiplus::Font font(&fontFamily, 16, FontStyleRegular, UnitPixel);

SolidBrush solidBrush(Color(0, 0, 0));

StringFormat stringFormat;
