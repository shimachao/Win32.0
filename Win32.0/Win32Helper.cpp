#include "Win32Helper.h"
#include <Windows.h>

// ��ȡ��ĻDPI
void GetScreenDpi(int& dpix, int& dpiy)
{
    // ��ȡ��ĻHDC
    HDC hdcScreen = GetDC(NULL);
    dpix = GetDeviceCaps(hdcScreen, LOGPIXELSX);
    dpiy = GetDeviceCaps(hdcScreen, LOGPIXELSY);
}
