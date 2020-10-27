#include "GameManager.h"

GameManager::GameManager() :
	_blockHolder(BlockHolder(400, 32)), _field(400, 32), _block(), _vx(0), _vy(0) {
	setup();
}
//----------------------------------------------------------------
shared_ptr<Block> GameManager::createNewBlock(int blockId, int x, int y, int rot) {
	return _blockHolder.getBlock(blockId, x, y, rot);
}
//----------------------------------------------------------------
bool GameManager::isBlockMovable(int x, int y) {

	auto&& shape = _block->getShape();
	for (auto&& j = 0; j < shape.size(); j++)
		for (auto&& i = 0; i < shape.at(0).size(); i++) {
			if (shape[i][j] == 0) continue;

			auto posX = _block->getX() + x + j;
			auto posY = _block->getY() + y + i;

			if (_field.isOutOfFieldIndex(posX, posY))return false;
			if (_field.getField()[posY][posX] != 0) return false;
		}

	return true;
}
//----------------------------------------------------------------
void GameManager::controllBlock() {
	Input::updateKeyState();


	if (Input::inputKey(KEY_INPUT_LEFT)) _vx--;
	else if (Input::inputKey(KEY_INPUT_RIGHT)) _vx++;
	else _vx = 0;

	if (Input::inputKey(KEY_INPUT_DOWN))_vy++;

	if (isBlockMovable(_vx, _vy)) {
		_block->setX(_block->getX() + _vx);
		_block->setY(_block->getY() + _vy);
	}
	DrawFormatString(0, 32, GetColor(255, 255, 255), "pos: x:%d/y:%d", _block->getX(), _block->getY());


	if (Input::inputKey(KEY_INPUT_Q))_block->turnLeft();
	if (Input::inputKey(KEY_INPUT_E))_block->turnRight();
}
//----------------------------------------------------------------
void GameManager::setup() { _block = createNewBlock(0, 3, 4, 0); }
//----------------------------------------------------------------
void GameManager::update() {
	controllBlock();

	_field.draw();
	_block->draw();
}
//----------------------------------------------------------------
