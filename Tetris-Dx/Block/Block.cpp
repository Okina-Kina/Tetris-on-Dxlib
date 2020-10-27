#include "Block.h"

//----------------------------------------------------------------
Block::Block(int color) :
	_x(), _y(), _rot(), _color(color), _shapeData({}), _currentShape({ }) {}
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
void Block::turnLeft() { _rot--; turn(); }
//----------------------------------------------------------------
void Block::turnRight() { _rot++; turn(); }
//----------------------------------------------------------------
void Block::draw() {
	for (int i = 0; i < s_size; i++)for (int j = 0; j < s_size; j++)

		if (_currentShape[i][j] != 0) {

			auto&& x = _x + (j * s_scale);
			auto&& y = _y + (i * s_scale);

			DrawBox(x, y, x + s_scale, y + s_scale, _color, true);
		}
}
//----------------------------------------------------------------
int Block::getScale() { return s_scale; }
//----------------------------------------------------------------
void Block::setup(int x, int y, int rot) {
	_x = x;
	_y = y;
	_rot = rot;

	turn();
}
//----------------------------------------------------------------
