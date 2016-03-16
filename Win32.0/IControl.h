#pragma once
#include "IElement.h"
enum Event
{
    clicked, check, uncheck
};

// 控件基类

class IControl :public IElement
{
public:
    IControl(unsigned width, unsigned height);
    ~IControl();
    
    // 鼠标移动到控件上
    virtual void mouseMoveIn() = 0;
    // 鼠标移出控件
    virtual void mouseMoveOut() = 0;

    // 鼠标左键按下（在控件捕获范围内）
    virtual void LMBDown() = 0;
    // 鼠标左键弹起（在控件捕获范围内）
    virtual void LMBUp() = 0;

    // 获得焦点
    virtual void getFocus() = 0;
    // 失去焦点
    virtual void loseFocus() = 0;

    // 测试鼠标是否落在在元素的捕获范围内
    virtual bool ifMouseIn(unsigned x, unsigned y);
};

