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


// ����ƶ���Ԫ�ط�Χ��
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
