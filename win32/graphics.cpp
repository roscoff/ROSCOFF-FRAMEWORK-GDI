#include "graphics.h"



graphics::graphics()
{
    hdc = CreateCompatibleDC(nullptr);
}

graphics::~graphics()
{
    DeleteObject(hBackBuffer);
    DeleteDC(hdc);
}

void graphics::putPixel(int x, int y, color col)
{
    BYTE* p = ((BYTE*)backBuffer.bmBits) + y * backBuffer.bmWidthBytes + x * sizeof(color);

    color* cp = (color *)p;
    *cp = col;
    // <=> 
    //*p++ = col.b; // blue
    //*p++ = col.g; // green
    //*p++ = col.r;
    //*p = col.a;
}

color graphics::getPixel(int x, int y)
{
    BYTE* p = ((BYTE*)backBuffer.bmBits) + y * backBuffer.bmWidthBytes + x * sizeof(BYTE) * 4;
    color out{*p++, *p++ ,*p++ ,*p };
    return out;
}


void graphics::draw(HWND hWnd)
{
    PAINTSTRUCT paint;
    HDC hWndDc = BeginPaint(hWnd, &paint);
    BitBlt(hWndDc, 0, 0, backBuffer.bmWidth, backBuffer.bmHeight, hdc, 0, 0, SRCCOPY);
    EndPaint(hWnd, &paint);
}

void graphics::onResize(int width, int height, color clearColor)
{
    DeleteObject(hBackBuffer);

    BITMAPINFO bmi;
    memset(&bmi, 0, sizeof(bmi));
    bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth = width;
    bmi.bmiHeader.biHeight = height;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biCompression = BI_RGB;
    hBackBuffer = CreateDIBSection(nullptr, &bmi, DIB_RGB_COLORS, nullptr, 0, 0);
    GetObject(hBackBuffer, sizeof(backBuffer), &backBuffer);
    SelectObject(hdc, hBackBuffer);

    for (int row = 0; row < backBuffer.bmHeight; ++row) {
        BYTE* p = ((BYTE*)backBuffer.bmBits) + row * backBuffer.bmWidthBytes;
        for (int col = 0; col < backBuffer.bmWidth; ++col){
            //base color
            *p++ = clearColor.b; // blue
            *p++ = clearColor.g; // green
            *p++ = clearColor.r; // red
            *p++ = clearColor.a; // alpha
        }
    }
}
