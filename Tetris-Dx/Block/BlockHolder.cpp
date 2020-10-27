#include "BlockHolder.h"

//--------------------------------------------------------------------------------------
BlockHolder::BlockHolder(int x, int y) :_offsetX(x), _offsetY(y) {
	_blockTable.insert(make_pair(0, new BlockI(_offsetX, _offsetY)));
	_blockTable.insert(make_pair(1, new BlockO(_offsetX, _offsetY)));
	_blockTable.insert(make_pair(2, new BlockT(_offsetX, _offsetY)));
	_blockTable.insert(make_pair(3, new BlockJ(_offsetX, _offsetY)));
	_blockTable.insert(make_pair(4, new BlockL(_offsetX, _offsetY)));
	_blockTable.insert(make_pair(5, new BlockS(_offsetX, _offsetY)));
	_blockTable.insert(make_pair(6, new BlockZ(_offsetX, _offsetY)));
}
//--------------------------------------------------------------------------------------
shared_ptr<Block> BlockHolder::getBlock(int hundle, int x, int y, int rot) {
	auto&& block = _blockTable.at(hundle);
	block->setup(x, y, rot);
	return block;
}
//--------------------------------------------------------------------------------------