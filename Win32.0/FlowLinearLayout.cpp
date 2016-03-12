#include "FlowLinearLayout.h"



FlowLinearLayout::FlowLinearLayout(unsigned width, unsigned height, Orientation ori) 
    :ILayout(width, height), m_orientation(ori)
{
}


FlowLinearLayout::~FlowLinearLayout()
{
}


// 添加元素
void FlowLinearLayout::add(IElement* pElement)
{
    m_childArray.push_back(pElement);

    if (m_orientation == horizontal)
    {
        // 设置子元素的y坐标，让其在垂直方向上居中
        unsigned top = (m_height - pElement->getHeight()) / 2;
        pElement->setTop(top);
        // 调整所有元素的x坐标，让它们在水平方向上均匀分布
        horRepositionX();
    }
    else
    {
        // 设置子元素的x坐标，让其在水平方向上居中
        unsigned left = (m_width - pElement->getWidth()) / 2;
        pElement->setLeft(left);
        // 调整所有元素的y坐标，让它们在垂直方向上均匀分布
        verRepositionY();
    }
}


// 方向为水平时调整所有子元素位置
void FlowLinearLayout::horRepositionX()
{
    // 计算元素之间在水平方向上的间隔距离
    unsigned sumWidth = 0;
    for each (auto var in m_childArray)
    {
        sumWidth += var->getWidth();
    }
    int margin = m_width - m_leftBlank - m_rightBlank - sumWidth;
    if (margin < 0)
    {
        margin = 0;
    }
    // 设置元素的x坐标
    unsigned left = m_leftBlank;
    for each (auto var in m_childArray)
    {
        var->setLeft(left);
        left += margin;
    }
}


// 方向为垂直时调整所有子元素位置
void FlowLinearLayout::verRepositionY()
{
    // 计算元素之间在垂直方向上的间隔距离
    unsigned sumHeight = 0;
    for each (auto var in m_childArray)
    {
        sumHeight += var->getHeight();
    }
    int margin = m_height - m_topBlank - m_bottomBlank - sumHeight;
    if (margin < 0)
    {
        margin = 0;
    }
    // 设置元素的y坐标
    unsigned top = m_topBlank;
    for each (auto var in m_childArray)
    {
        var->setTop(top);
        top += margin;
    }
}

