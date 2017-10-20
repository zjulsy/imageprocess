#include <iostream>
#include "opencv2/opencv.hpp"
#include "c3.h"
using namespace std;
using namespace cv;

void f_3_10()
{
	Mat img=imread("/home/lsy/图片/DIP3E_Original_Images_CH03/Fig0310(b)(washed_out_pollen_image).tif",0);


	Mat lookUpTable=Mat::zeros(1, 256, CV_8U);
	uchar* p = lookUpTable.ptr();

	double max1,min1;
	minMaxLoc(img,&min1,&max1);
	double a=255/(max1-min1);
	double b= a*min1;
	for( int i = 0; i < 256; ++i)
		p[i]=saturate_cast<uchar>(a*i-b);
	/*{
		if(i>max1)
			p[i]=255;
		if(i>min1)
		p[i]=(a*i-b);
	}*/
		//p[i] = saturate_cast<uchar>((i>min(img,255)?1:0)*255/(max(img,1)-min(img,255))*(i-min(img,255)));

	Mat img2=Mat(img.rows,img.cols,img.type());
	LUT(img, lookUpTable, img2);
	namedWindow("原图", WINDOW_NORMAL);
	imshow("原图",img);
	namedWindow("对比度拉伸", WINDOW_NORMAL);
	imshow("对比度拉伸",img2);
	waitKey(0);
}
