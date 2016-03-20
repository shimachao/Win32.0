#include "Button.h"



Button::Button(int width, int height, TCHAR * text)
    :StaticText(width, height, text)
{
}


Button::~Button()
{
}


// ��ý���
void Button::getFocus()
{
    m_ifGotFocus = true;
}


// ʧȥ����
void Button::loseFocus()
{
    m_ifGotFocus = false;
}


// ����ƶ����ؼ���
void Button::mouseMoveIn()
{
    m_ifMouseIn = true;
}


// ����Ƴ��ؼ�
void Button::mouseMoveOut()
{
    m_ifMouseIn = false;
    if (m_state == Pressed)
    {
        m_state = Normal;
    }
}


// ���������£��ڿؼ�����Χ�ڣ�
void Button::LMBDown()
{
    if (m_state == Normal)
    {
        m_state = Pressed;
    }
}


// �����������ڿؼ�����Χ�ڣ�
void Button::LMBUp()
{
    if (m_state == Pressed)
    {
        m_state = Normal;

        // ��������˰���������ִ�жԶ���
        auto it = m_eventActionMap.find(clicked);
        if (it != m_eventActionMap.end())
        {
            (it->second)();
        }
    }
}


// �����¼��Ͷ���
void Button::connect(Event event, function<void()> action)
{
    m_eventActionMap[event] = action;
}


// ����
void Button::draw(Gdiplus::Graphics &g)
{
    // ���Ʊ߿�
    g.DrawRectangle(&blackPen, (int)m_left, m_top, m_width, m_height);

    // ��������
    
    RectF rectF(m_left, m_top, m_width, m_height);

    g.DrawString(m_text, -1, &font, rectF, &stringFormat, &solidBrush);
}
