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
