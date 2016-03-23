#include "StaticText.h"



StaticText::StaticText(int width, int height, TCHAR *text)
    :IControl(width, height), m_text(text)
{
}


StaticText::~StaticText()
{
}


// ����ˮƽ���뷽ʽ
void StaticText::setTextHorizontalAlignment(Alignment align)
{
    if (align == left || align == center || align == right)
    {
        m_horizontalAlignment = align;
    }
}



// ���ô�ֱ�����ϵĶ��뷽ʽ
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


// ����
void StaticText::draw(Graphics &g)
{
    Pen blackPen(Gdiplus::Color::Gray, 2.0f);
    // ������������
    blackPen.SetAlignment(Gdiplus::PenAlignmentInset);
    // ���Ʊ߿�
    g.DrawRectangle(&blackPen, (int)m_left, m_top, m_width, m_height);

    FontFamily fontFamily(L"Consolas");
    Gdiplus::Font font(&fontFamily, 16, FontStyleRegular, UnitPixel);
    SolidBrush solidBrush(Color(0, 0, 0));
    StringFormat stringFormat;
    // ��������
    stringFormat.SetAlignment(StringAlignmentCenter);
    stringFormat.SetLineAlignment(StringAlignmentCenter);

    // ��������
    RectF rectF(m_left, m_top, m_width, m_height);
    g.DrawString(m_text, -1, &font, rectF, &stringFormat, &solidBrush);
}
