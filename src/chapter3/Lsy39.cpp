#include <iostream>
#include "opencv2/opencv.hpp"
#include "c3.h"
using namespace std;
using namespace cv;
//没有频率值。。。。
void f_3_9()
{
	Mat img=imread("/home/lsy/图片/DIP3E_Original_Images_CH03/Fig0309(a)(washed_out_aerial_image).tif",0);

	Mat lookUpTable(1, 256, CV_8U);
	Mat lookUpTable2(1, 256, CV_8U);
	Mat lookUpTable3(1, 256, CV_8U);
	uchar* p = lookUpTable.ptr();
	uchar* p2 = lookUpTable2.ptr();
	uchar* p3 = lookUpTable3.ptr();
	for( double i = 0; i < 256; i++)
	{

		p[(int)i] =static_cast<uchar>(pow(i/255,3)*255);
		p2[(int)i] =static_cast<uchar>(pow(i/255,4)*255);
		p3[(int)i] =static_cast<uchar>(pow(i/255,5)*255);
	}
	//cout<< lookUpTable<<endl;




	Mat img2=Mat(img.rows,img.cols,img.type());
	Mat img3=Mat(img.rows,img.cols,img.type());
	Mat img4=Mat(img.rows,img.cols,img.type());
	LUT(img, lookUpTable, img2);
	LUT(img, lookUpTable2, img3);
	LUT(img, lookUpTable3, img4);

	imshow("原图",img);
	imshow("伽马3",img2);
	imshow("伽马4",img3);
	imshow("伽马5",img4);
	waitKey(0);
}
