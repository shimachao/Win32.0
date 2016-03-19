#pragma once
#include "IElement.h"

// 布局基类
class ILayout : public IElement
{
public:
    ILayout(unsigned width, unsigned height);
    ~ILayout();

    // 设置留白
    void setBlank(unsigned blank);
    // 设置左留白
    void setLeftBlank(unsigned leftBlank);
    // 设置右留白
    void setRightBlank(unsigned rightBlank);
    // 设置顶部留白
    void setTopBlank(unsigned topBlank);
    // 设置底部留白
    void setBottomBlank(unsigned bottomBlank);
    // 测试鼠标是否落在在元素的捕获范围内
    bool ifMouseIn(unsigned x, unsigned y);

    // 鼠标移动到元素范围内
    virtual void mouseMoveIn(unsigned x, unsigned y);

protected:
    unsigned m_blank;        // 内部边缘留白大小
    unsigned m_leftBlank;    // 内部左边缘留白
    unsigned m_rightBlank;   // 内部右边缘留白
    unsigned m_topBlank;     // 内部上边缘留白
    unsigned m_bottomBlank;  // 内部底边缘留白
};

