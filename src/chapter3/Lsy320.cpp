#include <iostream>
#include "opencv2/opencv.hpp"
#include "c3.h"
using namespace std;
using namespace cv;

void f_3_20()
{
	Mat img=imread("/home/lsy/图片/DIP3E_Original_Images_CH03/Fig0320(1)(top_left).tif",0);

	Mat img1=Mat(img.size(),img.type());
	equalizeHist( img, img1 );


	namedWindow("原图", WINDOW_NORMAL);
	namedWindow("直方图均衡", WINDOW_NORMAL);
	imshow("原图",img);
	imshow("直方图均衡",img1);
	waitKey(0);
}
