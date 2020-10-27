#pragma once

//*****************************************************
// 各種ブロックを持つクラス
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

