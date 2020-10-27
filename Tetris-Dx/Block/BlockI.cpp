#include "BlockI.h"

//--------------------------------------------------------------------------------------
BlockI::BlockI(int offsetX, int offsetY) :Block(offsetX, offsetY, GetColor(100, 255, 255)) {
	initShape();
}
//--------------------------------------------------------------------------------------
void BlockI::initShape() {
	for (auto&& i = 0; i < s_size; i++)	_shapeData[1][i] = 1;
}
//--------------------------------------------------------------------------------------
