#include "ILayout.h"



ILayout::ILayout(int width, int height) 
    :IElement(width, height), m_blank(0), m_leftBlank(0), m_rightBlank(0)
    , m_topBlank(0), m_bottomBlank(0)
{
}


ILayout::~ILayout()
{
}


// 设置留白
void ILayout::setBlank(int blank)
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
void ILayout::setLeftBlank(int leftBlank)
{
    m_leftBlank = leftBlank;
}


// 设置右留白
void ILayout::setRightBlank(int rightBlank)
{
    m_rightBlank = rightBlank;
}


// 设置顶部留白
void ILayout::setTopBlank(int topBlank)
{
    m_topBlank = topBlank;
}


// 设置底部留白
void ILayout::setBottomBlank(int bottomBlank)
{
    m_bottomBlank = bottomBlank;
}


// 测试鼠标是否落在在元素的捕获范围内
//bool ILayout::ifMouseIn(int x, int y)
//{
//    if (x >= m_left && x <= m_left + m_width
//        && y >= m_top && y <= m_top + m_height)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}


// 鼠标移动到元素范围内
void ILayout::mouseMoveIn(int x, int y)
{
    // 空实现，供子类覆盖或继承
}
