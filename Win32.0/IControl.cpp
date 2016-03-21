#include "IControl.h"



IControl::IControl(int width, int height) 
    :IElement(width, height)
{
}


IControl::~IControl()
{
}

bool IControl::ifMouseIn(int x, int y)
{
    if (x >= 0 && x <= m_width && y >=0 && y << m_height)
    {
        return true;
    }
    else
    {
        return false;
    }
}


// 鼠标移动到元素范围内
void IControl::mouseMoveIn(int x, int y)
{
    // 空实习，供子类覆盖或继承
}


// 鼠标移出元素范围外
void IControl::mouseMoveOut()
{
    // do nothing
}


// 鼠标左键按下（在控件捕获范围内）
void IControl::LMBDown()
{
    // do nothing
}

// 鼠标左键弹起（在控件捕获范围内）
void IControl::LMBUp()
{
    // do nothing
}


// 获得焦点
void IControl::getFocus()
{
    // do nothing
}


// 失去焦点
void IControl::loseFocus()
{
    // do nothing
}
