#include <iostream>
#include "opencv2/opencv.hpp"
#include "c3.h"
using namespace std;
using namespace cv;

void f_3_14()
{
	Mat img=imread("/home/lsy/图片/DIP3E_Original_Images_CH03/Fig0314(a)(100-dollars).tif",0);
	int bit_1=1;int bit_2=2;int bit_3=4;int bit_4=8;
	int bit_5=16;int bit_6=32;int bit_7=64;int bit_8=128;

	Mat img1=Mat(img.size(),img.type());
	img1=img&(uchar)(bit_8+bit_7+bit_6+bit_5);



	imshow("原图",img);
	imshow("比特平面",img1);
	waitKey(0);
}
