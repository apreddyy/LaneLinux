#include "opencv2/opencv.hpp"
#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "sobelfilter.h"
#include "gray.h"

using namespace std;
using namespace cv;

void sobel_frame(Mat& src, Mat& dst)
{
	Mat sobelx, sobely, adwsobelx, adwsobely, gray_framea;
	gray_frame(src, gray_framea);
	Sobel(gray_framea, sobelx, CV_16S, 1, 0, 3, 1, BORDER_DEFAULT);;
	convertScaleAbs(sobelx, sobelx);
	sobelx.convertTo(dst, CV_8UC1);
}
