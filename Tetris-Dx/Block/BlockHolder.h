#pragma once

//*****************************************************
// �e��u���b�N�����N���X
#include"BlockI.h"
#include"BlockJ.h"
#include"BlockL.h"
#include"BlockO.h"
#include"BlockS.h"
#include"BlockT.h"
#include"BlockZ.h"

#include<typeinfo>
#include<memory>
#include<map>

using std::map;
using std::make_pair;
using std::shared_ptr;
using std::unique_ptr;

class BlockHolder
{
private:
	int _offsetX, _offsetY;
	map<int, unique_ptr<Block>> _blockTable;

public:
	BlockHolder(int x, int y);

	//*****************************************************
	// getter
	Block& getBlock(int hundle, int x, int y, int rot) const;
};

