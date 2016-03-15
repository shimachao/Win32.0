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
    Button(unsigned width, unsigned height, string text = "static text");
    ~Button();

    // 连接事件和动作
    void connect(Event event, function<void()> action);

    // 获得焦点
    void getFocus();
    // 失去焦点
    void loseFocus();

    // 鼠标移动到控件上
    void mouseMoveIn();
    // 鼠标移出控件
    void mouseMoveOut();

    // 鼠标左键按下（在控件捕获范围内）
    void LMBDown();
    // 鼠标左键弹起（在控件捕获范围内）
    void LMBUp();

private:
    enum ButtonState
    {
        Pressed, Normal
    };

private:
    bool m_ifGotFocus = false;  // 是否拥有焦点
    bool m_ifMouseIn = false;   // 鼠标是否在控件内
    ButtonState m_state;    // 鼠标的状态，被按下或正常
    map<Event, function<void()>> m_eventActionMap; // 事件和动作之间的映射
};

