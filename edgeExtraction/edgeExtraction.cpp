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
		cap >> srcMat;//捕捉当前帧
		Sobel(srcMat, dxMat, CV_16SC1, 1, 0, 3);//用Sobel算子提取x方向上边缘
		Sobel(srcMat, dyMat, CV_16SC1, 0, 1, 3);//用Sobel算子提取y方向上边缘
		cv::imshow("frame", srcMat);//显示原图像
		cv::imshow("x", dxMat);//显示提取x方向上边缘的图像
		cv::imshow("y", dyMat);//显示提取y方向上边缘的图像
		waitKey(30);
	}
}


