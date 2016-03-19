#include "ILayout.h"



ILayout::ILayout(unsigned width, unsigned height) 
    :IElement(width, height), m_blank(0), m_leftBlank(0), m_rightBlank(0)
    , m_topBlank(0), m_bottomBlank(0)
{
}


ILayout::~ILayout()
{
}


// 设置留白
void ILayout::setBlank(unsigned blank)
{
    m_blank = blank;

    if (m_leftBlank == 0)
    {
        m_leftBlank = m_blank;
    }

    if (m_rightBlank == 0)
    {
        m_rightBlank = m_blank;
    }

    if (m_topBlank == 0)
    {
        m_topBlank = m_blank;
    }

    if (m_bottomBlank == 0 )
    {
        m_bottomBlank = m_blank;
    }
}


// 设置左留白
void ILayout::setLeftBlank(unsigned leftBlank)
{
    m_leftBlank = leftBlank;
}


// 设置右留白
void ILayout::setRightBlank(unsigned rightBlank)
{
    m_rightBlank = rightBlank;
}


// 设置顶部留白
void ILayout::setTopBlank(unsigned topBlank)
{
    m_topBlank = topBlank;
}


// 设置底部留白
void ILayout::setBottomBlank(unsigned bottomBlank)
{
    m_bottomBlank = bottomBlank;
}


// 测试鼠标是否落在在元素的捕获范围内
bool ILayout::ifMouseIn(unsigned x, unsigned y)
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
void ILayout::mouseMoveIn(unsigned x, unsigned y)
{
    // 空实现，供子类覆盖或继承
}
