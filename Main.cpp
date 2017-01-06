#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>

#include "Screenshot.h"
#include "Scanner.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "Aimbot.h"

#include "Tracer.h"

using namespace cv;

int main()
{
	Mouse::Initialize();

	while (true)
	{
		Tracer::Update();

		Mat frame = Screenshot::GetScreenshot("Overwatch");

		Tracer::Update();
		//Aimbot::SetFrame(frame);
		//Aimbot::Update();

		imshow("Frame", frame);
		waitKey(1);
	}
}