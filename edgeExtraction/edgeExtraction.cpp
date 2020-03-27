#include <iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	VideoCapture cap(0);//调用摄像头
	while (1)
	{
		cv::Mat srcMat;
		cv::Mat dxMat;
		cv::Mat dyMat;
		cv::Mat abs_dxMat;
		cv::Mat abs_dyMat;
		cap >> srcMat;//捕捉当前帧
		Sobel(srcMat, dxMat, CV_16SC1, 1, 0, 3);//用Sobel算子提取x方向上边缘
		convertScaleAbs(dxMat, abs_dxMat);
		Sobel(srcMat, dyMat, CV_16SC1, 0, 1, 3);//用Sobel算子提取y方向上边缘
		convertScaleAbs(dyMat, abs_dyMat);
		cv::imshow("frame", srcMat);//显示原图像
		cv::imshow("x", abs_dxMat);//显示提取x方向上边缘的图像
		cv::imshow("y", abs_dyMat);//显示提取y方向上边缘的图像
		convertScaleAbs;
		waitKey(30);
	}
}


