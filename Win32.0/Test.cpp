#include "Window.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    Window window(100, 100);
    window.Initialize();
    window.Run();

    return 0;
}
