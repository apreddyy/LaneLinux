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
#include "processb.h"

using namespace std;
using namespace cv;




void processingb_frame(Mat& frame, Mat& src, double PointsA[720], double PointsB[720], double AlertSide, double center_data[], Mat& dst)
{
	Mat unwrap_framein, unwrap_frameout, merge_frameout, sobel_frameout;
	int mL = 360;
	int	mR = 360;
	int nL = 2;
	int	nR = 2;
	int dataL[720];
	int dataR[720];
    int ii, jj;
    for (ii = 0; ii < nL; ii++)
    {
        for (jj = 0; jj < mL; jj++)
        {
            dataL[ii + nL * jj] = (int)PointsA[ii*mL + jj];
            dataR[ii + nR * jj] = (int)PointsB[ii*mR + jj];
        }
    }

	Mat Lpoint = Mat(mL, nL, CV_32SC1, dataL);
	Mat Rpoint = Mat(mR, nR, CV_32SC1, dataR);
	Mat maskImage = Mat(frame.size(), CV_8UC3, Scalar(0));
	vector<Point2i>TestPoint;
	for (int r = 0; r < mL; r++)
	{
		Point2i L = (Point2i(Lpoint.at <int>(r, 0), Lpoint.at <int>(r, 1)));
		TestPoint.push_back(L);
		drawMarker(maskImage, L, Scalar(0, 0, 255), MARKER_SQUARE, 30, 1, 8);

	}
	for (int rp = 359; rp >= 0; rp--)
	{
		Point2i R = (Point2i(Rpoint.at <int>(rp, 0), Rpoint.at <int>(rp, 1)));
		TestPoint.push_back(R);
		drawMarker(maskImage, R, Scalar(0, 0, 255), MARKER_SQUARE, 30, 1, 8);
	}
	const Point *pts = (const cv::Point*)Mat(TestPoint).data;
	int npts = Mat(TestPoint).rows;
    fillPoly(maskImage, &pts, &npts, 1, Scalar(0, 255, 0), 8);
	unwrap_frame(maskImage, unwrap_frameout);
	addWeighted(src, 1, unwrap_frameout, 0.5, -1, dst);
}

