#pragma once
#include "opencv2/opencv.hpp"
#include <iostream>

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/core/core.hpp>
#include "opencv2/objdetect.hpp"
#include <cmath>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "processedout.h"
#include "unwrap.h"
#include "processedout_emxAPI.h"
#include "processedout_types.h"
/*#include "LaneLogic/Implement/LaneLogic_grt_rtw/LaneLogic.h"*/
#include <thread>
#include "Rightprocessing.h"
#include "Leftprocessing.h"

using namespace std;
using namespace cv;




void processingb_frame(Mat& frame, Mat& src, double PointsA[720], double PointsB[720], int AlertSide, double center_data[], Mat& dst);
