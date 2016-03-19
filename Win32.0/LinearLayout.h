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

    LinearLayout(unsigned width, unsigned height, Orientation orientation = horizontal);
    ~LinearLayout();

    // 添加子元素
    void add(IElement *pElement);
    // 调整大小来以便放下所有子元素
    void resizeToFit();
    
private:
    // 布局方向为水平时的添加方法
    void horAdd(IElement *pElment);
    // 布局方向为垂直时的添加方法
    void verAdd(IElement *pElment);
    // 布局方向为水平时resizeToFit方法
    void horResizeToFit();
    // 布局方向为垂直时resizeToFit方法
    void verResizeToFit();

private:
    list<IElement*> m_childList;    // 子元素列表
    Orientation m_orientation;      // 线性布局的方向：水平或垂直

};

