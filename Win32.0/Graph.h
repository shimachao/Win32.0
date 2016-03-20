#pragma once
#include <Windows.h>
#include <gdiplus.h>
using Gdiplus::GdiplusStartupInput;

class Graph
{
public:
    Graph();
    ~Graph();

private:
    ULONG_PTR m_gdiplusToken;
    GdiplusStartupInput m_gdiplusStartupInput;
};

