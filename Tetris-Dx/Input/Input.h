#pragma once

//*****************************************************
// キー入力の検知
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
	/// キーの入力状態を監視する
	/// </summary>
	static void updateKeyState();

	//--------------------------------------------------------------------------------------
	/// <summary>
	/// 押された瞬間
	/// </summary>
	static bool inputKey(int keyCode);
	//--------------------------------------------------------------------------------------
	/// <summary>
	/// 押されているとき
	/// </summary>
	static bool inputDownKey(int keyCode);
};

