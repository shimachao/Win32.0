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
        horAdd(pElement);
    }
    else
    {
        verAdd(pElement);
    }
}


// ���ַ���Ϊˮƽʱ����ӷ���
void LinearLayout::horAdd(IElement *pElment)
{
    // ����x����
    static int margin = 0; // Ԫ��֮���ˮƽ��Ե���
    static int left = m_leftBlank; // ��ʼ�ڷ�Ԫ�ص���ʼx����

    if (pElment->getLeftMargin() > margin)
    {
        margin = pElment->getLeftMargin();
    }

    // ����Ԫ��y���꣬��Ԫ���ڴ�ֱ�����Ͼ���
    int top = (m_height - pElment->getHeight()) / 2;
    pElment->move(left + margin, top);

    //����left��margin
    left += pElment->getWidth();
    margin = pElment->getRightMargin();
}


// ���ַ���Ϊ��ֱʱ����ӷ���
void LinearLayout::verAdd(IElement *pElment)
{
    // ����y����
    static int margin = 0; // Ԫ��֮��Ĵ�ֱ��Ե���
    static int top = m_topBlank;   // ��ʼ�ڷ�Ԫ�ص���ʼy����

    if (pElment->getTopMargin() > margin)
    {
        margin = pElment->getTopMargin();
    }

    // ����x���꣬��Ԫ����ˮƽ�����Ͼ���
    int left = (m_width - pElment->getWidth()) / 2;
    pElment->move(left, top + margin);

    // ����top��margin
    top += pElment->getHeight();
    margin = pElment->getBottomMargin();
}

// ������С���Ա����������Ԫ��
void LinearLayout::resizeToFit()
{
    if (m_orientation == horizontal)
    {
        horResizeToFit();
    }
    else
    {
        verResizeToFit();
    }
}


// ���ַ���ΪˮƽʱresizeToFit����
void LinearLayout::horResizeToFit()
{
    // �������
    int margin = 0;
    int sumWidth = m_leftBlank + m_rightBlank;
    for each (const auto& var in m_childList)
    {
        if (var->getLeftMargin() > margin)
        {
            margin = var->getLeftMargin();
        }
        sumWidth += margin + var->getWidth();
        margin = var->getRightMargin();
    }
    m_width = sumWidth;

    // �����߶�
    // �ҳ���Ԫ��������߶ȵ����ֵ
    int height = 0;
    for each (const auto& var in m_childList)
    {
        int h = var->getTopMargin() + var->getBottomMargin() + var->getHeight();
        if (h > height)
        {
            height = h;
        }
    }
    m_height = height + m_topBlank + m_bottomBlank;

    // ������Ԫ�ص�y���꣬��������y�����Ͼ���
    for each (const auto& var in m_childList)
    {
        int top = (m_height - var->getHeight()) / 2;
        var->setTop(top);
    }
}


// ���ַ���Ϊ��ֱʱresizeToFit����
void LinearLayout::verResizeToFit()
{
    // �����߶�
    int sumHeight = m_topBlank + m_bottomBlank;
    int margin = 0;

    for each (const auto& var in m_childList)
    {
        if (var->getTopMargin() > margin)
        {
            margin = var->getTopMargin();
        }

        sumHeight += margin + var->getHeight();
        margin = var->getBottomMargin();
    }
    m_height = sumHeight;

    // �������
    // �ҳ���Ԫ���������ȵ����ֵ
    int width = 0;
    for each (const auto& var in m_childList)
    {
        int w = var->getLeftMargin() + var->getWidth() + var->getRightMargin();
        if (w > width)
        {
            width = w;
        }
    }
    m_width = width + m_leftBlank + m_rightBlank;

    // ������Ԫ�ص�x���꣬��������x�����Ͼ���
    for each (const auto& var in m_childList)
    {
        int left = (m_width - var->getWidth()) / 2;
        var->setLeft(left);
    }
}


// ����ƶ���Ԫ�ط�Χ��
//void LinearLayout::mouseMoveIn(int x, int y)
//{
//    for each (const auto& var in m_childList)
//    {
//        if (var->ifMouseIn(x - m_left, y - m_top))
//        {
//            var->mouseMoveIn(x - m_left, y - m_top);
//            break;
//        }
//    }
//}


// ����
void LinearLayout::draw(Gdiplus::Graphics &g)
{
    g.TranslateTransform(m_left, m_top);

    for each (const auto& var in m_childList)
    {
        var->draw(g);
    }

    g.TranslateTransform(-m_left, -m_top);
}


// ���в���
IElement* LinearLayout::hitTest(int x, int y)
{
    for each (const auto& var in m_childList)
    {
        if (var->hitTest(x - m_left, y - m_top))
        {
            return var;
        }
    }

    return nullptr;
}
