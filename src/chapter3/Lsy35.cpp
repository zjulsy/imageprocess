#include <iostream>
#include "opencv2/opencv.hpp"
#include "c3.h"
using namespace std;
using namespace cv;
//没有频率值。。。。
void f_3_5()
{
	Mat img=imread("/home/lsy/图片/DIP3E_Original_Images_CH03/Fig0305(a)(DFT_no_log).tif",0);

	Mat lookUpTable(1, 256, CV_32F);
	uchar* p = lookUpTable.ptr();
	for( int i = 0; i < 256; ++i)
	    p[i] =log10(1+i);

	Mat lookUpTable2(1,256,CV_8U);
	lookUpTable2=lookUpTable*255/cv::max(lookUpTable,1);

	Mat img2=Mat(img.rows,img.cols,img.type());
	LUT(img, lookUpTable2, img2);

	imshow("原图",img);
	imshow("对数变换",img2);
	waitKey(0);
}
