#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;
#define ColorHistbackproj  //ColorHistbackproj
#ifdef GrayHistbackproj
class Histogram1D{
    private:
	    int histSize[1];
	    float hranges[2];
	    const float *ranges[1];
	    int channels[1];
    public:
	    Histogram1D(){
	        histSize[0] = 256;
	 	    hranges[0] = 0.0;
	    	hranges[1] = 255.0;
		    ranges[0] = hranges;
		    channels[0] = 0;
	    }
		MatND getHistogram(Mat &image){
		    MatND hist;
			calcHist(&image, 1, channels, Mat(), hist, 1, histSize, ranges );
			return hist;		
		}

		Mat getHistogramImage(Mat &image){
		    MatND hist = getHistogram(image);
			double maxVal = 0;
			double minVal = 0;
			minMaxLoc(hist,&minVal,&maxVal,0,0);
			cout <<minVal<< " " << maxVal<<endl;
			Mat histImg(histSize[0] , histSize[0] , CV_8U , Scalar(255));
			int hpt = static_cast<int>(0.9* histSize[0]);

			for(int h = 0; h<histSize[0];h++){
			    float binVal = hist.at<float>(h);
				int intensity = static_cast<int>(binVal*hpt/maxVal);
				cout << h<<" "<<binVal <<endl;
				line(histImg, Point(h,histSize[0]),Point(h,histSize[0] - intensity), Scalar::all(0));
			
			}

            return histImg;		
		
		}
		Mat applyLookUp(const Mat &image, const Mat &lookup){
		    Mat result;
			LUT(image,lookup,result);
			return result;
		}
		Mat stretch(Mat &image, int minValue = 0){
			MatND hist = getHistogram(image);
		 
			int imin = 0;
			for(;imin<histSize[0];imin++){
			    cout << hist.at<float>(imin) <<endl;
				if(hist.at<float>(imin) > minValue)
					break;
			}

			int imax = histSize[0] -1;
			for(;imax >= 0;imax--){
				if(hist.at<float>(imax) > minValue)
					break;
			}
			cout << "min: " <<imin <<" " <<"max: "<< imax<<endl;
			int dim(256);
			Mat lookup(1,&dim,CV_8U);
			for(int i=0;i<256;i++){
			    if(i<imin)
					lookup.at<uchar>(i) = 0;
				else if(i >imax)
					lookup.at<uchar>(i) = 255;
				else
					lookup.at<uchar>(i) = static_cast<uchar>(255*(i-imin)/(imax-imin)+0.5);

			}
		
			Mat result;
			result = applyLookUp(image,lookup);
			return result;
		}
			Mat equalize(Mat &image){
			    Mat result;
				equalizeHist(image,result);
				return result;
			
			}
			Mat histbackproj(Mat &image , Mat &imageROI){
			    Mat result;
				MatND hist = getHistogram(imageROI);
				normalize(hist,hist,1.0);
			    calcBackProject(&image,
					            1,
					            channels,
					            hist,
					            result,
								ranges,
								255.0);

				return result;

			}

		
		
};
#endif
#ifdef ColorHistbackproj
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

};
#endif
int main( int argc, char** argv )
{
     

#ifdef GrayHistbackproj
	//=========================================================  use hist backproject
	Mat image;
	image = imread("Image_DataSet/waves.jpg", CV_LOAD_IMAGE_GRAYSCALE);   // Read the file
    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
	Histogram1D h; 
	Mat imageROI = image(Rect(360,55,40,50));
	Mat result;
	result = h.histbackproj(image,imageROI);
	threshold(result,result,26,255,THRESH_BINARY);
	imshow("result" , result);
	waitKey(0);
	//=========================================================
#endif

#ifdef ColorHistbackproj
	Mat image;
	image = imread("Image_DataSet/waves.jpg", CV_LOAD_IMAGE_COLOR);   // Read the file
    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
	ColorHistorgram hc;
	Mat ColorReduce_img;
	Mat Rec_img;
	ColorReduce_img = hc.colorReduce(image,32);
	Rec_img = hc.colorReduce(image,32);
	rectangle(Rec_img,Rect(250,200,165,75),Scalar(0,0,255),1,8,0);
	imshow("image" , Rec_img);
	Mat ColorReduce_imgROI = ColorReduce_img(Rect(250,200,165,75));
	MatND hist = hc.getHistorgram(ColorReduce_imgROI);
	ContentFinder finder;
	finder.setHisogram(hist);
	finder.setThreshold(0.05f);
	Mat result = finder.find(ColorReduce_img,0,255,3);
	imshow("result ",result);
#endif
	waitKey(0);
	return 0;

}

