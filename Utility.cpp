#include "Utility.h"

Point Utility::GetFrameCenter(Mat frame)
{
	return Point(frame.size().width / 2, frame.size().height / 2);
}

float Utility::GetDistance(Point pointA, Point pointB)
{
	return sqrt(pow(pointA.x - pointB.x, 2) + pow(pointA.y - pointB.y, 2));
}

Point Utility::GetClosestPoint(list<Point> points, Point relativeTo)
{
	Point closestPoint = points.front();
	for (Point point : points)
	{
		if (GetDistance(relativeTo, point) < GetDistance(relativeTo, closestPoint))
		{
			closestPoint = point;
		}
	}

	return closestPoint;
}
