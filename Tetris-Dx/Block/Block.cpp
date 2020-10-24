#include "Block.h"

//----------------------------------------------------------------
Block::Block(int x, int y, int rot, int color) :
	_x(), _y(), _rot(), _color(color), _shapeData({}) {}
//----------------------------------------------------------------
void Block::turn() {
	auto&& rot = (40000000 + _rot) % 4;
	for (auto&& r = 0; r < rot; r++) {
		for (auto&& y = 0; y < s_size; y++)	for (auto&& x = 0; x < s_size; x++)
			_shapeData[_y + y][_x + x] = _shapeData[x][y];
	}
}
//----------------------------------------------------------------
void Block::turnLeft() { _rot--; }
//----------------------------------------------------------------
void Block::turnRight() { _rot++; }
//----------------------------------------------------------------
void Block::draw() {
	for (auto&& y = 0; y < s_size; y++)	for (auto&& x = 0; x < s_size; x++)
		if (_shapeData[_y][_x] != 0)
			DrawBox(_x, _y, (_x + s_scale), (_y + s_scale), _color, true);
}
//----------------------------------------------------------------
