#pragma once


namespace Sample_Code {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::PictureBox^  pictureBox1;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox4;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button11;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(34, 36);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(118, 36);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Open Image";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(198, 36);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(370, 236);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(34, 78);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(118, 36);
			this->button2->TabIndex = 3;
			this->button2->Text = L"GrayScale";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(686, 36);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(370, 236);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(198, 318);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(370, 236);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 1;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Location = System::Drawing::Point(686, 318);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(370, 236);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 1;
			this->pictureBox4->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(603, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 12);
			this->label1->TabIndex = 4;
			this->label1->Text = L"label1";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(34, 120);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(118, 36);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Color extraction";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click_1);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(34, 162);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(118, 36);
			this->button4->TabIndex = 6;
			this->button4->Text = L"Sobel";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(794, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 12);
			this->label2->TabIndex = 7;
			this->label2->Text = L"label2";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(34, 251);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(118, 36);
			this->button5->TabIndex = 8;
			this->button5->Text = L"threshold";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(34, 206);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(118, 36);
			this->button6->TabIndex = 9;
			this->button6->Text = L"Histogram Equalization";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(34, 293);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(118, 36);
			this->button7->TabIndex = 10;
			this->button7->Text = L"Erosion";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(34, 335);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(118, 36);
			this->button8->TabIndex = 11;
			this->button8->Text = L"dilation ";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(34, 377);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(118, 41);
			this->button9->TabIndex = 12;
			this->button9->Text = L"Mean Filter";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(34, 424);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(118, 41);
			this->button10->TabIndex = 12;
			this->button10->Text = L"Median filter";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Form1::button10_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(34, 476);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(117, 39);
			this->button11->TabIndex = 13;
			this->button11->Text = L"EdgeOverlape";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &Form1::button11_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1080, 633);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		Bitmap^ temp_img;
		Bitmap^ Gray_Scale;
		Bitmap^ BGR2gray(Bitmap^ image){
				Bitmap^ Gray_Scale = gcnew Bitmap(image->Width, image->Height);
				int count = 0;
				for (int i = 0; i < image->Height; i++)
					for (int j = 0; j < image->Width; j++)
					{ 
						Color RGB = image->GetPixel(j, i);
						int gray = (RGB.R + RGB.G + RGB.B) / 3;
						Gray_Scale->SetPixel(j, i, Color::FromArgb(gray, gray, gray));
						count++;
					}
				return Gray_Scale;
				

			}
			int* Bmp2vector(Bitmap^ Gray_img){

				int *ptr = nullptr;
				ptr = new int[Gray_img->Width * Gray_img->Height];

				for (int i = 0; i < Gray_img->Height; i++)
					for (int j = 0; j < Gray_img->Width; j++)
					{
						Color RGB = Gray_img->GetPixel(j, i);
						int gray = (RGB.R + RGB.G + RGB.B) / 3;
						ptr[i*Gray_img->Width + j] = gray;
					}
				return ptr;
			}
			String^ PassFunction(Bitmap^ Gray_img, int* image_vector){
				bool pass = true;
				String^ Mes;
				for (int i = 0; i < Gray_img->Height; i++){
					for (int j = 0; j < Gray_img->Width; j++)
					{
						Color RGB = Gray_img->GetPixel(j, i);
						if (image_vector[i*Gray_img->Width + j] != RGB.R)
							pass = false;
					}
				}
				if (pass == false){
					Mes = "fail";
					return Mes;
				}
				else{
					Mes = "pass";
					return Mes;
				}
			}
			Bitmap^ Vector2bmp(int *img_vector,int width, int heith){
				Bitmap^ result = gcnew Bitmap(width, heith);
				for (int i = 0; i < width*heith -1; i++){
					int value = img_vector[i];
					result->SetPixel(i % width, i / width, Color::FromArgb(value, value, value));
				}
				return result;
			}
			int abs(int x){
				if (x < 0)
					return x*-1;
				else
				   return x;
			}
			int* Sobel(int *img_vector, int Width, int  Height){
				int kernelv[9] = { -3, -10, -3,
					0, 0, 0,
					3, 10, 3 };
				int kernelh[9] = { -3, 0, 3,
					-10, 0, 10,
					-3, 0, 3 };
				int kernelrl[9] = { -2, -1, 0,
					-1, 0, 1,
					0, 1, 2 };
				int kernelll[9] = { 0, 1, 2,
					-1, 0, 1,
					-2, -1, 0 };

				int *sobel = nullptr;
				sobel = new int[Width * Height];
				int vector_size = Width * Height;
				for (int i = 0; i < vector_size; i += 1){
					if (i >= Width + 1 && i < vector_size - Width){
						sobel[i] = 0;
						int Gr, Gl, G;
						Gr = (img_vector[i - 1 - Width] * kernelrl[0]) + (img_vector[i - Width] * kernelrl[1]) + (img_vector[i + 1 - Width] * kernelrl[2]) +
							(img_vector[i - 1] * kernelrl[3]) + (img_vector[i] * kernelrl[4]) + (img_vector[i + 1] * kernelrl[5]) +
							(img_vector[i - 1 + Width] * kernelrl[6]) + (img_vector[i + Width] * kernelrl[7]) + (img_vector[i + 1 + Width] * kernelrl[8]);

						Gl = (img_vector[i - 1 - Width] * kernelll[0]) + (img_vector[i - Width] * kernelll[1]) + (img_vector[i + 1 - Width] * kernelll[2]) +
							(img_vector[i - 1] * kernelll[3]) + (img_vector[i] * kernelll[4]) + (img_vector[i + 1] * kernelll[5]) +
							(img_vector[i - 1 + Width] * kernelll[6]) + (img_vector[i + Width] * kernelll[7]) + (img_vector[i + 1 + Width] * kernelll[8]);

						G = abs(Gr) + abs(Gl);

						if (G <= 255 && G >= 0){
							sobel[i] = G;
						}
						else if (G > 255){
							sobel[i] = 255;
						}
						else{
							sobel[i] = 0;
						}
					}
					else
						sobel[i] = 0;
				}
				return sobel;
			}
			int *eqhi(int *img_vector, int Width, int  Height){

				int *eqhi = nullptr;
				eqhi = new int[Width * Height];
				int vector_size = Width * Height;
				int hist[256] = { 0 };
				float eq_hist[256] = { 0 };
				for (int i = 0; i < vector_size; i += 1){
					hist[int(img_vector[i])]++;
				}
				float temp_total = 0;
					for (int i = 0; i < 256; i++){
						eq_hist[i] = (float((hist[i]) * 255) / float((vector_size))) + temp_total;
						temp_total = eq_hist[i];
					}
					for (int i = 0; i < vector_size; i++){  /// lookup table
						eqhi[i] = eq_hist[img_vector[i]];

					}
					return eqhi;

				}
			int *threshold(int *img_vector, int Width, int  Height , int bias){

				int *thresh_v = nullptr;
				thresh_v = new int[Width * Height];
				int vector_size = Width * Height;
			
				for (int i = 0; i < vector_size; i += 1){
					if (img_vector[i] > bias)
						thresh_v[i] = 255;
					else
						thresh_v[i] = 0;

				}
				return thresh_v;

			}
			
			int *erosion(int *img_vector, int Width, int  Height){

				int *ero_v = nullptr;
				ero_v = new int[Width * Height];
				int vector_size = Width * Height;
				for (int i = 0; i < vector_size; i += 1){
					if (i >= Width + 1 && i < vector_size - Width){
						ero_v[i] = 0;
						if (img_vector[i - Width] == 255 && img_vector[i - 1] == 255 && img_vector[i] == 255
							&& img_vector[i + 1] == 255 && img_vector[i + Width] == 255)
							ero_v[i] = 255;
						
					}
					else
						ero_v[i] = 0;
				}
				return ero_v;
			}
			
			int *dilation(int *img_vector, int Width, int  Height){

				int *dil_v = nullptr;
				dil_v = new int[Width * Height];
				int vector_size = Width * Height;
				for (int i = 0; i < vector_size; i += 1){
					if (i >= Width + 1 && i < vector_size - Width){
						dil_v[i] = 0;
						if (img_vector[i - Width] == 255 || img_vector[i - 1] == 255 || img_vector[i] == 255
							|| img_vector[i + 1] == 255 || img_vector[i + Width] == 255)
							dil_v[i] = 255;

					}
					else
						dil_v[i] = 0;
				}
				return dil_v;
			}
			int *Mean_filter(int *img_vector, int Width, int  Height){
				float kernelv[9] = { 0.1111, 0.1111, 0.1111,
					0.1111, 0.1111, 0.1111,
					0.1111, 0.1111, 0.1111 };
				int *Mean = nullptr;
				Mean = new int[Width * Height];
				int vector_size = Width * Height;
				int count1 = 0, count2 = 0;
				for (int i = 0; i < vector_size; i += 1){
					if (i >= Width + 1 && i < vector_size - Width){
						count1++;
						
						Mean[i] = int((img_vector[i - 1 - Width] * kernelv[0]) + (img_vector[i - Width] * kernelv[1]) + (img_vector[i + 1 - Width] * kernelv[2]) +
							(img_vector[i - 1] * kernelv[3]) + (img_vector[i] * kernelv[4]) + (img_vector[i + 1] * kernelv[5]) +
							(img_vector[i - 1 + Width] * kernelv[6]) + (img_vector[i + Width] * kernelv[7]) + (img_vector[i + 1 + Width] * kernelv[8]));
						if (Mean[i] > 255)
							Mean[i] = 255;
						else if (Mean[i] < 0)
							Mean[i] = 0;
						else
							Mean[i] = Mean[i];
						 
					}
					else{
						Mean[i] = 0;

					}
					
				}
				return Mean;
			}

			int *Median_filter(int *img_vector, int Width, int  Height){

				int *Median = nullptr;
				Median = new int[Width * Height];
				int vector_size = Width * Height;
				array<int>^ x = gcnew array<int>(10);
				for (int i = 0; i < vector_size; i += 1){
					if (i >= Width + 1 && i < vector_size - Width){

						x[0] = img_vector[i - 1 - Width];
						x[1] = img_vector[i - Width];
						x[2] = img_vector[i + 1 - Width];
						x[3] = img_vector[i - 1];
						x[4] = img_vector[i];
						x[5] = img_vector[i + 1];
						x[6] = img_vector[i - 1 + Width];
						x[7] = img_vector[i + Width];
						x[8] = img_vector[i + 1 + Width];
						Array::Sort(x);
						Median[i] = x[4];
					}
					else{
						Median[i] = 0;
					}

				}
				return Median;
			}
			Bitmap^ Edge_over(int *gray_img, int* thresh_img, int width, int heith){


				int vector_size = Width * Height;
				Bitmap^ result = gcnew Bitmap(width, heith);
				for (int i = 0; i < width*heith - 1; i++){
					if (thresh_img[i] == 255)
						result->SetPixel(i % width, i / width, Color::FromArgb(0, 255, 0));
					else{
						result->SetPixel(i % width, i / width, Color::FromArgb(gray_img[i], gray_img[i], gray_img[i]));

					}
				}
				return result;
			}


	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 if( openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
					 // 如果成功開檔
				 {	
					 Bitmap^ openImg=gcnew Bitmap(openFileDialog1->FileName);
					 temp_img = gcnew Bitmap(openImg->Width, openImg->Height);
					 //宣告暫存的 Bitmap
					 pictureBox1->Image = openImg;
					 
					 for (int i = 0; i < temp_img->Height; i++)
						 for (int j = 0; j <temp_img->Width; j++)
						 {
							 Color RGB = openImg->GetPixel(j,i); 
							 //讀取影像平面上 (j,i) 的 RGB 資訊
							 //這邊要注意因為縱軸座標是 i 橫軸座標是 j 所以要寫成 (j,i) ;
							 int R = Convert::ToInt32(RGB.R);
							 int G = Convert::ToInt32(RGB.G);
							 int B = Convert::ToInt32(RGB.B);
							 //RGB 是VS內建的class 可以直接讀取影像的色彩資訊 R = Red G = Green B =Blue

							 temp_img->SetPixel(j, i, Color::FromArgb(R, G, B));
						 }
					 
					 pictureBox2->Image = nullptr;
					 pictureBox3->Image = nullptr;
					 pictureBox4->Image = nullptr;
						 
				 }	
				 label1->Text = "load image ";
			 } //button

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		Bitmap^ GrayScale = BGR2gray(temp_img);
		pictureBox2->Image = nullptr;
		pictureBox3->Image = nullptr;
		pictureBox4->Image = nullptr;
		pictureBox2->Image = GrayScale;
		label1->Text = "Gray Scale";




	}; //Form
private: System::Void button3_Click_1(System::Object^  sender, System::EventArgs^  e) {

	Bitmap^ R_img = gcnew Bitmap(temp_img->Width, temp_img->Height);
	Bitmap^ G_img = gcnew Bitmap(temp_img->Width, temp_img->Height);
	Bitmap^ B_img = gcnew Bitmap(temp_img->Width, temp_img->Height);

	for (int i = 0; i < temp_img->Height; i++)
		for (int j = 0; j <temp_img->Width; j++)
		{
			Color RGB = temp_img->GetPixel(j, i);
			//讀取影像平面上 (j,i) 的 RGB 資訊
			//這邊要注意因為縱軸座標是 i 橫軸座標是 j 所以要寫成 (j,i) ;

			int R = Convert::ToInt32(RGB.R);
			int G = Convert::ToInt32(RGB.G);
			int B = Convert::ToInt32(RGB.B);
			//RGB 是VS內建的class 可以直接讀取影像的色彩資訊 R = Red G = Green B =Blue

			R_img->SetPixel(j, i, Color::FromArgb(R, R, R));
			G_img->SetPixel(j, i, Color::FromArgb(G, G, G));
			B_img->SetPixel(j, i, Color::FromArgb(B, B, B));
		}
	pictureBox2->Image = nullptr;
	pictureBox3->Image = nullptr;
	pictureBox4->Image = nullptr;
	pictureBox2->Image = R_img;
	pictureBox3->Image = G_img;
	pictureBox4->Image = B_img;
	label1->Text = "Color extraction";
	
	}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap^ Gray_img = BGR2gray(temp_img);
	int vector_size = Gray_img->Width * Gray_img->Height;
	int *img_vector = Bmp2vector(Gray_img);
	int *sobel = Sobel(img_vector, Gray_img->Width, Gray_img->Height);
	Bitmap^ Sobel_img = Vector2bmp(sobel, Gray_img->Width, Gray_img->Height);
	pictureBox2->Image = nullptr;
	pictureBox3->Image = nullptr;
	pictureBox4->Image = nullptr;
	pictureBox2->Image = Sobel_img;
	label1->Text = "Sobel_img";
}

private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap^ Gray_img = BGR2gray(temp_img);
	int vector_size = Gray_img->Width * Gray_img->Height;
	int *img_vector = Bmp2vector(Gray_img);
	int *eq = eqhi(img_vector, Gray_img->Width, Gray_img->Height);
	Bitmap^ eqhi_img = Vector2bmp(eq, Gray_img->Width, Gray_img->Height);
	pictureBox2->Image = nullptr;
	pictureBox3->Image = nullptr;
	pictureBox4->Image = nullptr;
	pictureBox3->Image = Gray_img;
	pictureBox4->Image = eqhi_img;
	label1->Text = "Histogram Equalization";
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	
	Bitmap^ Gray_img = BGR2gray(temp_img);
	int vector_size = Gray_img->Width * Gray_img->Height;
	int *img_vector = Bmp2vector(Gray_img);
	int *threshold_v = threshold(img_vector, Gray_img->Width, Gray_img->Height, 100);
	int *erosion_vector = erosion(threshold_v, Gray_img->Width, Gray_img->Height);
	Bitmap^ threshold_img = Vector2bmp(threshold_v, Gray_img->Width, Gray_img->Height);
	Bitmap^ erosion_img = Vector2bmp(erosion_vector, Gray_img->Width, Gray_img->Height);
	pictureBox2->Image = nullptr;
	pictureBox3->Image = nullptr;
	pictureBox4->Image = nullptr;
	pictureBox3->Image = threshold_img;
	pictureBox4->Image = erosion_img;
	label1->Text = "erosion_(default 100)";
	

}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap^ Gray_img = BGR2gray(temp_img);
	int vector_size = Gray_img->Width * Gray_img->Height;
	int *img_vector = Bmp2vector(Gray_img);
	int *threshold_v = threshold(img_vector, Gray_img->Width, Gray_img->Height,100);
	Bitmap^ threshold_img = Vector2bmp(threshold_v, Gray_img->Width, Gray_img->Height);
	pictureBox2->Image = nullptr;
	pictureBox3->Image = nullptr;
	pictureBox4->Image = nullptr;
	pictureBox3->Image = Gray_img;
	pictureBox4->Image = threshold_img;
	label1->Text = "threshold default(100)";

}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {

	Bitmap^ Gray_img = BGR2gray(temp_img);
	int vector_size = Gray_img->Width * Gray_img->Height;
	int *img_vector = Bmp2vector(Gray_img);
	int *threshold_v = threshold(img_vector, Gray_img->Width, Gray_img->Height, 100);
	int *dilation_v= dilation(threshold_v, Gray_img->Width, Gray_img->Height);
	Bitmap^ threshold_img = Vector2bmp(threshold_v, Gray_img->Width, Gray_img->Height);
	Bitmap^ dilation_img = Vector2bmp(dilation_v, Gray_img->Width, Gray_img->Height);
	pictureBox2->Image = nullptr;
	pictureBox3->Image = nullptr;
	pictureBox4->Image = nullptr;
	pictureBox3->Image = threshold_img;
	pictureBox4->Image = dilation_img;
	label1->Text = "dilation_(default 100)";
}
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap^ Gray_img = BGR2gray(temp_img);
	int vector_size = Gray_img->Width * Gray_img->Height;
	int *img_vector = Bmp2vector(Gray_img);
	int *Mean_v = Mean_filter(img_vector, Gray_img->Width, Gray_img->Height);
	Bitmap^ Meanf_img = Vector2bmp(Mean_v, Gray_img->Width, Gray_img->Height);
	pictureBox2->Image = nullptr;
	pictureBox3->Image = nullptr;
	pictureBox4->Image = nullptr;
	pictureBox4->Image = Meanf_img;
	pictureBox3->Image = Gray_img;
	label1->Text = "Mean_filter";
}
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap^ Gray_img = BGR2gray(temp_img);
	int vector_size = Gray_img->Width * Gray_img->Height;
	int *img_vector = Bmp2vector(Gray_img);
	int *Median_v = Median_filter(img_vector, Gray_img->Width, Gray_img->Height);
	Bitmap^ Median_img = Vector2bmp(Median_v, Gray_img->Width, Gray_img->Height);
	pictureBox2->Image = nullptr;
	pictureBox3->Image = nullptr;
	pictureBox4->Image = nullptr;
	pictureBox4->Image = Median_img;
	pictureBox3->Image = Gray_img;
	label1->Text = "Median_img";
}

private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap^ Gray_img = BGR2gray(temp_img);
	int vector_size = Gray_img->Width * Gray_img->Height;
	int *img_vector = Bmp2vector(Gray_img);
	int *sobel_vector = Sobel(img_vector, Gray_img->Width, Gray_img->Height);
	int *threshold_v = threshold(sobel_vector, Gray_img->Width, Gray_img->Height, 100);
	Bitmap^ Sobel_img = Vector2bmp(threshold_v, Gray_img->Width, Gray_img->Height);
	Bitmap^ Edge_img = Edge_over(img_vector, threshold_v, Gray_img->Width, Gray_img->Height);

	pictureBox2->Image = nullptr;
	pictureBox3->Image = nullptr;
	pictureBox4->Image = nullptr;
	pictureBox3->Image = Sobel_img;
	pictureBox4->Image = Edge_img;
	label1->Text = "EdgeOverlapp";
}
}; //public

}

