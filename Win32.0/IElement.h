#pragma once
class IElement
{
public:
    IElement(int width = 0, int height = 0);
    ~IElement();

    // 设置位置和大小
    virtual void setPos(int left, int top, int width, int height) = 0;
    // 查询位置和大小
    void getPos(int &left, int &top, int &width, int &height);
    // 设置大小
    virtual void setSize(int width, int height) = 0;
    // 查询大小
    void getSize(int &width, int &height);
    // 移动
    virtual void move(int left, int top) = 0;
    // 设置宽度
    virtual void setWidth(int width) = 0;
    // 查询宽度
    int getWidth();
    // 设置高度
    virtual void setHeight(int height) = 0;
    // 查询高度
    int getHeight();
    // 设置垂直方向位置
    void setTop(unsigned top);
    // 查询垂直方向位置
    unsigned getTop();
    // 设置水平方向位置
    void setLeft(unsigned left);
    // 查询水平方向位置
    unsigned getLeft();

protected:
    int m_left;     // 左边界
    int m_top;      // 上边界
    int m_width;    // 宽度
    int m_height;   // 高度
};

