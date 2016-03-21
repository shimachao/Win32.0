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

    FlowLinearLayout(int width, int height, Orientation ori = horizontal);
    ~FlowLinearLayout();

    // ���Ԫ��
    void add(IElement* pElement);
    // ����ƶ���Ԫ�ط�Χ��
    void mouseMoveIn(int x, int y);
    // ����
    virtual void draw(Gdiplus::Graphics &g) override;
    // ���в���
    virtual IElement* hitTest(int x, int y) override;

private:
    // ����Ϊˮƽʱ����������Ԫ�ص�x����
    void horRepositionX();
    // ����Ϊ��ֱʱ����������Ԫ�ص�y����
    void verRepositionY();

private:
    vector<IElement*>   m_childArray;   // ��Ԫ������
    Orientation m_orientation;  // ����
};

