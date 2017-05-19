#include "Header.h"

int main() {

	// Load four images named a, b, c, d
	IplImage* arr_image[4];
	for (int i = 0; i < 4; i++) {
		switch (i) {
		case 0:
			arr_image[i] = cvLoadImage("C:\\a.jpg", CV_LOAD_IMAGE_COLOR);
			if (arr_image[i] == NULL)
				return -1;
			break;
		case 1:
			arr_image[i] = cvLoadImage("C:\\b.jpg", CV_LOAD_IMAGE_COLOR);
			if (arr_image[i] == NULL)
				return -1;
			break;
		case 2:
			arr_image[i] = cvLoadImage("C:\\c.jpg", CV_LOAD_IMAGE_COLOR);
			if (arr_image[i] == NULL)
				return -1;
			break;
		default:
			arr_image[i] = cvLoadImage("C:\\d.jpg", CV_LOAD_IMAGE_COLOR);
			if (arr_image[i] == NULL)
				return -1;
		}
	}

	cout << "Result : " << endl;

	// First, make Points objects 
	// And find high, low, right, left points
	// Finally, If the image is circle, print "Circle!!" or not print "Triangle"
	Points imgA = Points();
	imgA.findPoints(arr_image[0]);
	if (imgA.isCircle(arr_image[0])) {
		cout <<"a : Circle!!" << endl;
	}
	else {
		cout<< "a : Triangle!!" << endl;
	}
	
	Points imgB = Points();
	imgB.findPoints(arr_image[1]);
	if (imgB.isCircle(arr_image[1])) {
		cout << "b : Circle!!" << endl;
	}
	else {
		cout << "b : Triangle!!" << endl;
	}


	Points imgC = Points();
	imgC.findPoints(arr_image[2]);
	if (imgC.isCircle(arr_image[2])) {
		cout << "c : Circle!!" << endl;
	}
	else {
		cout << "c : Triangle!!" << endl;
	}


	Points imgD = Points();
	imgD.findPoints(arr_image[3]);
	if (imgD.isCircle(arr_image[3])) {
		cout << "d : Circle!!" << endl;
	}
	else {
		cout << "d : Triangle!!" << endl;
	}
}