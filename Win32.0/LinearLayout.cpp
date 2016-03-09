#include "LinearLayout.h"



LinearLayout::LinearLayout(int width, int height, Orientation orientation)
    :ILayout(width, height), m_orientation(orientation)
{
}


LinearLayout::~LinearLayout()
{
}


// �����Ԫ��
void LinearLayout::add(IElement *pElement)
{
    m_childList.push_back(pElement);

    // ����������Ԫ�ص�λ�ã�ÿ���һ��Ԫ�ض�Ҫ���¼���ÿ����Ԫ�ص�λ��
    // ���貼���ǿ��Է��������ӿؼ��ģ��Ų��µĻ����Խ�������κα�֤
    if (m_orientation == horizontal)
    {
        horAdjustSize();
    }
    else
    {
        verAdjustSize();
    }
}


// ���ַ���Ϊˮƽʱ�ĵ�����Ԫ��λ�÷���
void LinearLayout::horAdjustSize()
{
    // �ȼ��㲢���ø����ؼ���ֱ��������꣬�����ڴ�ֱ�����Ͼ���
    for each (IElement* var in m_childList)
    {
        // ��Ϊ����ÿ����Ԫ�صĸ߶ȶ���һ��������ÿ����Ԫ�صĴ�ֱ�������궼Ҫ����һ��
        int top = m_topBlank + (m_height - m_topBlank - m_bottomBlank - var->getHeight()) / 2;
        var->setTop(top);
    }

    // �ټ���ÿ���ؼ���ˮƽ����
    if (m_childList.size() == 1)
    {
        //  ���ֻ��һ����Ԫ�أ�ֱ�ӽ�������м�
        auto var = m_childList.front();
        int left = (m_width - var->getWidth()) / 2;
        var->setLeft(left);
    }
    else
    {
        // ����ж��Ԫ�ؾ;��ȷ���
        int spacex = m_width - m_leftBlank - m_rightBlank;  // ˮƽ����Ŀռ��С
        int sumWidth = 0;   // ���пؼ��������Ŀ��
        for each (IElement* var in m_childList)
        {
            sumWidth += var->getWidth();
        }
        // �ؼ�֮��ľ���
        int margin = (spacex - sumWidth) / (m_childList.size() - 1);
        // ��ʼ����
        int left = m_leftBlank;
        for each (IElement* var in m_childList)
        {
            var->setLeft(left);
            left += var->getWidth() + margin;
        }
    }
}


// ���ַ���Ϊ��ֱʱ�ĵ�����Ԫ��λ�÷���
void LinearLayout::verAdjustSize()
{
    // �ȼ��㲢���ø����ؼ�ˮƽ��������꣬������ˮƽ�����Ͼ���
    for each (IElement* var in m_childList)
    {
        // ��Ϊ����ÿ����Ԫ�صĿ�ȶ���һ��������ÿ����Ԫ�ص�ˮƽ�������궼Ҫ����һ��
        int left = m_leftBlank + (m_width - m_leftBlank - m_rightBlank - var->getWidth()) / 2;
        var->setLeft(left);
    }

    // �ټ���ÿ���ؼ���ֱ�����ϵ�����
    if (m_childList.size() == 1)
    {
        //  ���ֻ��һ����Ԫ�أ�ֱ�ӽ�������м�
        auto var = m_childList.front();
        int top = (m_height - var->getHeight()) / 2;
        var->setTop(top);
    }
    else
    {
        // ����ж��Ԫ�ؾ;��ȷ���
        int spacey = m_height - m_topBlank - m_bottomBlank;  // ��ֱ����Ŀռ��С
        int sumHeight = 0;   // ���пؼ��������ĸ߶�
        for each (IElement* var in m_childList)
        {
            sumHeight += var->getHeight();
        }
        // �ؼ�֮��ľ���
        int margin = (spacey - sumHeight) / (m_childList.size() - 1);
        // ��ʼ����
        int top = m_topBlank;
        for each (IElement* var in m_childList)
        {
            var->setTop(top);
            top += var->getHeight() + margin;
        }
    }
}