#pragma once
#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>

#include <vector>
#include <list>

using namespace cv;
using namespace std;

class Utility
{
public:
	static Point GetFrameCenter(Mat frame);
	static float GetDistance(Point pointA, Point pointB);
	static Point GetClosestPoint(std::list<Point> points, Point relativeTo);
};

