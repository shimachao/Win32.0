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

private:
    vector<IElement*>   m_childArray;
};

