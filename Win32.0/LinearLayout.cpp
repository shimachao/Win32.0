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
        horAdjustSize();
    }
    else
    {
        verAdjustSize();
    }
}


// 布局方向为水平时的调整子元素位置方法
void LinearLayout::horAdjustSize()
{
    // 先计算并设置各个控件垂直方向的坐标，让其在垂直方向上居中
    for each (IElement* var in m_childList)
    {
        // 因为假设每个子元素的高度都不一样，所以每个子元素的垂直方向坐标都要计算一次
        unsigned top = m_topBlank + (m_height - m_topBlank - m_bottomBlank - var->getHeight()) / 2;
        var->setTop(top);
    }

    // 再计算每个控件的水平坐标
    if (m_childList.size() == 1)
    {
        //  如果只有一个子元素，直接将其放在中间
        auto var = m_childList.front();
        unsigned left = (m_width - var->getWidth()) / 2;
        var->setLeft(left);
    }
    else
    {
        // 如果有多个元素就均匀放置
        unsigned spacex = m_width - m_leftBlank - m_rightBlank;  // 水平方向的空间大小
        unsigned sumWidth = 0;   // 所有控件加起来的宽度
        for each (IElement* var in m_childList)
        {
            sumWidth += var->getWidth();
        }
        // 控件之间的距离
        unsigned margin = (spacex - sumWidth) / (m_childList.size() - 1);
        // 开始设置
        unsigned left = m_leftBlank;
        for each (IElement* var in m_childList)
        {
            var->setLeft(left);
            left += var->getWidth() + margin;
        }
    }
}


// 布局方向为垂直时的调整子元素位置方法
void LinearLayout::verAdjustSize()
{
    // 先计算并设置各个控件水平方向的坐标，让其在水平方向上居中
    for each (IElement* var in m_childList)
    {
        // 因为假设每个子元素的宽度都不一样，所以每个子元素的水平方向坐标都要计算一次
        unsigned left = m_leftBlank + (m_width - m_leftBlank - m_rightBlank - var->getWidth()) / 2;
        var->setLeft(left);
    }

    // 再计算每个控件垂直方向上的坐标
    if (m_childList.size() == 1)
    {
        //  如果只有一个子元素，直接将其放在中间
        auto var = m_childList.front();
        unsigned top = (m_height - var->getHeight()) / 2;
        var->setTop(top);
    }
    else
    {
        // 如果有多个元素就均匀放置
        unsigned spacey = m_height - m_topBlank - m_bottomBlank;  // 垂直方向的空间大小
        unsigned sumHeight = 0;   // 所有控件加起来的高度
        for each (IElement* var in m_childList)
        {
            sumHeight += var->getHeight();
        }
        // 控件之间的距离
        unsigned margin = (spacey - sumHeight) / (m_childList.size() - 1);
        // 开始设置
        unsigned top = m_topBlank;
        for each (IElement* var in m_childList)
        {
            var->setTop(top);
            top += var->getHeight() + margin;
        }
    }
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


