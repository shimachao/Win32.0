#pragma once
#include "ILayout.h"
#include <vector>
using std::vector;

// ���Բ���

class AbsoluteLayout :
    public ILayout
{
public:
    AbsoluteLayout(unsigned width, unsigned height);
    ~AbsoluteLayout();

    // �����Ԫ�أ�����left��topΪ��Ԫ�����Ͻ�����
    void add(IElement *pElement, unsigned left, unsigned top);
    // ����ƶ���Ԫ�ط�Χ��
    void mouseMoveIn(unsigned x, unsigned y);
    // ����
    virtual void draw(Gdiplus::Graphics &g) override;

private:
    vector<IElement*>   m_childArray;
};

