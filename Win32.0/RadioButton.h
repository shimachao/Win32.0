#pragma once
#include "IControl.h"
#include <string>
#include <map>
#include <functional>
using std::string;
using std::map;
using std::function;

// ��ѡ��ť

class RadioButton :
    public IControl
{
public:
    enum TextPosition
    {
        left, right
    };

    RadioButton(unsigned width, unsigned height, string text);
    ~RadioButton();

    // �����¼��Ͷ���
    void connect(Event event, function<void()> action);

    //������������߻����ұ�
    void setTextPos(TextPosition pos);
    // ��ѯ�Ƿ�ѡ��
    bool ifChecked();

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

private:
    string m_text = "radio button"; // �ı�
    TextPosition m_textPos = right;  // �ı�λ�ã�Ĭ�����ұ�
    bool m_ifMouseIn = false;   // ����Ƿ��ڿؼ���
    bool m_ifGotFocus = false;  // �Ƿ��ý���
    bool m_ifChecked = false;   // �Ƿ�ѡ��
    map<Event, function<void()>> m_eventActionMap;  // �¼��Ͷ���֮���ӳ��
};

