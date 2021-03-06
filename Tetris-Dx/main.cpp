#include "DxLib.h"
#include"GameManager.h"

int initDxLib() {
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// DXライブラリ初期化処理
	if (DxLib_Init() < 0) return -1;

	//描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	// 画面モードの変更
	SetGraphMode(960, 720, 32);

	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	initDxLib();
	auto&& gameMgr = GameManager();

	gameMgr.setup();

	// while(裏画面を表画面に反映, メッセージ処理, 画面クリア)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

		DrawFormatString(0, 0, GetColor(255, 255, 255), "ESCキーで終了します");

		if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) break;

		gameMgr.update();

	}

	DxLib_End();    // DXライブラリ終了処理
	return 0;
}