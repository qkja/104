// 下面为进行检测的C++ 代码

//     分别对摄像头、单张图像以及文件夹图像进行检测，摄像头和单张图像检测代码以注释掉了，然后读取文件夹中所有图像进行检测后的结果以原图像名称进行保存：

//#include "util.hpp"
//#include "yolo.hpp"
//int main()
//{
//    if (!isReady())
//    {
//        std::cerr << "cuda 和 cudnn 没有准备好" << std::endl;
//        return -1;
//    }
//
//    // set up threshold
//
//    system("pause");
//    return 0;
//}

//#include <torch/script.h>
//#include <opencv2/opencv.hpp>
//
//int main() {
//    // 加载模型
//    torch::jit::script::Module module = torch::jit::load("best.torchscript.pt");
//
//    // 加载图像
//    cv::Mat image = cv::imread("1.png");
//
//    // 将图像转换为Tensor
//    cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
//    torch::Tensor tensor_image = torch::from_blob(image.data, { 1, image.rows, image.cols, 3 }, torch::kByte);
//    tensor_image = tensor_image.permute({ 0, 3, 1, 2 });
//    tensor_image = tensor_image.to(torch::kFloat);
//    tensor_image /= 255.0;
//
//    // 进行推理
//    std::vector<torch::jit::IValue> inputs;
//    inputs.push_back(tensor_image);
//    at::Tensor output = module.forward(inputs).toTensor();
//
//    // 处理输出
//    std::cout << output.slice(/*dim=*/1, /*start=*/0, /*end=*/5) << '\n';
//
//    return 0;
//}
//#include <torch/script.h>
//
//#include <memory>
//#include <assert.h>
//#include <string>
//#include <torch/torch.h>
//#include <opencv2/opencv.hpp>
//#include <torch/script.h> // One-stop header.
//#include <iostream>
//#include <memory>
//int main() {
//	 Deserialize the ScriptModule from a file using torch::jit::load().
//	std::shared_ptr<torch::jit::script::Module> module = torch::jit::load("yolov5s.pt");
//
//	assert(module != nullptr);
//	std::cout << "ok\n";
//	std::cout << module << '\n';
//	 Create a vector of inputs.
//	std::vector<torch::jit::IValue> inputs;
//	inputs.push_back(torch::ones({ 1, 3, 224, 224 }));
//
//	 Execute the model and turn its output into a tensor.
//	at::Tensor output = module->forward(inputs).toTensor();
//
//	std::cout << output.slice(1, 0, 5) << '\n';
//	while (1);
//}
//

//#include <iostream>
//#include <torch/script.h> // One-stop header.
//#include <torch/torch.h>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/highgui.hpp>
//
//
//using namespace cv;
//int main(int argc, const char* argv[]) {
//	//std::cout << "OpenCV version : " << CV_VERSION << std::endl;
//	Mat image;
//	image = imread("../img_1.jpg", IMREAD_GRAYSCALE);
//
//	imshow("Display window", image);
//	waitKey(20);
//	// Deserialize the ScriptModule from a file using torch::jit::load().
//	torch::jit::script::Module module = torch::jit::load("../model_trace.pt");
//
//	std::vector<int64_t> sizes = { 1, 1, image.rows, image.cols };
//	at::TensorOptions options(at::ScalarType::Byte);
//	at::Tensor tensor_image = torch::from_blob(image.data, at::IntList(sizes), options);
//	tensor_image = tensor_image.toType(at::kFloat);
//	at::Tensor result = module.forward({ tensor_image }).toTensor();
//
//	auto max_result = result.max(1, true);
//	auto max_index = std::get<1>(max_result).item<float>();
//	std::cout << max_index << std::endl;
//	system("pause");
//	return 0;
//


#include <torch/script.h>
#include <iostream>
#include <memory>
#include <torch/torch.h>

//int main() {
//	auto device = torch::kCPU;
//	// Deserialize the ScriptModule from a file using torch::jit::load().
//	torch::jit::script::Module module = torch::jit::load("best.torchscript.pt", device);
//
//	assert(module != nullptr);
//	std::cout << "ok\n";
//	// Create a vector of inputs.
//	std::vector<torch::jit::IValue> inputs;
//	inputs.push_back(torch::ones({ 1,3,320,192 }));
//
//	// Execute the model and turn its output into a tensor.
//	auto o = module.forward(std::move(inputs));
//	at::Tensor output = o.toTensor();
//
//	std::cout << output.slice(/*dim=*/1, /*start=*/0, /*end=*/5) << '\n';
//	while (1);
//}
//


//#include <torch/torch.h>
//#include <torch/script.h>
//#include <iostream>


//class Detector {
//public:
//	/***
//	 * @brief constructor
//	 * @param model_path - path of the TorchScript weight file
//	 * @param device_type - inference with CPU/GPU
//	 */
//	Detector(const std::string& model_path, bool use_gpu);
//
//	// other methond
//	//...
//
//private:
//	torch::jit::script::Module module_;
//	torch::Device device_;
//	bool half_;
//};
//
//Detector::Detector(const std::string& model_path, bool use_gpu) :device_(torch::kCPU)
//{
//	if (torch::cuda::is_available() && use_gpu)
//	{
//		//std::cout << "use cuda...\n";
//		device_ = torch::kCUDA;
//	}
//	else
//	{
//		//std::cout << "use cpu...\n";
//		device_ = torch::kCPU;
//	}
//
//	try {
//		// Deserialize the ScriptModule from a file using torch::jit::load().
//		module_ = torch::jit::load(model_path);
//	}
//	catch (const c10::Error& e) {
//		std::cerr << "Error loading the model!\n";
//		std::exit(EXIT_FAILURE);
//	}
//
//	half_ = (device_ != torch::kCPU);
//	module_.to(device_);
//
//	if (half_) {
//		module_.to(torch::kHalf);
//	}
//
//	module_.eval();
//}
//
//
//int main()
//{
//	std::shared_ptr<Detector> detector = std::make_shared<Detector>("best.torchscript.pt", true);
//	return 0;
//}
//
//#include <torch/script.h> 
//#include <opencv2/opencv.hpp>
//#include <torch/script.h>
//#include <torch/torch.h>
//#include <algorithm>
//#include <iostream>
//#include <time.h>
//#include <iostream>
//#include <memory>
//
//
//std::vector<torch::Tensor> non_max_suppression(torch::Tensor preds, float score_thresh = 0.01, float iou_thresh = 0.35)
//{
//    std::vector<torch::Tensor> output;
//    for (size_t i = 0; i < preds.sizes()[0]; ++i)
//    {
//        torch::Tensor pred = preds.select(0, i);
//
//        //GPU推理结果为cuda数据类型，nms之前要转成cpu，否则会报错
//        pred = pred.to(at::kCPU); //增加到函数里pred = pred.to(at::kCPU); 注意preds的数据类型，转成cpu进行后处理。
//
//        // Filter by scores
//        torch::Tensor scores = pred.select(1, 4) * std::get<0>(torch::max(pred.slice(1, 5, pred.sizes()[1]), 1));
//        pred = torch::index_select(pred, 0, torch::nonzero(scores > score_thresh).select(1, 0));
//        if (pred.sizes()[0] == 0) continue;
//
//        // (center_x, center_y, w, h) to (left, top, right, bottom)
//        pred.select(1, 0) = pred.select(1, 0) - pred.select(1, 2) / 2;
//        pred.select(1, 1) = pred.select(1, 1) - pred.select(1, 3) / 2;
//        pred.select(1, 2) = pred.select(1, 0) + pred.select(1, 2);
//        pred.select(1, 3) = pred.select(1, 1) + pred.select(1, 3);
//
//        // Computing scores and classes
//        std::tuple<torch::Tensor, torch::Tensor> max_tuple = torch::max(pred.slice(1, 5, pred.sizes()[1]), 1);
//        pred.select(1, 4) = pred.select(1, 4) * std::get<0>(max_tuple);
//        pred.select(1, 5) = std::get<1>(max_tuple);
//
//        torch::Tensor  dets = pred.slice(1, 0, 6);
//
//        torch::Tensor keep = torch::empty({ dets.sizes()[0] });
//        torch::Tensor areas = (dets.select(1, 3) - dets.select(1, 1)) * (dets.select(1, 2) - dets.select(1, 0));
//        std::tuple<torch::Tensor, torch::Tensor> indexes_tuple = torch::sort(dets.select(1, 4), 0, 1);
//        torch::Tensor v = std::get<0>(indexes_tuple);
//        torch::Tensor indexes = std::get<1>(indexes_tuple);
//        int count = 0;
//        while (indexes.sizes()[0] > 0)
//        {
//            keep[count] = (indexes[0].item().toInt());
//            count += 1;
//
//            // Computing overlaps
//            torch::Tensor lefts = torch::empty(indexes.sizes()[0] - 1);
//            torch::Tensor tops = torch::empty(indexes.sizes()[0] - 1);
//            torch::Tensor rights = torch::empty(indexes.sizes()[0] - 1);
//            torch::Tensor bottoms = torch::empty(indexes.sizes()[0] - 1);
//            torch::Tensor widths = torch::empty(indexes.sizes()[0] - 1);
//            torch::Tensor heights = torch::empty(indexes.sizes()[0] - 1);
//            for (size_t i = 0; i < indexes.sizes()[0] - 1; ++i)
//            {
//                lefts[i] = std::max(dets[indexes[0]][0].item().toFloat(), dets[indexes[i + 1]][0].item().toFloat());
//                tops[i] = std::max(dets[indexes[0]][1].item().toFloat(), dets[indexes[i + 1]][1].item().toFloat());
//                rights[i] = std::min(dets[indexes[0]][2].item().toFloat(), dets[indexes[i + 1]][2].item().toFloat());
//                bottoms[i] = std::min(dets[indexes[0]][3].item().toFloat(), dets[indexes[i + 1]][3].item().toFloat());
//                widths[i] = std::max(float(0), rights[i].item().toFloat() - lefts[i].item().toFloat());
//                heights[i] = std::max(float(0), bottoms[i].item().toFloat() - tops[i].item().toFloat());
//            }
//            torch::Tensor overlaps = widths * heights;
//
//            // FIlter by IOUs
//            torch::Tensor ious = overlaps / (areas.select(0, indexes[0].item().toInt()) + torch::index_select(areas, 0, indexes.slice(0, 1, indexes.sizes()[0])) - overlaps);
//            indexes = torch::index_select(indexes, 0, torch::nonzero(ious <= iou_thresh).select(1, 0) + 1);
//        }
//        keep = keep.toType(torch::kInt64);
//        output.push_back(torch::index_select(dets, 0, keep.slice(0, 0, count)));
//    }
//    return output;
//}
//
//
//
//int main(int argc, char* argv[])
//{
//    std::cout << "cuda::is_available():" << torch::cuda::is_available() << std::endl;
//    torch::DeviceType device_type = at::kCPU; // 定义设备类型
//    if (torch::cuda::is_available())
//        device_type = at::kCUDA;
//    // Loading  Module
//    torch::jit::script::Module module = torch::jit::load("best.torchscript.pt");//best.torchscript3.pt//yolov5x.torchscript.pt
//    module.to(device_type); // 模型加载至GPU
//
//    std::vector<std::string> classnames;
//    std::ifstream f("coco.names");
//    std::string name = "";
//    while (std::getline(f, name))
//    {
//        classnames.push_back(name);
//    }
//   /* if (argc < 2)
//    {
//        std::cout << "Please run with test video." << std::endl;
//        return -1;
//    }*/
//    std::string video = "0";
//    cv::VideoCapture cap = cv::VideoCapture(0);
//    // cap.set(cv::CAP_PROP_FRAME_WIDTH, 1920);
//    // cap.set(cv::CAP_PROP_FRAME_HEIGHT, 1080);
//
//
//    
//    int count = 0;
//    while (true)
//    {
//        cv::Mat frame, img;
//        int width = frame.size().width;
//        int height = frame.size().height;
//        count++;
//        clock_t start = clock();
//        cap >> frame;
//        if (frame.empty())
//        {
//            std::cout << "Read frame failed!" << std::endl;
//            break;
//        }
//        //frame 类似与一帧图片
//
//        //cv::resize(frame, img, cv::Size(640, 640));
//        //cv::cvtColor(img, img, cv::COLOR_BGR2RGB);  // BGR -> RGB
//        //img.convertTo(img, CV_32FC3, 1.0f / 255.0f);  // normalization 1/255
//        //auto imgTensor = torch::from_blob(img.data, { 1, img.rows, img.cols, img.channels() }).to(device_type);
//        //imgTensor = imgTensor.permute({ 0, 3, 1, 2 }).contiguous();  // BHWC -> BCHW (Batch, Channel, Height, Width)
//        //
//        //std::vector<torch::jit::IValue> inputs;
//        //inputs.emplace_back(imgTensor);
//        //// preds: [?, 15120, 9]
//        //torch::jit::IValue output = module.forward(inputs);
//        //auto preds = output.toTuple()->elements()[0].toTensor();
//        //// torch::Tensor preds = module.forward({ imgTensor }).toTensor();
//        //std::vector<torch::Tensor> dets = non_max_suppression(preds, 0.35, 0.5);
//       
//        //if (dets.size() > 0)
//        //{
//        //    // Visualize result
//        //    for (size_t i = 0; i < dets[0].sizes()[0]; ++i)
//        //    {
//        //        float left = dets[0][i][0].item().toFloat() * frame.cols / 640;
//        //        float top = dets[0][i][1].item().toFloat() * frame.rows / 640;
//        //        float right = dets[0][i][2].item().toFloat() * frame.cols / 640;
//        //        float bottom = dets[0][i][3].item().toFloat() * frame.rows / 640;
//        //        float score = dets[0][i][4].item().toFloat();
//        //        int classID = dets[0][i][5].item().toInt();
//
//        //        cv::rectangle(frame, cv::Rect(left, top, (right - left), (bottom - top)), cv::Scalar(0, 255, 0), 2);
//
//        //        cv::putText(frame,
//        //            classnames[classID] + ": " + cv::format("%.2f", score),
//        //            cv::Point(left, top),
//        //            cv::FONT_HERSHEY_SIMPLEX, (right - left) / 200, cv::Scalar(0, 255, 0), 2);
//        //    }
//        //}
//        //std::cout << "-[INFO] Frame:" << std::to_string(count) << std::endl;
//
//        //显示图像
//        cv::imshow("", frame);
//
//        cv::waitKey(1);
//    
//
//        //if (cv::waitKey(1) == 27) break;
//    }
//    cap.release();
//    return 0;
//}
//


// yzy
#include <fstream>
#include <sstream>
#include <iostream>
#include <opencv2/dnn.hpp>      // 深度学习模块
#include <opencv2/imgproc.hpp>	// 图像处理模块
#include <opencv2/highgui.hpp>  // 高层GUI图形用户界面

#include<time.h>


// 命名空间
using namespace cv;
using namespace dnn;
using namespace std;

// 自定义配置结构
struct Configuration
{
public:
	float confThreshold; // Confidence threshold
	float nmsThreshold;  // Non-maximum suppression threshold
	float objThreshold;  //Object Confidence threshold
	string modelpath;
};

// 模型
class YOLOv5
{
public:
	// 初始化
	YOLOv5(Configuration config, bool isCuda);
	void detect(Mat& frame);  // 检测函数
private:
	float confThreshold;
	float nmsThreshold;
	float objThreshold;
	int inpWidth;
	int inpHeight;
	int num_classes;
	string classes[80] = { "person", "bicycle", "car", "motorbike", "aeroplane", "bus",
					"train", "truck", "boat", "traffic light", "fire hydrant",
					"stop sign", "parking meter", "bench", "bird", "cat", "dog",
					"horse", "sheep", "cow", "elephant", "bear", "zebra", "giraffe",
					"backpack", "umbrella", "handbag", "tie", "suitcase", "frisbee",
					"skis", "snowboard", "sports ball", "kite", "baseball bat",
					"baseball glove", "skateboard", "surfboard", "tennis racket",
					"bottle", "wine glass", "cup", "fork", "knife", "spoon", "bowl",
					"banana", "apple", "sandwich", "orange", "broccoli", "carrot",
					"hot dog", "pizza", "donut", "cake", "chair", "sofa", "pottedplant",
					"bed", "diningtable", "toilet", "tvmonitor", "laptop", "mouse",
					"remote", "keyboard", "cell phone", "microwave", "oven", "toaster",
					"sink", "refrigerator", "book", "clock", "vase", "scissors",
					"teddy bear", "hair drier", "toothbrush" };
	//vector<string> class_names;
	const bool keep_ratio = true;
	Net net;   // dnn里的
	void drawPred(float conf, int left, int top, int right, int bottom, Mat& frame, int classid);
	Mat resize_image(Mat srcimg, int* newh, int* neww, int* top, int* left);
};

// 初始化
YOLOv5::YOLOv5(Configuration config, bool isCuda = false)
{
	this->confThreshold = config.confThreshold;
	this->nmsThreshold = config.nmsThreshold;
	this->objThreshold = config.objThreshold;

	this->net = readNet(config.modelpath);  // 解析模型onnx权重。dnn.hpp
	//cuda // https://blog.csdn.net/cxyhjl/article/details/125383555
	if (isCuda) {
		net.setPreferableBackend(cv::dnn::DNN_BACKEND_CUDA);
		net.setPreferableTarget(cv::dnn::DNN_TARGET_CUDA);
		cout << "cuda" << endl;
	}
	//cpu
	else {
		net.setPreferableBackend(cv::dnn::DNN_BACKEND_DEFAULT);
		net.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);
	}
	this->num_classes = sizeof(this->classes) / sizeof(this->classes[0]);  // 类别数量
	this->inpHeight = 640;
	this->inpWidth = 640;
}

Mat YOLOv5::resize_image(Mat srcimg, int* newh, int* neww, int* top, int* left)
{
	int srch = srcimg.rows, srcw = srcimg.cols;  // 输入高宽
	*newh = this->inpHeight;    // 指针变量指向输入yolo模型的宽高
	*neww = this->inpWidth;
	Mat dstimg;                 // 定义一个目标源
	if (this->keep_ratio && srch != srcw) {  // 高宽不等
		float hw_scale = (float)srch / srcw; // 保存比列
		if (hw_scale > 1) {     // 按照yolov5的预处理进行处理
			*newh = this->inpHeight;
			*neww = int(this->inpWidth / hw_scale); // 
			resize(srcimg, dstimg, Size(*neww, *newh), INTER_AREA);
			*left = int((this->inpWidth - *neww) * 0.5);
			// 和yolov5的处理对应,没有进行32的取模运算,这个是用114像素填充到(640,640)了,最后输入还是640,640
			copyMakeBorder(dstimg, dstimg, 0, 0, *left, this->inpWidth - *neww - *left, BORDER_CONSTANT, 114);
		}
		else {
			*newh = (int)this->inpHeight * hw_scale;
			*neww = this->inpWidth;
			resize(srcimg, dstimg, Size(*neww, *newh), INTER_AREA);
			*top = (int)(this->inpHeight - *newh) * 0.5;
			copyMakeBorder(dstimg, dstimg, *top, this->inpHeight - *newh - *top, 0, 0, BORDER_CONSTANT, 114);
		}
	}
	else {
		resize(srcimg, dstimg, Size(*neww, *newh), INTER_AREA);
	}
	return dstimg;
}

void YOLOv5::drawPred(float conf, int left, int top, int right, int bottom, Mat& frame, int classid)   // Draw the predicted bounding box
{
	//Draw a rectangle displaying the bounding box
	rectangle(frame, Point(left, top), Point(right, bottom), Scalar(0, 0, 255), 2);

	//Get the label for the class name and its confidence
	string label = format("%.2f", conf);
	label = this->classes[classid] + ":" + label;

	//Display the label at the top of the bounding box
	int baseLine;
	Size labelSize = getTextSize(label, FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseLine);
	top = max(top, labelSize.height);
	//rectangle(frame, Point(left, top - int(1.5 * labelSize.height)), Point(left + int(1.5 * labelSize.width), top + baseLine), Scalar(0, 255, 0), FILLED);
	putText(frame, label, Point(left, top), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0, 255, 0), 1);
}

// 预测
void YOLOv5::detect(Mat& frame)
{
	int newh = 0, neww = 0, padh = 0, padw = 0;
	Mat dstimg = this->resize_image(frame, &newh, &neww, &padh, &padw);  // 预处理
	Mat blob = blobFromImage(dstimg, 1 / 255.0, Size(this->inpWidth, this->inpHeight), Scalar(0, 0, 0), true, false); // return:4-dimensional Mat with NCHW dimensions order.
	this->net.setInput(blob);    // 设置输出
	vector<Mat> outs;   // 要给空的走一遍
	this->net.forward(outs, this->net.getUnconnectedOutLayersNames());  // [b,num_pre,(5+classes)]

	int num_proposal = outs[0].size[1]; // 25200
	int out_dim2 = outs[0].size[2];  // 
	if (outs[0].dims > 2)
	{
		outs[0] = outs[0].reshape(0, num_proposal);  // 一般都会大于二维的，所以展平二维[b,num_pre*(5+classes)]
	}
	/////generate proposals
	vector<float> confidences;
	vector<Rect> boxes;    //  opencv里保存box的
	vector<int> classIds;
	float ratioh = (float)frame.rows / newh, ratiow = (float)frame.cols / neww;
	float* pdata = (float*)outs[0].data;  // 定义浮点型指针，
	for (int i = 0; i < num_proposal; ++i) // 遍历所有的num_pre_boxes
	{
		int index = i * out_dim2;      // prob[b*num_pred_boxes*(classes+5)]  
		float obj_conf = pdata[index + 4];  // 置信度分数
		if (obj_conf > this->objThreshold)  // 大于阈值
		{
			//Mat scores = outs[0].row(row_ind).colRange(5, nout); // 相当于python里的切片操作，每类的预测类别分数
			Mat scores(1, this->num_classes, CV_32FC1, pdata + index + 5);     // 这样操作更好理解
			Point classIdPoint; //定义点
			double max_class_socre; // 定义一个double类型的变量保存预测中类别分数最大值
			// Get the value and location of the maximum score
			minMaxLoc(scores, 0, &max_class_socre, 0, &classIdPoint);  // 求每类类别分数最大的值和索引
			max_class_socre *= obj_conf;   // 最大的类别分数*置信度
			if (max_class_socre > this->confThreshold) // 再次筛选
			{
				const int class_idx = classIdPoint.x;  // 类别索引,在yolo里就是表示第几类
				// float cx = (pdata[0] * 2.f - 0.5f + j) * stride;  ///cx,映射回原图。对应yolov5里后处理部分
				// float cy = (pdata[1] * 2.f - 0.5f + i) * stride;   ///cy，但是现在的yolov5导出的onnx已经将这个处理放在里面了
				// float w = powf(pdata[2] * 2.f, 2.f) * anchor_w;   ///w，所以这里不需要后处理一下了，直接取输出就行
				// float h = powf(pdata[3] * 2.f, 2.f) * anchor_h;  ///h

				// 经过后处理的只需要直接取就行
				float cx = pdata[index];  //x
				float cy = pdata[index + 1];  //y
				float w = pdata[index + 2];  //w
				float h = pdata[index + 3];  //h

				int left = int((cx - padw - 0.5 * w) * ratiow);  // *ratiow，变回原图尺寸
				int top = int((cy - padh - 0.5 * h) * ratioh);

				confidences.push_back((float)max_class_socre);
				boxes.push_back(Rect(left, top, (int)(w * ratiow), (int)(h * ratioh)));  //（x,y,w,h）
				classIds.push_back(class_idx);  // 
			}
		}

	}

	vector<int> indices;
	dnn::NMSBoxes(boxes, confidences, this->confThreshold, this->nmsThreshold, indices);
	for (size_t i = 0; i < indices.size(); ++i)
	{
		int idx = indices[i];
		Rect box = boxes[idx];
		this->drawPred(confidences[idx], box.x, box.y,
			box.x + box.width, box.y + box.height, frame, classIds[idx]);
	}
}

int main()
{
	double timeStart = (double)getTickCount();
	clock_t startTime, endTime; //计算时间
	// 自己定义的yolo一些配置超参
	Configuration yolo_nets = { 0.3, 0.5, 0.3, "yolov5m.onnx" };
	YOLOv5 yolo_model(yolo_nets, false);
	string imgpath = "20200908150407973.png";
	Mat srcimg = imread(imgpath);

	double nTime = ((double)getTickCount() - timeStart) / getTickFrequency();
	startTime = clock();//计时开始	
	yolo_model.detect(srcimg);
	endTime = clock();//计时结束
	cout << "clock_running time is:" << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	cout << "The whole run time is:" << (double)clock() / CLOCKS_PER_SEC << "s" << endl;
	cout << "getTickCount_running time :" << nTime << "s" << endl;

	static const string kWinName = "Deep learning object detection in OpenCV";
	namedWindow(kWinName, WINDOW_NORMAL);  // 自适应调节窗口大小
	imwrite("restult_cpu.jpg", srcimg);
	imshow(kWinName, srcimg);
	waitKey(0);
	destroyAllWindows();
	return 0;
}


