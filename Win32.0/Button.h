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
    void getFocus();
    // ʧȥ����
    void loseFocus();

    // ����ƶ����ؼ���
    void mouseMoveIn();
    // ����Ƴ��ؼ�
    void mouseMoveOut();

    // ���������£��ڿؼ�����Χ�ڣ�
    void LMBDown();
    // �����������ڿؼ�����Χ�ڣ�
    void LMBUp();

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
    ButtonState m_state;    // ����״̬�������»�����
    map<Event, function<void()>> m_eventActionMap; // �¼��Ͷ���֮���ӳ��
};

