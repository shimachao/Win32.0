#include "FlowLinearLayout.h"



FlowLinearLayout::FlowLinearLayout(int width, int height, Orientation ori) 
    :ILayout(width, height), m_orientation(ori)
{
}


FlowLinearLayout::~FlowLinearLayout()
{
}


// ���Ԫ��
void FlowLinearLayout::add(IElement* pElement)
{
    m_childArray.push_back(pElement);

    if (m_orientation == horizontal)
    {
        // ������Ԫ�ص�y���꣬�����ڴ�ֱ�����Ͼ���
        int top = (m_height - pElement->getHeight()) / 2;
        pElement->setTop(top);
        // ��������Ԫ�ص�x���꣬��������ˮƽ�����Ͼ��ȷֲ�
        horRepositionX();
    }
    else
    {
        // ������Ԫ�ص�x���꣬������ˮƽ�����Ͼ���
        int left = (m_width - pElement->getWidth()) / 2;
        pElement->setLeft(left);
        // ��������Ԫ�ص�y���꣬�������ڴ�ֱ�����Ͼ��ȷֲ�
        verRepositionY();
    }
}


// ����Ϊˮƽʱ����������Ԫ��λ��
void FlowLinearLayout::horRepositionX()
{
    // ����Ԫ��֮����ˮƽ�����ϵļ������
    int sumWidth = 0;
    for each (const auto& var in m_childArray)
    {
        sumWidth += var->getWidth();
    }
    int margin = (m_width - m_leftBlank - m_rightBlank - sumWidth) / (m_childArray.size() + 1);
    if (margin < 0)
    {
        margin = 0;
    }
    // ����Ԫ�ص�x����
    int left = m_leftBlank + margin;
    for each (const auto& var in m_childArray)
    {
        var->setLeft(left);
        left += var->getWidth() + margin;
    }
}


// ����Ϊ��ֱʱ����������Ԫ��λ��
void FlowLinearLayout::verRepositionY()
{
    // ����Ԫ��֮���ڴ�ֱ�����ϵļ������
    int sumHeight = 0;
    for each (const auto& var in m_childArray)
    {
        sumHeight += var->getHeight();
    }
    int margin = (m_height - m_topBlank - m_bottomBlank - sumHeight) / (m_childArray.size() + 1);
    if (margin < 0)
    {
        margin = 0;
    }
    // ����Ԫ�ص�y����
    int top = m_topBlank + margin;
    for each (const auto& var in m_childArray)
    {
        var->setTop(top);
        top += var->getHeight() + margin;
    }
}


// ����ƶ���Ԫ�ط�Χ��
//void FlowLinearLayout::mouseMoveIn(int x, int y)
//{
//    for each (const auto& var in m_childArray)
//    {
//        if (var->ifMouseIn(x - m_left, y - m_top))
//        {
//            var->mouseMoveIn(x - m_left, y - m_top);
//        }
//    }
//}


// ����
void FlowLinearLayout::draw(Gdiplus::Graphics &g)
{
    g.TranslateTransform(m_left, m_top);

    for each (const auto& var in m_childArray)
    {
        var->draw(g);
    }

    g.TranslateTransform(-m_left, -m_top);
}


// ���в���
IElement* FlowLinearLayout::hitTest(int x, int y)
{
    if (x >= m_left && x <= m_left + m_width
        && y >= m_top && y <= m_top + m_height)
    {
        IElement* p = nullptr;
        for each (const auto& var in m_childArray)
        {
            if ((p = var->hitTest(x - m_left, y - m_top)) != nullptr)
            {
                break;
            }
        }
        return p;
    }
    else
    {
        return nullptr;
    }
}
