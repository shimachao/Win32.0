#pragma once
#include "StaticText.h"
#include <string>
#include <map>
#include <functional>
using std::string;
using std::map;
using std::function;

// 按钮类

class Button :
    public StaticText
{
public:
    Button(int width, int height, TCHAR * text = L"Static Text");
    ~Button();

    // 连接事件和动作
    void connect(Event event, function<void()> action);

    // 获得焦点
    virtual void getFocus() override;
    // 失去焦点
    virtual void loseFocus() override;

    // 鼠标移动到控件上
    void mouseMoveIn();
    // 鼠标移出控件
    virtual void mouseMoveOut() override;

    // 鼠标左键按下（在控件捕获范围内）
    virtual void LMBDown() override;
    // 鼠标左键弹起（在控件捕获范围内）
    virtual void LMBUp() override;

    // 绘制
    virtual void draw(Gdiplus::Graphics &g) override;

private:
    enum ButtonState
    {
        Pressed, Normal
    };

private:
    bool m_ifGotFocus = false;  // 是否拥有焦点
    bool m_ifMouseIn = false;   // 鼠标是否在控件内
    ButtonState m_state = Normal;    // 鼠标的状态，被按下或正常
    map<Event, function<void()>> m_eventActionMap; // 事件和动作之间的映射
};

