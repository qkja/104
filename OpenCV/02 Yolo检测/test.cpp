#include<torch/torch.h>
#include<torch/script.h>
#include<iostream>


//int main() {
//
//	std::cout << "cuda::is_available():" << torch::cuda::is_available() << std::endl;
//	std::cout << "torch::cuda::cudnn_is_available():" << torch::cuda::cudnn_is_available() << std::endl;
//	std::cout << "torch::cuda::device_count():" << torch::cuda::device_count() << std::endl;
//
//	torch::Device device(torch::kCUDA);
//	torch::Tensor tensor1 = torch::eye(3); // (A) tensor-cpu
//	torch::Tensor tensor2 = torch::eye(3, device); // (B) tensor-cuda
//	std::cout << tensor1 << std::endl;
//	std::cout << tensor2 << std::endl;
//}

//#include <iostream>
//
//#include <torch/torch.h>
//#include <ATen/ATen.h>
//#include <torch/script.h>
//
//int main()
//{
//    torch::Tensor tensor = torch::rand({ 5,3 });
//    std::cout << tensor << std::endl;
//    std::cout << torch::cuda::is_available() << std::endl; // 测试CUDA是否可用
//    std::cout << torch::cuda::cudnn_is_available() << std::endl; // 测试CUDNN是否可用
//}

//#include<torch/torch.h>
//#include<torch/script.h>
//#include<iostream>
//
//
//int main() {
//
//	std::cout << "cuda::is_available():" << torch::cuda::is_available() << std::endl;
//	std::cout << "torch::cuda::cudnn_is_available():" << torch::cuda::cudnn_is_available() << std::endl;
//	std::cout << "torch::cuda::device_count():" << torch::cuda::device_count() << std::endl;
//
//	torch::Device device(torch::kCUDA);
//	torch::Tensor tensor1 = torch::eye(3); // (A) tensor-cpu
//	torch::Tensor tensor2 = torch::eye(3, device); // (B) tensor-cuda
//	std::cout << tensor1 << std::endl;
//	std::cout << tensor2 << std::endl;
//}


//#include<opencv2/core/core.hpp>
//#include<opencv2/highgui/highgui.hpp>
//#include<opencv2/imgproc.hpp>
//
//int main()
//{
//	printf("hello");
//	return 0;
//}

//#include <opencv2/opencv.hpp>
//
//int main() {
//    // 打开摄像头，参数为摄像头索引，一般情况下，0表示默认摄像头
//    cv::VideoCapture cap(0);
//
//    // 检查摄像头是否成功打开
//    if (!cap.isOpened()) {
//        std::cerr << "Error: Could not open camera." << std::endl;
//        return -1;
//    }
//
//    // 创建人脸检测器
//    cv::CascadeClassifier faceCascade;
//    if (!faceCascade.load(cv::samples::findFile("haarcascades/haarcascade_frontalface_default.xml"))) {
//        std::cerr << "Error: Could not load face cascade." << std::endl;
//        return -1;
//    }
//
//    // 循环读取视频流帧
//    while (true) {
//        // 读取一帧
//        cv::Mat frame;
//        cap >> frame;
//
//        // 检查帧是否成功读取
//        if (frame.empty()) {
//            std::cerr << "Error: Could not read frame." << std::endl;
//            break;
//        }
//
//        // 将图像转换为灰度图
//        cv::Mat gray;
//        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
//
//        // 进行人脸检测
//        std::vector<cv::Rect> faces;
//        faceCascade.detectMultiScale(gray, faces, 1.3, 5);
//
//        // 在图像上绘制检测到的人脸
//        for (const auto& face : faces) {
//            cv::rectangle(frame, face, cv::Scalar(0, 255, 0), 2);
//        }
//
//        // 显示带有人脸框的图像
//        cv::imshow("Face Detection", frame);
//
//        // 检测按键，如果按下 'q' 键则退出循环
//        char key = cv::waitKey(1);
//        if (key == 'q' || key == 27) {  // 27 是 ESC 键的 ASCII 值
//            break;
//        }
//    }
//
//    // 释放摄像头资源
//    cap.release();
//
//    // 关闭显示窗口
//    cv::destroyAllWindows();
//
//    return 0;
//}


//#include <opencv2/opencv.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//
//int main() {
//    // 加载人脸检测器（Haar 级联分类器）
//    cv::CascadeClassifier faceCascade;
//    if (!faceCascade.load("haarcascade_frontalface_default.xml")) {
//        std::cerr << "Error loading face cascade.\n";
//        return -1;
//    }
//
//    // 读取图像
//    cv::Mat image = cv::imread("1.png");
//    if (image.empty()) {
//        std::cerr << "Error loading image.\n";
//        return -1;
//    }
//
//    // 转换图像为灰度
//    cv::Mat gray;
//    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
//
//    // 进行人脸检测
//    std::vector<cv::Rect> faces;
//    faceCascade.detectMultiScale(gray, faces, 1.1, 3, 0, cv::Size(30, 30));
//
//    // 在图像上绘制人脸框
//    for (const auto& face : faces) {
//        cv::rectangle(image, face, cv::Scalar(0, 255, 0), 2);
//    }
//
//    // 显示结果
//    cv::imshow("Face Detection", image);
//    cv::waitKey(0);
//
//    return 0;
//}

//#include <opencv2/opencv.hpp>
//
//int main() {
//    // ��ȡͼ��
//    cv::Mat image = cv::imread("1.png");
//
//    // ���ͼ���Ƿ�ɹ���ȡ
//    if (image.empty()) {
//        std::cerr << "Error: Could not open or find the image." << std::endl;
//        return -1;
//    }
//
//    // �������������ģ�ͣ�ʾ��ʹ�õ��� OpenCV �Դ��������������
//    cv::CascadeClassifier faceCascade;
//    if (!faceCascade.load(cv::samples::findFile("haarcascades/haarcascade_frontalface_default.xml"))) {
//        std::cerr << "Error: Could not load face cascade." << std::endl;
//        return -1;
//    }
//
//    // ��ͼ��ת��Ϊ�Ҷ�ͼ
//    cv::Mat gray;
//    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
//
//    // �����������
//    std::vector<cv::Rect> faces;
//    faceCascade.detectMultiScale(gray, faces, 1.3, 5);
//
//    // ��ͼ���ϻ��Ƽ�⵽������
//    for (const auto& face : faces) {
//        cv::rectangle(image, face, cv::Scalar(0, 255, 0), 2);
//    }
//
//    // ��ʾ�����������ͼ��
//    cv::imshow("Detected Faces", image);
//    cv::waitKey(0);
//
//    return 0;
//}


//#include <opencv2/opencv.hpp>
//#include <torch/torch.h>
//
//int main() {
//    // 加载 YOLOv5 模型
//    torch::jit::script::Module model = torch::jit::load("yolov5s.pt");
//    model.to(torch::kCPU);
//
//    // 读取图像
//    cv::Mat image = cv::imread("1.jpg");
//    if (image.empty()) {
//        std::cerr << "Error loading image.\n";
//        return -1;
//    }
//
//    // 预处理图像，将其转换为 Torch 的张量
//    cv::Mat inputBlob;
//    cv::cvtColor(image, inputBlob, cv::COLOR_BGR2RGB);
//    torch::Tensor inputTensor = torch::from_blob(inputBlob.data, { 1, inputBlob.rows, inputBlob.cols, 3 }, torch::kByte);
//    inputTensor = inputTensor.permute({ 0, 3, 1, 2 });
//    inputTensor = inputTensor.to(torch::kFloat) / 255.0;
//
//    // 运行 YOLOv5 模型
//    std::vector<torch::jit::IValue> inputs;
//    inputs.push_back(inputTensor);
//    auto output = model.forward(inputs).toTensor();
//
//    // 后处理输出，处理检测框等信息
//    // TODO: 在这里添加后处理逻辑
//
//    // 显示结果
//    cv::imshow("YOLOv5 Detection", image);
//    cv::waitKey(0);
//
//    return 0;
//}


//#include <opencv2/opencv.hpp>
//#include <torch/torch.h>
//
//int main() {
//    // 设置设备为 GPU（如果可用的话）
//    torch::Device device(torch::cuda::is_available() ? torch::kCUDA : torch::kCPU);
//
//    // 加载 YOLOv5 模型
//    torch::jit::script::Module model = torch::jit::load("best.torchscript.pt");
//    model.to(device);
//
//    // 读取图像
//    cv::Mat image = cv::imread("1.png");
//    if (image.empty()) {
//        std::cerr << "Error loading image.\n";
//        return -1;
//    }
//
//    // 预处理图像，将其转换为 Torch 的张量
//    cv::Mat inputBlob;
//    cv::cvtColor(image, inputBlob, cv::COLOR_BGR2RGB);
//    torch::Tensor inputTensor = torch::from_blob(inputBlob.data, { 1, inputBlob.rows, inputBlob.cols, 3 }, torch::kByte);
//    inputTensor = inputTensor.permute({ 0, 3, 1, 2 });
//    inputTensor = inputTensor.to(torch::kFloat) / 255.0;
//    inputTensor = inputTensor.to(device);
//
//    // 运行 YOLOv5 模型
//    std::vector<torch::jit::IValue> inputs;
//    inputs.push_back(inputTensor);
//    auto output = model.forward(inputs).toTensor();
//
//    // 后处理输出，处理检测框等信息
//    // TODO: 在这里添加后处理逻辑
//
//    // 将结果移回 CPU（如果运行在 GPU 上）并转换为 OpenCV 格式
//    output = output.to(torch::kCPU);
//    output = output.squeeze();
//    auto result = output.accessor<float, 2>();
//
//    // 显示结果
//    // TODO: 在这里添加显示逻辑
//
//    cv::imshow("YOLOv5 Detection", image);
//    cv::waitKey(0);
//
//    return 0;
//}


//#include <opencv2/opencv.hpp>
//#include <torch/torch.h>
//
//int main() {
//    // 设置设备为 GPU（如果可用的话）
//    torch::Device device(torch::cuda::is_available() ? torch::kCUDA : torch::kCPU);
//    std::cout << "Model output shape: 1" << std::endl;
//
//    // 加载 YOLOv5 模型
//    torch::jit::script::Module model = torch::jit::load("best.torchscript.pt");
//    model.to(device);
//    std::cout << "Model output shape: 2" << std::endl;
//
//    // 读取图像
//    cv::Mat image = cv::imread("1.png");
//    if (image.empty()) {
//        std::cerr << "Error loading image.\n";
//        return -1;
//    }
//    std::cout << "Model output shape: 3" << std::endl;
//
//    // 预处理图像，将其转换为 Torch 的张量
//    cv::Mat inputBlob;
//    cv::cvtColor(image, inputBlob, cv::COLOR_BGR2RGB);
//    torch::Tensor inputTensor = torch::from_blob(inputBlob.data, { 1, inputBlob.rows, inputBlob.cols, 3 }, torch::kByte);
//    inputTensor = inputTensor.permute({ 0, 3, 1, 2 });
//    inputTensor = inputTensor.to(torch::kFloat) / 255.0;
//    inputTensor = inputTensor.to(device);
//    std::cout << "Model output shape: 4" << std::endl;
//
//    // 运行 YOLOv5 模型
//    std::vector<torch::jit::IValue> inputs;
//    inputs.push_back(inputTensor);
//    //std::cout << "Model output shape: 6" << std::endl;
//    //std::cout << "Input shape: " << inputs.sizes() << std::endl;
//
//    auto output = model.forward(inputs).toTensor();
//    std::cout << "Model output shape: 7" << std::endl;
//
//    std::cout << "Model output shape: 5" << std::endl;
//
//    // 后处理输出，处理检测框等信息
//    // TODO: 在这里添加后处理逻辑
//
//    // 将结果移回 CPU（如果运行在 GPU 上）并转换为 OpenCV 格式
//    output = output.to(torch::kCPU);
//    output = output.squeeze();
//    auto result = output.accessor<float, 2>();
//
//    // 显示结果
//    // TODO: 在这里添加显示逻辑
//
//    cv::imshow("YOLOv5 Detection", image);
//    cv::waitKey(0);
//
//    return 0;
//}
