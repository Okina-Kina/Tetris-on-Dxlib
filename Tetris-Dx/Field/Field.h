#pragma once
//*****************************************************
// フィールドクラス
#include<DxLib.h>
#include<array>
using std::array;

class Field
{
private:
	static const int s_width = 10;
	static const int s_height = 20;
	static const int s_blockScale = 32;

	int _x, _y;
	array<array<int, s_width>, s_height> _field;

	//*****************************************************
	// method
	void initField();

public:
	//*****************************************************
	// constructor
	Field(int x, int y);

	//*****************************************************
	// method
	bool isOutOfFieldIndex(int x, int y);
	bool isFilled(int y);

	void draw();
	void clearLine();

	//*****************************************************
	// getter
	array<array<int, s_width>, s_height> getField();
	int getFieldWidth();
	int getFieldHeight();
	//*****************************************************
	// setter
	void setBlockIndex(int x, int y);

};

