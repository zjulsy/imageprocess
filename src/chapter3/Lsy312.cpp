#include <iostream>
#include "opencv2/opencv.hpp"
#include "c3.h"
using namespace std;
using namespace cv;

void f_3_12()
{
	Mat img=imread("/home/lsy/图片/DIP3E_Original_Images_CH03/Fig0312(a)(kidney).tif",0);


	Mat lookUpTable=Mat::zeros(1, 256, CV_8U);
	uchar* p = lookUpTable.ptr();
	Mat lookUpTable2=Mat::zeros(1, 256, CV_8U);
	uchar* p2 = lookUpTable2.ptr();

	for( int i = 0; i < 256; ++i)
	{
		p[i]=i>150?255:0;
		//p2[i]=((150>i) && (i>20))?0:i;
		p2[i]=((150>i) && (i>50))?0:i;
	}

	Mat img2=Mat(img.rows,img.cols,img.type());
	LUT(img, lookUpTable, img2);
	Mat img3=Mat(img.rows,img.cols,img.type());
	LUT(img, lookUpTable2, img3);

	namedWindow("原图", WINDOW_NORMAL);
	imshow("原图",img);
	namedWindow("分层变换1", WINDOW_NORMAL);
	imshow("分层变换1",img2);
	namedWindow("分层变换2", WINDOW_NORMAL);
	imshow("分层变换2",img3);
	waitKey(0);
}
