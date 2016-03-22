#include "LinearLayout.h"



LinearLayout::LinearLayout(int width, int height, Orientation orientation)
    :ILayout(width, height), m_orientation(orientation)
{
}


LinearLayout::~LinearLayout()
{
}


// 添加子元素
void LinearLayout::add(IElement *pElement)
{
    m_childList.push_back(pElement);

    // 设置所有子元素的位置，每添加一个元素都要重新计算每个子元素的位置
    // 假设布局是可以放下所有子控件的，放不下的话，对结果不做任何保证
    if (m_orientation == horizontal)
    {
        horAdd(pElement);
    }
    else
    {
        verAdd(pElement);
    }
}


// 布局方向为水平时的添加方法
void LinearLayout::horAdd(IElement *pElment)
{
    // 计算x坐标
    static int margin = 0; // 元素之间的水平边缘间隔
    static int left = m_leftBlank; // 开始摆放元素的起始x坐标

    if (pElment->getLeftMargin() > margin)
    {
        margin = pElment->getLeftMargin();
    }

    // 计算元素y坐标，让元素在垂直方向上居中
    int top = (m_height - pElment->getHeight()) / 2;
    pElment->move(left + margin, top);

    //更新left和margin
    left += pElment->getWidth();
    margin = pElment->getRightMargin();
}


// 布局方向为垂直时的添加方法
void LinearLayout::verAdd(IElement *pElment)
{
    // 计算y坐标
    static int margin = 0; // 元素之间的垂直边缘间隔
    static int top = m_topBlank;   // 开始摆放元素的起始y坐标

    if (pElment->getTopMargin() > margin)
    {
        margin = pElment->getTopMargin();
    }

    // 计算x坐标，让元素在水平方向上居中
    int left = (m_width - pElment->getWidth()) / 2;
    pElment->move(left, top + margin);

    // 跟新top和margin
    top += pElment->getHeight();
    margin = pElment->getBottomMargin();
}

// 调整大小来以便放下所有子元素
void LinearLayout::resizeToFit()
{
    if (m_orientation == horizontal)
    {
        horResizeToFit();
    }
    else
    {
        verResizeToFit();
    }
}


// 布局方向为水平时resizeToFit方法
void LinearLayout::horResizeToFit()
{
    // 调整宽度
    int margin = 0;
    int sumWidth = m_leftBlank + m_rightBlank;
    for each (const auto& var in m_childList)
    {
        if (var->getLeftMargin() > margin)
        {
            margin = var->getLeftMargin();
        }
        sumWidth += margin + var->getWidth();
        margin = var->getRightMargin();
    }
    m_width = sumWidth;

    // 调整高度
    // 找出子元素中所需高度的最大值
    int height = 0;
    for each (const auto& var in m_childList)
    {
        int h = var->getTopMargin() + var->getBottomMargin() + var->getHeight();
        if (h > height)
        {
            height = h;
        }
    }
    m_height = height + m_topBlank + m_bottomBlank;

    // 调整子元素的y坐标，保持其在y方向上居中
    for each (const auto& var in m_childList)
    {
        int top = (m_height - var->getHeight()) / 2;
        var->setTop(top);
    }
}


// 布局方向为垂直时resizeToFit方法
void LinearLayout::verResizeToFit()
{
    // 调整高度
    int sumHeight = m_topBlank + m_bottomBlank;
    int margin = 0;

    for each (const auto& var in m_childList)
    {
        if (var->getTopMargin() > margin)
        {
            margin = var->getTopMargin();
        }

        sumHeight += margin + var->getHeight();
        margin = var->getBottomMargin();
    }
    m_height = sumHeight;

    // 调整宽度
    // 找出子元素中所需宽度的最大值
    int width = 0;
    for each (const auto& var in m_childList)
    {
        int w = var->getLeftMargin() + var->getWidth() + var->getRightMargin();
        if (w > width)
        {
            width = w;
        }
    }
    m_width = width + m_leftBlank + m_rightBlank;

    // 调整子元素的x坐标，保持其在x方向上居中
    for each (const auto& var in m_childList)
    {
        int left = (m_width - var->getWidth()) / 2;
        var->setLeft(left);
    }
}


// 鼠标移动到元素范围内
//void LinearLayout::mouseMoveIn(int x, int y)
//{
//    for each (const auto& var in m_childList)
//    {
//        if (var->ifMouseIn(x - m_left, y - m_top))
//        {
//            var->mouseMoveIn(x - m_left, y - m_top);
//            break;
//        }
//    }
//}


// 绘制
void LinearLayout::draw(Gdiplus::Graphics &g)
{
    g.TranslateTransform(m_left, m_top);

    for each (const auto& var in m_childList)
    {
        var->draw(g);
    }

    g.TranslateTransform(-m_left, -m_top);
}


// 击中测试
IElement* LinearLayout::hitTest(int x, int y)
{
    for each (const auto& var in m_childList)
    {
        if (var->hitTest(x - m_left, y - m_top))
        {
            return var;
        }
    }

    return nullptr;
}
