#pragma once
#include"Block.h"

class BlockL : public Block
{
protected:
	void initShape() override;

public:
	BlockL(int offsetX, int offsetY);
};

