#include "Tracer.h"
#include "Keyboard.h"
#include "Mouse.h"

void Tracer::Update()
{
	if (Keyboard::wasJustPressed(VK_RBUTTON))
	{
		int multiplier = 0;
		if (GetKeyState(0x41) & 0x80)
			multiplier = -1;
		if (GetKeyState(0x44) & 0x80)
			multiplier = 1;
		Mouse::MoveDelta(multiplier * 7800 / 4, 0, 50, 1);
	}

	if (Keyboard::wasJustPressed(VK_MENU))
	{
		int randomInt = 0 + (rand() % (int)(1 - 0 + 1));
		if (randomInt > 0)
			Mouse::MoveDelta(7800, 0, 100, 1);
		else
			Mouse::MoveDelta(-7800, 0, 100, 1);
	}
}
