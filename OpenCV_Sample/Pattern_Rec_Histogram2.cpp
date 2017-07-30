#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/video/tracking.hpp"
#include <iostream>

using namespace cv;
using namespace std;
class ContentFinder{
    private:
		float hranges[2];
		const float *ranges[3];
		int channels[3];
		float threshold;
		MatND histogram;
		int histSize[3];
    public:
		ContentFinder():threshold(-1.0f){
			histSize[0] = histSize[1] = histSize[2] = 256;
		    ranges[0] = hranges;
			ranges[1] = hranges;
			ranges[2] = hranges;
		

		}
		void setThreshold(float t){
		    threshold = t;
		}
		float getThreshold(){
		    return threshold;
		}
		MatND getHistorgram(const Mat &image){            //use sparse matrix SparseMat
		    MatND hist;
			calcHist(&image,
				     1,   //only calc one image
					 channels, // channels
					 Mat(), // didn't use filter image
					 hist, // return hist
					 3, //it's 3d histogram
					 histSize, // histsize
					 ranges   //ranges
					 );
			return hist;
		}
		void setHisogram(MatND &h){
		    histogram = h;
			normalize(histogram, histogram, 1.0);
		}
		Mat find(Mat &image,float minVal, float maxVal,int dim){
		    Mat result;
			hranges[0] = minVal;
			hranges[1] = maxVal;
			for(int i =0 ; i < dim ; i++)
				this->channels[i] = i;

			calcBackProject(&image,
				            1,
				            channels,
							histogram,
							result,
							ranges,
							255.0);
		
		if(threshold>0.0)
			cv::threshold(result,result,255*threshold,255,THRESH_BINARY);
		return result;
		}



};
class ColorHistorgram{
    private:
		int histSize[3];
		float hranges[2];
		const float *ranges[3];
		int channels[3];
    public:
		ColorHistorgram(){
		    histSize[0] = histSize[1] = histSize[2] = 256;
			hranges[0] = 0.0;
			hranges[1] = 256.0;
			ranges[0] = hranges;
			ranges[1] = hranges;
			ranges[2] = hranges;
			channels[0] = 0;
			channels[1] = 1;
			channels[2] = 2;
		}
		MatND getHistorgram(const Mat &image){            //use sparse matrix SparseMat
		    MatND hist;
			calcHist(&image,
				     1,   //only calc one image
					 channels, // channels
					 Mat(), // didn't use filter image
					 hist, // return hist
					 3, //it's 3d histogram
					 histSize, // histsize
					 ranges   //ranges
					 );
			return hist;
		}
		Mat applyLookUp(const Mat &image, const Mat &lookup){
		    Mat result;
			LUT(image,lookup,result);
			return result;
		}
		Mat colorReduce(Mat &image, int div){
		    int nl = 1;
			int nc = image.cols*image.channels()*image.rows;
			Mat result(image.rows,image.cols,image.type());
			for(int j = 0 ;j<nl;j++){
				uchar *data = image.ptr<uchar>(j);
				uchar *result_img = result.ptr<uchar>(j);
				for(int i = 0; i< nc;i++){
				    result_img[i] = data[i]/div*div+div/2;
				}
			}
			return result;	
		}
		MatND getHueHistogram(Mat &image, int minSaturation=0){
		    MatND hist;
			Mat hsv;
			cvtColor(image,hsv,CV_BGR2HSV);
			Mat mask;
			if(minSaturation > 0){
			    vector<Mat>v;
				split(hsv,v);
				threshold(v[1],mask,minSaturation,255,CV_THRESH_BINARY);
			}
			hranges[0] = 0.0;
			hranges[1] = 180.0;
			channels[0] = 0;
			calcHist(&hsv,
				     1,
					 channels,
					 mask,
					 hist,
					 1,
					 histSize,
					 ranges
		    );
			return hist;
		}

};

int main( int argc, char** argv )
{     
	Mat image1;
	image1 = imread("Image_DataSet/baboon1.jpg", CV_LOAD_IMAGE_COLOR);   // Read the file
    if(! image1.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
	Mat imageROI = image1(Rect(110,260,35,40));
	int minSat = 65;
	ColorHistorgram hc;
	MatND colorhist = hc.getHueHistogram(imageROI,minSat);
	ContentFinder finder;
	finder.setHisogram(colorhist);

	Mat image2;
	image2 = imread("Image_DataSet/baboon2.jpg", CV_LOAD_IMAGE_COLOR);
	Mat hsv;
	cvtColor(image2, hsv, CV_BGR2HSV);
	vector<Mat> v;
	split(hsv,v);
	threshold(v[1],v[1],minSat,255,THRESH_BINARY);
	merge(v,hsv);
	Mat result;
	result = finder.find(hsv,0.0,180,1);
	bitwise_and(result,v[1],result);
	Rect rect(110, 260, 35, 40);
	rectangle(image2,rect,Scalar(0,0,255));
	TermCriteria criteria(TermCriteria::MAX_ITER,1000,0.01);
	meanShift(result,rect,criteria);
	rectangle(image2,rect,Scalar(255,0,0));
	imshow("result" , image2);



	waitKey(0);
	return 0;
}

