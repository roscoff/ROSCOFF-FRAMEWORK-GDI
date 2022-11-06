#pragma once
#include "graphics.h"
#include "meshBuilder.h"

class framework : public graphics{
public:
	framework();
	void onMouseEvent(int x, int y);
	void onKeyboardEvent();
	void update();
private:
	meshBuilder mb;
};