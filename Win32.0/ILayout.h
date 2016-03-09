#pragma once
#include "IElement.h"

// ���ֻ���
class ILayout : public IElement
{
public:
    ILayout(int width, int height);
    ~ILayout();

    // �����Ԫ��
    virtual void add(IElement *pElement) = 0;
    // ��������
    void setBlank(unsigned blank);
    // ����������
    void setLeftBlank(unsigned leftBlank);
    // ����������
    void setRightBlank(unsigned rightBlank);
    // ���ö�������
    void setTopBlank(unsigned topBlank);
    // ���õײ�����
    void setBottomBlank(unsigned bottomBlank);


protected:
    unsigned int m_blank;        // �ڲ���Ե���״�С
    unsigned int m_leftBlank;    // �ڲ����Ե����
    unsigned int m_rightBlank;   // �ڲ��ұ�Ե����
    unsigned int m_topBlank;     // �ڲ��ϱ�Ե����
    unsigned int m_bottomBlank;  // �ڲ��ױ�Ե����
};

