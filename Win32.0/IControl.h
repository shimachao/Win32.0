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
    IControl(unsigned width, unsigned height);
    ~IControl();
    
    // ����ƶ����ؼ���
    virtual void mouseMoveIn() = 0;
    // ����Ƴ��ؼ�
    virtual void mouseMoveOut() = 0;

    // ���������£��ڿؼ�����Χ�ڣ�
    virtual void LMBDown() = 0;
    // �����������ڿؼ�����Χ�ڣ�
    virtual void LMBUp() = 0;

    // ��ý���
    virtual void getFocus() = 0;
    // ʧȥ����
    virtual void loseFocus() = 0;

    // ��������Ƿ�������Ԫ�صĲ���Χ��
    virtual bool ifMouseIn(unsigned x, unsigned y);
};

