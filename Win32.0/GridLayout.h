#pragma once
#include "ILayout.h"
#include <map>
using std::map;

// 网格布局
class GridLayout :
    public ILayout
{
public:
    GridLayout(int width, int height, int row, int column);
    ~GridLayout();

    // 添加子元素
    void add(IElement *pElement);
    // 在具体的某行某列添加子元素
    void add(IElement *pElement, int row, int column);
    // 鼠标移动到元素范围内
//    void mouseMoveIn(int x, int y);
    // 绘制
    virtual void draw(Graphics &g) override;
    // 击中测试
    virtual IElement* hitTest(int x, int y) override;

private:
    // 设置子元素位置
    void setPos(IElement *pElement, int row, int column);

private:
    int    m_row;  // 行数
    int    m_column;   // 列数
    bool    *m_pMark;   // 用来记录网格的使用情况
    map<int, IElement*> m_childMap; // 用来保存子元素的字典
};

