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

    LinearLayout(unsigned width, unsigned height, Orientation orientation = horizontal);
    ~LinearLayout();

    // �����Ԫ��
    void add(IElement *pElement);
    // ������С���Ա����������Ԫ��
    void resizeToFit();
    
private:
    // ���ַ���Ϊˮƽʱ����ӷ���
    void horAdd(IElement *pElment);
    // ���ַ���Ϊ��ֱʱ����ӷ���
    void verAdd(IElement *pElment);
    // ���ַ���ΪˮƽʱresizeToFit����
    void horResizeToFit();
    // ���ַ���Ϊ��ֱʱresizeToFit����
    void verResizeToFit();

private:
    list<IElement*> m_childList;    // ��Ԫ���б�
    Orientation m_orientation;      // ���Բ��ֵķ���ˮƽ��ֱ

};

