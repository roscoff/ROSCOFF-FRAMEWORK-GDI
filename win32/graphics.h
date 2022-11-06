#pragma once
#include <windows.h>
#include "utilities.h"

class graphics {
public:
	graphics();
	~graphics();

	void putPixel(int x, int y, color col);
	color getPixel(int x, int y);

	void draw(HWND hWnd);
	void onResize(int width, int height, color clearColor = { 0, 11, 22, 0 });




protected:
	HBITMAP hBackBuffer;
	BITMAP  backBuffer;
	HDC hdc;
};