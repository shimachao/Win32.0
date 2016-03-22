#pragma once
#include "Base.h"

class IElement
{
public:
    IElement(int width = 0, int height = 0);
    ~IElement();

    // 设置位置和大小
    virtual void setPos(int left, int top, int width, int height);
    // 查询位置和大小
    void getPos(int &left, int &top, int &width, int &height);
    // 设置大小
    virtual void setSize(int width, int height);
    // 查询大小
    void getSize(int &width, int &height);
    // 移动
    void move(int left, int top);
    // 设置宽度
    virtual void setWidth(int width);
    // 查询宽度
    int getWidth();
    // 设置高度
    virtual void setHeight(int height);
    // 查询高度
    int getHeight();
    // 设置垂直方向位置
    void setTop(int top);
    // 查询垂直方向位置
    int getTop();
    // 设置水平方向位置
    void setLeft(int left);
    // 查询水平方向位置
    int getLeft();

    // 设置边缘宽度
    void setMargin(int margin);
    // 设置上边缘
    void setTopMargin(int margin);
    // 设置下边缘
    void setBottomMargin(int margin);
    // 设置左边缘
    void setLeftMargin(int margin);
    // 设置右边缘
    void setRightMargin(int margin);
    // 查询边缘宽度
    int getMargin();
    // 查询上边缘宽度
    int getTopMargin();
    // 查询下边缘宽度
    int getBottomMargin();
    // 查询左边缘宽度
    int getLeftMargin();
    // 查询右边缘宽度
    int getRightMargin();

    // 测试鼠标是否落在在元素的捕获范围内
    virtual bool ifMouseIn(int x, int y);
    // 击中测试
    virtual IElement* hitTest(int x, int y);

    // 绘制
    virtual void draw(Gdiplus::Graphics &g) = 0;

protected:
    int m_left;     // 左边界
    int m_top;      // 上边界
    int m_width;    // 宽度
    int m_height;   // 高度

    int m_margin = 0;  // 边缘宽度
    int m_leftMargin = 0;  // 左边缘
    int m_rightMargin = 0; // 右边缘
    int m_topMargin = 0;   // 上边缘
    int m_bottomMargin = 0;    // 下边缘
};

