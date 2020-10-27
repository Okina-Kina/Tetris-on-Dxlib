#pragma once

//*****************************************************
// �L�[���͂̌��m
#include<DxLib.h>
#include "InputType.h"

class Input
{
private:
	static int s_keyFlag[256];

public:
	//*****************************************************
	// @ method
	/// <summary>
	/// �L�[�̓��͏�Ԃ��Ď�����
	/// </summary>
	static void updateKeyState();

	//--------------------------------------------------------------------------------------
	/// <summary>
	/// �����ꂽ�u��
	/// </summary>
	static bool inputKey(int keyCode);
	//--------------------------------------------------------------------------------------
	/// <summary>
	/// ������Ă���Ƃ�
	/// </summary>
	static bool inputDownKey(int keyCode);
};

