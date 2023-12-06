//#include <opencv2/opencv.hpp>
//#include <iostream>

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
//    // 设置摄像头的宽度和高度
//    cap.set(cv::CAP_PROP_FRAME_WIDTH, 6400);
//    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 4800);
//
//    // 创建窗口用于显示视频
//    cv::namedWindow("Camera", cv::WINDOW_NORMAL);
//
//    // 循环读取视频流帧
//    while (true)
//    {
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
//        // 在窗口中显示当前帧
//        //cv::imshow("Camera", frame);
//        // 在这里检测我们的,去实时监测我们的摄像头,这里使用我们的 处理好的数据集
//
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
//
//int main() {
//    // 读取图像
//    cv::Mat image = cv::imread("20231204162036.png");
//
//    // 检查图像是否成功读取
//    if (image.empty()) {
//        std::cerr << "Error: Could not open or find the image." << std::endl;
//        return -1;
//    }
//
//    // 加载人脸检测器模型（示例使用的是 OpenCV 自带的人脸检测器）
//    cv::CascadeClassifier faceCascade;
//    if (!faceCascade.load(cv::samples::findFile("haarcascades/haarcascade_frontalface_default.xml"))) {
//        std::cerr << "Error: Could not load face cascade." << std::endl;
//        return -1;
//    }
//
//    // 将图像转换为灰度图
//    cv::Mat gray;
//    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
//
//    // 进行人脸检测
//    std::vector<cv::Rect> faces;
//    faceCascade.detectMultiScale(gray, faces, 1.3, 5);
//
//    // 在图像上绘制检测到的人脸
//    for (const auto& face : faces) {
//        cv::rectangle(image, face, cv::Scalar(0, 255, 0), 2);
//    }
//
//    // 显示带有人脸框的图像
//    cv::imshow("Detected Faces", image);
//    cv::waitKey(0);
//
//    return 0;
//}




//#include <opencv2/opencv.hpp>
//
//int main() {
//
//
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
//    while (true)
//    {
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

//
//#include <torch/script.h>
//#include <opencv2/opencv.hpp>

//int main() {
//    // 设置设备
//    torch::Device device(torch::kCPU);
//    if (torch::cuda::is_available()) {
//        device = torch::Device(torch::kCUDA);
//    }
//
//    // 加载 YOLOv5 模型
//    const std::string model_path = "path/to/your/yolov5/model.pt";
//    torch::jit::script::Module model = torch::jit::load(model_path);
//    model.to(device);
//
//    // 打开摄像头，参数为摄像头索引，一般情况下，0表示默认摄像头
//    cv::VideoCapture cap(0);
//
//    // 检查摄像头是否成功打开
//    if (!cap.isOpened()) {
//        std::cerr << "Error: Could not open camera." << std::endl;
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
//        // 将图像转换为 Tensor
//        torch::Tensor tensor_image = torch::from_blob(frame.data, { 1, frame.rows, frame.cols, 3 }, torch::kByte);
//        tensor_image = tensor_image.permute({ 0, 3, 1, 2 }).to(torch::kFloat) / 255.0;
//        tensor_image = tensor_image.to(device);
//
//        // 模型推理
//        std::vector<torch::jit::IValue> inputs;
//        inputs.emplace_back(tensor_image);
//        at::Tensor output = model.forward(inputs).toTensor();
//
//        // 处理输出
//        auto result = output.squeeze().detach().to(torch::kCPU).numpy();
//        for (int i = 0; i < result.sizes()[0]; i += 7) {
//            float score = result[i + 4].item<float>();
//            int class_id = result[i + 5].item<int>();
//
//            // 当类别是人脸时，绘制边框
//            if (class_id == 0 && score > 0.5) {
//                int x = result[i + 0].item<int>();
//                int y = result[i + 1].item<int>();
//                int w = result[i + 2].item<int>();
//                int h = result[i + 3].item<int>();
//
//                cv::rectangle(frame, cv::Rect(x, y, w, h), cv::Scalar(0, 255, 0), 2);
//            }
//        }
//
//        // 显示带有人脸框的图像
//        cv::imshow("YOLOv5 Face Detection", frame);
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
//#include <torch/script.h>
//
//int main() {
//    // 设置设备
//    torch::Device device(torch::kCPU);
//
//    // 加载 YOLOv5 模型
//    const std::string model_path = "path/to/your/yolov5/model.pt";
//    torch::jit::script::Module model = torch::jit::load(model_path);
//    model.to(device);
//
//    // 打开摄像头，参数为摄像头索引，一般情况下，0表示默认摄像头
//    cv::VideoCapture cap(0);
//
//    // 检查摄像头是否成功打开
//    if (!cap.isOpened()) {
//        std::cerr << "Error: Could not open camera." << std::endl;
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
//        // 将图像转换为 Tensor
//        torch::Tensor tensor_image = torch::from_blob(frame.data, { 1, frame.rows, frame.cols, 3 }, torch::kByte);
//        tensor_image = tensor_image.permute({ 0, 3, 1, 2 }).to(torch::kFloat) / 255.0;
//        tensor_image = tensor_image.to(device);
//
//        // 模型推理
//        std::vector<torch::jit::IValue> inputs;
//        inputs.emplace_back(tensor_image);
//        //at::Tensor output = model.forward(inputs).toTensor();
//        torch::Tensor output = model.forward(inputs).toTensor();
//
//        // 处理输出
//        auto result = output.squeeze().detach().to(torch::kCPU).numpy();
//        // 将输出 Tensor 转换为 C++ 数组
//        //auto result = output.squeeze().detach().to(torch::kCPU);
//
//        for (int i = 0; i < result.sizes()[0]; i += 7) {
//            float score = result[i + 4].item<float>();
//            int class_id = result[i + 5].item<int>();
//
//            // 当类别是人脸时，绘制边框
//            if (class_id == 0 && score > 0.5) {
//                int x = result[i + 0].item<int>();
//                int y = result[i + 1].item<int>();
//                int w = result[i + 2].item<int>();
//                int h = result[i + 3].item<int>();
//
//                cv::rectangle(frame, cv::Rect(x, y, w, h), cv::Scalar(0, 255, 0), 2);
//            }
//        }
//
//        // 显示带有人脸框的图像
//        cv::imshow("YOLOv5 Face Detection", frame);
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
//#include <torch/script.h>
//
//int main() {
//    // 设置设备
//    torch::Device device(torch::kCPU);
//
//    // 加载 YOLOv5 模型
//    const std::string model_path = "path/to/your/yolov5/model.pt";
//    torch::jit::script::Module model = torch::jit::load(model_path);
//    model.to(device);
//
//    // 打开摄像头，参数为摄像头索引，一般情况下，0表示默认摄像头
//    cv::VideoCapture cap(0);
//
//    // 检查摄像头是否成功打开
//    if (!cap.isOpened()) {
//        std::cerr << "Error: Could not open camera." << std::endl;
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
//        // 将图像转换为 Tensor
//        torch::Tensor tensor_image = torch::from_blob(frame.data, { 1, frame.rows, frame.cols, 3 }, torch::kByte);
//        tensor_image = tensor_image.permute({ 0, 3, 1, 2 }).to(torch::kFloat) / 255.0;
//        tensor_image = tensor_image.to(device);
//
//        // 模型推理
//        std::vector<torch::jit::IValue> inputs;
//        inputs.emplace_back(tensor_image);
//        at::Tensor output = model.forward(inputs).toTensor();
//
//        // 处理输出
//        // 在这里根据你的模型输出进行处理，检测人脸等
//
//        // 显示带有人脸框的图像
//        cv::imshow("YOLOv5 Face Detection", frame);
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

//#include <torch/script.h>
//#include <iostream>
//
//int main() {
//    // 创建一个张量
//    torch::Tensor tensor = torch::randn({ 3, 3 });
//
//    // 打印张量
//    std::cout << "Tensor: " << tensor << std::endl;
//
//    return 0;
//}
