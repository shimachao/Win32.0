#pragma once
#include "ILayout.h"
#include <vector>
using std::vector;

// �������Բ���

class FlowLinearLayout :
    public ILayout
{
public:
    enum Orientation
    {
        horizontal, vertical
    };

    FlowLinearLayout(unsigned width, unsigned height, Orientation ori = horizontal);
    ~FlowLinearLayout();

    // ���Ԫ��
    void add(IElement* pElement);
    // ����ƶ���Ԫ�ط�Χ��
    void mouseMoveIn(unsigned x, unsigned y);

private:
    // ����Ϊˮƽʱ����������Ԫ�ص�x����
    void horRepositionX();
    // ����Ϊ��ֱʱ����������Ԫ�ص�y����
    void verRepositionY();

private:
    vector<IElement*>   m_childArray;   // ��Ԫ������
    Orientation m_orientation;  // ����
};

