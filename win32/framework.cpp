#include "framework.h"

framework::framework()
{
}

void framework::onMouseEvent(int x, int y)
{
    y = backBuffer.bmHeight - 1 - y;
    putPixel(x, y, { 255,255,255 });
}

void framework::onKeyboardEvent()
{
}

void framework::update()
{
    /*for (int y = 0; y < backBuffer.bmHeight; y++) {
        for (int x = 0; x < backBuffer.bmWidth; x++) {
            color c = getPixel(x, y);
            c.r += 1;
            c.g += 1;
            c.b += 1;
            putPixel(x, y, c);
        }
    }*/
}
