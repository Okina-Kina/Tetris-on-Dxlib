#pragma once

//*****************************************************
// 各種ブロックを持つクラス
#include"Block/BlockI.h"
#include"Block/BlockJ.h"
#include"Block/BlockL.h"
#include"Block/BlockO.h"
#include"Block/BlockS.h"
#include"Block/BlockT.h"
#include"Block/BlockZ.h"

#include<typeinfo>
#include<memory>
#include<map>

using std::map;
using std::make_pair;
using std::shared_ptr;

class BlockHolder
{
private:
	map<int, shared_ptr<Block>> _blockTable;

public:
	BlockHolder();
	
	//*****************************************************
	// getter
	shared_ptr<Block> getBlock(int hundle, int x, int y, int rot);
};

