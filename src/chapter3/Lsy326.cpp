#include <iostream>
#include "opencv2/opencv.hpp"
#include "c3.h"
using namespace std;
using namespace cv;

void f_3_26()
{
	Mat img=imread("/home/lsy/图片/DIP3E_Original_Images_CH03/Fig0326(a)(embedded_square_noisy_512).tif",0);

	Mat img1=Mat(img.size(),img.type());
	equalizeHist( img, img1 );

	Mat img2=Mat(img.size(),img.type());
	Mat local(3,3,img.type());
	Mat core(3,3,img.type());
	uchar * p;
	for(int i=1;i<img.rows-1;i++)
	{
		p=img2.ptr<uchar>(i);
		for(int j=1;j<img.cols-1;j++)
		{
			local=img(Range(i-1,i+1),Range(j-1,j+1));
			equalizeHist( local, core );
			p[j]=core.at<uchar>(1,1);
		}
	}
	namedWindow("原图", WINDOW_NORMAL);
	namedWindow("直方图均衡", WINDOW_NORMAL);
	namedWindow("局部直方图均衡", WINDOW_NORMAL);
	imshow("原图",img);
	imshow("直方图均衡",img1);
	imshow("局部直方图均衡",img2);
	waitKey(0);
}
