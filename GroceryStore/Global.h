#pragma once
#include "Employee.h"
#include "drawBox.h"
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<vector>
#include <cstdarg>

using namespace std;

class Global
{
private:
	vector<int> initMenuColor;
	int counter;
	char key;
	string option;
public:
	//config global
	Employee employee;
	void setColor(int color);
	void gotoXY(int x, int y);
	void drawRectangle(int left, int top, int right, int bottom);
	void hideCursor(bool isHiden);
	int getTerminalWidth();
	int getTerminalHeight();
	int leftCenter(int width);
	int leftCenterBox(int boxWidth, int width);
	void loadingEffect(string text);
	void notiBox(string text);
	int getNumberElementBox(string text);
	string getTextElementBox(string text);
	//getter & setter
	string getOption();
	void setOption(string option);

	//init menu
	void generateMenu();
	int drawMenu(int height, int numberMenu, string storeLabels, string menuLabel, ...);
	void initBar(int offSet, int number, ...);
	//init login
	void generateLogin();
	

};

