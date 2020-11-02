#include "Field.h"

//--------------------------------------------------------------------------------------
Field::Field(int x, int y) :_x(x), _y(y), _field({}) {
	initField();
}
//--------------------------------------------------------------------------------------
void Field::initField() {
	for (int i = 0; i < s_height; i++) for (int j = 0; j < s_width; j++)
		_field[i][j] = 0;

	for (int i = 0; i < s_height; i++) {
		for (int j = 0; j < s_width; j++) {
			auto&& numOfWall = 99;

			_field[i][0] = numOfWall;
			_field[i][s_width - 1] = numOfWall;
			_field[s_height - 1][j] = numOfWall;
		}
	}
}
//--------------------------------------------------------------------------------------
bool Field::isOutOfFieldIndex(int x, int y) {
	return (x < 0) || (s_width <= x) || (y < 0) || (s_height <= y);
}
//--------------------------------------------------------------------------------------
bool Field::isFilled(int y) {
	for (int j = 1; j < s_width - 1; j++)
		if (_field[y][j] != 1) return false;

	return true;
}
//--------------------------------------------------------------------------------------
void Field::clearLine() {
	for (int i = 0; i < s_height; i++) {
		if (!isFilled(i)) continue;
		for (int j = 1; j < s_width - 1; j++) _field[i][j] = 0;

		for (int k = s_height - 1; k > 0; k--)for (int j = 1; j < s_width - 1; j++)
			_field[k][j] = _field[k - 1][j];
	}
}
//--------------------------------------------------------------------------------------
void Field::draw() {
	for (int i = 0; i < s_height; i++) {
		for (int j = 0; j < s_width; j++) {
			auto color = 0;

			if (_field[i][j] == 0)color = GetColor(255, 255, 255);
			if (_field[i][j] == 1) color = GetColor(40, 40, 40);
			if (_field[i][j] == 99) color = GetColor(200, 200, 200);

			auto&& x = _x + (j * s_blockScale);
			auto&& y = _y + (i * s_blockScale);

			DrawBox(x, y, x + s_blockScale, y + s_blockScale, color, true);
			DrawFormatString(x, y, GetColor(255, 255, 255), "%d", _field[i][j]);
		}
	}
}
//--------------------------------------------------------------------------------------
// getter
//--------------------------------------------------------------------------------------
array<array<int, Field::s_width>, Field::s_height> Field::getField() { return _field; }
//--------------------------------------------------------------------------------------
int Field::getFieldWidth() { return s_width; }
//--------------------------------------------------------------------------------------
int Field::getFieldHeight() { return s_height; }
//--------------------------------------------------------------------------------------
// setter
void Field::setBlockIndex(int x, int y) { _field[y][x] = 1; }
