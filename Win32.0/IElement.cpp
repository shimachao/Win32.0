#include "IElement.h"



IElement::IElement(int width, int height) :
    m_left(0), m_top(0), m_width(width), m_height(height)
{
}


IElement::~IElement()
{
}


// 查询位置和大小
void IElement::getPos(int &left, int &top, int &width, int &height)
{
    left = m_left;
    top = m_top;
    width = m_width;
    height = m_height;
}

// 查询大小
void IElement::getSize(int &width, int &height)
{
    width = m_width;
    height = m_height;
}

// 查询宽度
int IElement::getWidth()
{
    return m_width;
}


// 查询高度
int IElement::getHeight()
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

