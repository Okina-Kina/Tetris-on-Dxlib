#pragma once
#include "Block.h"
class BlockJ : public Block
{
protected:
	void initShape() override;

public:
	BlockJ(int x, int y, int rot);
};

