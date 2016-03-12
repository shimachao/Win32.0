#include "AbsoluteLayout.h"



AbsoluteLayout::AbsoluteLayout(unsigned width, unsigned height) 
    :ILayout(width, height)
{
}


AbsoluteLayout::~AbsoluteLayout()
{
}


// 添加子元素，参数left，top为子元素左上角坐标
void AbsoluteLayout::add(IElement *pElement, unsigned left, unsigned top)
{
    m_childArray.push_back(pElement);
    pElement->move(left, top);
}
