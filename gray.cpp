#include "gray.h"
#include "opencv2/opencv.hpp"
#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"



using namespace std;
using namespace cv;



void gray_frame(Mat& src, Mat& dst)
{
	cvtColor(src, dst, cv::COLOR_RGB2GRAY);
}
