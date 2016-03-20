#pragma once
#include "IElement.h"

// 布局基类
class ILayout : public IElement
{
public:
    ILayout(int width, int height);
    ~ILayout();

    // 设置留白
    void setBlank(int blank);
    // 设置左留白
    void setLeftBlank(int leftBlank);
    // 设置右留白
    void setRightBlank(int rightBlank);
    // 设置顶部留白
    void setTopBlank(int topBlank);
    // 设置底部留白
    void setBottomBlank(int bottomBlank);
    // 测试鼠标是否落在在元素的捕获范围内
    bool ifMouseIn(int x, int y);

    // 鼠标移动到元素范围内
    virtual void mouseMoveIn(int x, int y);

protected:
    int m_blank;        // 内部边缘留白大小
    int m_leftBlank;    // 内部左边缘留白
    int m_rightBlank;   // 内部右边缘留白
    int m_topBlank;     // 内部上边缘留白
    int m_bottomBlank;  // 内部底边缘留白
};

