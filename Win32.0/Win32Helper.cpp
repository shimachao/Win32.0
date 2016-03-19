#include "Win32Helper.h"
#include <Windows.h>

// 获取屏幕DPI
void GetScreenDpi(int& dpix, int& dpiy)
{
    // 获取屏幕HDC
    HDC hdcScreen = GetDC(NULL);
    dpix = GetDeviceCaps(hdcScreen, LOGPIXELSX);
    dpiy = GetDeviceCaps(hdcScreen, LOGPIXELSY);
}
