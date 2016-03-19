#include "GridLayout.h"



GridLayout::GridLayout(unsigned width, unsigned height, unsigned row, unsigned column) 
    :ILayout(width, height), m_row(row), m_column(column), m_pMark(nullptr)
{
    m_pMark = new bool[m_row * m_column];

    for (size_t i = 0; i < m_row * m_column; i++)
    {
        m_pMark[i] = false;
    }
}


GridLayout::~GridLayout()
{
    if (m_pMark)
    {
        delete[] m_pMark;
        m_pMark = nullptr;
    }
}


// �����Ԫ��
void GridLayout::add(IElement *pElement)
{
    // �ҵ�һ�����е�����
    unsigned i = 0;
    while (!m_pMark[i])
    {
        i++;
    }

    if (i >= m_row * m_column)
    {
        // ����ҵ���λ��ֱ�ӷ���
        return;
    }
    else
    {
        m_pMark[i] = true;
        m_childMap[i] = pElement;
        // ���ø���Ԫ�ص�����
        unsigned row = i / m_column; // Ԫ��������
        unsigned column = i % m_column;// Ԫ��������
        setPos(pElement, row, column);
    }
}


// �ھ����ĳ��ĳ�������Ԫ��
void GridLayout::add(IElement *pElement, unsigned row, unsigned column)
{
    unsigned index = row * m_column + column;

    if (row >= m_row 
        || column >= m_column 
        || index >= m_row*m_column
        || m_pMark[index])
    {
        // �����������г����˷�Χ�����߸�λ������Ԫ�أ��;ܾ�����
        return;
    }
    else
    {
        m_pMark[index] = true;
        m_childMap[index] = pElement;
        // ���ø�Ԫ������
        setPos(pElement, row, column);
    }
}


// ������Ԫ��λ��
void GridLayout::setPos(IElement *pElement, unsigned row, unsigned column)
{
    unsigned perWidth = m_width / m_column;  // ÿ������Ŀ��
    unsigned perHeight = m_height / m_row;   // ÿ������ĸ߶�

    unsigned left = column*perWidth + (perWidth - pElement->getWidth()) / 2;
    unsigned top = row*perHeight + (perHeight - pElement->getHeight()) / 2;
    pElement->move(left, top);
}
