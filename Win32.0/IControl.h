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
    virtual void LMBDown() = 0;
    // �����������ڿؼ�����Χ�ڣ�
    virtual void LMBUp() = 0;

    // ��ý���
    virtual void getFocus() = 0;
    // ʧȥ����
    virtual void loseFocus() = 0;

    // ��������Ƿ�������Ԫ�صĲ���Χ��
    virtual bool ifMouseIn(int x, int y);
    // ����ƶ���Ԫ�ط�Χ��
    virtual void mouseMoveIn(int x, int y);
};

