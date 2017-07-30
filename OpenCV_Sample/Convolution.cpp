#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;
void Laplace ( const cv::Mat &image , cv::Mat &result){
    result.create(image.size() , image.type());
	for (int j = 1 ; j < image.rows-1 ; j++){
	    const uchar* previous = image.ptr<const uchar>(j-1);
		const uchar* current = image.ptr<const uchar>(j);
		const uchar* next = image.ptr<const uchar>(j+1);
		uchar* output = result.ptr<uchar>(j);

		for (int i =1  ;i< image.cols -1 ; i++)
		{
			*output++= cv::saturate_cast<uchar>(5*current[i] - current[i-1] - current[i+1] - previous[i] - next[i]);    //saturate_cast uchar(0 ~ 255) 數值小於0會等於0 大於255會等於255
		}

    result.row(0).setTo(cv::Scalar(0));
	result.row(result.rows-1).setTo(cv::Scalar(0));
    result.col(0).setTo(cv::Scalar(0));
	result.col(result.cols-1).setTo(cv::Scalar(0));
	
	}
}
void Laplace2d( const cv::Mat &image , cv::Mat &result){
    Mat kernel(3,3,CV_32F,Scalar(0));
    kernel.at<float>(1,1) = 5.0;
	kernel.at<float>(0,1) = -1.0;
	kernel.at<float>(2,1) = -1.0;
	kernel.at<float>(1,0) = -1.0;
	kernel.at<float>(1,2) = -1.0;
	filter2D(image , result , image.depth() , kernel);
}
int main( int argc, char** argv )
{
  
    Mat image;
    image = imread("Image_DataSet/TestImage.jpg", CV_LOAD_IMAGE_COLOR);   // Read the file
	cvtColor(image, image, CV_RGB2GRAY);
    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
	Mat result ; 
//	Laplace(image , result);
	Laplace2d(image ,result);
	imshow("result" , result);
	waitKey(0);
    return 0;
}