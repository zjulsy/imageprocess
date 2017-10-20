#include <iostream>
#include "opencv2/opencv.hpp"
#include "c3.h"
using namespace std;
using namespace cv;

void f_3_34()
{
	Mat img=imread("/home/lsy/图片/DIP3E_Original_Images_CH03/Fig0334(a)(hubble-original).tif",0);

	Mat img1=Mat(img.size(),img.type());
	Mat img2;
    double thresh = 100;
       int maxVal = 255;
	blur(img,img1,Size(15,15));
	threshold(img,img2,thresh,maxVal,cv::THRESH_BINARY);

	namedWindow("原图", WINDOW_NORMAL);
	namedWindow("均值滤波", WINDOW_NORMAL);
	namedWindow("阈值处理", WINDOW_NORMAL);
	imshow("原图",img);
	imshow("均值滤波",img1);
	imshow("阈值处理",img2);

	waitKey(0);
}
