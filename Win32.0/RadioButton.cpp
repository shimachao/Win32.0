#include "RadioButton.h"



RadioButton::RadioButton(int width, int height, TCHAR* text)
    :IControl(width, height), m_text(text)
{
}


RadioButton::~RadioButton()
{
}


//设置文字在左边还是右边
void RadioButton::setTextPos(TextPosition pos)
{
    m_textPos = pos;
}


// 查询是否被选中
bool RadioButton::ifChecked()
{
    return m_ifChecked;
}


// 连接事件和动作
void RadioButton::connect(Event event, function<void()> action)
{
    m_eventActionMap[event] = action;
}


// 获得焦点
void RadioButton::getFocus()
{
    m_ifGotFocus = true;
}


// 失去焦点
void RadioButton::loseFocus()
{
    m_ifGotFocus = false;
}


// 鼠标移动到控件上
void RadioButton::mouseMoveIn()
{
    m_ifMouseIn = true;
}


// 鼠标移出控件
void RadioButton::mouseMoveOut()
{
    m_ifMouseIn = false;
}


// 鼠标左键按下（在控件捕获范围内）
void RadioButton::LMBDown()
{
    // 修改选中状态
    m_ifChecked = !m_ifChecked;

    if (m_ifChecked)
    {
        // 如果连接了动作，就执行对应的动作
        auto it = m_eventActionMap.find(check);
        if (it != m_eventActionMap.end())
        {
            (it->second)();
        }
    }
    else
    {
        // 如果连接了动作，就执行对应的动作
        auto it = m_eventActionMap.find(uncheck);
        if (it != m_eventActionMap.end())
        {
            (it->second)();
        }
    }
}

// 鼠标左键弹起（在控件捕获范围内）
void RadioButton::LMBUp()
{
}


// 测试鼠标是否落在在元素的捕获范围内
bool RadioButton::ifMouseIn(int x, int y)
{
    if (m_textPos == right)
    {
        if (x >=0 && x << m_height && y >= 0 && y <= m_height)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (x >= (m_width - m_height) && x <= m_width && y >= 0 && y <= m_height)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}


// 击中测试
IElement* RadioButton::hitTest(int x, int y)
{
    if (m_textPos == left)
    {
        if (x >= m_left + m_width - 10 && x <= m_left + m_width
            && y >= m_top + (m_height - 10)/2 && y <= m_top + m_height / 2 + 5)
        {
            return this;
        }
    }
    else
    {
        if (x >= m_left && x <= m_left + 10
            && y >= m_top + (m_height - 10) / 2 && y <= m_top + m_height / 2 + 5)
        {
            return this;
        }
    }

    return nullptr;
}


// 绘制
void RadioButton::draw(Gdiplus::Graphics &g)
{
    // 计算选中状态部分和文字部分范围
    Rect selectRect;
    RectF textRectF;
    selectRect.Width = 10;
    selectRect.Height = 10;
    selectRect.Y = m_top + (m_height - 10) / 2;

    textRectF.Y = m_top;
    textRectF.Height = m_height;
    textRectF.Width = m_width - 10;

    if (m_textPos == left)
    {
        textRectF.X = m_left;

        selectRect.X = m_left + m_width - 10;
    }
    else
    {
        textRectF.X = m_left + 10;

        selectRect.X = m_left;
    }
    // 绘制表示选中状态的部分
    // 如果鼠标移到到单选按钮上就绘制一层效果
    if (m_ifMouseIn)
    {
        SolidBrush brush(Color(40, 0, 0, 0));
        Rect r = selectRect;
        r.X -= 4;
        r.Y -= 4;
        r.Width += 8;
        r.Height += 8;
        g.FillEllipse(&brush, r);
    }
    // 绘制圆孔
    Pen blackPen(Color::Black);
    g.DrawEllipse(&blackPen, selectRect);
    // 如果选中就填充选中状态部分
    if (m_ifChecked)
    {
        selectRect.X += 1;
        selectRect.Y += 1;
        selectRect.Width -= 2;
        selectRect.Height -= 2;
        SolidBrush solidBrush(Color::Black);
        g.FillEllipse(&solidBrush, selectRect);
    }

    // 绘制文字
    FontFamily fontFamily(L"Consolas");
    Gdiplus::Font font(&fontFamily, 16, FontStyleRegular, UnitPixel);
    SolidBrush solidBrush(Color::Black);
    StringFormat stringFormat;
    stringFormat.SetAlignment(StringAlignmentCenter);
    stringFormat.SetLineAlignment(StringAlignmentCenter);

    g.DrawString(m_text, -1, &font, textRectF, &stringFormat, &solidBrush);
}
