#include "GameManager.h"

GameManager::GameManager() :
	_vx(0), _vy(0), _vr(0), _block(0, 0, 0),
	_interval(60), _count(0), _blockHolder(BlockHolder(400, 32)), _field(400, 32) {
	setup();
}
//----------------------------------------------------------------
Block* GameManager::createNewBlock(int blockId, int x, int y, int rot) {
	return new Block(_blockHolder.getBlock(blockId, x, y, rot));
}

//----------------------------------------------------------------
bool GameManager::isBlockMovable(int x, int y) {

	auto&& shape = _block.getShape();
	for (auto&& j = 0; j < shape.size(); j++)
		for (auto&& i = 0; i < shape.at(0).size(); i++) {
			if (shape[i][j] == 0) continue;

			auto posX = _block.getX() + x + j;
			auto posY = _block.getY() + y + i;

			if (_field.isOutOfFieldIndex(posX, posY))return false;
			if (_field.getField()[posY][posX] != 0) return false;
		}

	return true;
}
//----------------------------------------------------------------
bool GameManager::isBlockRotatable(const Block* block, int rot) {

	auto rotateBlock = *block;
	rotateBlock.addRotate(rot);
	DrawFormatString(0, 192, GetColor(255, 255, 255), "rot:%d", rotateBlock.getRotation());

	rotateBlock.turn();
	auto&& shape = rotateBlock.getShape();

	for (auto&& i = 0; i < shape.size(); i++)for (auto&& j = 0; j < shape.at(0).size(); j++) {
		if (shape[i][j] == 0) continue;

		const auto posX = rotateBlock.getX() + j;
		const auto posY = rotateBlock.getY() + i;

		if (_field.isOutOfFieldIndex(posX - 1, posY)) return false;
		if (_field.isOutOfFieldIndex(posX + 1, posY)) return false;

		if (_field.getField()[posY][posX] != 0) return false;
	}

	return true;
}
//----------------------------------------------------------------
bool GameManager::isBlockDroppable(int x, int y) {
	auto&& shape = _block.getShape();
	for (auto&& i = 0; i < shape.size(); i++)for (auto&& j = 0; j < shape.at(0).size(); j++) {
		if (shape[i][j] == 0) continue;

		auto posX = _block.getX() + x + j;
		auto posY = _block.getY() + y + i;

		if (_field.isOutOfFieldIndex(posX, posY + 1))return false;
		if (_field.getField()[posY + 1][posX] != 0) return false;
	}

	return true;
}
//----------------------------------------------------------------
void GameManager::moveBlock() {
	Input::updateKeyState();

	if (Input::inputKey(KEY_INPUT_LEFT)) _vx--;
	else if (Input::inputKey(KEY_INPUT_RIGHT)) _vx++;
	else _vx = 0;


	if (Input::inputKey(KEY_INPUT_Q)) _vr = -1;
	else if (Input::inputKey(KEY_INPUT_E)) _vr = 1;
	else _vr = 0;

	if (isBlockMovable(_vx, _vy)) _block.addX(_vx);

	if (isBlockRotatable(&_block, _vr)) {
		_block.addRotate(_vr);
		_block.turn();
	}
	else DrawFormatString(0, 96, GetColor(255, 255, 255), "isRotatable: false");

	DrawFormatString(0, 32, GetColor(255, 255, 255), "pos: x:%d/y:%d", _block.getX(), _block.getY());
	DrawFormatString(0, 64, GetColor(255, 255, 255), "rotate: %d", _block.getRotation());
	DrawFormatString(0, 128, GetColor(255, 255, 255), "isMovable: %d", isBlockMovable(_vx, _vy));
	DrawFormatString(0, 160, GetColor(255, 255, 255), "vx:%d/vy:%d", _vx, _vy);
}
//----------------------------------------------------------------
void GameManager::dropBlock() {
	if (Input::inputKey(KEY_INPUT_DOWN))_vy++;
	else _vy = 0;

	if (isBlockDroppable(_vx, _vy))	_block.addY(_vy);

	if (_interval < _count) {
		if (!isBlockDroppable(_vx, _vy)) {
			saveField();
			setup();
		}
		else _block.addY(1);

		_count = 0;
	}

	else _count++;

}
//----------------------------------------------------------------
void GameManager::saveField() {
	auto&& shape = _block.getShape();
	for (auto&& j = 0; j < shape.size(); j++)
		for (auto&& i = 0; i < shape.at(0).size(); i++) {
			if (shape[i][j] == 0) continue;

			auto posX = _block.getX() + j;
			auto posY = _block.getY() + i;

			_field.setBlockIndex(posX, posY);

			_field.clearLine();
		}
}
//----------------------------------------------------------------
void GameManager::setup() {
	const auto hundle = GetRand(6);
	const auto x = GetRand(3) + 1;
	const auto rot = GetRand(1) * GetRand(-1);
	_block = *createNewBlock(hundle, x, 0, rot);
}
//----------------------------------------------------------------
void GameManager::update() {
	moveBlock();
	dropBlock();

	_field.draw();
	_block.draw();
}
//----------------------------------------------------------------
