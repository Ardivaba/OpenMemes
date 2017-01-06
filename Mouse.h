#pragma once
#include <thread>
#include <Windows.h>
#include <chrono>
#include <thread>

using namespace std;

class Mouse
{
public:
	static void Initialize();
	static void MoveDelta(int x, int y, int step = 10, int sleep = 1);

private:
	static void Thread();
	static void Loop();
};

