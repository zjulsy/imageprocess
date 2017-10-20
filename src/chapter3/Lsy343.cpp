#include <iostream>
#include "opencv2/opencv.hpp"
#include "c3.h"
using namespace std;
using namespace cv;

void f_3_43()
{
	Mat img=imread("/home/lsy/图片/DIP3E_Original_Images_CH03/Fig0343(a)(skeleton_orig).tif",0);
	imshow("原图",img);
	Mat img1,abs_img1;
	Mat img2,img3;

	int ddepth = CV_16S;
	Laplacian( img, img1, ddepth);
	img.convertTo(img3,CV_16S);
	img2=img3-img1;
	Mat just_img2;
	convertScaleAbs( img2, just_img2 );
	convertScaleAbs( img1, abs_img1 );

	Mat imgx,imgy;
	Sobel( img, imgx, ddepth, 1, 0);
	Sobel( img, imgy, ddepth, 0, 1);
	Mat abs_grad_x,abs_grad_y,grad;
	convertScaleAbs( imgx, abs_grad_x );
	convertScaleAbs( imgy, abs_grad_y );
	addWeighted( abs_grad_x, 1, abs_grad_y, 1, 0, grad );

	Mat img4,imgmodel;
	Mat imgmul;
	blur(grad,img4,Size(5,5));
	int thresh;
	double max1,min1;
	minMaxLoc(img4,&min1,&max1);
	thresh=50;
	threshold(img4,imgmodel,thresh,1,cv::THRESH_BINARY);
	multiply(just_img2,imgmodel,imgmul);

    Mat imgf,imgfinal;
    imgf=imgmul+img;

    Mat lookUpTable(1, 256, CV_8U);
    uchar* p = lookUpTable.ptr();
    for( double i = 0; i < 256; i++)
    {
    		p[(int)i] =static_cast<uchar>(pow(i/255,0.5)*255);
    }

    LUT(imgf, lookUpTable, imgfinal);

	imshow("拉普拉斯滤波",just_img2);
	imshow("拉普拉斯绝对值",abs_img1);
	imshow("Sobel滤波",grad);
	imshow("平滑Sobel",img4);
	imshow("平滑Sobel * LPA",imgmul);
    imshow("Sobel+LAP锐化",imgf);
    imshow("幂函数增亮",imgfinal);
	waitKey(0);
}
