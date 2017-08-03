#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <algorithm>
using namespace cv;
using namespace std;
class Basic_fun{
    private:
	    int threshold_val;
		int sobel_threshold;
    public:
		Basic_fun(){
			threshold_val = 100;
			sobel_threshold = 200;
			
		}
			Mat bgr2gray(Mat &image){
				uchar *BGRimg, *Grayimg;
				Mat Gray_img(image.rows, image.cols, 0);
				int img_rows = 1;
				int img_vector = image.rows * image.cols *image.channels();
				int it = 0;
				for (int i = 0; i < img_rows; i++){
					BGRimg = image.ptr<uchar>(i);
					Grayimg = Gray_img.ptr<uchar>(i);
					for (int j = 0; j < img_vector; j += 3){
						Grayimg[it++] = (BGRimg[j] + BGRimg[j + 1] + BGRimg[j + 2]) / 3;

					}
				}
				return Gray_img;
			}
			Mat Meanfilter(Mat &image, float *mask){
				uchar *img_current , *Mean;
				Mat Meanf(image.rows, image.cols, image.type(), Scalar(0));
				int img_rows = 1; 
				int img_vector = image.rows *image.cols *image.channels();

				img_current = image.ptr<uchar>(0);
				Mean = Meanf.ptr<uchar>(0);
				for (int i = image.cols + 1; i < img_vector - image.cols; i++){
					Mean[i] = img_current[i - 1] * mask[0] + img_current[i] * mask[0] + img_current[i + 1] * mask[0] +
						img_current[i - 1 - image.cols] * mask[0] + img_current[i - image.cols] * mask[0] + img_current[i + 1 - image.cols] * mask[0] +
						img_current[i - 1 + image.cols] * mask[0] + img_current[i + image.cols] * mask[0] + img_current[i + 1 + image.cols] * mask[0];

				}

				return Meanf;
				
			}
			Mat threshold(Mat &image){
				Mat result(image.rows, image.cols, image.type());
				uchar *img, *result_img;
				int img_rows = 1;
				int img_vector = image.rows *image.cols *image.channels();
				img = image.ptr<uchar>(0);
				result_img = result.ptr<uchar>(0);
				for (int i = 0; i <img_vector; i++){
					if (img[i] > this->threshold_val){
						result_img[i] = 255;
					}
					else
						result_img[i] = 0;
				}
				return result;
			}

			Mat Medianfilter(Mat &image){
				uchar *img_current, *Median;
				Mat Medianf(image.rows, image.cols, image.type(), Scalar(255));
				int img_rows = 1;
				int img_vector = image.rows *image.cols *image.channels();

				img_current = image.ptr<uchar>(0);
				Median = Medianf.ptr<uchar>(0);
				int x[9];
				for (int i = 0; i <img_vector; i++){ // img_vector - image.cols
					x[0] = img_current[i - 1 - image.cols];
					x[1] = img_current[i  - image.cols];
					x[2] = img_current[i + 1 - image.cols];
					x[3] = img_current[i - 1];
					x[4] = img_current[i ];
					x[5] = img_current[i + 1];
					x[6] = img_current[i - 1 + image.cols];
					x[7] = img_current[i  + image.cols];
					x[8] = img_current[i + 1 + image.cols];
					sort(x, x + 9);
					Median[i] = x[4];

				}
				return Medianf;
			}
			Mat eq_histogram(Mat &image){
				Mat eh_img(image.rows, image.cols, image.type(),Scalar(0));
				int hist[256] = {0};
				float eq_hist[256] = {0};
				uchar *img , *eh;
				int img_vector = image.cols* image.rows * image.channels();
				img = image.ptr<uchar>(0);
				eh = eh_img.ptr<uchar>(0);
				int total = 0;
					for (int i = 0; i < img_vector; i++){
						hist[int(img[i])]++;
					}
					float temp_total = 0;
					for (int i = 0; i < 256; i++){
						eq_hist[i] = (float((hist[i] ) * 255) / float((img_vector ))) + temp_total;
						temp_total = eq_hist[i];
					}
					for (int i = 0; i < img_vector; i++){  /// lookup table
						eh[i] = uchar(eq_hist[img[i]]);
					
					}
					return eh_img;
					
			}
			Mat img2sobel(Mat &image){

				Mat sobel_img(image.rows, image.cols, image.type(),Scalar(0));
				int kernelv[9] = { -3,  -10,  -3,
					               0,  0,  0,
					              3, 10, 3 };
				int kernelh[9] = { -3, 0, 3,
					               -10, 0, 10,
					               -3, 0, 3 };
				int kernelrl [9] = { -2, -1, 0,
					                 -1, 0, 1,
					                 0, 1, 2 };
				int kernelll[9] = { 0, 1, 2,
					                -1, 0, 1,
					               -2, -1, 0 };
				uchar *img, *so;
				img = image.ptr<uchar>(0);
				so = sobel_img.ptr<uchar>(0);
				int img_vector = image.rows * image.cols * image.channels();

				for (int i = image.cols + 1; i < img_vector - image.cols; i+=1){
					int Gx, Gy , Gr,Gl , G;
					/*
					Gx = (img[i - 1 - image.cols] * kernelv[0]) + (img[i - image.cols] * kernelv[1]) + (img[i + 1 - image.cols] * kernelv[2]) +
						(img[i - 1 + image.cols] * kernelv[6]) + (img[i + image.cols] * kernelv[7]) + (img[i + 1 + image.cols] * kernelv[8]);
					
				
					Gy = img[i - 1 - image.cols] * kernelv[0] + img[i + 1 - image.cols] * kernelv[2] +
						img[i - 1 ] * kernelv[3] + img[i + 1 ] * kernelv[5] +
						img[i - 1 + image.cols] * kernelv[6] + img[i + 1 + image.cols] * kernelv[8];

					G = abs(Gx) + abs(Gy);
					*/
					Gr = (img[i - 1 - image.cols] * kernelrl[0]) + (img[i - image.cols] * kernelrl[1]) + (img[i + 1 - image.cols] * kernelrl[2]) +
						(img[i - 1] * kernelrl[3]) + (img[i] * kernelrl[4]) + (img[i + 1] * kernelrl[5])+
						(img[i - 1 + image.cols] * kernelrl[6]) + (img[i + image.cols] * kernelrl[7]) + (img[i + 1 + image.cols] * kernelrl[8]);

					Gl = (img[i - 1 - image.cols] * kernelll[0]) + (img[i - image.cols] * kernelll[1]) + (img[i + 1 - image.cols] * kernelll[2]) +
						(img[i - 1] * kernelll[3]) + (img[i] * kernelll[4]) + (img[i + 1] * kernelll[5]) +
						(img[i - 1 + image.cols] * kernelll[6]) + (img[i + image.cols] * kernelll[7]) + (img[i + 1 + image.cols] * kernelll[8]);
					//cout << Gl << endl;
					G = abs(Gr) + abs(Gl);
					/*
					if (abs(Gl) > this->sobel_threshold){

						so[i - 1 - image.cols] = 255;
						so[i - image.cols] = 255;
						so[i + 1 - image.cols] = 255;
						so[i - 1] = 255;
						so[i] = 255;
						so[i + 1] = 255;
						so[i - 1 + image.cols] = 255;
						so[i + image.cols] = 255;
						so[i + 1 + image.cols] = 255;
					
					}
					*/
					if (G <= 255 && G >= 0){
						so[i] = G;
					}
					else if (G > 255){
						so[i] = 255;
					}
					else
						so[i] = 0;
				}
				return sobel_img;	
			}
			Mat EdgeOverlapping(Mat &image, Mat &sobel_mask){
				Mat overlapp(image.rows, image.cols, 16, Scalar(0));
				uchar *img, *mask , *over;
				int img_vector = image.cols * image.rows * image.channels() *3;
				
				img = image.ptr<uchar>(0);
				mask = sobel_mask.ptr<uchar>(0);
				over = overlapp.ptr<uchar>(0);
				for (int i = 0; i < img_vector; i+=3){

					if (mask[i / 3] == 255){
						over[i] = 0;
						over[i+1] = 255;
						over[i+2] = 0;
					}
					else{
						over[i] = img[i/3];
						over[i + 1] = over[i];
						over[i + 2] = over[i];

					}

				}
				return overlapp;

			}
			Mat Erosion(Mat &image){
				uchar *img_current, *Erosion;
				Mat Erosion_img(image.rows, image.cols, image.type(), Scalar(255));
				int img_rows = 1;
				int img_vector = image.rows *image.cols *image.channels();

				img_current = image.ptr<uchar>(0);
				Erosion = Erosion_img.ptr<uchar>(0);
				int x[9] = {0,1,0,1,1,1,0,1,0};
				int opafter[9];
				for (int i = 0; i <img_vector; i++){ // img_vector - image.cols
					x[0] &img_current[i - 1 - image.cols]);
					x[1] & img_current[i - image.cols]);
					x[2] & img_current[i + 1 - image.cols]);
					x[3] & img_current[i - 1]);
					x[4] & img_current[i]);
					x[5] & img_current[i + 1]);
					x[6] & img_current[i - 1 + image.cols]);
					x[7] & img_current[i + image.cols]);
					x[8] & img_current[i + 1 + image.cols]);
					sort(x, x + 9);
					Median[i] = x[4];

				}
				return Medianf;


			}
};
int main(int argc, char** argv){


		Mat image;
		image = imread("SampleImage/E_I-edge.bmp", CV_LOAD_IMAGE_COLOR);   
		cout << image.type() << endl;
		if (!image.data)                             
		{
			cout << "Could not open or find the image" << std::endl;
			return -1;
		}

		Mat img_gray;
		img_gray = hi.bgr2gray(image);
		//Mat result;
		//Sobel(img_gray, result,3);
		
		Mat Mean_filter;
		float filed2d[9] = { 0.1111, 0.1111, 0.1111,
			                  0.1111, 0.1111, 0.1111, 
			                  0.1111, 0.1111, 0.1111 };
		 
		Mean_filter = hi.Meanfilter(img_gray,filed2d);
	 

		

		Mat Median_filter = hi.Medianfilter(img_gray);
		
	    Mat He_img = hi.eq_histogram(img_gray);
		
		Mat Sobel_img = hi.img2sobel(He_img);
		Mat thresh_img = hi.threshold(Sobel_img);
		imshow("source_img", img_gray);
		Mat overlap = hi.EdgeOverlapping(img_gray,thresh_img);
		imshow("overlap", overlap);

		imshow("grayscale_img", img_gray);
		imshow("mean_filter", Mean_filter);
		imshow("thresh_img", thresh_img);
		imshow("median_filter", Median_filter);
		imshow("Histogram equalization", He_img);
		
		imshow("Sobel img", Sobel_img);
		waitKey(0);                                   
		return 0;

}
