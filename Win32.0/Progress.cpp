#include "Progress.h"



Progress::Progress(int width, int height, unsigned range, unsigned step)
    :IControl(width, height), m_range(range), m_step(step)
{
}


Progress::~Progress()
{
}


// 设置步长
void Progress::setStep(unsigned step)
{
    if (step <= m_range)
    {
        m_step = step;
    }
}


// 设置进度
void Progress::setPace(unsigned pace)
{
    // 设置的进度不能超过范围，超过了设为最大值
    if (pace > m_range)
    {
        pace = m_range;
    }
    m_pace = pace;

    // 如果进度条满了就执行对应的动作
    if (m_pace == m_range && m_fullAction != nullptr)
    {
        m_fullAction();
    }
}


// 设置进度条满后需要执行的动作
void Progress::setFullAction(function<void()> action)
{
    m_fullAction = action;
}


// 按步长前进一个单位
void Progress::step()
{
    m_pace += m_step;

    // 如果进度超过了最大值，让其回到最大值
    if (m_pace > m_range)
    {
        m_pace = m_range;
    }
    // 如果进度条满了，调用对应的动作
    if (m_pace == m_range)
    {
        m_fullAction();
    }
}


// 查询范围
unsigned Progress::getRange()
{
    return m_range;
}


// 查询当前位置
unsigned Progress::getPace()
{
    return m_pace;
}


// 绘制
void Progress::draw(Gdiplus::Graphics &g)
{
    // 绘制边框
    Pen blackPen(Color::Black);
    g.DrawRectangle(&blackPen, m_left, m_top, m_width, m_height);

    // 绘制进度
    SolidBrush brush(Color::DarkGray);
    g.FillRectangle(&brush, m_left, m_top, ((double)m_pace / m_range)*m_width, m_height);
}
