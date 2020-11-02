#pragma once

//*****************************************************
// ÉQÅ[ÉÄä«óùÉNÉâÉX
#include"Block/BlockHolder.h"
#include"Field/Field.h"
#include"Input/Input.h"
#include<vector>

using std::vector;
using std::unique_ptr;

class GameManager
{
private:
	int _interval, _count;
	BlockHolder _blockHolder;
	Field _field;

	Block _block;

	int _vx, _vy;
	int _vr;

	//----------------------------------------------------------------
	// Method
	Block* createNewBlock(int blockId, int x, int y, int rot);
	void moveBlock();
	void dropBlock();
	void saveField();

	bool isBlockMovable(int x, int y);
	bool isBlockDroppable(int x, int y);
	bool isBlockRotatable(const Block* block, int rot);

public:
	GameManager();

	void setup();
	void update();
};

