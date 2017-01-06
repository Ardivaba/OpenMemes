#include "Scanner.h"

Mat Scanner::currentFrame;

using namespace std;

void Scanner::setFrame(Mat frame)
{
	Scanner::currentFrame = frame;
}

list<Point> Scanner::findHealths()
{
	list<Point> healths;

	for (int x = 0; x < currentFrame.size().width; x++)
	{
		for (int y = 0; y < currentFrame.size().height; y++)
		{
			if (currentFrame.at<byte>(y, x) == 255)
			{
				if (currentFrame.at<byte>(y, x - 1) != 255)
				{
					if (currentFrame.at<byte>(y + 1, x) != 255)
					{
						if (currentFrame.at<byte>(y - 1, x - 1) != 255)
						{
							healths.push_front(Point(x, y));
						}
					}
				}
			}
		}
	}

	return healths;
}