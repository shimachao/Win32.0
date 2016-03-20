#pragma once
#include "ILayout.h"
#include <vector>
using std::vector;

// 绝对布局

class AbsoluteLayout :
    public ILayout
{
public:
    AbsoluteLayout(unsigned width, unsigned height);
    ~AbsoluteLayout();

    // 添加子元素，参数left，top为子元素左上角坐标
    void add(IElement *pElement, unsigned left, unsigned top);
    // 鼠标移动到元素范围内
    void mouseMoveIn(unsigned x, unsigned y);
    // 绘制
    virtual void draw(Gdiplus::Graphics &g) override;

private:
    vector<IElement*>   m_childArray;
};

