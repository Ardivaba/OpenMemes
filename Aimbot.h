#pragma once
#include "Scanner.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Utility.h"

class Aimbot
{
private:
	static Mat frame;

public:
	static void SetFrame(Mat frame);
	static Mat GetHealthRange(Mat mat);
	static void Update();
};

