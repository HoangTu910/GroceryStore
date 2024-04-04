#pragma once
#include "Global.h"
class drawBox
{
private:
	int left;
	int top;
	int width;
	int heigth;
public:
	drawBox();
	drawBox(int width, int heigth);
	int getLeft();
	int getTop();
};

