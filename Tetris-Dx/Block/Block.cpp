#include "Block.h"

//----------------------------------------------------------------
Block::Block(int offsetX, int offsetY, int color) :
	_x(0), _y(0), _offsetX(offsetX), _offsetY(offsetY),
	_rot(0), _color(color), _shapeData({}), _currentShape({ }) {}
//----------------------------------------------------------------
void Block::turn() {
	auto rot = (40000000 + _rot) % 4;
	auto rotShape = _shapeData;

	for (auto&& y = 0; y < s_size; y++)	for (auto&& x = 0; x < s_size; x++)
		_currentShape[y][x] = _shapeData[y][x];

	for (int r = 0; r < rot; r++) {
		for (auto&& y = 0; y < s_size; y++)	for (auto&& x = 0; x < s_size; x++)
			rotShape[x][y] = 0;

		for (auto&& y = 0; y < s_size; y++)	for (auto&& x = 0; x < s_size; x++)
			rotShape[y][x] = _currentShape[(s_size - 1) - x][y];

		for (auto&& y = 0; y < s_size; y++)	for (auto&& x = 0; x < s_size; x++)
			_currentShape[y][x] = rotShape[y][x];
	}
}
//----------------------------------------------------------------
void Block::draw() {
	for (int i = 0; i < s_size; i++)for (int j = 0; j < s_size; j++)

		if (_currentShape[i][j] != 0) {

			auto&& x = ((_x + j) * s_scale) + _offsetX;
			auto&& y = ((_y + i) * s_scale) + _offsetY;

			DrawBox(x, y, x + s_scale, y + s_scale, _color, true);
			DrawBox(x, y, x + s_scale, y + s_scale, GetColor(0, 0, 0), false);
			DrawFormatString(x, y, GetColor(255, 255, 255), "%d", 1);
		}
}
//----------------------------------------------------------------
// getter
int Block::getScale() { return s_scale; }
array<array<int, Block::s_size>, Block::s_size> Block::getShape() { return _currentShape; }
int Block::getX() { return _x; }
int Block::getY() { return _y; }
int Block::getRotation() { return _rot; }
//----------------------------------------------------------------
// setter
void Block::setup(int x, int y, int rot) {
	_x = x;
	_y = y;
	_rot = rot;
	turn();
}
void Block::addX(int x) { _x += x; }
void Block::addY(int y) { _y += y; }
void Block::addRotate(int rot) { _rot += rot; }
//----------------------------------------------------------------
