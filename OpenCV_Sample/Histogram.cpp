#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;
#define Grayscale    // Grayscale  or ColorScale

#ifdef Grayscale
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

		
		
};

int main( int argc, char** argv )
{
    Histogram1D h;  
    Mat image;
	
	image = imread("Image_DataSet/group.jpg", CV_LOAD_IMAGE_GRAYSCALE);   // Read the file

    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
	imshow("img", image);
	
	MatND histo = h.getHistogram(image);
	for (int i = 0; i < 256 ; i++)
		cout <<"Value"<<i<<"="<<histo.at<float>(i)<<endl;

	imshow("img_Hist", h.getHistogramImage(image));

	Mat threshold_img;
	threshold(image,threshold_img,60,255,THRESH_BINARY);
	imshow("thresold " , threshold_img);

	imshow("stretch" ,  h.stretch(image,100));
	imshow("strimg_Hist", h.getHistogramImage(h.stretch(image,100)));
	imshow("strimgequt", h.equalize(h.stretch(image,100)));
	imshow("strimgequ_Hist", h.getHistogramImage(h.equalize(h.stretch(image,100))));
	waitKey(0);
	system("pause");
	return 0;
}
#endif
#ifdef ColorScale
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

};
int main(){
    ColorHistorgram h;  
    Mat image;
	
	image = imread("Image_DataSet/group.jpg", CV_LOAD_IMAGE_COLOR);   // Read the file

    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
	


	Mat threshold_img;
	threshold(image,threshold_img,60,255,THRESH_BINARY);
	imshow("thresold " , threshold_img);


	Mat lut(1,256,CV_8U);
	uchar *p = lut.data;
	for(int i = 0; i < 256; i++){
		 p[i] = 255-i;
	}
	
	imshow("lookuptable" , h.applyLookUp(image,lut));


	waitKey(0);
	system("pause");
	return 0;


}
#endif