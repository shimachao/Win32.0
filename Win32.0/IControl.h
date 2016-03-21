#pragma once
#include "IElement.h"
enum Event
{
    clicked, check, uncheck
};

// �ؼ�����

class IControl :public IElement
{
public:
    IControl(int width, int height);
    ~IControl();
    
    // ���������£��ڿؼ�����Χ�ڣ�
    virtual void LMBDown();
    // �����������ڿؼ�����Χ�ڣ�
    virtual void LMBUp();

    // ��ý���
    virtual void getFocus();
    // ʧȥ����
    virtual void loseFocus();

    // ��������Ƿ�������Ԫ�صĲ���Χ��
    virtual bool ifMouseIn(int x, int y);
    // ����ƶ���Ԫ�ط�Χ��
    virtual void mouseMoveIn(int x, int y);
    // ����Ƴ�Ԫ�ط�Χ��
    virtual void mouseMoveOut() = 0;
};

