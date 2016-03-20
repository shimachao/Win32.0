#include "RadioButton.h"



RadioButton::RadioButton(int width, int height, string text)
    :IControl(width, height)
{
}


RadioButton::~RadioButton()
{
}


//设置文字在左边还是右边
void RadioButton::setTextPos(TextPosition pos)
{
    m_textPos = pos;
}


// 查询是否被选中
bool RadioButton::ifChecked()
{
    return m_ifChecked;
}


// 连接事件和动作
void RadioButton::connect(Event event, function<void()> action)
{
    m_eventActionMap[event] = action;
}


// 获得焦点
void RadioButton::getFocus()
{
    m_ifGotFocus = true;
}


// 失去焦点
void RadioButton::loseFocus()
{
    m_ifGotFocus = false;
}


// 鼠标移动到控件上
void RadioButton::mouseMoveIn()
{
    m_ifMouseIn = true;
}


// 鼠标移出控件
void RadioButton::mouseMoveOut()
{
    m_ifMouseIn = false;
}


// 鼠标左键按下（在控件捕获范围内）
void RadioButton::LMBDown()
{
    // 修改选中状态
    m_ifChecked = !m_ifChecked;

    if (m_ifChecked)
    {
        // 如果连接了动作，就执行对应的动作
        auto it = m_eventActionMap.find(check);
        if (it != m_eventActionMap.end())
        {
            (it->second)();
        }
    }
    else
    {
        // 如果连接了动作，就执行对应的动作
        auto it = m_eventActionMap.find(uncheck);
        if (it != m_eventActionMap.end())
        {
            (it->second)();
        }
    }
}

// 鼠标左键弹起（在控件捕获范围内）
void RadioButton::LMBUp()
{
}


// 测试鼠标是否落在在元素的捕获范围内
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
    else if (m_textPos == left)
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
