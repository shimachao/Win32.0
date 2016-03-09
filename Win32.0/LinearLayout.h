#pragma once
#include "ILayout.h"
#include <list>
using std::list;

// ���Բ���
class LinearLayout :
    public ILayout
{
public:
    enum Orientation
    {
        horizontal, vertical
    };

    LinearLayout(int width, int height, Orientation orientation = horizontal);
    ~LinearLayout();

    // �����Ԫ��
    void add(IElement *pElement);

private:
    // ���ַ���Ϊˮƽʱ�ĵ�����Ԫ��λ�÷���
    void horAdjustSize();
    // ���ַ���Ϊ��ֱʱ�ĵ�����Ԫ��λ�÷���
    void verAdjustSize();

private:
    list<IElement*> m_childList;    // ��Ԫ���б�
    Orientation m_orientation;      // ���Բ��ֵķ���ˮƽ��ֱ

};

