#include "GameManager.h"

GameManager::GameManager() :_blockHolder(BlockHolder(400, 32)), _field(400, 32), _block() {
	setup();
}

shared_ptr<Block> GameManager::createNewBlock(int blockId, int x, int y, int rot) {
	return _blockHolder.getBlock(blockId, x, y, rot);
}

void GameManager::controllBlock() {
	Input::updateKeyState();
	if (Input::inputKey(KEY_INPUT_LEFT))_block->turnLeft();
	if (Input::inputKey(KEY_INPUT_RIGHT))_block->turnRight();
}

void GameManager::setup() {
	_block = createNewBlock(0, 5, 4, 0);
}

void GameManager::update() {
	controllBlock();

	_field.draw();
	_block->draw();
}