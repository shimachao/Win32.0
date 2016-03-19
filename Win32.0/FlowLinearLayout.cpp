#include "FlowLinearLayout.h"



FlowLinearLayout::FlowLinearLayout(unsigned width, unsigned height, Orientation ori) 
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
        unsigned top = (m_height - pElement->getHeight()) / 2;
        pElement->setTop(top);
        // ��������Ԫ�ص�x���꣬��������ˮƽ�����Ͼ��ȷֲ�
        horRepositionX();
    }
    else
    {
        // ������Ԫ�ص�x���꣬������ˮƽ�����Ͼ���
        unsigned left = (m_width - pElement->getWidth()) / 2;
        pElement->setLeft(left);
        // ��������Ԫ�ص�y���꣬�������ڴ�ֱ�����Ͼ��ȷֲ�
        verRepositionY();
    }
}


// ����Ϊˮƽʱ����������Ԫ��λ��
void FlowLinearLayout::horRepositionX()
{
    // ����Ԫ��֮����ˮƽ�����ϵļ������
    unsigned sumWidth = 0;
    for each (const auto& var in m_childArray)
    {
        sumWidth += var->getWidth();
    }
    int margin = m_width - m_leftBlank - m_rightBlank - sumWidth;
    if (margin < 0)
    {
        margin = 0;
    }
    // ����Ԫ�ص�x����
    unsigned left = m_leftBlank;
    for each (const auto& var in m_childArray)
    {
        var->setLeft(left);
        left += margin;
    }
}


// ����Ϊ��ֱʱ����������Ԫ��λ��
void FlowLinearLayout::verRepositionY()
{
    // ����Ԫ��֮���ڴ�ֱ�����ϵļ������
    unsigned sumHeight = 0;
    for each (const auto& var in m_childArray)
    {
        sumHeight += var->getHeight();
    }
    int margin = m_height - m_topBlank - m_bottomBlank - sumHeight;
    if (margin < 0)
    {
        margin = 0;
    }
    // ����Ԫ�ص�y����
    unsigned top = m_topBlank;
    for each (const auto& var in m_childArray)
    {
        var->setTop(top);
        top += margin;
    }
}


// ����ƶ���Ԫ�ط�Χ��
void FlowLinearLayout::mouseMoveIn(unsigned x, unsigned y)
{
    for each (const auto& var in m_childArray)
    {
        if (var->ifMouseIn(x - m_left, y - m_top))
        {
            var->mouseMoveIn(x - m_left, y - m_top);
        }
    }
}
