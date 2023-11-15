#include "hazeremoval.h"
#include "opencv2/opencv.hpp"
#include <iostream>
#include <ctime>

using namespace cv;
using namespace std;
int main() {
	clock_t start, end;
	double cpu_time_used;
	start = clock();
	const char* img_path = "F:/photo/xam.jpg";
	Mat in_img = imread(img_path, cv::IMREAD_GRAYSCALE);
	imshow("int_img", in_img);
	Mat out_img(in_img.rows, in_img.cols, CV_8UC3);
	unsigned char* indata = in_img.data;
	unsigned char* outdata = out_img.data;

	CHazeRemoval hr;
	cout << hr.InitProc(in_img.cols, in_img.rows, in_img.channels()) << endl;
	cout << hr.Process(indata, outdata, in_img.cols, in_img.rows, in_img.channels()) << endl;
	cv::imwrite("F:/photo/ketqua/khu1.jpg", out_img);
	imshow("out_img", out_img);
	waitKey(0);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	std::cout << "CPU time: " << cpu_time_used << " s" << std::endl;

	return 0;
}