#pragma once
#include <windows.h>
struct color {
	byte b, g, r, a;
};

class graphics {
public:
	graphics();
	~graphics();

	void putPixel(int x, int y, color col);
	color getPixel(int x, int y);

	void draw(HWND hWnd);
	void onResize(int width, int height, color clearColor = { 22, 11, 0, 0 });
protected:
	HBITMAP hBackBuffer;
	BITMAP  backBuffer;
	HDC hdc;
};