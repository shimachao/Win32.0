#include "Window.h"
#include "AbsoluteLayout.h"
#include "FlowLinearLayout.h"
#include "LinearLayout.h"
#include "GridLayout.h"
#include "StaticText.h"
#include "Button.h"
#include "Graph.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    Graph g;


    FlowLinearLayout flowLayout(600, 100);
    LinearLayout linearLayout(600, 100);
    GridLayout girdLayout(600, 200, 2, 2);

    Button button1(100, 50, L"button1");
    Button button2(100, 50, L"button2");
    StaticText staticText(100, 50, L"staticText1");

    flowLayout.add(&button1);
    flowLayout.add(&button2);
    flowLayout.add(&staticText);

    Button button3(100, 50, L"button3");
    Button button4(100, 50, L"button4");
    StaticText staticText2(100, 50, L"staticText2");

    linearLayout.add(&button3);
    linearLayout.add(&button4);
    linearLayout.add(&staticText2);

    Button button5(100, 50, L"button5");
    Button button6(100, 50, L"button6");
    StaticText staticText3(100, 50, L"staticText3");
    StaticText staticText4(100, 50, L"staticText4");

    girdLayout.add(&button5);
    girdLayout.add(&button6);
    girdLayout.add(&staticText3);
    girdLayout.add(&staticText4);

    AbsoluteLayout absoluteLayout(600, 400);
    absoluteLayout.add(&flowLayout, 0, 0);
    absoluteLayout.add(&linearLayout, 0, 100);
    absoluteLayout.add(&girdLayout, 0, 200);

    Window window(600, 400);
    window.setLayout(&absoluteLayout);
    window.Initialize();
    window.Run();

    return 0;
}
