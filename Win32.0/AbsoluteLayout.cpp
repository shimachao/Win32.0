#include "AbsoluteLayout.h"



AbsoluteLayout::AbsoluteLayout(int width, int height) 
    :ILayout(width, height)
{
}


AbsoluteLayout::~AbsoluteLayout()
{
}


// �����Ԫ�أ�����left��topΪ��Ԫ�����Ͻ�����
void AbsoluteLayout::add(IElement *pElement, int left, int top)
{
    m_childArray.push_back(pElement);
    pElement->move(left, top);
}


// ����ƶ���Ԫ�ط�Χ��
//void AbsoluteLayout::mouseMoveIn(int x, int y)
//{
//    for each (const auto& var in m_childArray)
//    {
//        if (var->ifMouseIn(x - m_left, y - m_top))
//        {
//            var->mouseMoveIn(x - m_left, y - m_top);
//            break;
//        }
//    }
//}


// ����
void AbsoluteLayout::draw(Gdiplus::Graphics &g)
{
    g.TranslateTransform(m_left, m_top);

    for each (const auto& var in m_childArray)
    {
        var->draw(g);
    }

    g.TranslateTransform(-m_left, -m_top);
}


// ���в���
IElement* AbsoluteLayout::hitTest(int x, int y)
{
    if (x >= m_left && x <= m_left + m_width
        && y >= m_top && y <= m_top + m_height)
    {
        IElement* p = nullptr;
        for each (const auto& var in m_childArray)
        {
            if ((p = var->hitTest(x - m_left, y - m_top)) != nullptr)
            {
                break;
            }
        }
        return p;
    }
    else
    {
        return nullptr;
    }
}

