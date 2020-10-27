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

public:
	//*****************************************************
	// constructor
	Field(int x, int y);

	//*****************************************************
	// method
	void initField();
	void draw();
};

