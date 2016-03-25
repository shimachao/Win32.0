#include "Progress.h"



Progress::Progress(int width, int height, unsigned range, unsigned step)
    :IControl(width, height), m_range(range), m_step(step)
{
}


Progress::~Progress()
{
}


// ���ò���
void Progress::setStep(unsigned step)
{
    if (step <= m_range)
    {
        m_step = step;
    }
}


// ���ý���
void Progress::setPace(unsigned pace)
{
    // ���õĽ��Ȳ��ܳ�����Χ����������Ϊ���ֵ
    if (pace > m_range)
    {
        pace = m_range;
    }
    m_pace = pace;

    // ������������˾�ִ�ж�Ӧ�Ķ���
    if (m_pace == m_range && m_fullAction != nullptr)
    {
        m_fullAction();
    }
}


// ���ý�����������Ҫִ�еĶ���
void Progress::setFullAction(function<void()> action)
{
    m_fullAction = action;
}


// ������ǰ��һ����λ
void Progress::step()
{
    m_pace += m_step;

    // ������ȳ��������ֵ������ص����ֵ
    if (m_pace > m_range)
    {
        m_pace = m_range;
    }
    // ������������ˣ����ö�Ӧ�Ķ���
    if (m_pace == m_range)
    {
        m_fullAction();
    }
}


// ��ѯ��Χ
unsigned Progress::getRange()
{
    return m_range;
}


// ��ѯ��ǰλ��
unsigned Progress::getPace()
{
    return m_pace;
}


// ����
void Progress::draw(Gdiplus::Graphics &g)
{
    // ���Ʊ߿�
    Pen blackPen(Color::Black);
    g.DrawRectangle(&blackPen, m_left, m_top, m_width, m_height);

    // ���ƽ���
    SolidBrush brush(Color::DarkGray);
    g.FillRectangle(&brush, m_left, m_top, ((double)m_pace / m_range)*m_width, m_height);
}
