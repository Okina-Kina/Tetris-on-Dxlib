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
void Field::draw() {
	for (int i = 0; i < s_height; i++) {
		for (int j = 0; j < s_width; j++) {
			auto color = 0;

			if (_field[i][j] == 0) color = GetColor(255, 0, 0);
			else color = GetColor(255, 255, 255);

			auto&& x = _x + (j * s_blockScale);
			auto&& y = _y + (i * s_blockScale);

			DrawBox(x, y, x + s_blockScale, y + s_blockScale, color, false);
			DrawFormatString(x, y, GetColor(255, 255, 255), "%d", _field[i][j]);
		}
	}
}
//--------------------------------------------------------------------------------------