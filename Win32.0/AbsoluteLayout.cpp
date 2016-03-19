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


// 鼠标移动到元素范围内
void AbsoluteLayout::mouseMoveIn(unsigned x, unsigned y)
{
    for each (auto var in m_childArray)
    {
        if (var->ifMouseIn(x - m_left, y - m_top))
        {
            var->mouseMoveIn(x - m_left, y - m_top);
            break;
        }
    }
}
