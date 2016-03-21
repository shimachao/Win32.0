#include "IElement.h"



IElement::IElement(int width, int height) :
    m_left(0), m_top(0), m_width(width), m_height(height)
{
}


IElement::~IElement()
{
}


// ����λ�úʹ�С
void IElement::setPos(int left, int top, int width, int height)
{
    m_left = left;
    m_top = top;
    m_width = width;
    m_height = height;
}


// ��ѯλ�úʹ�С
void IElement::getPos(int &left, int &top, int &width, int &height)
{
    left = m_left;
    top = m_top;
    width = m_width;
    height = m_height;
}


// ���ô�С
void IElement::setSize(int width, int height)
{
    m_width = width;
    m_height = height;
}


// ��ѯ��С
void IElement::getSize(int &width, int &height)
{
    width = m_width;
    height = m_height;
}


// �ƶ�
void IElement::move(int left, int top)
{
    m_left = left;
    m_top = top;
}


// ���ÿ��
void IElement::setWidth(int width)
{
    m_width = width;
}


// ��ѯ���
int IElement::getWidth()
{
    return m_width;
}


// ���ø߶�
void IElement::setHeight(int height)
{
    m_height = height;
}


// ��ѯ�߶�
int IElement::getHeight()
{
    return m_height;
}


// ���ô�ֱ����λ��
void IElement::setTop(int top)
{
    m_top = top;
}


// ��ѯ��ֱ����λ��
int IElement::getTop()
{
    return m_top;
}


// ����ˮƽ����λ��
void IElement::setLeft(int left)
{
    m_left = left;
}


// ��ѯˮƽ����λ��
int IElement::getLeft()
{
    return m_left;
}


// ���ñ�Ե���
void IElement::setMargin(int margin)
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
void IElement::setTopMargin(int margin)
{
    m_topMargin = margin;
}


// �����±�Ե
void IElement::setBottomMargin(int margin)
{
    m_bottomMargin = margin;
}


// �������Ե
void IElement::setLeftMargin(int margin)
{
    m_left = margin;
}


// �����ұ�Ե
void IElement::setRightMargin(int margin)
{
    m_rightMargin = margin;
}


// ��ѯ��Ե���
int IElement::getMargin()
{
    return m_margin;
}


// ��ѯ�ϱ�Ե���
int IElement::getTopMargin()
{
    return m_topMargin;
}


// ��ѯ�±�Ե���
int IElement::getBottomMargin()
{
    return m_bottomMargin;
}


// ��ѯ���Ե���
int IElement::getLeftMargin()
{
    return m_leftMargin;
}


// ��ѯ�ұ�Ե���
int IElement::getRightMargin()
{
    return m_rightMargin;
}


// ��������Ƿ�������Ԫ�صĲ���Χ��
bool IElement::ifMouseIn(int x, int y)
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


// ����ƶ���Ԫ�ط�Χ��
void IElement::mouseMoveIn(int x, int y)
{
    // do nothing
}
