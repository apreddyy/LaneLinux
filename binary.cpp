#include "binary.h"
#include "opencv2/opencv.hpp"
#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;



void binary_frame(Mat& src, Mat& dst)
{
	int threshold_value = 110;
	int max_value = 255;
	threshold(src, dst, threshold_value, max_value, THRESH_BINARY);
}
