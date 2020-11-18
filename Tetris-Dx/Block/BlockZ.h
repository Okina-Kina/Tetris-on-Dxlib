#pragma once
#include "Block.h"
class BlockZ : public Block
{
protected:
	void initShape() override;

public:
	BlockZ(int offsetX, int offsetY);
};

