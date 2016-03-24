#include "RadioButton.h"



RadioButton::RadioButton(int width, int height, TCHAR* text)
    :IControl(width, height), m_text(text)
{
}


RadioButton::~RadioButton()
{
}


//������������߻����ұ�
void RadioButton::setTextPos(TextPosition pos)
{
    m_textPos = pos;
}


// ��ѯ�Ƿ�ѡ��
bool RadioButton::ifChecked()
{
    return m_ifChecked;
}


// �����¼��Ͷ���
void RadioButton::connect(Event event, function<void()> action)
{
    m_eventActionMap[event] = action;
}


// ��ý���
void RadioButton::getFocus()
{
    m_ifGotFocus = true;
}


// ʧȥ����
void RadioButton::loseFocus()
{
    m_ifGotFocus = false;
}


// ����ƶ����ؼ���
void RadioButton::mouseMoveIn()
{
    m_ifMouseIn = true;
}


// ����Ƴ��ؼ�
void RadioButton::mouseMoveOut()
{
    m_ifMouseIn = false;
}


// ���������£��ڿؼ�����Χ�ڣ�
void RadioButton::LMBDown()
{
    // �޸�ѡ��״̬
    m_ifChecked = !m_ifChecked;

    if (m_ifChecked)
    {
        // ��������˶�������ִ�ж�Ӧ�Ķ���
        auto it = m_eventActionMap.find(check);
        if (it != m_eventActionMap.end())
        {
            (it->second)();
        }
    }
    else
    {
        // ��������˶�������ִ�ж�Ӧ�Ķ���
        auto it = m_eventActionMap.find(uncheck);
        if (it != m_eventActionMap.end())
        {
            (it->second)();
        }
    }
}

// �����������ڿؼ�����Χ�ڣ�
void RadioButton::LMBUp()
{
}


// ��������Ƿ�������Ԫ�صĲ���Χ��
bool RadioButton::ifMouseIn(int x, int y)
{
    if (m_textPos == right)
    {
        if (x >=0 && x << m_height && y >= 0 && y <= m_height)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (x >= (m_width - m_height) && x <= m_width && y >= 0 && y <= m_height)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}


// ���в���
IElement* RadioButton::hitTest(int x, int y)
{
    if (m_textPos == left)
    {
        if (x >= m_left + m_width - 10 && x <= m_left + m_width
            && y >= m_top + (m_height - 10)/2 && y <= m_top + m_height / 2 + 5)
        {
            return this;
        }
    }
    else
    {
        if (x >= m_left && x <= m_left + 10
            && y >= m_top + (m_height - 10) / 2 && y <= m_top + m_height / 2 + 5)
        {
            return this;
        }
    }

    return nullptr;
}


// ����
void RadioButton::draw(Gdiplus::Graphics &g)
{
    // ����ѡ��״̬���ֺ����ֲ��ַ�Χ
    Rect selectRect;
    RectF textRectF;
    selectRect.Width = 10;
    selectRect.Height = 10;
    selectRect.Y = m_top + (m_height - 10) / 2;

    textRectF.Y = m_top;
    textRectF.Height = m_height;
    textRectF.Width = m_width - 10;

    if (m_textPos == left)
    {
        textRectF.X = m_left;

        selectRect.X = m_left + m_width - 10;
    }
    else
    {
        textRectF.X = m_left + 10;

        selectRect.X = m_left;
    }
    // ���Ʊ�ʾѡ��״̬�Ĳ���
    // �������Ƶ�����ѡ��ť�Ͼͻ���һ��Ч��
    if (m_ifMouseIn)
    {
        SolidBrush brush(Color(40, 0, 0, 0));
        Rect r = selectRect;
        r.X -= 4;
        r.Y -= 4;
        r.Width += 8;
        r.Height += 8;
        g.FillEllipse(&brush, r);
    }
    // ����Բ��
    Pen blackPen(Color::Black);
    g.DrawEllipse(&blackPen, selectRect);
    // ���ѡ�о����ѡ��״̬����
    if (m_ifChecked)
    {
        selectRect.X += 1;
        selectRect.Y += 1;
        selectRect.Width -= 2;
        selectRect.Height -= 2;
        SolidBrush solidBrush(Color::Black);
        g.FillEllipse(&solidBrush, selectRect);
    }

    // ��������
    FontFamily fontFamily(L"Consolas");
    Gdiplus::Font font(&fontFamily, 16, FontStyleRegular, UnitPixel);
    SolidBrush solidBrush(Color::Black);
    StringFormat stringFormat;
    stringFormat.SetAlignment(StringAlignmentCenter);
    stringFormat.SetLineAlignment(StringAlignmentCenter);

    g.DrawString(m_text, -1, &font, textRectF, &stringFormat, &solidBrush);
}
