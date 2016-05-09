#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
//#include "cvconfig.h"
#include "opencv2/core/core.hpp"
//#include <cv2.h>
#include<stdio.h>
using namespace std;
using namespace cv;

#define h 500
#define w 1000
int main()
{
	//Image variables
	IplImage* img = cvLoadImage("c:\\AM10.png");///Image Location in your system
	IplImage* rimg = cvCreateImage(cvSize(w, h), 8, 3);///Image Size Adjustment
	IplImage* hsvimg = cvCreateImage(cvSize(w, h), 8, 3);
	IplImage* thresh = cvCreateImage(cvSize(w, h), 8, 1);
	//Windows
	cvNamedWindow("Original Image", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Thresholded Image", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("cnt", CV_WINDOW_AUTOSIZE);

	//Variables for trackbar
	int h1 = 0; int s1 = 0; int v1 = 0;
	int h2 = 0; int s2 = 0; int v2 = 0;
	//Creating the trackbars
	cvCreateTrackbar("H1", "cnt", &h1, 255, 0);
	cvCreateTrackbar("H2", "cnt", &h2, 255, 0);
	cvCreateTrackbar("S1", "cnt", &s1, 255, 0);
	cvCreateTrackbar("S2", "cnt", &s2, 255, 0);
	cvCreateTrackbar("V1", "cnt", &v1, 255, 0);
	cvCreateTrackbar("V2", "cnt", &v2, 255, 0);

	//Resizing the image
	cvResize(img, rimg, CV_INTER_LINEAR);
	//Changing into HSV plane
	cvCvtColor(rimg, hsvimg, CV_BGR2HSV);
	while (1)
	{
		//Thresholding the image
		cvInRangeS(hsvimg, cvScalar(h1, s1, v1), cvScalar(h2, s2, v2), thresh);
		//Showing the images
		cvShowImage("Original Image", rimg);
		cvShowImage("Thresholded Image", thresh);
		//Escape Sequence
		char c = cvWaitKey(33);
		if (c == 27)
			break;
	}
	//Showing the image
	cvShowImage("Original Image", rimg);
	cvShowImage("Thresholded Image", thresh);
	//Waiting for user to press any key
	cvWaitKey(0);
	//Cleanup
	cvReleaseImage(&img);
	cvReleaseImage(&thresh);
	cvReleaseImage(&rimg);
	cvReleaseImage(&hsvimg);
	cvDestroyAllWindows();

}
