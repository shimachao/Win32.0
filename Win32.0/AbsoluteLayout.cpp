#include "AbsoluteLayout.h"



AbsoluteLayout::AbsoluteLayout(int width, int height) 
    :ILayout(width, height)
{
}


AbsoluteLayout::~AbsoluteLayout()
{
}


// 添加子元素，参数left，top为子元素左上角坐标
void AbsoluteLayout::add(IElement *pElement, int left, int top)
{
    m_childArray.push_back(pElement);
    pElement->move(left, top);
}


// 鼠标移动到元素范围内
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


// 绘制
void AbsoluteLayout::draw(Gdiplus::Graphics &g)
{
    g.TranslateTransform(m_left, m_top);

    for each (const auto& var in m_childArray)
    {
        var->draw(g);
    }

    g.TranslateTransform(-m_left, -m_top);
}


// 击中测试
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

