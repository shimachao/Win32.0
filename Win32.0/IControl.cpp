#include "IControl.h"



IControl::IControl(int width, int height) 
    :IElement(width, height)
{
}


IControl::~IControl()
{
}

bool IControl::ifMouseIn(int x, int y)
{
    if (x >= 0 && x <= m_width && y >=0 && y << m_height)
    {
        return true;
    }
    else
    {
        return false;
    }
}


// ����Ƶ��ؼ���
void IControl::mouseMoveIn()
{
    // do nothing
}


// ����Ƶ��ؼ���
void IControl::mouseMoveOut()
{
    // do nothing
}


// ���������£��ڿؼ�����Χ�ڣ�
void IControl::LMBDown()
{
    // do nothing
}

// �����������ڿؼ�����Χ�ڣ�
void IControl::LMBUp()
{
    // do nothing
}


// ��ý���
void IControl::getFocus()
{
    // do nothing
}


// ʧȥ����
void IControl::loseFocus()
{
    // do nothing
}
