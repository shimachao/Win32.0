#include "Window.h"
#include "AbsoluteLayout.h"
#include "FlowLinearLayout.h"
#include "StaticText.h"
#include "Button.h"
#include "Graph.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    Graph g;

    Window window(600, 400);

    FlowLinearLayout flowLayout(100, 400, FlowLinearLayout::vertical);

    StaticText staticText(100, 50, L"静态文本框");
    flowLayout.add(&staticText);

    Button button(100, 50, L"按钮1");
    flowLayout.add(&button);

    Button button2(100, 50, L"按钮2");
    flowLayout.add(&button2);

    AbsoluteLayout absLayout(600, 400);
    absLayout.add(&flowLayout, 300, 0);

    window.setLayout(&absLayout);

    window.Initialize();
    window.Run();

    return 0;
}
