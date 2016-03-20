#pragma once
#include "ILayout.h"
#include <vector>
using std::vector;

// ���Բ���

class AbsoluteLayout :
    public ILayout
{
public:
    AbsoluteLayout(int width, int height);
    ~AbsoluteLayout();

    // �����Ԫ�أ�����left��topΪ��Ԫ�����Ͻ�����
    void add(IElement *pElement, int left, int top);
    // ����ƶ���Ԫ�ط�Χ��
    void mouseMoveIn(int x, int y);
    // ����
    virtual void draw(Gdiplus::Graphics &g) override;

private:
    vector<IElement*>   m_childArray;
};

