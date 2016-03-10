#pragma once
#include "ILayout.h"
#include <map>
using std::map;

// 网格布局
class GridLayout :
    public ILayout
{
public:
    GridLayout(int width, int height, unsigned row, unsigned column);
    ~GridLayout();

    // 添加子元素
    void add(IElement *pElement);
    // 在具体的某行某列添加子元素
    void add(IElement *pElement, unsigned row, unsigned column);

private:
    // 设置子元素位置
    void setPos(IElement *pElement, unsigned row, unsigned column);

private:
    unsigned    m_row;  // 行数
    unsigned    m_column;   // 列数
    bool    *m_pMark;   // 用来记录网格的使用情况
    IElement*   *m_childArray; // 用来保存子元素的字典
};

