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


// ����������
void ILayout::setLeftBlank(int leftBlank)
{
    m_leftBlank = leftBlank;
}


// ����������
void ILayout::setRightBlank(int rightBlank)
{
    m_rightBlank = rightBlank;
}


// ���ö�������
void ILayout::setTopBlank(int topBlank)
{
    m_topBlank = topBlank;
}


// ���õײ�����
void ILayout::setBottomBlank(int bottomBlank)
{
    m_bottomBlank = bottomBlank;
}


// ��������Ƿ�������Ԫ�صĲ���Χ��
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


// ����ƶ���Ԫ�ط�Χ��
void ILayout::mouseMoveIn(int x, int y)
{
    // ��ʵ�֣������า�ǻ�̳�
}
