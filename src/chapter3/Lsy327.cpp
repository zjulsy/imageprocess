#include <iostream>
#include "opencv2/opencv.hpp"
#include "c3.h"
using namespace std;
using namespace cv;

void f_3_27()
{
	Mat img=imread("/home/lsy/图片/DIP3E_Original_Images_CH03/Fig0327(a)(tungsten_original).tif",0);

	Mat img1=Mat(img.size(),img.type());
	equalizeHist( img, img1 );

	Mat tmp_m, tmp_sd;
	//double average=mean(img)[0];
	meanStdDev(img, tmp_m, tmp_sd);

	double average = tmp_m.at<double>(0,0);
	double std = tmp_sd.at<double>(0,0);

	Mat img2=img.clone();
	Mat local(3,3,img.type());
	//Mat core(3,3,img.type());
	uchar * p;
	for(int i=1;i<img.rows-1;i++)
	{
		p=img2.ptr<uchar>(i);
		for(int j=1;j<img.cols-1;j++)
		{
			local=img(Range(i-1,i+1),Range(j-1,j+1));
			Mat tmp_m2, tmp_sd2;
			meanStdDev(img2, tmp_m2, tmp_sd2);
			double average2 = tmp_m2.at<double>(0,0);
			double std2 = tmp_sd2.at<double>(0,0);

			if((average2<= 0.4*average) && (0.02*std<= std2) && (std2 <=0.4*std))
			{
				p[j]=saturate_cast<uchar>(p[j]*4);
			}
			/*equalizeHist( local, core );
			p[j]=core.at<uchar>(1,1);*/
		}
	}
	namedWindow("原图", WINDOW_NORMAL);
	namedWindow("直方图均衡", WINDOW_NORMAL);
	namedWindow("使用直方图统计局部增强", WINDOW_NORMAL);
	imshow("原图",img);
	imshow("直方图均衡",img1);
	imshow("使用直方图统计局部增强",img2);
	waitKey(0);
}
