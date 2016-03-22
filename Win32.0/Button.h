#pragma once
#include "StaticText.h"
#include <string>
#include <map>
#include <functional>
using std::string;
using std::map;
using std::function;

// ��ť��

class Button :
    public StaticText
{
public:
    Button(int width, int height, TCHAR * text = L"Static Text");
    ~Button();

    // �����¼��Ͷ���
    void connect(Event event, function<void()> action);

    // ��ý���
    virtual void getFocus() override;
    // ʧȥ����
    virtual void loseFocus() override;

    // ����ƶ����ؼ���
    void mouseMoveIn();
    // ����Ƴ��ؼ�
    virtual void mouseMoveOut() override;

    // ���������£��ڿؼ�����Χ�ڣ�
    virtual void LMBDown() override;
    // �����������ڿؼ�����Χ�ڣ�
    virtual void LMBUp() override;

    // ����
    virtual void draw(Gdiplus::Graphics &g) override;

private:
    enum ButtonState
    {
        Pressed, Normal
    };

private:
    bool m_ifGotFocus = false;  // �Ƿ�ӵ�н���
    bool m_ifMouseIn = false;   // ����Ƿ��ڿؼ���
    ButtonState m_state = Normal;    // ����״̬�������»�����
    map<Event, function<void()>> m_eventActionMap; // �¼��Ͷ���֮���ӳ��
};

