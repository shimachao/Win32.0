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
