#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <vector>
#include <list>
#include <Windows.h>

using namespace cv;

class Scanner
{
public:
	static Mat currentFrame;
	static std::list<Point> findHealths();
	static void setFrame(Mat frame);
};

