#include "Aimbot.h"

Mat Aimbot::frame;

void Aimbot::SetFrame(Mat frame)
{
	Aimbot::frame = frame;
}

Mat Aimbot::GetHealthRange(Mat mat)
{
	Mat healthRange;
	inRange(Aimbot::frame, Scalar(0, 0, 255, 0), Scalar(25, 25, 255, 255), healthRange);

	int dilation_size = 2;
	Mat element = getStructuringElement(MORPH_RECT,
		Size(2 * dilation_size + 1, 1 * dilation_size + 1),
		Point(dilation_size, dilation_size));
	dilate(healthRange, healthRange, element);

	return healthRange;
}

void Aimbot::Update()
{
	Mat healthRange = Aimbot::GetHealthRange(frame);
	Scanner::setFrame(healthRange);
	list<Point> healths = Scanner::findHealths();
	Point frameCenter = Utility::GetFrameCenter(frame);
	Point closestPoint = Utility::GetClosestPoint(healths, frameCenter);

	drawMarker(healthRange, closestPoint, Scalar(255));

	imshow("Range", healthRange);
	return;

	int centerX = -30 + healthRange.size().width / 2;
	int centerY = -35 + healthRange.size().height / 2;

	int deltaX = centerX - closestPoint.x;
	int distanceX = abs(deltaX);
	int dirX = deltaX > 0 ? 1 : -1;

	int movementX = 0;
	if (distanceX > 10)
		movementX = 20;
	else if (distanceX > 5 && distanceX < 10)
		movementX = 5;

	int deltaY = centerY - closestPoint.y;
	int distanceY = abs(deltaY);
	int dirY = deltaY > 0 ? 1 : -1;

	int movementY = 0;
	if (distanceY > 10)
		movementY = 20;
	else if (distanceY > 5 && distanceY < 10)
		movementY = 5;

	putText(healthRange, to_string(dirX), closestPoint, 0, 1.0, Scalar(255));

	int finalMovementX = 0;
	if (movementX > 2)
		finalMovementX = 3 * distanceX * dirX;

	int finalMovementY = 0;
	if (movementY > 2)
		finalMovementY = 3 * distanceY * dirY;

	Mouse::MoveDelta(finalMovementX, finalMovementY, 10, 0);
}
