#include "Graph.h"
#pragma comment(lib,"Gdiplus.lib")

Graph::Graph()
{
    Gdiplus::GdiplusStartup(&m_gdiplusToken, &m_gdiplusStartupInput, NULL);
}


Graph::~Graph()
{
    Gdiplus::GdiplusShutdown(m_gdiplusToken);
}
