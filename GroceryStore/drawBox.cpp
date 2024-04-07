#include "drawBox.h"

drawBox::drawBox()
{
	Global global;
	this->width = 46;
	this->heigth = 5;
	this->top = 7;
	this->left = global.leftCenter(this->width);
	global.drawRectangle(this->left, this->top, this->width, this->heigth);
}

drawBox::drawBox(int width, int heigth)
{
	Global global;
	this->width = width;
	this->heigth = heigth;
	this->top = 7;
	this->left = global.leftCenter(this->width);
	global.drawRectangle(this->left, this->top, this->width, this->heigth);
}

int drawBox::getLeft()
{
	return this->left;
}

int drawBox::getTop()
{
	return this->top;
}

int drawBox::getWidth()
{
	return this->width;
}



