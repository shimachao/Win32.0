#pragma once
#include "Progress.h"
class LineProgress :
    public Progress
{
public:
    LineProgress(int width, int height, unsigned range = 100, unsigned step = 1);
    ~LineProgress();

    // »æÖÆ
    virtual void draw(Gdiplus::Graphics &g) override;
};

