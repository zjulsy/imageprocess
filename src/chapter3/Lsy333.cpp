#include <iostream>
#include "opencv2/opencv.hpp"
#include "c3.h"
using namespace std;
using namespace cv;

void f_3_33()
{
	Mat img=imread("/home/lsy/图片/DIP3E_Original_Images_CH03/Fig0333(a)(test_pattern_blurring_orig).tif",0);

	Mat img1=Mat(img.size(),img.type());

	blur(img,img1,Size(9,9));
	namedWindow("原图", WINDOW_NORMAL);
	namedWindow("均值滤波", WINDOW_NORMAL);

	imshow("原图",img);
	imshow("均值滤波",img1);

	waitKey(0);
}
