#include "ILayout.h"



ILayout::ILayout(int width, int height) 
    :IElement(width, height), m_blank(0), m_leftBlank(0), m_rightBlank(0)
    , m_topBlank(0), m_bottomBlank(0)
{
}


ILayout::~ILayout()
{
}


// ��������
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


// ����������
void ILayout::setLeftBlank(unsigned leftBlank)
{
    m_leftBlank = leftBlank;
}


// ����������
void ILayout::setRightBlank(unsigned rightBlank)
{
    m_rightBlank = rightBlank;
}


// ���ö�������
void ILayout::setTopBlank(unsigned topBlank)
{
    m_topBlank = topBlank;
}


// ���õײ�����
void ILayout::setBottomBlank(unsigned bottomBlank)
{
    m_bottomBlank = bottomBlank;
}

