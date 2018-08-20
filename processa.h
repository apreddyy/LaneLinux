#pragma once
#include "opencv2/opencv.hpp"
#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/core/core.hpp>
#include "opencv2/objdetect.hpp"
#include "hsv.h"
#include "resize.h"
#include "gray.h"
#include "wrap.h"
#include "sobelfilter.h"
#include "binary.h"


using namespace std;
using namespace cv;


void processinga_frame(Mat& src, Mat& resize, Mat& dst);
