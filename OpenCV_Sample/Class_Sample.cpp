#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;
class ColorDetector{
    private:
		int minDist;
		Vec3b target;
		Mat result;
		Mat convert;
		int getDistance(const Vec3b& color)const{
        return abs(color[0] - target[0]) + abs(color[1] - target[1]) + abs(color[2] - target[2]);
		//return static_cast<int>( norm<int,3>(Vec3i(color[0] - target[0] , color[1] - target[1], color[2] - target[2])));
    }
	public:
		ColorDetector():minDist(100){
			
	    target[0] = target[1] = target[2] = 0;
	}

		Mat ColorDetector::process(const Mat &image){
			result.create(image.rows, image.cols, CV_8U);
			Mat_<Vec3b>::const_iterator it = image.begin<Vec3b>();
			Mat_<Vec3b>::const_iterator itend = image.end<Vec3b>();
			Mat_<uchar>::iterator itout = result.begin<uchar>();
			int count = 0;
			for (;it != itend;++it,++itout){
			//count++;
			//cout << count <<endl;
				if(getDistance(*it) < minDist){
				
					*itout = 255;
				}
				else{
					*itout = 0;
				}
			}	
			return result;
		}
		Mat ColorDetector::ToGray(Mat &image){
			result.create(image.rows , image.cols , CV_8UC3);
			int channels = image.channels();
			int nRows = image.rows ;
			int nCols = image.cols* channels;
			if (image.isContinuous())
			{
				nCols *= nRows;
				nRows = 1;
			}
			uchar *p_img, *p_result;

			for(int i = 0; i < nRows; i++)
			{
				p_img = image.ptr<uchar>(i);  
				p_result = result.ptr<uchar>(i);
				for (int j = 0; j < nCols; j=j+3)
				{
					p_result[j] = p_img[j+1]*0.3 + p_img[j+2]*0.3 + p_img[j+3]*0.3;
					p_result[j+1] = p_result[j];
					p_result[j+2] = p_result[j];
				}
			}
			return result;
		}
		Mat ColorDetector::converted(const Mat &image){
			result.create(image.rows, image.cols, CV_8U);
			convert.create(image.rows, image.cols, image.type());
			cvtColor(image, convert,CV_BGR2Lab);
			Mat_<Vec3b>::const_iterator it = convert.begin<Vec3b>();
			Mat_<Vec3b>::const_iterator itend = convert.end<Vec3b>();
			Mat_<uchar>::iterator itout = result.begin<uchar>();
			int count = 0;
			for (;it != itend;++it,++itout){
			//count++;
			//cout << count <<endl;
				if(getDistance(*it) < minDist){
				
					*itout = 255;
				}
				else{
					*itout = 0;
				}
			}	
			return result;
		}
		void setColorDistanceThreshold(int distance){
			if(distance < 0){
				distance = 0;
				minDist = distance;
			}
		}

		int getColorDistanceThreshold()const{
			return minDist;
		}

		void setTargetColor(unsigned char red,unsigned char green,unsigned char blue){
			target[2] =red;
			target[1] = green;
			target[0] = blue;
		}
		void setTargetColorLab(unsigned char red,unsigned char green,unsigned char blue){
			Mat tmp(1,1,CV_8UC3);
			tmp.at<Vec3b>(0,0)[0] = blue;
			tmp.at<Vec3b>(0,0)[1] = green;
			tmp.at<Vec3b>(0,0)[2] = red;
			cvtColor(tmp,tmp,CV_BGR2Lab);
			target = tmp.at<Vec3b>(0,0);
		}
		void setTargetColor(Vec3b color){
			target = color;
		}
		Vec3b getTargetColor()const{
			return target;
		}

};


int main( int argc, char** argv )
{
	ColorDetector cdetect;
	cdetect.setColorDistanceThreshold(0);
    Mat image;
    image = imread("Image_DataSet/boldt.jpg", CV_LOAD_IMAGE_COLOR);   // Read the file

    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

	imshow("image" , image);
	cdetect.setTargetColor(130,190,230);
	imshow("result_process" , cdetect.process(image));
	imshow("result_ToGray"  , cdetect.ToGray(image));

	cdetect.setTargetColorLab(100,100,100);
	imshow("result_Convert" , cdetect.converted(image));
	waitKey(0);

	return 0;
}