#pragma once

//*****************************************************
// ブロックの基底
#include<DxLib.h>
#include<array>
using std::array;

class Block
{
private:
	static const int s_scale = 32;

	int _x, _y;
	int _offsetX, _offsetY;

	int _color;
	int _rot;


protected:
	static const int s_size = 5;

	array<array < int, s_size>, s_size> _shapeData;
	array<array < int, s_size>, s_size> _currentShape;

	//*************************************************
	// method
	virtual void initShape(){}

public:
	//*************************************************
	// constructor
	Block(int offsetX, int offsetY, int color);
	//*************************************************
	// method
	void turn();
	void draw();
	//*************************************************
	// getter
	int getScale();
	array<array<int, s_size>, s_size> getShape();
	int getRotation();
	int getX();
	int getY();

	//*************************************************
	// setter
	void addX(int x);
	void addY(int y);
	void addRotate(int rot);

	void setup(int offsetX, int offsetY, int rot);
};

