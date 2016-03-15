#pragma once
#include "IControl.h"
#include <string>
using std::string;

// 静态文本控件

class StaticText :
    public IControl
{
public:
    // 对齐方式枚举类型
    enum Alignment{left, right, top, bottom, center};

    StaticText(unsigned width, unsigned height, string text);
    ~StaticText();

    void setText(string text);
    // 设置水平对齐方式
    void setTextHorizontalAlignment(Alignment align);
    // 设置垂直方向上的对齐方式
    void setTextVerticalAlignment(Alignment align);

protected:
    string  m_text = "static text"; // 文本
    Alignment   m_horizontalAlignment = center; // 水平对齐方式
    Alignment   m_verticalAlignment = center;   // 垂直对齐方式
};

