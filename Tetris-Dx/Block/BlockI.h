#pragma once
#include "Block.h"
class BlockI : public Block
{

protected:
	void initShape() override;

public:
	BlockI(int x, int y, int rot);
};

