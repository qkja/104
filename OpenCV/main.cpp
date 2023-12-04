#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
 
int main(){
    Mat image;
    image = imread("./1.jpg");
    if (image.empty()) {
        cout << "Error! Input image cannot be read...\n";
        return -1;
    }
    cout<<"图像宽为："<<image.cols<<"\t高度为："<<image.rows<<"\t通道数为："<<image.channels()<<endl;
    return 0;
}
