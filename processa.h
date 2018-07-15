#pragma once
#include "opencv2/opencv.hpp"
#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/core/core.hpp>
#include "opencv2/objdetect.hpp"
#include "HSVFrame.h"
#include "RESIZEFrame.h"
#include "GrayFrame.h"
#include "Binary_Frame.h"
#include "BirdView.h"
#include "sobelfilter.h"


using namespace std;
using namespace cv;


void processinga_frame(Mat& src, Mat& resize, Mat& dst);
