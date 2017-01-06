#pragma once
class Keyboard
{
public:
	static bool wasJustPressed(int keyCode);
	static bool isPressed(int keyCode);
	static bool isToggled(int keyCode);
};

