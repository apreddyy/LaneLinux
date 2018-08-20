#include "opencv2/opencv.hpp"
#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/videoio.hpp>
#include <cmath>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "processedout.h"
#include "processedout_emxAPI.h"
#include "processedout_types.h"
#include "processedout_initialize.h"
#include "processa.h"
#include "processb.h"


using namespace std;
using namespace cv;


void processinga_frame(Mat& src, Mat& resize, Mat& dst);
void processingb_frame(Mat& frame, Mat& src, double PointsA[720], double PointsB[720], double AlertSide, double center_data[], Mat& dst);


int main(int argc, char *argv[])
{
	setenv("DISPLAY", ":0", 0);
	VideoCapture cap("openv.avi");
	if (!cap.isOpened())
	{
		cout << "Error opening video stream or file" << endl;
		return -1;
	}
	while (1)
	{
		Mat frame,  cudaout_frame, frame_out;
		Mat process_framein, process_frame, process_frameout, resize_frame;
		int Width;
		int Height;
		Width = 640;
		Height = 360;
		double AlertSide;
		double center_data[1];
		int center_size[1];
		double left_curvature;
		double right_curveature;
		static int iv0[2] = { Height, Width };
		emxArray_uint8_T   *imageInput;
		imageInput = emxCreateND_uint8_T(2, *(int(*)[2])&iv0[0]);
		processedout_initialize();
		double PointsA[720];
		double PointsB[720];
		/*VideoWriter video("/pathtoproject/Debug/videoin.avi", CV_FOURCC('P','I','M','1'), 25, Size(1280, 720), true);*/
		for (;;)
		{
			cap >> frame;
			if (frame.empty())
				break;
			processinga_frame(frame, resize_frame, process_frame);
			int i, j;
			for (i = 0; i < Width; i++)
				for (j = 0; j < Height; j++)
					imageInput->data[i*Height+ j] = (uint8_T)process_frame.data[i+ Width * j];
			processedout(imageInput, PointsA, PointsB, &AlertSide, center_data, center_size, &left_curvature, &right_curveature);
			processingb_frame(process_frame, resize_frame, PointsA, PointsB, AlertSide, center_data, process_frameout);
			/*video.write(frame);*/
			imshow("FrameL", process_frameout);
			if (waitKey(27) >= 0)break;
		}
		cap.release();
		destroyAllWindows();
		return 2;
	}
}
