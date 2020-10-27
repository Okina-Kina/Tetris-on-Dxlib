#include "BlockHolder.h"

//--------------------------------------------------------------------------------------
BlockHolder::BlockHolder(int x, int y) :_offsetX(x), _offsetY(y) {
	_blockTable.insert(make_pair(0, new BlockI()));
	_blockTable.insert(make_pair(1, new BlockO()));
	_blockTable.insert(make_pair(2, new BlockT()));
	_blockTable.insert(make_pair(3, new BlockJ()));
	_blockTable.insert(make_pair(4, new BlockL()));
	_blockTable.insert(make_pair(5, new BlockS()));
	_blockTable.insert(make_pair(6, new BlockZ()));
}
//--------------------------------------------------------------------------------------
shared_ptr<Block> BlockHolder::getBlock(int hundle, int x, int y, int rot) {
	auto&& block = _blockTable.at(hundle);
	block->setup(
		_offsetX + (x * block->getScale()), _offsetY + (y * block->getScale()), rot);
	return block;
}