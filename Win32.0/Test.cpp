#include "Window.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    Window window(600, 400);
    window.Initialize();
    window.Run();

    return 0;
}
