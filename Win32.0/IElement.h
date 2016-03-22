#pragma once
#include "Base.h"

class IElement
{
public:
    IElement(int width = 0, int height = 0);
    ~IElement();

    // ����λ�úʹ�С
    virtual void setPos(int left, int top, int width, int height);
    // ��ѯλ�úʹ�С
    void getPos(int &left, int &top, int &width, int &height);
    // ���ô�С
    virtual void setSize(int width, int height);
    // ��ѯ��С
    void getSize(int &width, int &height);
    // �ƶ�
    void move(int left, int top);
    // ���ÿ��
    virtual void setWidth(int width);
    // ��ѯ���
    int getWidth();
    // ���ø߶�
    virtual void setHeight(int height);
    // ��ѯ�߶�
    int getHeight();
    // ���ô�ֱ����λ��
    void setTop(int top);
    // ��ѯ��ֱ����λ��
    int getTop();
    // ����ˮƽ����λ��
    void setLeft(int left);
    // ��ѯˮƽ����λ��
    int getLeft();

    // ���ñ�Ե���
    void setMargin(int margin);
    // �����ϱ�Ե
    void setTopMargin(int margin);
    // �����±�Ե
    void setBottomMargin(int margin);
    // �������Ե
    void setLeftMargin(int margin);
    // �����ұ�Ե
    void setRightMargin(int margin);
    // ��ѯ��Ե���
    int getMargin();
    // ��ѯ�ϱ�Ե���
    int getTopMargin();
    // ��ѯ�±�Ե���
    int getBottomMargin();
    // ��ѯ���Ե���
    int getLeftMargin();
    // ��ѯ�ұ�Ե���
    int getRightMargin();

    // ��������Ƿ�������Ԫ�صĲ���Χ��
    virtual bool ifMouseIn(int x, int y);
    // ���в���
    virtual IElement* hitTest(int x, int y);

    // ����
    virtual void draw(Gdiplus::Graphics &g) = 0;

protected:
    int m_left;     // ��߽�
    int m_top;      // �ϱ߽�
    int m_width;    // ���
    int m_height;   // �߶�

    int m_margin = 0;  // ��Ե���
    int m_leftMargin = 0;  // ���Ե
    int m_rightMargin = 0; // �ұ�Ե
    int m_topMargin = 0;   // �ϱ�Ե
    int m_bottomMargin = 0;    // �±�Ե
};

