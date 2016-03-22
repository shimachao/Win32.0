#include "GridLayout.h"



GridLayout::GridLayout(int width, int height, int row, int column) 
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
    int i = 0;
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
        int row = i / m_column; // Ԫ��������
        int column = i % m_column;// Ԫ��������
        setPos(pElement, row, column);
    }
}


// �ھ����ĳ��ĳ�������Ԫ��
void GridLayout::add(IElement *pElement, int row, int column)
{
    int index = row * m_column + column;

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
void GridLayout::setPos(IElement *pElement, int row, int column)
{
    int perWidth = m_width / m_column;  // ÿ������Ŀ��
    int perHeight = m_height / m_row;   // ÿ������ĸ߶�

    int left = column*perWidth + (perWidth - pElement->getWidth()) / 2;
    int top = row*perHeight + (perHeight - pElement->getHeight()) / 2;
    pElement->move(left, top);
}


// ����ƶ���Ԫ�ط�Χ��
//void GridLayout::mouseMoveIn(int x, int y)
//{
//    for each (const auto& var in m_childMap)
//    {
//        if (var.second->ifMouseIn(x - m_left, y - m_top))
//        {
//            var.second->mouseMoveIn(x - m_left, y - m_top);
//            break;
//        }
//    }
//}


// ����
void GridLayout::draw(Graphics &g)
{
    g.TranslateTransform(m_left, m_top);

    for each (const auto& var in m_childMap)
    {
        var.second->draw(g);
    }

    g.TranslateTransform(m_left, m_top);
}


// ���в���
IElement* GridLayout::hitTest(int x, int y)
{
    for each (const auto& var in m_childMap)
    {
        if (var.second->hitTest(x - m_left, y - m_top))
        {
            return var.second;
        }
    }

    return nullptr;
}
