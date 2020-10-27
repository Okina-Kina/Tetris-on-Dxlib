#pragma once

//*****************************************************
// ƒuƒƒbƒN‚ÌŠî’ê
#include<DxLib.h>
#include<array>
using std::array;

class Block
{
private:
	static const int s_scale = 32;

	int _x, _y;
	int _color;
	int _rot;


protected:
	static const int s_size = 4;

	array<array < int, s_size>, s_size> _shapeData;
	array<array < int, s_size>, s_size> _currentShape;

	//*************************************************
	// method
	virtual void initShape() = 0;

public:
	//*************************************************
	// constructor
	Block(int color);

	//*************************************************
	// method
	void turn();
	void turnLeft();
	void turnRight();
	void draw();

	//*************************************************
	// setter
	int getScale();
	//*************************************************
	// setter
	void setup(int x, int y, int rot);
};

