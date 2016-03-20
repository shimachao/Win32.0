#pragma once
#include "IElement.h"

// ���ֻ���
class ILayout : public IElement
{
public:
    ILayout(int width, int height);
    ~ILayout();

    // ��������
    void setBlank(int blank);
    // ����������
    void setLeftBlank(int leftBlank);
    // ����������
    void setRightBlank(int rightBlank);
    // ���ö�������
    void setTopBlank(int topBlank);
    // ���õײ�����
    void setBottomBlank(int bottomBlank);
    // ��������Ƿ�������Ԫ�صĲ���Χ��
    bool ifMouseIn(int x, int y);

    // ����ƶ���Ԫ�ط�Χ��
    virtual void mouseMoveIn(int x, int y);

protected:
    int m_blank;        // �ڲ���Ե���״�С
    int m_leftBlank;    // �ڲ����Ե����
    int m_rightBlank;   // �ڲ��ұ�Ե����
    int m_topBlank;     // �ڲ��ϱ�Ե����
    int m_bottomBlank;  // �ڲ��ױ�Ե����
};

