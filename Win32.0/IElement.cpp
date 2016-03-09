#include "IElement.h"



IElement::IElement(int width, int height) :
    m_left(0), m_top(0), m_width(width), m_height(height)
{
}


IElement::~IElement()
{
}


// ��ѯλ�úʹ�С
void IElement::getPos(int &left, int &top, int &width, int &height)
{
    left = m_left;
    top = m_top;
    width = m_width;
    height = m_height;
}

// ��ѯ��С
void IElement::getSize(int &width, int &height)
{
    width = m_width;
    height = m_height;
}

// ��ѯ���
int IElement::getWidth()
{
    return m_width;
}


// ��ѯ�߶�
int IElement::getHeight()
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

