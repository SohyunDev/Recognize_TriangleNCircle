#include "Header.h"

void Points::findPoints(IplImage* image) {
	high = cvPoint(image->height, image->width);
	low = cvPoint(0, 0);
	left = cvPoint(image->height, image->width);
	right = cvPoint(0, 0);
	central = cvPoint(0, 0);
	
	// find high, low, left, and right point
	for (int y = 0; y < image->height; y++) {
		for (int x = 0; x < image->width; x++) {
			if (cvGet2D(image, y, x).val[0] == 0 && cvGet2D(image, y, x).val[1] == 0 && cvGet2D(image, y, x).val[2] == 0) {
				if (y < high.y) {
					high.x = x;
					high.y = y;
				}
				if (y > low.y) {
					low.x = x;
					low.y = y;
				}
				if (x < left.x) {
					left.x = x;
					left.y = y;
				}
				if (x > right.x) {
					right.x = x;
					right.y = y;
				}
			}
		}
	}
	central.x = (left.x + right.x) / 2;
	central.y = (high.y + low.y) / 2;

	radius = (right.x - left.x) / 2;


}
// Determine the image is circle
bool Points::isCircle(IplImage* image) {
	for (int i = -10; i < 10; i++) {
		if (cvGet2D(image, central.y + radius + i, central.x).val[0] == 0) {
			cnt++;
			break;
		}
	}
	for (int i = -10; i < 10; i++) {
		if (cvGet2D(image, central.y, central.x - radius + i).val[0] == 0) {
			cnt++;
			break;
		}
	}
	for (int i = -10; i < 10; i++) {
		if (cvGet2D(image, central.y - radius + i, central.x).val[0] == 0) {
			cnt++;
			break;
		}
	}
	for (int i = -10; i < 10; i++) {
		if (cvGet2D(image, central.y, central.x + radius + i).val[0] == 0) {
			cnt++;
			break;
		}
	}
	if (cnt == 4)
		return true;
	else
		return false;

}
