#pragma once

//*****************************************************
// ƒQ[ƒ€ŠÇ—ƒNƒ‰ƒX
#include"Block/BlockHolder.h"
#include"Field/Field.h"
#include"Input/Input.h"

class GameManager
{
private:
	BlockHolder _blockHolder;
	Field _field;
	shared_ptr<Block> _block;
	int _vx, _vy;

	shared_ptr<Block> createNewBlock(int blockId, int x, int y, int rot);

	//----------------------------------------------------------------

	void controllBlock();

	void moveBlock();

	bool isBlockMovable(int x, int y);

	void dropBlock();

public:
	GameManager();

	void setup();
	void update();
};

