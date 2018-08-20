#include "opencv2/opencv.hpp"
#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/core/core.hpp>
#include "opencv2/objdetect.hpp"
#include "sobelfilter.h"
#include "binary.h"
#include "gray.h"
#include "hsv.h"
#include "processa.h"
#include "resize.h"
#include "wrap.h"

using namespace std;
using namespace cv;



void hsv_frame(Mat& src, Mat& dst);
void resize_frame(Mat& src, Mat& dst);
void gray_frame(Mat& src, Mat& dst);
void binary_frame(Mat& src, Mat& dst);
void birdview_frame(Mat& src, Mat& dst);
void sobel_frame(Mat& src, Mat& dst);






void processinga_frame(Mat& src, Mat& resize, Mat& dst)
{
	Mat frame, cudaout_frame, MergeFrameOut, cudaout_framet;
	Mat  resize_framea, gray_framea, binary_framea, birdview_framea, hsv_framea, threshold_frame, sobel_frameout;
	resize_frame(src, resize_framea);
	resize = resize_framea;
	birdview_frame(resize_framea, birdview_framea);
	sobel_frame(birdview_framea, sobel_frameout);
	hsv_frame(birdview_framea, hsv_framea);
	gray_frame(hsv_framea, gray_framea);
	binary_frame(gray_framea, binary_framea);
	addWeighted(binary_framea, 0.9, sobel_frameout, 0.1, -1, dst);
}
