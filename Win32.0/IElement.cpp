#include "IElement.h"



IElement::IElement(unsigned width, unsigned height) :
    m_left(0), m_top(0), m_width(width), m_height(height)
{
}


IElement::~IElement()
{
}


// 查询位置和大小
void IElement::getPos(unsigned &left, unsigned &top, unsigned &width, unsigned &height)
{
    left = m_left;
    top = m_top;
    width = m_width;
    height = m_height;
}


// 查询大小
void IElement::getSize(unsigned &width, unsigned &height)
{
    width = m_width;
    height = m_height;
}


// 移动
void IElement::move(unsigned left, unsigned top)
{
    m_left = left;
    m_top = top;
}


// 查询宽度
unsigned IElement::getWidth()
{
    return m_width;
}


// 查询高度
unsigned IElement::getHeight()
{
    return m_height;
}


// 设置垂直方向位置
void IElement::setTop(unsigned top)
{
    m_top = top;
}


// 查询垂直方向位置
unsigned IElement::getTop()
{
    return m_top;
}


// 设置水平方向位置
void IElement::setLeft(unsigned left)
{
    m_left = left;
}


// 查询水平方向位置
unsigned IElement::getLeft()
{
    return m_left;
}


// 设置边缘宽度
void IElement::setMargin(unsigned margin)
{
    m_margin = margin;

    if (m_topMargin == 0)
    {
        m_topMargin = margin;
    }

    if (m_bottomMargin == 0)
    {
        m_bottomMargin = margin;
    }

    if (m_leftMargin == 0)
    {
        m_leftMargin = margin;
    }

    if (m_rightMargin == 0)
    {
        m_rightMargin = margin;
    }
}


// 设置上边缘
void IElement::setTopMargin(unsigned margin)
{
    m_topMargin = margin;
}


// 设置下边缘
void IElement::setBottomMargin(unsigned margin)
{
    m_bottomMargin = margin;
}


// 设置左边缘
void IElement::setLeftMargin(unsigned margin)
{
    m_left = margin;
}


// 设置右边缘
void IElement::setRightMargin(unsigned margin)
{
    m_rightMargin = margin;
}


// 查询边缘宽度
unsigned IElement::getMargin()
{
    return m_margin;
}


// 查询上边缘宽度
unsigned IElement::getTopMargin()
{
    return m_topMargin;
}


// 查询下边缘宽度
unsigned IElement::getBottomMargin()
{
    return m_bottomMargin;
}


// 查询左边缘宽度
unsigned IElement::getLeftMargin()
{
    return m_leftMargin;
}


// 查询右边缘宽度
unsigned IElement::getRightMargin()
{
    return m_rightMargin;
}
