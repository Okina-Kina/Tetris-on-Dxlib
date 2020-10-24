#pragma once
#include "Block.h"
class BlockT : public Block
{
protected:
	void initShape() override;

public:
	BlockT();
};

