#include "Keyboard.h"

#include <Windows.h>

bool pressed[256] = { false };

bool Keyboard::wasJustPressed(int keyCode)
{
	if (GetKeyState(keyCode) & 0x80 && !pressed[keyCode])
	{
		pressed[keyCode] = true;
		return true;
	}
	else
	{
		if (!(GetKeyState(keyCode) & 0x80))
		{
			pressed[keyCode] = false;
		}

		return false;
	}
	
}

bool Keyboard::isPressed(int keyCode)
{
	if (GetKeyState(keyCode) & 0x80)
		return true;
	else
		return false;
}

bool Keyboard::isToggled(int keyCode)
{
	if (GetKeyState(keyCode))
		return true;
	else
		return false;
}
