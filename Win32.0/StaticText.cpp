#include "StaticText.h"



StaticText::StaticText(int width, int height, TCHAR *text)
    :IControl(width, height), m_text(text)
{
}


StaticText::~StaticText()
{
}


// 设置水平对齐方式
void StaticText::setTextHorizontalAlignment(Alignment align)
{
    if (align == left || align == center || align == right)
    {
        m_horizontalAlignment = align;
    }
}



// 设置垂直方向上的对齐方式
void StaticText::setTextVerticalAlignment(Alignment align)
{
    if (align == top || align == center || align == bottom)
    {
        m_verticalAlignment = align;
    }
}


void StaticText::setText(TCHAR *text)
{
    m_text = text;
}


// 绘制
void StaticText::draw(Graphics &g)
{
    // 绘制边框
    g.DrawRectangle(&blackPen, (int)m_left, m_top, m_width, m_height);

    // 绘制文字
    RectF rectF(m_left, m_top, m_width, m_height);
    g.DrawString(m_text, -1, &font, rectF, &stringFormat, &solidBrush);
}
