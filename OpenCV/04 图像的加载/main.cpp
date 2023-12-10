//#include <opencv2/opencv.hpp>
//
//int main()
//{
//	cv::Mat img;
//	img = cv::imread("1.png", cv::IMREAD_COLOR);
//	cv::Mat gray = cv::imread("1.png", cv::IMREAD_GRAYSCALE);
//
//
//	// 自适应
//	cv::namedWindow("img_w", cv::WINDOW_AUTOSIZE);
//	cv::namedWindow("gray_w", cv::WINDOW_NORMAL);
//
//	cv::imshow("img_w", img);
//	cv::imshow("gray_w", gray);
//
//
//	// 为了避免一闪而过
//	cv::waitKey(0); 
//	/*std::cout << "1" << std::endl;*/
//
//	// 保存图像
//	//std::vector<int> compression_params;
//	//compression_params.push_back(cv::IMWRITE_JPEG_SAMPLING_FACTOR_444)
//	cv::imwrite("1.jpg", img);
//
//	return 0;
//}

//#include <opencv2/opencv.hpp>
//
//int main()
//{
//	cv::Mat img;
//	cv::Mat a = (cv::Mat_<int>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
//	
//	img = cv::imread("1.png", cv::IMREAD_COLOR);
//	cv::Mat gray = cv::imread("1.png", cv::IMREAD_GRAYSCALE);
//
//
//	// 自适应
//	cv::namedWindow("img_w", cv::WINDOW_AUTOSIZE);
//	cv::namedWindow("gray_w", cv::WINDOW_NORMAL);
//
//	cv::imshow("img_w", img);
//	cv::imshow("gray_w", gray);
//
//
//	// 为了避免一闪而过
//	cv::waitKey(0);
//	return 0;
//}



#include <opencv2/opencv.hpp>

int main()
{
	cv::VideoCapture video;
	video.open("./box.mp4");
	if (video.isOpened() == false)
	{
		std::cerr << "path error" << std::endl;
		return -1;
	}

	std::cout << "帧率: " << video.get(cv::CAP_PROP_FPS) << std::endl;
	std::cout << "宽度: " << video.get(cv::CAP_PROP_FRAME_WIDTH) << std::endl;
	std::cout << "高度: " << video.get(cv::CAP_PROP_FRAME_HEIGHT) << std::endl;


	while (true)
	{
		cv::Mat frame;
		video >> frame;
		if (frame.empty())
			break;
		cv::imshow("video", frame);
		//阻塞等待一会
		uchar c = cv::waitKey(100 / video.get(cv::CAP_PROP_FPS));
		if (c == 'q')
		{
			break;
		}
	}
	return 0;
}