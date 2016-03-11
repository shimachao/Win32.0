#pragma once
class IElement
{
public:
    IElement(unsigned width = 0, unsigned height = 0);
    ~IElement();

    // 设置位置和大小
    virtual void setPos(unsigned left, unsigned top, unsigned width, unsigned height) = 0;
    // 查询位置和大小
    void getPos(unsigned &left, unsigned &top, unsigned &width, unsigned &height);
    // 设置大小
    virtual void setSize(unsigned width, unsigned height) = 0;
    // 查询大小
    void getSize(unsigned &width, unsigned &height);
    // 移动
    void move(unsigned left, unsigned top);
    // 设置宽度
    virtual void setWidth(unsigned width) = 0;
    // 查询宽度
    unsigned getWidth();
    // 设置高度
    virtual void setHeight(unsigned height) = 0;
    // 查询高度
    unsigned getHeight();
    // 设置垂直方向位置
    void setTop(unsigned top);
    // 查询垂直方向位置
    unsigned getTop();
    // 设置水平方向位置
    void setLeft(unsigned left);
    // 查询水平方向位置
    unsigned getLeft();
    // 鼠标移到到元素上了
    virtual void MouseMoveOver(unsigned x, unsigned y) = 0;
    // 测试鼠标是否落在在元素的捕获范围内
    virtual bool ifMouseIn(unsigned x, unsigned y) = 0;

protected:
    unsigned m_left;     // 左边界
    unsigned m_top;      // 上边界
    unsigned m_width;    // 宽度
    unsigned m_height;   // 高度
};

