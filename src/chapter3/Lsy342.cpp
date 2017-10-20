#include <iostream>
#include "opencv2/opencv.hpp"
#include "c3.h"
using namespace std;
using namespace cv;

void f_3_42()
{
	Mat img=imread("/home/lsy/图片/DIP3E_Original_Images_CH03/Fig0342(a)(contact_lens_original).tif",0);

	Mat img1;
	Mat img2;

	int ddepth = CV_16S;
	Sobel( img, img1, ddepth, 1, 0);
	Sobel( img, img2, ddepth, 0, 1);
	Mat abs_grad_x,abs_grad_y,grad;
	convertScaleAbs( img1, abs_grad_x );
	convertScaleAbs( img2, abs_grad_y );
	 addWeighted( abs_grad_x, 1, abs_grad_y, 1, 0, grad );

    namedWindow("原图",WINDOW_NORMAL);
    namedWindow("Sobel滤波",WINDOW_NORMAL);
	imshow("原图",img);
	imshow("Sobel滤波",grad);


	waitKey(0);
}
