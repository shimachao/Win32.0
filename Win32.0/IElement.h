#pragma once
class IElement
{
public:
    IElement(int width = 0, int height = 0);
    ~IElement();

    // ����λ�úʹ�С
    virtual void setPos(int left, int top, int width, int height) = 0;
    // ��ѯλ�úʹ�С
    void getPos(int &left, int &top, int &width, int &height);
    // ���ô�С
    virtual void setSize(int width, int height) = 0;
    // ��ѯ��С
    void getSize(int &width, int &height);
    // �ƶ�
    virtual void move(int left, int top) = 0;
    // ���ÿ��
    virtual void setWidth(int width) = 0;
    // ��ѯ���
    int getWidth();
    // ���ø߶�
    virtual void setHeight(int height) = 0;
    // ��ѯ�߶�
    int getHeight();
    // ���ô�ֱ����λ��
    void setTop(unsigned top);
    // ��ѯ��ֱ����λ��
    unsigned getTop();
    // ����ˮƽ����λ��
    void setLeft(unsigned left);
    // ��ѯˮƽ����λ��
    unsigned getLeft();

protected:
    int m_left;     // ��߽�
    int m_top;      // �ϱ߽�
    int m_width;    // ���
    int m_height;   // �߶�
};

