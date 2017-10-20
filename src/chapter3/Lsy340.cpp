#include <iostream>
#include "opencv2/opencv.hpp"
#include "c3.h"
using namespace std;
using namespace cv;

void f_3_40()
{
	Mat img=imread("/home/lsy/图片/DIP3E_Original_Images_CH03/Fig0340(a)(dipxe_text).tif",0);

	Mat img1;
	Mat img2;

	GaussianBlur(img,img1,Size(5,5),3,3);
	img2=img+1*(img-img1);


	imshow("原图",img);
	imshow("高斯滤波",img1);
	imshow("非锐化掩蔽模板",img-img1);
	imshow("非锐化掩蔽",img2);

	waitKey(0);
}
