#include "Button.h"



Button::Button(int width, int height, TCHAR * text)
    :StaticText(width, height, text)
{
}


Button::~Button()
{
}


// 获得焦点
void Button::getFocus()
{
    m_ifGotFocus = true;
}


// 失去焦点
void Button::loseFocus()
{
    m_ifGotFocus = false;
}


// 鼠标移动到控件上
void Button::mouseMoveIn()
{
    m_ifMouseIn = true;
}


// 鼠标移出控件
void Button::mouseMoveOut()
{
    m_ifMouseIn = false;
    if (m_state == Pressed)
    {
        m_state = Normal;
    }
}


// 鼠标左键按下（在控件捕获范围内）
void Button::LMBDown()
{
    if (m_state == Normal)
    {
        m_state = Pressed;
    }
}


// 鼠标左键弹起（在控件捕获范围内）
void Button::LMBUp()
{
    if (m_state == Pressed)
    {
        m_state = Normal;

        // 如果连接了按键动作就执行对动作
        auto it = m_eventActionMap.find(clicked);
        if (it != m_eventActionMap.end())
        {
            (it->second)();
        }
    }
}


// 连接事件和动作
void Button::connect(Event event, function<void()> action)
{
    m_eventActionMap[event] = action;
}


// 绘制
void Button::draw(Gdiplus::Graphics &g)
{
    // 绘制边框
    Pen blackPen(Color::Black, 2.0f);
    blackPen.SetAlignment(Gdiplus::PenAlignmentInset);
    g.DrawRectangle(&blackPen, (int)m_left, m_top, m_width, m_height);

    // 如果鼠标在按钮上就绘制一层效果
    if (m_ifMouseIn)
    {
        SolidBrush solidBrush(Color(20, 0, 0, 0));
        g.FillRectangle(&solidBrush, m_left, m_top, m_width, m_height);
    }

    // 绘制文字
    FontFamily fontFamily(L"Consolas");
    Gdiplus::Font font(&fontFamily, 16, FontStyleRegular, UnitPixel);
    SolidBrush solidBrush(Color(0, 0, 0));

    StringFormat stringFormat;
    stringFormat.SetAlignment(StringAlignmentCenter);
    stringFormat.SetLineAlignment(StringAlignmentCenter);
    RectF rectF(m_left, m_top, m_width, m_height);

    g.DrawString(m_text, -1, &font, rectF, &stringFormat, &solidBrush);
}
