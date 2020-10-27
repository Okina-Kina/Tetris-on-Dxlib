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
	int _vr;

	shared_ptr<Block> createNewBlock(int blockId, int x, int y, int rot);

	//----------------------------------------------------------------

	void moveBlock();
	bool isBlockMovable(int x, int y);
	bool isBlockRotatable(const shared_ptr<Block> block, int rot);
	void dropBlock();

public:
	GameManager();

	void setup();
	void update();
};

