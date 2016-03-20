#pragma once
#include <Windows.h>
#include <gdiplus.h>

using Gdiplus::Graphics;
using Gdiplus::Rect;
using Gdiplus::RectF;
using Gdiplus::GdiplusStartupInput;
using Gdiplus::GdiplusShutdown;
using Gdiplus::Pen;
using Gdiplus::Color;
using Gdiplus::Image;
using Gdiplus::Brush;
using Gdiplus::HatchBrush;
using Gdiplus::HatchStyleHorizontal;
using Gdiplus::FontFamily;
using Gdiplus::StringFormat;
using Gdiplus::SolidBrush;
using Gdiplus::FontStyleBold;
using Gdiplus::UnitPoint;
using Gdiplus::StringAlignmentCenter;
using Gdiplus::Matrix;
using Gdiplus::PrivateFontCollection;
using Gdiplus::FontStyleRegular;
using Gdiplus::UnitPixel;
using Gdiplus::PenAlignmentInset;

extern Pen blackPen;
extern Gdiplus::Font font;
extern SolidBrush solidBrush;
extern StringFormat stringFormat;
