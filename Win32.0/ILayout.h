#pragma once
#include "IElement.h"

// ���ֻ���
class ILayout : public IElement
{
public:
    ILayout(unsigned width, unsigned height);
    ~ILayout();

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
    // ��������Ƿ�������Ԫ�صĲ���Χ��
    bool ifMouseIn(unsigned x, unsigned y);

    // ����ƶ���Ԫ�ط�Χ��
    virtual void mouseMoveIn(unsigned x, unsigned y);

protected:
    unsigned m_blank;        // �ڲ���Ե���״�С
    unsigned m_leftBlank;    // �ڲ����Ե����
    unsigned m_rightBlank;   // �ڲ��ұ�Ե����
    unsigned m_topBlank;     // �ڲ��ϱ�Ե����
    unsigned m_bottomBlank;  // �ڲ��ױ�Ե����
};

