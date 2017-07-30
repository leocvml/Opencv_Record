#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;
 
int main( int argc, char** argv )
{
  
    Mat image;
    image = imread("Image_DataSet/TestImage.jpg", CV_LOAD_IMAGE_COLOR);   // Read the file

    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

	Mat rain_img;
	rain_img = imread("Image_DataSet/rain.jpg", CV_LOAD_IMAGE_COLOR);
	resize(image, image, Size(rain_img.cols ,rain_img.rows));


	Mat result;
	addWeighted(image, 0.7, rain_img, 0.3, 0,result);
	imshow("MatOperand1" , result);

	Mat result2;
	result2 = image*0.7 + rain_img*0.5;
	imshow("MatOperand2" , result2);

	Mat result3;
	add(image, Scalar(0,0,255),result3);
	imshow("MatOperand3" , result3);

	Mat result4;
	vector<Mat>planes;
	split(image,planes);
	add(planes[1],Scalar(30),planes[0]);
	merge(planes , result4 );
	imshow("MatOperand4" , result4);


	Mat logo;
	logo = imread("Image_DataSet/nvidia_logo.jpg",CV_LOAD_IMAGE_COLOR);
	resize(logo,logo,Size(50,50));
	Mat imageROI;
	imageROI = image(Rect(300,300,logo.cols,logo.rows));
	addWeighted(imageROI,0.0,logo,1.0,0,imageROI);
	imshow("ROI_addWeighted" , image);

	Mat imageROI2;
	imageROI2 = image(Rect(300,300,logo.cols,logo.rows));
	logo.copyTo(imageROI2);
	imshow("ROI_mask" , image);




	waitKey(0);
	return 0;
}