#include "Input.h"

int Input::s_keyFlag[256];
//--------------------------------------------------------------------------------------
void Input::updateKeyState() {
	static char keyBuffer[256];

	GetHitKeyStateAll(keyBuffer);

	for (int i = 0; i < 256; i++) {

		if (keyBuffer[i]) {
			if (s_keyFlag[i] == InputType::None)s_keyFlag[i] = InputType::Inputed;
			else if (s_keyFlag[i] == InputType::Inputed) s_keyFlag[i] = InputType::Down;
		}
		else s_keyFlag[i] = InputType::None;
	}
}
//--------------------------------------------------------------------------------------
bool Input::inputKey(int keyCode) { return s_keyFlag[keyCode] == InputType::Inputed; }
//--------------------------------------------------------------------------------------
bool Input::inputDownKey(int keyCode) { return s_keyFlag[keyCode] == InputType::Down; }
//--------------------------------------------------------------------------------------