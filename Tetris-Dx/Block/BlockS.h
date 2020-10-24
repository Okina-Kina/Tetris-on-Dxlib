#pragma once
#include"Block.h"
class BlockS : public Block
{
protected:
	void initShape() override;

public:
	BlockS(int x, int y, int rot);
};

