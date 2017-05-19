#include <iostream>
#include <opencv2\highgui\highgui.hpp>

using namespace std;

#ifndef __HEADER_H__
#define __HEADER_H__

class Points {
private:
	CvPoint high, low, left, right, central;
	int radius = 0;
	int cnt = 0;

public:
	// Make Points object
	Points() {};
	// Find high, low, left, and right point
	void findPoints(IplImage* image);
	// Determine the image is circle
	bool isCircle(IplImage* image);
};

#endif