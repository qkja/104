//#include <opencv2/opencv.hpp>
//#include <iostream>

//int main() {
//    // ������ͷ������Ϊ����ͷ������һ������£�0��ʾĬ������ͷ
//    cv::VideoCapture cap(0);
//
//    // �������ͷ�Ƿ�ɹ���
//    if (!cap.isOpened()) {
//        std::cerr << "Error: Could not open camera." << std::endl;
//        return -1;
//    }
//
//    // ��������ͷ�Ŀ�Ⱥ͸߶�
//    cap.set(cv::CAP_PROP_FRAME_WIDTH, 6400);
//    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 4800);
//
//    // ��������������ʾ��Ƶ
//    cv::namedWindow("Camera", cv::WINDOW_NORMAL);
//
//    // ѭ����ȡ��Ƶ��֡
//    while (true)
//    {
//        // ��ȡһ֡
//        cv::Mat frame;
//        cap >> frame;
//
//        // ���֡�Ƿ�ɹ���ȡ
//        if (frame.empty()) {
//            std::cerr << "Error: Could not read frame." << std::endl;
//            break;
//        }
//
//        // �ڴ�������ʾ��ǰ֡
//        //cv::imshow("Camera", frame);
//        // �����������ǵ�,ȥʵʱ������ǵ�����ͷ,����ʹ�����ǵ� ����õ����ݼ�
//
//        
//        // ��ⰴ����������� 'q' �����˳�ѭ��
//        char key = cv::waitKey(1);
//        if (key == 'q' || key == 27) {  // 27 �� ESC ���� ASCII ֵ
//            break;
//        }
//    }
//
//    // �ͷ�����ͷ��Դ
//    cap.release();
//
//    // �ر���ʾ����
//    cv::destroyAllWindows();
//
//    return 0;
//}


//#include <opencv2/opencv.hpp>
//
//int main() {
//    // ��ȡͼ��
//    cv::Mat image = cv::imread("20231204162036.png");
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
//
//int main() {
//
//
//    // ������ͷ������Ϊ����ͷ������һ������£�0��ʾĬ������ͷ
//    cv::VideoCapture cap(0);
//
//    // �������ͷ�Ƿ�ɹ���
//    if (!cap.isOpened()) {
//        std::cerr << "Error: Could not open camera." << std::endl;
//        return -1;
//    }
//
//    // �������������
//    cv::CascadeClassifier faceCascade;
//    if (!faceCascade.load(cv::samples::findFile("haarcascades/haarcascade_frontalface_default.xml"))) {
//        std::cerr << "Error: Could not load face cascade." << std::endl;
//        return -1;
//    }
//
//    // ѭ����ȡ��Ƶ��֡
//    while (true)
//    {
//        // ��ȡһ֡
//        cv::Mat frame;
//        cap >> frame;
//
//        // ���֡�Ƿ�ɹ���ȡ
//        if (frame.empty()) {
//            std::cerr << "Error: Could not read frame." << std::endl;
//            break;
//        }
//
//        // ��ͼ��ת��Ϊ�Ҷ�ͼ
//        cv::Mat gray;
//        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
//
//        // �����������
//        std::vector<cv::Rect> faces;
//        faceCascade.detectMultiScale(gray, faces, 1.3, 5);
//
//        // ��ͼ���ϻ��Ƽ�⵽������
//        for (const auto& face : faces) {
//            cv::rectangle(frame, face, cv::Scalar(0, 255, 0), 2);
//        }
//
//        // ��ʾ�����������ͼ��
//        cv::imshow("Face Detection", frame);
//
//        // ��ⰴ����������� 'q' �����˳�ѭ��
//        char key = cv::waitKey(1);
//        if (key == 'q' || key == 27) {  // 27 �� ESC ���� ASCII ֵ
//            break;
//        }
//    }
//
//    // �ͷ�����ͷ��Դ
//    cap.release();
//
//    // �ر���ʾ����
//    cv::destroyAllWindows();
//
//    return 0;
//}

//
//#include <torch/script.h>
//#include <opencv2/opencv.hpp>

//int main() {
//    // �����豸
//    torch::Device device(torch::kCPU);
//    if (torch::cuda::is_available()) {
//        device = torch::Device(torch::kCUDA);
//    }
//
//    // ���� YOLOv5 ģ��
//    const std::string model_path = "path/to/your/yolov5/model.pt";
//    torch::jit::script::Module model = torch::jit::load(model_path);
//    model.to(device);
//
//    // ������ͷ������Ϊ����ͷ������һ������£�0��ʾĬ������ͷ
//    cv::VideoCapture cap(0);
//
//    // �������ͷ�Ƿ�ɹ���
//    if (!cap.isOpened()) {
//        std::cerr << "Error: Could not open camera." << std::endl;
//        return -1;
//    }
//
//    // ѭ����ȡ��Ƶ��֡
//    while (true) {
//        // ��ȡһ֡
//        cv::Mat frame;
//        cap >> frame;
//
//        // ���֡�Ƿ�ɹ���ȡ
//        if (frame.empty()) {
//            std::cerr << "Error: Could not read frame." << std::endl;
//            break;
//        }
//
//        // ��ͼ��ת��Ϊ Tensor
//        torch::Tensor tensor_image = torch::from_blob(frame.data, { 1, frame.rows, frame.cols, 3 }, torch::kByte);
//        tensor_image = tensor_image.permute({ 0, 3, 1, 2 }).to(torch::kFloat) / 255.0;
//        tensor_image = tensor_image.to(device);
//
//        // ģ������
//        std::vector<torch::jit::IValue> inputs;
//        inputs.emplace_back(tensor_image);
//        at::Tensor output = model.forward(inputs).toTensor();
//
//        // �������
//        auto result = output.squeeze().detach().to(torch::kCPU).numpy();
//        for (int i = 0; i < result.sizes()[0]; i += 7) {
//            float score = result[i + 4].item<float>();
//            int class_id = result[i + 5].item<int>();
//
//            // �����������ʱ�����Ʊ߿�
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
//        // ��ʾ�����������ͼ��
//        cv::imshow("YOLOv5 Face Detection", frame);
//
//        // ��ⰴ����������� 'q' �����˳�ѭ��
//        char key = cv::waitKey(1);
//        if (key == 'q' || key == 27) {  // 27 �� ESC ���� ASCII ֵ
//            break;
//        }
//    }
//
//    // �ͷ�����ͷ��Դ
//    cap.release();
//
//    // �ر���ʾ����
//    cv::destroyAllWindows();
//
//    return 0;
//}


//#include <opencv2/opencv.hpp>
//#include <torch/script.h>
//
//int main() {
//    // �����豸
//    torch::Device device(torch::kCPU);
//
//    // ���� YOLOv5 ģ��
//    const std::string model_path = "path/to/your/yolov5/model.pt";
//    torch::jit::script::Module model = torch::jit::load(model_path);
//    model.to(device);
//
//    // ������ͷ������Ϊ����ͷ������һ������£�0��ʾĬ������ͷ
//    cv::VideoCapture cap(0);
//
//    // �������ͷ�Ƿ�ɹ���
//    if (!cap.isOpened()) {
//        std::cerr << "Error: Could not open camera." << std::endl;
//        return -1;
//    }
//
//    // ѭ����ȡ��Ƶ��֡
//    while (true) {
//        // ��ȡһ֡
//        cv::Mat frame;
//        cap >> frame;
//
//        // ���֡�Ƿ�ɹ���ȡ
//        if (frame.empty()) {
//            std::cerr << "Error: Could not read frame." << std::endl;
//            break;
//        }
//
//        // ��ͼ��ת��Ϊ Tensor
//        torch::Tensor tensor_image = torch::from_blob(frame.data, { 1, frame.rows, frame.cols, 3 }, torch::kByte);
//        tensor_image = tensor_image.permute({ 0, 3, 1, 2 }).to(torch::kFloat) / 255.0;
//        tensor_image = tensor_image.to(device);
//
//        // ģ������
//        std::vector<torch::jit::IValue> inputs;
//        inputs.emplace_back(tensor_image);
//        //at::Tensor output = model.forward(inputs).toTensor();
//        torch::Tensor output = model.forward(inputs).toTensor();
//
//        // �������
//        auto result = output.squeeze().detach().to(torch::kCPU).numpy();
//        // ����� Tensor ת��Ϊ C++ ����
//        //auto result = output.squeeze().detach().to(torch::kCPU);
//
//        for (int i = 0; i < result.sizes()[0]; i += 7) {
//            float score = result[i + 4].item<float>();
//            int class_id = result[i + 5].item<int>();
//
//            // �����������ʱ�����Ʊ߿�
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
//        // ��ʾ�����������ͼ��
//        cv::imshow("YOLOv5 Face Detection", frame);
//
//        // ��ⰴ����������� 'q' �����˳�ѭ��
//        char key = cv::waitKey(1);
//        if (key == 'q' || key == 27) {  // 27 �� ESC ���� ASCII ֵ
//            break;
//        }
//    }
//
//    // �ͷ�����ͷ��Դ
//    cap.release();
//
//    // �ر���ʾ����
//    cv::destroyAllWindows();
//
//    return 0;
//}



//#include <opencv2/opencv.hpp>
//#include <torch/script.h>
//
//int main() {
//    // �����豸
//    torch::Device device(torch::kCPU);
//
//    // ���� YOLOv5 ģ��
//    const std::string model_path = "path/to/your/yolov5/model.pt";
//    torch::jit::script::Module model = torch::jit::load(model_path);
//    model.to(device);
//
//    // ������ͷ������Ϊ����ͷ������һ������£�0��ʾĬ������ͷ
//    cv::VideoCapture cap(0);
//
//    // �������ͷ�Ƿ�ɹ���
//    if (!cap.isOpened()) {
//        std::cerr << "Error: Could not open camera." << std::endl;
//        return -1;
//    }
//
//    // ѭ����ȡ��Ƶ��֡
//    while (true) {
//        // ��ȡһ֡
//        cv::Mat frame;
//        cap >> frame;
//
//        // ���֡�Ƿ�ɹ���ȡ
//        if (frame.empty()) {
//            std::cerr << "Error: Could not read frame." << std::endl;
//            break;
//        }
//
//        // ��ͼ��ת��Ϊ Tensor
//        torch::Tensor tensor_image = torch::from_blob(frame.data, { 1, frame.rows, frame.cols, 3 }, torch::kByte);
//        tensor_image = tensor_image.permute({ 0, 3, 1, 2 }).to(torch::kFloat) / 255.0;
//        tensor_image = tensor_image.to(device);
//
//        // ģ������
//        std::vector<torch::jit::IValue> inputs;
//        inputs.emplace_back(tensor_image);
//        at::Tensor output = model.forward(inputs).toTensor();
//
//        // �������
//        // ������������ģ��������д������������
//
//        // ��ʾ�����������ͼ��
//        cv::imshow("YOLOv5 Face Detection", frame);
//
//        // ��ⰴ����������� 'q' �����˳�ѭ��
//        char key = cv::waitKey(1);
//        if (key == 'q' || key == 27) {  // 27 �� ESC ���� ASCII ֵ
//            break;
//        }
//    }
//
//    // �ͷ�����ͷ��Դ
//    cap.release();
//
//    // �ر���ʾ����
//    cv::destroyAllWindows();
//
//    return 0;
//}

//#include <torch/script.h>
//#include <iostream>
//
//int main() {
//    // ����һ������
//    torch::Tensor tensor = torch::randn({ 3, 3 });
//
//    // ��ӡ����
//    std::cout << "Tensor: " << tensor << std::endl;
//
//    return 0;
//}
