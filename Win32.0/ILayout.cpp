#include "ILayout.h"



ILayout::ILayout(int width, int height) 
    :IElement(width, height), m_blank(0), m_leftBlank(0), m_rightBlank(0)
    , m_topBlank(0), m_bottomBlank(0)
{
}


ILayout::~ILayout()
{
}


// …Ë÷√¡Ù∞◊
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


// …Ë÷√◊Û¡Ù∞◊
void ILayout::setLeftBlank(unsigned leftBlank)
{
    m_leftBlank = leftBlank;
}


// …Ë÷√”“¡Ù∞◊
void ILayout::setRightBlank(unsigned rightBlank)
{
    m_rightBlank = rightBlank;
}


// …Ë÷√∂•≤ø¡Ù∞◊
void ILayout::setTopBlank(unsigned topBlank)
{
    m_topBlank = topBlank;
}


// …Ë÷√µ◊≤ø¡Ù∞◊
void ILayout::setBottomBlank(unsigned bottomBlank)
{
    m_bottomBlank = bottomBlank;
}

