#include "IControl.h"



IControl::IControl(unsigned width, unsigned height) 
    :IElement(width, height)
{
}


IControl::~IControl()
{
}

bool IControl::ifMouseIn(unsigned x, unsigned y)
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
void IControl::mouseMoveIn(unsigned x, unsigned y)
{
    // 空实习，供子类覆盖或继承
}
