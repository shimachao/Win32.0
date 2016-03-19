#pragma once
class IElement
{
public:
    IElement(unsigned width = 0, unsigned height = 0);
    ~IElement();

    // ����λ�úʹ�С
    virtual void setPos(unsigned left, unsigned top, unsigned width, unsigned height) = 0;
    // ��ѯλ�úʹ�С
    void getPos(unsigned &left, unsigned &top, unsigned &width, unsigned &height);
    // ���ô�С
    virtual void setSize(unsigned width, unsigned height) = 0;
    // ��ѯ��С
    void getSize(unsigned &width, unsigned &height);
    // �ƶ�
    void move(unsigned left, unsigned top);
    // ���ÿ��
    virtual void setWidth(unsigned width) = 0;
    // ��ѯ���
    unsigned getWidth();
    // ���ø߶�
    virtual void setHeight(unsigned height) = 0;
    // ��ѯ�߶�
    unsigned getHeight();
    // ���ô�ֱ����λ��
    void setTop(unsigned top);
    // ��ѯ��ֱ����λ��
    unsigned getTop();
    // ����ˮƽ����λ��
    void setLeft(unsigned left);
    // ��ѯˮƽ����λ��
    unsigned getLeft();

    // ���ñ�Ե���
    void setMargin(unsigned margin);
    // �����ϱ�Ե
    void setTopMargin(unsigned margin);
    // �����±�Ե
    void setBottomMargin(unsigned margin);
    // �������Ե
    void setLeftMargin(unsigned margin);
    // �����ұ�Ե
    void setRightMargin(unsigned margin);
    // ��ѯ��Ե���
    unsigned getMargin();
    // ��ѯ�ϱ�Ե���
    unsigned getTopMargin();
    // ��ѯ�±�Ե���
    unsigned getBottomMargin();
    // ��ѯ���Ե���
    unsigned getLeftMargin();
    // ��ѯ�ұ�Ե���
    unsigned getRightMargin();

    // ����ƶ���Ԫ�ط�Χ��
    virtual void mouseMoveIn(unsigned x, unsigned y) = 0;
    // ����Ƴ�Ԫ�ط�Χ��
    virtual void mouseMoveOut() = 0;
    // ��������Ƿ�������Ԫ�صĲ���Χ��
    virtual bool ifMouseIn(unsigned x, unsigned y) = 0;

protected:
    unsigned m_left;     // ��߽�
    unsigned m_top;      // �ϱ߽�
    unsigned m_width;    // ���
    unsigned m_height;   // �߶�

    unsigned m_margin = 0;  // ��Ե���
    unsigned m_leftMargin = 0;  // ���Ե
    unsigned m_rightMargin = 0; // �ұ�Ե
    unsigned m_topMargin = 0;   // �ϱ�Ե
    unsigned m_bottomMargin = 0;    // �±�Ե
};

