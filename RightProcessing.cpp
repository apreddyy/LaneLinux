#include "opencv2/opencv.hpp"
#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "Rightprocessing.h"

using namespace std;
using namespace cv;

void rightprocessing(double PointB[720], int dataR[720])
{

	int	mR = 360;
	int	nR = 2;
	int ir, jr;
	for (ir = 0; ir < nR; ir++)
		for (jr = 0; jr < mR; jr++)
		{
			dataR[ir + nR * jr] = (int)PointB[ir*mR + jr];
		}
}
