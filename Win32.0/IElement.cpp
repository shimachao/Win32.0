#include "IElement.h"



IElement::IElement(int width, int height) :
    m_left(0), m_top(0), m_width(width), m_height(height)
{
}


IElement::~IElement()
{
}


// 设置位置和大小
void IElement::setPos(int left, int top, int width, int height)
{
    m_left = left;
    m_top = top;
    m_width = width;
    m_height = height;
}


// 查询位置和大小
void IElement::getPos(int &left, int &top, int &width, int &height)
{
    left = m_left;
    top = m_top;
    width = m_width;
    height = m_height;
}


// 设置大小
void IElement::setSize(int width, int height)
{
    m_width = width;
    m_height = height;
}


// 查询大小
void IElement::getSize(int &width, int &height)
{
    width = m_width;
    height = m_height;
}


// 移动
void IElement::move(int left, int top)
{
    m_left = left;
    m_top = top;
}


// 设置宽度
void IElement::setWidth(int width)
{
    m_width = width;
}


// 查询宽度
int IElement::getWidth()
{
    return m_width;
}


// 设置高度
void IElement::setHeight(int height)
{
    m_height = height;
}


// 查询高度
int IElement::getHeight()
{
    return m_height;
}


// 设置垂直方向位置
void IElement::setTop(int top)
{
    m_top = top;
}


// 查询垂直方向位置
int IElement::getTop()
{
    return m_top;
}


// 设置水平方向位置
void IElement::setLeft(int left)
{
    m_left = left;
}


// 查询水平方向位置
int IElement::getLeft()
{
    return m_left;
}


// 设置边缘宽度
void IElement::setMargin(int margin)
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
void IElement::setTopMargin(int margin)
{
    m_topMargin = margin;
}


// 设置下边缘
void IElement::setBottomMargin(int margin)
{
    m_bottomMargin = margin;
}


// 设置左边缘
void IElement::setLeftMargin(int margin)
{
    m_left = margin;
}


// 设置右边缘
void IElement::setRightMargin(int margin)
{
    m_rightMargin = margin;
}


// 查询边缘宽度
int IElement::getMargin()
{
    return m_margin;
}


// 查询上边缘宽度
int IElement::getTopMargin()
{
    return m_topMargin;
}


// 查询下边缘宽度
int IElement::getBottomMargin()
{
    return m_bottomMargin;
}


// 查询左边缘宽度
int IElement::getLeftMargin()
{
    return m_leftMargin;
}


// 查询右边缘宽度
int IElement::getRightMargin()
{
    return m_rightMargin;
}


// 测试鼠标是否落在在元素的捕获范围内
bool IElement::ifMouseIn(int x, int y)
{
    if (x >= m_left && x <= m_left + m_width
        && y >= m_top && y <= m_top + m_height)
    {
        return true;
    }
    else
    {
        return false;
    }
}


// 鼠标移动到元素范围内
void IElement::mouseMoveIn(int x, int y)
{
    // do nothing
}
