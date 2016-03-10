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
    virtual void move(unsigned left, unsigned top) = 0;
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

protected:
    unsigned m_left;     // ��߽�
    unsigned m_top;      // �ϱ߽�
    unsigned m_width;    // ���
    unsigned m_height;   // �߶�
};

