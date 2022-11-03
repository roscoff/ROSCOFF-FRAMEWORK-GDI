#pragma once
#include "graphics.h"

class framework : public graphics{
public:
	framework();
	void onMouseEvent(int x, int y);
	void onKeyboardEvent();
	void update();
private:

};