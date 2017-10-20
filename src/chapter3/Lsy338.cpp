#include <iostream>
#include "opencv2/opencv.hpp"
#include "c3.h"
using namespace std;
using namespace cv;

void f_3_38()
{
	Mat img=imread("/home/lsy/图片/DIP3E_Original_Images_CH03/Fig0338(a)(blurry_moon).tif",0);

	Mat img1;
	Mat img2;
	Mat img3;

	int ddepth = CV_16S;
	Laplacian( img, img1, ddepth);
	img.convertTo(img3,CV_16S);
	img2=img3-img1;
	Mat just_img2;
	convertScaleAbs( img2, just_img2 );

	Mat abs_img1;
	convertScaleAbs( img1, abs_img1 );
	//Mat up_img1;
	//threshold(img1,up_img1,1,233,3);
	//Mat abs_up_img1;
	//convertScaleAbs( up_img1, abs_up_img1 );
	//img2=img-(char)abs_img1;

	//namedWindow("add处理", WINDOW_NORMAL);
	for(int i=0;i<img1.rows;++i)
	    {
	        for(int j=0;j<img1.cols;++j)
	        {
	            short data=img1.at<short>(i,j);
	            if(data<0)
	            img1.at<short>(i,j)=0;
	        }

	    }
	Mat up_img1;
	convertScaleAbs( img1,up_img1 );
	imshow("原图",img);
	imshow("拉普拉斯绝对值",abs_img1);
	imshow("拉普大于0取0",up_img1);
	imshow("书上的拉普拉斯锐化",just_img2);

	waitKey(0);
}
