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

