#include <iostream>
#include "opencv2/opencv.hpp"
#include "c3.h"
using namespace std;
using namespace cv;

void f_3_35()
{
	Mat img=imread("/home/lsy/图片/DIP3E_Original_Images_CH03/Fig0335(a)(ckt_board_saltpep_prob_pt05).tif",0);

	Mat img1=Mat(img.size(),img.type());
	Mat img2;

	blur(img,img1,Size(3,3));
	medianBlur(img,img2,3);

	namedWindow("原图", WINDOW_NORMAL);
	namedWindow("均值滤波", WINDOW_NORMAL);
	namedWindow("中值处理", WINDOW_NORMAL);
	imshow("原图",img);
	imshow("均值滤波",img1);
	imshow("中值处理",img2);

	waitKey(0);
}
