#include "LineProgress.h"
#include "Win32Helper.h"


LineProgress::LineProgress(int width, int height, unsigned range, unsigned step)
    :Progress(width, height, range, step)
{
}


LineProgress::~LineProgress()
{
}


void LineProgress::draw(Gdiplus::Graphics &g)
{
    int dpix = 0, dpiy = 0;
    GetScreenDpi(dpix, dpiy);
    auto lineWidth = 2*dpiy / 96.0f;

    // 绘制整个进度条长度
    Pen darkPen(Color::DarkGray, lineWidth);
    g.DrawLine(&darkPen, m_left, m_top + (m_height / 2), m_left + m_width, m_top + (m_height / 2));
    // 绘制进度
    Pen blackPen(Color::Black, lineWidth);
    g.DrawLine(&blackPen, m_left, m_top + (m_height / 2),
        m_left + ((double)m_pace/m_range)*m_width, m_top + (m_height / 2));
}
