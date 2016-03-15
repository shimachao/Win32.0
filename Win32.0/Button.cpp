#include "Button.h"



Button::Button(unsigned width, unsigned height, string text) 
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
void Button::RMBDown()
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
