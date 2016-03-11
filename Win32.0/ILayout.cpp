#include "ILayout.h"



ILayout::ILayout(unsigned width, unsigned height) 
    :IElement(width, height), m_blank(0), m_leftBlank(0), m_rightBlank(0)
    , m_topBlank(0), m_bottomBlank(0)
{
}


ILayout::~ILayout()
{
}


// ÉèÖÃÁô°×
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


// ÉèÖÃ×óÁô°×
void ILayout::setLeftBlank(unsigned leftBlank)
{
    m_leftBlank = leftBlank;
}


// ÉèÖÃÓÒÁô°×
void ILayout::setRightBlank(unsigned rightBlank)
{
    m_rightBlank = rightBlank;
}


// ÉèÖÃ¶¥²¿Áô°×
void ILayout::setTopBlank(unsigned topBlank)
{
    m_topBlank = topBlank;
}


// ÉèÖÃµ×²¿Áô°×
void ILayout::setBottomBlank(unsigned bottomBlank)
{
    m_bottomBlank = bottomBlank;
}


// ²âÊÔÊó±êÊÇ·ñÂäÔÚÔÚÔªËØµÄ²¶»ñ·¶Î§ÄÚ
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
