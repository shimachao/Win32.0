#pragma once
#include "ILayout.h"
#include <vector>
using std::vector;

// 浮动线性布局

class FlowLinearLayout :
    public ILayout
{
public:
    enum Orientation
    {
        horizontal, vertical
    };

    FlowLinearLayout(unsigned width, unsigned height, Orientation ori = horizontal);
    ~FlowLinearLayout();

    // 添加元素
    void add(IElement* pElement);
    // 鼠标移动到元素范围内
    void mouseMoveIn(unsigned x, unsigned y);

private:
    // 方向为水平时调整所有子元素的x坐标
    void horRepositionX();
    // 方向为垂直时调整所有子元素的y坐标
    void verRepositionY();

private:
    vector<IElement*>   m_childArray;   // 子元素数组
    Orientation m_orientation;  // 方向
};

