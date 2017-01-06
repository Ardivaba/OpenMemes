#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <vector>
#include <Windows.h>

using namespace std;
using namespace cv;

class Screenshot
{
public:
	static Mat GetScreenshot(LPCSTR windowName);
};