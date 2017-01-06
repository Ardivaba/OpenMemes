#include "Mouse.h"

int moveX = 0;
int moveY = 0;
int moveStep = 19;
int moveSleep = 1;

thread mouseThread;

void Mouse::Initialize()
{
	mouseThread = thread(Mouse::Thread);
}

void Mouse::MoveDelta(int x, int y, int step, int sleep)
{
	moveX = x;
	moveY = y;
	moveStep = step;
	moveSleep = sleep;
}

void Mouse::Thread()
{
	while (true)
	{
		Mouse::Loop();
	}
}

void Mouse::Loop()
{
	if (abs(moveX) > 0 && abs(moveX) >= moveStep)
	{
		if (moveX > 0)
		{
			mouse_event(1, -moveStep, 0, 0, 0);
			moveX -= moveStep;
		}

		if (moveX < 0)
		{
			mouse_event(1, moveStep, 0, 0, 0);
			moveX += moveStep;
		}
	}
	else if (abs(moveX) > 0 && abs(moveX) < moveStep)
	{
		mouse_event(1, moveX, 0, 0, 0);
		moveX = 0;
	}

	if (abs(moveY) > 0 && abs(moveY) >= moveStep)
	{
		if (moveY > 0)
		{
			mouse_event(1, 0, -moveStep, 0, 0);
			moveY -= moveStep;
		}

		if (moveY < 0)
		{
			mouse_event(1, 0, moveStep, 0, 0);
			moveY += moveStep;
		}
	}
	else if (abs(moveY) > 0 && abs(moveY) < moveStep)
	{
		mouse_event(1, 0, moveY, 0, 0);
		moveY = 0;
	}

	std::this_thread::sleep_for(std::chrono::microseconds(moveSleep));
}
