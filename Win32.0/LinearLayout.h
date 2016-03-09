#pragma once
#include "ILayout.h"
#include <list>
using std::list;

// 线性布局
class LinearLayout :
    public ILayout
{
public:
    enum Orientation
    {
        horizontal, vertical
    };

    LinearLayout(int width, int height, Orientation orientation = horizontal);
    ~LinearLayout();

    // 添加子元素
    void add(IElement *pElement);

private:
    // 布局方向为水平时的调整子元素位置方法
    void horAdjustSize();
    // 布局方向为垂直时的调整子元素位置方法
    void verAdjustSize();

private:
    list<IElement*> m_childList;    // 子元素列表
    Orientation m_orientation;      // 线性布局的方向：水平或垂直

};

