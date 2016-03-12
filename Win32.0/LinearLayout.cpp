#include "LinearLayout.h"



LinearLayout::LinearLayout(unsigned width, unsigned height, Orientation orientation)
    :ILayout(width, height), m_orientation(orientation)
{
}


LinearLayout::~LinearLayout()
{
}


// 添加子元素
void LinearLayout::add(IElement *pElement)
{
    m_childList.push_back(pElement);

    // 设置所有子元素的位置，每添加一个元素都要重新计算每个子元素的位置
    // 假设布局是可以放下所有子控件的，放不下的话，对结果不做任何保证
    if (m_orientation == horizontal)
    {
        horAdd(pElement);
    }
    else
    {
        verAdd(pElement);
    }
}


// 布局方向为水平时的添加方法
void LinearLayout::horAdd(IElement *pElment)
{
    // 计算x坐标
    static unsigned margin = 0; // 元素之间的水平边缘间隔
    static unsigned left = m_leftBlank; // 开始摆放元素的起始x坐标

    if (pElment->getLeftMargin() > margin)
    {
        margin = pElment->getLeftMargin();
    }

    // 计算元素y坐标，让元素在垂直方向上居中
    unsigned top = (m_height - pElment->getHeight()) / 2;
    pElment->move(left + margin, top);

    //更新left和margin
    left += pElment->getWidth();
    margin = pElment->getRightMargin();
}


// 布局方向为垂直时的添加方法
void LinearLayout::verAdd(IElement *pElment)
{
    // 计算y坐标
    static unsigned margin = 0; // 元素之间的垂直边缘间隔
    static unsigned top = m_topBlank;   // 开始摆放元素的起始y坐标

    if (pElment->getTopMargin() > margin)
    {
        margin = pElment->getTopMargin();
    }

    // 计算x坐标，让元素在水平方向上居中
    unsigned left = (m_width - pElment->getWidth()) / 2;
    pElment->move(left, top + margin);

    // 跟新top和margin
    top += pElment->getHeight();
    margin = pElment->getBottomMargin();
}


// 鼠标移到到元素上了
void LinearLayout::MouseMoveOver(unsigned x, unsigned y)
{
    x -= m_left;
    y -= m_top;
    // 递归检测鼠标是否落在子元素中
    for each (IElement* var in m_childList)
    {
        if (var->ifMouseIn(x, y))
        {
            var->MouseMoveOver(x, y);
            break;
        }
    }
}


