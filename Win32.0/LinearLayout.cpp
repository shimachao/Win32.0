#include "LinearLayout.h"



LinearLayout::LinearLayout(unsigned width, unsigned height, Orientation orientation)
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
    static unsigned margin = 0; // Ԫ��֮���ˮƽ��Ե���
    static unsigned left = m_leftBlank; // ��ʼ�ڷ�Ԫ�ص���ʼx����

    if (pElment->getLeftMargin() > margin)
    {
        margin = pElment->getLeftMargin();
    }

    // ����Ԫ��y���꣬��Ԫ���ڴ�ֱ�����Ͼ���
    unsigned top = (m_height - pElment->getHeight()) / 2;
    pElment->move(left + margin, top);

    //����left��margin
    left += pElment->getWidth();
    margin = pElment->getRightMargin();
}


// ���ַ���Ϊ��ֱʱ����ӷ���
void LinearLayout::verAdd(IElement *pElment)
{
    // ����y����
    static unsigned margin = 0; // Ԫ��֮��Ĵ�ֱ��Ե���
    static unsigned top = m_topBlank;   // ��ʼ�ڷ�Ԫ�ص���ʼy����

    if (pElment->getTopMargin() > margin)
    {
        margin = pElment->getTopMargin();
    }

    // ����x���꣬��Ԫ����ˮƽ�����Ͼ���
    unsigned left = (m_width - pElment->getWidth()) / 2;
    pElment->move(left, top + margin);

    // ����top��margin
    top += pElment->getHeight();
    margin = pElment->getBottomMargin();
}


// ����Ƶ���Ԫ������
void LinearLayout::MouseMoveOver(unsigned x, unsigned y)
{
    x -= m_left;
    y -= m_top;
    // �ݹ�������Ƿ�������Ԫ����
    for each (IElement* var in m_childList)
    {
        if (var->ifMouseIn(x, y))
        {
            var->MouseMoveOver(x, y);
            break;
        }
    }
}


