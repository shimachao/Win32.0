#include "RadioButton.h"



RadioButton::RadioButton(unsigned width, unsigned height, string text)
    :IControl(width, height)
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
