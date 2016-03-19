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


// 添加子元素
void GridLayout::add(IElement *pElement)
{
    // 找到一个空闲的网格
    unsigned i = 0;
    while (!m_pMark[i])
    {
        i++;
    }

    if (i >= m_row * m_column)
    {
        // 如果找到空位就直接返回
        return;
    }
    else
    {
        m_pMark[i] = true;
        m_childMap[i] = pElement;
        // 设置该子元素的坐标
        unsigned row = i / m_column; // 元素所在行
        unsigned column = i % m_column;// 元素所在列
        setPos(pElement, row, column);
    }
}


// 在具体的某行某列添加子元素
void GridLayout::add(IElement *pElement, unsigned row, unsigned column)
{
    unsigned index = row * m_column + column;

    if (row >= m_row 
        || column >= m_column 
        || index >= m_row*m_column
        || m_pMark[index])
    {
        // 如果插入的行列超过了范围，或者该位置已有元素，就拒绝插入
        return;
    }
    else
    {
        m_pMark[index] = true;
        m_childMap[index] = pElement;
        // 设置该元素坐标
        setPos(pElement, row, column);
    }
}


// 设置子元素位置
void GridLayout::setPos(IElement *pElement, unsigned row, unsigned column)
{
    unsigned perWidth = m_width / m_column;  // 每个网格的宽度
    unsigned perHeight = m_height / m_row;   // 每个网格的高度

    unsigned left = column*perWidth + (perWidth - pElement->getWidth()) / 2;
    unsigned top = row*perHeight + (perHeight - pElement->getHeight()) / 2;
    pElement->move(left, top);
}


// 鼠标移动到元素范围内
void GridLayout::mouseMoveIn(unsigned x, unsigned y)
{
    for each (const auto& var in m_childMap)
    {
        if (var.second->ifMouseIn(x - m_left, y - m_top))
        {
            var.second->mouseMoveIn(x - m_left, y - m_top);
            break;
        }
    }
}
