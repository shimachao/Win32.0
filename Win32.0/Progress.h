#pragma once
#include "IControl.h"
#include <functional>
using std::function;

class Progress :
    public IControl
{
public:
    Progress(int width, int height, unsigned range = 100, unsigned step = 1);
    ~Progress();

    // ���ò���
    void setStep(unsigned step);
    // ���ý���
    void setPace(unsigned pace);
    // ���ý�����������Ҫִ�еĶ���
    void setFullAction(function<void()> action);
    // ������ǰ��һ����λ
    void step();
    // ��ѯ��Χ
    unsigned getRange();
    // ��ѯ��ǰλ��
    unsigned getPace();
    
    // ����
    virtual void draw(Gdiplus::Graphics &g) override;

protected:
    unsigned m_range;   // ��Χ
    unsigned m_pace;    // ����λ��
    unsigned m_step;    // ����
    function<void()> m_fullAction = nullptr; // ����������ִ�еĶ���
};

