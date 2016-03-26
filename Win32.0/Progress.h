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

    // 设置步长
    void setStep(unsigned step);
    // 设置进度
    void setPace(unsigned pace);
    // 设置进度条满后需要执行的动作
    void setFullAction(function<void()> action);
    // 按步长前进一个单位
    void step();
    // 查询范围
    unsigned getRange();
    // 查询当前位置
    unsigned getPace();
    
    // 绘制
    virtual void draw(Gdiplus::Graphics &g) override;

protected:
    unsigned m_range;   // 范围
    unsigned m_pace;    // 进度位置
    unsigned m_step;    // 步长
    function<void()> m_fullAction = nullptr; // 进度条满后执行的动作
};

