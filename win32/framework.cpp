#include "framework.h"

int randBetween(int v1, int v2) {
    if (v1 <= v2) {
        return (rand() % (v2 - v1)) + v1;
    }
    return randBetween(v2, v1);
}


framework::framework() : mb(this)
{

}

void framework::onMouseEvent(int x, int y)
{
    putPixel(x, y, { 255,255,255 });
}

void framework::onKeyboardEvent()
{
}

void framework::update()
{
    int w = backBuffer.bmWidth, h = backBuffer.bmHeight;
    //drawCircle(randBetween(0, w), randBetween(0, h), randBetween(5, 12), { (BYTE)randBetween(0, 255),(BYTE)randBetween(0, 255),(BYTE)randBetween(0, 255) });

    mb.drawTriangle({ 100,100 }, { 300, 200 }, { 200,400 }, { 255,0,0 });
    mb.drawTriangle({ 300,100 }, { 100, 200 }, { 200,400 }, { 255,255,0 });


    mb.drawQuad({ 100,100 }, {400,50}, {500,200}, {50,250}, {127,127,127});
    mb.drawTriangle({ 500,100 }, { 400, 200 }, { 600,200 }, { 0,255,0 });

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
