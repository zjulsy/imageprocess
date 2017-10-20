#include <iostream>
#include "opencv2/opencv.hpp"
#include "c4.h"
using namespace std;
using namespace cv;

void f4_42()
{
	Mat I=imread("/home/lsy/图片/DIP3E_Original_Images_CH04/Fig0442(a)(characters_test_pattern).tif",0);
	Mat padded;                            //expand input image to optimal size

	int m = getOptimalDFTSize( I.rows );
	int n = getOptimalDFTSize( I.cols ); // on the border add zero values
	copyMakeBorder(I, padded, 0, m - I.rows, 0, n - I.cols, BORDER_CONSTANT, Scalar::all(0));

	 Mat planes[] = {Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F)};
	 Mat complexI;
	 merge(planes, 2, complexI);         // Add to the expanded another plane with zeros
	 dft(complexI, complexI);

	 //正变换过后，先对频谱图进行中心平移
	 complexI = complexI(Rect(0, 0, complexI.cols & -2, complexI.rows & -2));

	    int cx = complexI.cols/2;
	    int cy = complexI.rows/2;
	    // rearrange the quadrants of Fourier image
	    // so that the origin is at the image center
	    Mat tmp;
	    Mat q0(complexI, Rect(0, 0, cx, cy));
	    Mat q1(complexI, Rect(cx, 0, cx, cy));
	    Mat q2(complexI, Rect(0, cy, cx, cy));
	    Mat q3(complexI, Rect(cx, cy, cx, cy));
	    q0.copyTo(tmp);
	    q3.copyTo(q0);
	    tmp.copyTo(q3);

	    q1.copyTo(tmp);
	    q2.copyTo(q1);
	    tmp.copyTo(q2);
	    //将得到的频谱图分解成虚部和实部两部分
	    split(complexI,planes);
	    Mat Proc_RE = planes[0];
	    Mat Proc_IM = planes[1];

	    for( int i = 0; i < Proc_RE.rows; ++i )
	           for( int j = 0; j < Proc_RE.cols; ++j )
	           {
	        	   double dx = i - Proc_RE.rows/2;
	        	   double dy = j - Proc_RE.cols/2;
	        	   double d=(dx*dx+dy*dy);
	               if(d>60*60)
	               {
	                   Proc_RE.at<float>(i, j)=0;
	                   Proc_IM.at<float>(i, j)=0;
	               }
	           }

	    //将处理后的虚部和实部矩阵合成一个矩阵，并进行中心平移，还原回（0，2π）的图像
	       merge(planes, 2, complexI);
	       q0.copyTo(tmp);
	       q3.copyTo(q0);
	       tmp.copyTo(q3);

	       q1.copyTo(tmp);
	       q2.copyTo(q1);
	       tmp.copyTo(q2);
	       //进行逆变换，归一化，并将尺寸调整为处理前的图像尺寸
	       idft(complexI, complexI,  DFT_SCALE | DFT_REAL_OUTPUT);//1

	       Mat imp = complexI;
	           normalize(imp, imp, 0, 255, CV_MINMAX);
	           imp.convertTo(imp, CV_8U);
	           Mat Output = imp(Range(0, I.rows), Range(0, I.cols));
	           imshow("Output",Output);
	           waitKey(0);
}
