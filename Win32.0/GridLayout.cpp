#include "GridLayout.h"



GridLayout::GridLayout(int width, int height, unsigned row, unsigned column) 
    :ILayout(width, height), m_row(row), m_column(column), m_pMark(nullptr)
    , m_childArray(nullptr)
{
    m_pMark = new bool[m_row * m_column];
    m_childArray = new IElement*[m_row * m_column];

    for (size_t i = 0; i < m_row * m_column; i++)
    {
        m_pMark[i] = false;
        m_childArray[i] = nullptr;
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
        m_childArray[i] = pElement;
        // ���ø���Ԫ�ص�����
        int row = i / m_column; // Ԫ��������
        int column = i % m_column;// Ԫ��������
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
        m_childArray[index] = pElement;
        // ���ø�Ԫ������
        int row = index / m_column; // Ԫ��������
        int column = index % m_column;// Ԫ��������
        setPos(pElement, row, column);
    }
}


// ������Ԫ��λ��
void GridLayout::setPos(IElement *pElement, unsigned row, unsigned column)
{
    int perWidth = m_width / m_column;  // ÿ������Ŀ��
    int perHeight = m_height / m_row;   // ÿ������ĸ߶�

    int left = column*perWidth + (perWidth - pElement->getWidth()) / 2;
    int top = row*perHeight + (perHeight - pElement->getHeight()) / 2;
    pElement->move(left, top);
}
