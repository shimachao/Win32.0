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
    // ������С���Ա����������Ԫ��
    void resizeToFit();
    // ����ƶ���Ԫ�ط�Χ��
//    void mouseMoveIn(int x, int y);
    // ����
    virtual void draw(Gdiplus::Graphics &g) override;
    // ���в���
    virtual IElement* hitTest(int x, int y) override;
    
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

