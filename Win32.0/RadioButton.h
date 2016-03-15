#pragma once
#include "IControl.h"
#include <string>
#include <map>
#include <functional>
using std::string;
using std::map;
using std::function;

// 单选按钮

class RadioButton :
    public IControl
{
public:
    enum TextPosition
    {
        left, right
    };

    RadioButton(unsigned width, unsigned height, string text);
    ~RadioButton();

    // 连接事件和动作
    void connect(Event event, function<void()> action);

    //设置文字在左边还是右边
    void setTextPos(TextPosition pos);
    // 查询是否被选中
    bool ifChecked();

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
    string m_text = "radio button"; // 文本
    TextPosition m_textPos = right;  // 文本位置，默认在右边
    bool m_ifMouseIn = false;   // 鼠标是否在控件内
    bool m_ifGotFocus = false;  // 是否获得焦点
    bool m_ifChecked = false;   // 是否被选中
    map<Event, function<void()>> m_eventActionMap;  // 事件和动作之间的映射
};

