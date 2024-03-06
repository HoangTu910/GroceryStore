#pragma once
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<vector>

using namespace std;

class Global
{
private:
	vector<int> initMenuColor;
	int counter;
	char key;
	int option;
public:
	//config global
	void setColor(int color);
	void gotoXY(int x, int y);
	void drawRectangle(int left, int top, int right, int bottom);
	int getTerminalWidth();
	int getTerminalHeight();
	int leftCenter(int width);
	int leftCenterBox(int boxWidth, int width);

	//getter & setter
	int getOption();
	void setOption(int option);

	//init menu
	void generateMenu();

	//init login
	void generateLogin();

};

