#include "opencv2/opencv.hpp"
#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "Leftprocessing.h"

using namespace std;
using namespace cv;

void leftprocessing(double PointA[720],  int dataL[720])
{
	int mL = 360;
	int nL = 2;
	int ii, jj;
	for (ii = 0; ii < nL; ii++)
		for (jj = 0; jj < mL; jj++)
		{
			dataL[ii + nL * jj] = (int)PointA[ii*mL + jj];
		}
}
