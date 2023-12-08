#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
  cv::Mat a = (cv::Mat_<int>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
  cv::Mat b = (cv::Mat_<int>(3, 3) << 1, 2, 3, 7, 8, 9, 4, 5, 6);
  cv::Mat c = (cv::Mat_<double>(3, 3) << 1.0, 2.1, 3.2, 4.3, 5.4, 6.5, 7.6, 8.7, 9.8);
  cv::Mat d = (cv::Mat_<double>(3, 3) << 1.0, 2.1, 3.2, 4.3, 5.4, 6.5, 7.6, 8.7, 9.8);

  std::cout << "两个矩阵的和 " << std::endl
            << a + b << std::endl;
  std::cout << "两个矩阵的差 " << std::endl
            << a - b << std::endl;
  std::cout << "矩阵的数乘 " << std::endl
            << a * 2 << std::endl;
  std::cout << "矩阵的数除 " << std::endl
            << d / 2.0 << std::endl;

  std::cout << "两个矩阵乘积 " << std::endl
            << c * d << std::endl;

  std::cout << "两个矩阵内积 " << std::endl
            << a.dot(b) << std::endl;
  std::cout << "两个矩阵对应位相乘 " << std::endl
            << a.mul(b) << std::endl;
  std::cout << "两个矩阵最小值 " << std::endl
            << min(a, b) << std::endl;
  return 0;
}
// int main()
// {
//   cv::Mat a = (cv::Mat_<int>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
//   cv::Mat c0(5, 5, CV_8UC1, cv::Scalar(4, 5, 6));
//   cv::Mat c1(5, 5, CV_8UC2, cv::Scalar(4, 5, 6));
//   cv::Mat c2(5, 5, CV_8UC3, cv::Scalar(4, 5, 6));
//   // a 是单通道的
//   std::cout << a.at<int>(0, 0) << std::endl;
//   cv::Vec2b vc = c1.at<cv::Vec2b>(0, 1);
//   std::cout << vc << std::endl;
//   std::cout << (int)vc[0] << std::endl;

//   std::cout << (double)(*(c2.data + c2.step[0] * 2 + c2.step[1] * 2 + 4)) << std::endl;
//   std::cout << vc[1] << std::endl;

//   return 0;
// }
// int main()
// {
//   cv::Mat a = (cv::Mat_<int>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
//   cv::Mat c0(5, 5, CV_8UC1, cv::Scalar(4, 5, 6));
//   cv::Mat c1(5, 5, CV_8UC2, cv::Scalar(4, 5, 6));
//   cv::Mat c2(5, 5, CV_8UC3, cv::Scalar(4, 5, 6));

//   std::cout << a << std::endl;
//   return 0;
// }

// #include <iostream>
// #include <opencv2/opencv.hpp>
// using namespace std;
//
//
// int main()
//{
//     cv::Mat image;
//     image = cv::imread("./1.png");
//     if (image.empty()) {
//         cout << "Error! Input image cannot be read...\n";
//         return -1;
//     }
//     cv::imshow("test", image);
//     cv::waitKey(0);
//     return 0;
// }

// #include "opencv2/core/utility.hpp"
// #include "opencv2/imgproc.hpp"
// #include "opencv2/imgcodecs.hpp"
// #include "opencv2/highgui.hpp"
//
// #include <stdio.h>
//
// using namespace cv;
// using namespace std;
//
// int edgeThresh = 1;
// int edgeThreshScharr = 1;
//
// Mat image, gray, blurImage, edge1, edge2, cedge;
//
// const char *window_name1 = "Edge map : Canny default (Sobel gradient)";
// const char *window_name2 = "Edge map : Canny with custom gradient (Scharr)";
//
//// define a trackbar callback
// static void onTrackbar(int, void *)
//{
//     blur(gray, blurImage, Size(3, 3));
//
//     // Run the edge detector on grayscale
//     Canny(blurImage, edge1, edgeThresh, edgeThresh * 3, 3);
//     cedge = Scalar::all(0);
//
//     image.copyTo(cedge, edge1);
//     imshow(window_name1, cedge);
//
//     /// Canny detector with scharr
//     Mat dx, dy;
//     Scharr(blurImage, dx, CV_16S, 1, 0);
//     Scharr(blurImage, dy, CV_16S, 0, 1);
//     Canny(dx, dy, edge2, edgeThreshScharr, edgeThreshScharr * 3);
//     /// Using Canny's output as a mask, we display our result
//     cedge = Scalar::all(0);
//     image.copyTo(cedge, edge2);
//     imshow(window_name2, cedge);
// }
//
// static void help(const char **argv)
//{
//     printf("\nThis sample demonstrates Canny edge detection\n"
//            "Call:\n"
//            "    %s [image_name -- Default is fruits.jpg]\n\n",
//            argv[0]);
// }
//
// const char *keys =
//     {
//         "{help h||}{@image |fruits.jpg|input image name}"};
//
// int main(int argc, const char **argv)
//{
//
//     help(argv);
//     CommandLineParser parser(argc, argv, keys);
//     string filename = parser.get<string>(0);
//
//     image = imread(samples::findFile(filename), IMREAD_COLOR);
//     if (image.empty())
//     {
//         printf("Cannot read image file: %s\n", filename.c_str());
//         // help(argv);
//         return -1;
//     }
//     cedge.create(image.size(), image.type());
//     cvtColor(image, gray, COLOR_BGR2GRAY);
//
//     // Create a window
//     namedWindow(window_name1, 1);
//     namedWindow(window_name2, 1);
//
//     // create a toolbar
//     createTrackbar("Canny threshold default", window_name1, &edgeThresh, 100, onTrackbar);
//     createTrackbar("Canny threshold Scharr", window_name2, &edgeThreshScharr, 400, onTrackbar);
//
//     // Show the image
//     onTrackbar(0, 0);
//
//     // Wait for a key stroke; the same function arranges events processing
//     waitKey(0);
//
//     return 0;
// }

// #include <opencv2/opencv.hpp>
// #include <stdio.h>
// #include <iostream>
//
// int main()
//{
//	//system("color F0");
//
//	cv::Mat a(3, 3, CV_8UC1);
//	cv::Mat b(cv::Size(4, 4), CV_8UC1);
//
//
//	cv::Mat c0(5, 5, CV_8UC1, cv::Scalar(4, 5, 6));
//	cv::Mat c1(5, 5, CV_8UC2, cv::Scalar(4, 5, 6));
//	cv::Mat c2(5, 5, CV_8UC3, cv::Scalar(4, 5, 6));
//
//
//	cv::Mat d = (cv::Mat_<int>(1, 5) << 1, 2, 3, 4, 5);
//
//	cv::Mat e = cv::Mat::diag(d);
//	cv::Mat f = cv::Mat(e, cv::Range(2, 4), cv::Range(2, 4));
//
//	std::cout << c0 << std::endl;
//	std::cout << c1 << std::endl;
//	std::cout << c2 << std::endl;
//
//	std::cout << d << std::endl;
//	std::cout << e << std::endl;
//	std::cout << f << std::endl;
//	return 0;
// }
