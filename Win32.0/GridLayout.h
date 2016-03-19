#pragma once
#include "ILayout.h"
#include <map>
using std::map;

// ���񲼾�
class GridLayout :
    public ILayout
{
public:
    GridLayout(unsigned width, unsigned height, unsigned row, unsigned column);
    ~GridLayout();

    // �����Ԫ��
    void add(IElement *pElement);
    // �ھ����ĳ��ĳ�������Ԫ��
    void add(IElement *pElement, unsigned row, unsigned column);

private:
    // ������Ԫ��λ��
    void setPos(IElement *pElement, unsigned row, unsigned column);

private:
    unsigned    m_row;  // ����
    unsigned    m_column;   // ����
    bool    *m_pMark;   // ������¼�����ʹ�����
    map<unsigned, IElement*> m_childMap; // ����������Ԫ�ص��ֵ�
};

