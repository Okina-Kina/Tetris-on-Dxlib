#include "BlockO.h"

//--------------------------------------------------------------------------------------
BlockO::BlockO():Block(GetColor(255, 255, 100)) {
	initShape();
}
//--------------------------------------------------------------------------------------
void BlockO::initShape() {
	_shapeData[1][1] = 1;
	_shapeData[1][2] = 1;
	_shapeData[2][1] = 1;
	_shapeData[2][2] = 1;
}
//--------------------------------------------------------------------------------------
