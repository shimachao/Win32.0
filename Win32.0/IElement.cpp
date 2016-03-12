#include "IElement.h"



IElement::IElement(unsigned width, unsigned height) :
    m_left(0), m_top(0), m_width(width), m_height(height)
{
}


IElement::~IElement()
{
}


// ��ѯλ�úʹ�С
void IElement::getPos(unsigned &left, unsigned &top, unsigned &width, unsigned &height)
{
    left = m_left;
    top = m_top;
    width = m_width;
    height = m_height;
}


// ��ѯ��С
void IElement::getSize(unsigned &width, unsigned &height)
{
    width = m_width;
    height = m_height;
}


// �ƶ�
void IElement::move(unsigned left, unsigned top)
{
    m_left = left;
    m_top = top;
}


// ��ѯ���
unsigned IElement::getWidth()
{
    return m_width;
}


// ��ѯ�߶�
unsigned IElement::getHeight()
{
    return m_height;
}


// ���ô�ֱ����λ��
void IElement::setTop(unsigned top)
{
    m_top = top;
}


// ��ѯ��ֱ����λ��
unsigned IElement::getTop()
{
    return m_top;
}


// ����ˮƽ����λ��
void IElement::setLeft(unsigned left)
{
    m_left = left;
}


// ��ѯˮƽ����λ��
unsigned IElement::getLeft()
{
    return m_left;
}


// ���ñ�Ե���
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


// �����ϱ�Ե
void IElement::setTopMargin(unsigned margin)
{
    m_topMargin = margin;
}


// �����±�Ե
void IElement::setBottomMargin(unsigned margin)
{
    m_bottomMargin = margin;
}


// �������Ե
void IElement::setLeftMargin(unsigned margin)
{
    m_left = margin;
}


// �����ұ�Ե
void IElement::setRightMargin(unsigned margin)
{
    m_rightMargin = margin;
}


// ��ѯ��Ե���
unsigned IElement::getMargin()
{
    return m_margin;
}


// ��ѯ�ϱ�Ե���
unsigned IElement::getTopMargin()
{
    return m_topMargin;
}


// ��ѯ�±�Ե���
unsigned IElement::getBottomMargin()
{
    return m_bottomMargin;
}


// ��ѯ���Ե���
unsigned IElement::getLeftMargin()
{
    return m_leftMargin;
}


// ��ѯ�ұ�Ե���
unsigned IElement::getRightMargin()
{
    return m_rightMargin;
}
