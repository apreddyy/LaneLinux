#include "resize.h"
#include "opencv2/opencv.hpp"
#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"



using namespace std;
using namespace cv;


void resize_frame(Mat& src, Mat& dst)
{
	int resize_height = 360;
	int resize_weidght = 640;
	resize(src, dst, Size(resize_weidght, resize_height));

}
