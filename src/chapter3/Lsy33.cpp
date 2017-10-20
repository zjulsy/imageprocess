#include <iostream>
#include "opencv2/opencv.hpp"
#include "c3.h"
using namespace std;
using namespace cv;

void f_3_3()
{
	Mat img=imread("/home/lsy/图片/DIP3E_Original_Images_CH03/Fig0304(a)(breast_digital_Xray).tif",0);

	Mat lookUpTable(1, 256, CV_8U);
	uchar* p = lookUpTable.ptr();
	for( int i = 0; i < 256; ++i)
	    p[i] =255-i;

	Mat img2=Mat(img.rows,img.cols,img.type());
	LUT(img, lookUpTable, img2);

	imshow("原图",img);
	imshow("图像反转",img2);
	waitKey(0);
}
