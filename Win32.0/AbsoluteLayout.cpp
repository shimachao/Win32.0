#include "AbsoluteLayout.h"



AbsoluteLayout::AbsoluteLayout(unsigned width, unsigned height) 
    :ILayout(width, height)
{
}


AbsoluteLayout::~AbsoluteLayout()
{
}


// �����Ԫ�أ�����left��topΪ��Ԫ�����Ͻ�����
void AbsoluteLayout::add(IElement *pElement, unsigned left, unsigned top)
{
    m_childArray.push_back(pElement);
    pElement->move(left, top);
}
