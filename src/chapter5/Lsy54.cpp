
#include <iostream>
#include "opencv2/opencv.hpp"
#include "c5.h"
using namespace std;
using namespace cv;

void showhist(const Mat * imgs, const String & windowname)
{
	int histSize = 256;
	float range[] = { 0, 256 } ;
	const float* histRange = { range };
	Mat hist;
	bool uniform = true; bool accumulate = false;

	calcHist( imgs, 1, 0, Mat(), hist, 1, &histSize, &histRange, uniform, accumulate );

	int hist_w = 256; int hist_h = 400;
	int bin_w = cvRound( (double) hist_w/histSize );

	Mat histImage( hist_h, hist_w, CV_8U, Scalar(0));
	normalize(hist, hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );

	 for( int i = 1; i < histSize; i++ )
	  {
	      line( histImage, Point( bin_w*(i-1), hist_h - cvRound(hist.at<float>(i-1)) ) ,
	                       Point( bin_w*(i), hist_h - cvRound(hist.at<float>(i)) ),
	                       Scalar( 255, 0, 0), 2, 8, 0  );
	  }

	 imshow(windowname, histImage );
	 waitKey(0);
}

void f5_4()
{
	Mat img=imread("/home/lsy/图片/DIP3E_CH05_Original_Images/Fig0503 (original_pattern).tif",0);
	Mat noise(img.size(),img.type());
	randn(noise,0,6);

	imshow("原图",img);
	showhist(&img, "原图直方图");
	imshow("高斯噪声",img+noise);
	Mat gaussimg=img+noise;
	showhist(&gaussimg, "高斯噪声直方图");
}



