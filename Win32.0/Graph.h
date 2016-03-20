#pragma once
#include <Windows.h>
#include "Base.h"

class Graph
{
public:
    Graph();
    ~Graph();

private:
    ULONG_PTR m_gdiplusToken;
    GdiplusStartupInput m_gdiplusStartupInput;
};
