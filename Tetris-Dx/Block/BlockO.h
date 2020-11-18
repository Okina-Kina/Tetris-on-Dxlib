#pragma once
#include "Block.h"

class BlockO : public Block
{
protected:
	void initShape() override;

public:
	BlockO(int offsetX, int offsetY);
};

