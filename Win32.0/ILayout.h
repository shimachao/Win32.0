#pragma once
#include "IElement.h"

// 布局基类
class ILayout : public IElement
{
public:
    ILayout(int width, int height);
    ~ILayout();

    // 添加子元素
    virtual void add(IElement *pElement) = 0;
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


protected:
    unsigned int m_blank;        // 内部边缘留白大小
    unsigned int m_leftBlank;    // 内部左边缘留白
    unsigned int m_rightBlank;   // 内部右边缘留白
    unsigned int m_topBlank;     // 内部上边缘留白
    unsigned int m_bottomBlank;  // 内部底边缘留白
};

