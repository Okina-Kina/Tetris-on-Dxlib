#include "DxLib.h"
#include"Field/Field.h"
#include"Input/Input.h"

int initDxLib() {
	// �E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

	// DX���C�u��������������
	if (DxLib_Init() < 0) return -1;

	//�`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	// ��ʃ��[�h�̕ύX
	SetGraphMode(960, 720, 32);

	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	initDxLib();
	auto&& field = Field(400, 32);

	// while(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

		DrawFormatString(0, 0, GetColor(255, 255, 255), "ESC�L�[�ŏI�����܂�");

		Input::updateKeyState();

		if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) break;

		field.draw();
	}

	DxLib_End();    // DX���C�u�����I������
	return 0;
}