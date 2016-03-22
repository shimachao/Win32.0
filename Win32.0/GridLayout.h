#pragma once
#include "ILayout.h"
#include <map>
using std::map;

// ���񲼾�
class GridLayout :
    public ILayout
{
public:
    GridLayout(int width, int height, int row, int column);
    ~GridLayout();

    // �����Ԫ��
    void add(IElement *pElement);
    // �ھ����ĳ��ĳ�������Ԫ��
    void add(IElement *pElement, int row, int column);
    // ����ƶ���Ԫ�ط�Χ��
//    void mouseMoveIn(int x, int y);
    // ����
    virtual void draw(Graphics &g) override;
    // ���в���
    virtual IElement* hitTest(int x, int y) override;

private:
    // ������Ԫ��λ��
    void setPos(IElement *pElement, int row, int column);

private:
    int    m_row;  // ����
    int    m_column;   // ����
    bool    *m_pMark;   // ������¼�����ʹ�����
    map<int, IElement*> m_childMap; // ����������Ԫ�ص��ֵ�
};

