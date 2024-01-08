#include <opencv2/opencv.hpp>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
using namespace cv;

//int main()
//{
//	string path = "1.png";
//	Mat img = imread(path);
//	Mat img32;
//	img.convertTo(img32, CV_32F, 1 / 255.0, 0);
//	/*Mat HSV;
//	Mat HSV32;*/
//	
//	/*cvtColor(img, HSV, COLOR_BGR2HSV);
//	cvtColor(img32, HSV32, COLOR_BGR2HSV);*/
//
//	Mat gray0, gray1;
//	cvtColor(img, gray0, COLOR_BGR2GRAY);
//	cvtColor(img32, gray1, COLOR_RGB2GRAY);
//
//
//	return 0;
//}

//int main()
//{
//	string path = "1.png";
//	Mat img = imread(path);
//
//	Mat imgs[3];
//	// 分离
//	split(img, imgs);
//	Mat img1 = imgs[0];
//	Mat img2 = imgs[1];
//	Mat img3 = imgs[2];
//
//	return 0;
//}

//int main()
//{
//	string path = "1.png";
//	Mat img = imread(path);
//
//	Mat imgs[3];
//	// 合并
//	split(img, imgs);
//	Mat img_copy;
//	merge(imgs, 3, img_copy);
//
//	return 0;
//}

void test01()
{
	Mat a = (Mat_<uchar>(1, 2) << 0, 5);
	Mat b = (Mat_<uchar>(1, 2) << 0, 6);

	cout << a << endl;
	cout << b << endl;


	cout << "=========== 矩阵 =====" << endl;

	Mat Xor, Or, Not, And;
	// 逻辑非
	bitwise_not(a, Not);
	/*bitwise_and(a, b, And);
	bitwise_or(a, b, Or);
	bitwise_xor(a, b, Xor);*/
	//cout << Xor << endl;
	//cout << Or << endl;
	cout << Not << endl;
	//cout << And << endl;
	cout << "=========== 图片 =====" << endl;


}
// LUT

void test02()
{
	// 第一层
	uchar lutfirst[256] = {0};
	for (int i = 0; i < sizeof(lutfirst) / sizeof(lutfirst[0]); i++)
	{
		if (i < 100) lutfirst[i] = 0;
		else if (i <= 200) lutfirst[i] = 100;
		else lutfirst[i] = 255;
	}

	Mat lutOne(1, 256, CV_8UC1, lutfirst);

	// 第二层
	uchar lutSecond[256] = { 0 };
	for (int i = 0; i < sizeof(lutSecond) / sizeof(lutSecond[0]); i++)
	{
		if (i <= 100) lutSecond[i] = 0;
		else if (i <= 150) lutSecond[i] = 100;
		else if (i <= 200) lutSecond[i] = 150;
		else lutSecond[i] = 255;
	}

	Mat lutTwo(1, 256, CV_8UC1, lutSecond);

	uchar lutThird[256] = { 0 };
	for (int i = 0; i < sizeof(lutThird) / sizeof(lutThird[0]); i++)
	{
		if (i <= 100) lutThird[i] = 1000;
		else if (i <= 200) lutThird[i] = 200;
		else lutThird[i] = 255;
	}

	Mat lutThree(1, 256, CV_8UC1, lutThird);


	vector<Mat> mergeMat;
}
//void test03()
//{
//	Mat 
//}

//int main()
//{
//	//test01();
//	test02();
//	return 0;
//}


// 图像的绘制, 在图片上面进行绘制