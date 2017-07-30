#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;
#define PTR_Method2
int main( int argc, char** argv )
{
  
    Mat image;
    image = imread("Image_DataSet/TestImage.jpg", CV_LOAD_IMAGE_COLOR);   // Read the file

    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
#ifdef PTR_Method1
	Mat img_gray1 = Mat::zeros(Size(image.cols, image.rows), CV_8UC3);
    int channels = img_gray1.channels();
    int nRows = img_gray1.rows ;
    int nCols = img_gray1.cols* channels;
    if (image.isContinuous())
    {
        nCols *= nRows;
        nRows = 1;
    }
    uchar *org_img, *Gray_img;
    for(int i = 0; i < nRows; i++)
    {
        org_img = image.ptr<uchar>(i);  
        Gray_img = img_gray1.ptr<uchar>(i);
        for (int j = 0; j < nCols; j=j+3)
        {
            Gray_img[j] = org_img[j+1]*0.3 + org_img[j+2]*0.3 + org_img[j+3]*0.3;
            Gray_img[j+1] = Gray_img[j];
            Gray_img[j+2] = Gray_img[j];
        }
	}

	imshow("result1",img_gray1);
    waitKey(0); 
#endif // PTR1


//======================================================================================================================
#ifdef PTR_Method2
	Mat img_gray2 = Mat::zeros(Size(image.cols, image.rows), CV_8UC3);


    int channels = img_gray2.channels();
    int i = 0 , j = 0;
    int p;
    uchar *PTR2 , *org_img;
    org_img= image.ptr<uchar>(i);  
    PTR2= img_gray2.ptr<uchar>(i);    
    for( i = 0; i < image.rows; i++)
    {
        p = i * j * channels;
        for ( j = 0; j < image.cols; j++)
        {
            PTR2[p] = org_img[p+1]*0.3 + org_img[p+2]*0.3 + org_img[p+3]*0.3;
            PTR2[p+1] = PTR2[p];
            PTR2[p+2] = PTR2[p];
            p = p + 3;
        }
    }
	imshow("result2",img_gray2);
	waitKey(0);
#endif // PTR1
    return 0;
}