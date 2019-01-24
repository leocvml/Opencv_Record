# OpenCV_Cuda_on_UBuntu

# this document is for how to install opencv with cuda on ubuntu 

**environment**  
OS: ubuntu 14.04  
opencv: 2.4.13  
cuda: 7.5  


**step**  
 ### 1.check your gpu is ready (driver)
    find out the model of your graphics card    
    **$ lspci -vnn | grep -i VGA -A 12**  
 ### 2. download cuda from nvidia website  (cuda 7.5)
    Installation Instructions:  
`sudo dpkg -i cuda-repo-"verision".deb`  
`sudo apt-get update`  
`sudo apt-get install cuda`  
 ### 3.Verify that the CUDA Toolkit is installed on your device: 
`$ nvcc -V**`    
 ### 4. Make sure you update and upgrade your PC.  
`sudo apt-get update`
`sudo apt-get upgrade`  
 ### 5. Remove previously installed FFMPEG and x264 libraries  
 ``sudo apt-get install ocl-icd-libopencl1 build-essential checkinstall cmake pkg-config``   
``yasm libjpeg-dev libjasper-dev libavcodec-dev libavformat-dev libswscale-dev``   
``libdc1394-22-dev libxine-dev libgstreamer0.10-dev libgstreamer-plugins-base0.10-dev``   
``libv4l-dev python-dev python-numpy libtbb-dev libqt4-dev libgtk2.0-dev libfaac-dev``   
``libmp3lame-dev libopencore-amrnb-dev libopencore-amrwb-dev libtheora-dev libvorbis-dev``   
``libxvidcore-dev x264 v4l-utils``  
### 6. Now download the OpenCV-2.4.13 source:
```Unzip it:
   unzip opencv-2.4.13.zip
    mkdir build
       cd build
```
### 7. cmake (care your gpu model(XX)  https://developer.nvidia.com/cuda-gpus)  
```  
cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D CUDA_ARCH_BIN=”X.X” 
-D BUILD_opencv_nonfree=ON -D WITH_V4L=ON -D CUDA_ARCH_PTX=”X.X” ..  
```
### 8. make  
`make -j4  // -j?  how many core do you have `  
### 9. install  
`sudo make install ` 
### 10. add Path  
  #### 10.1 part 1
```
sudo gedit /etc/ld.so.conf 
```
in this document /etc/ld.so.conf add
```
/usr/local/lib 
sudo ldconfig -v  
```
*********************************
  #### 10.2 part 2
```
sudo gedit /etc/profile 
```
in the last line add
```
export  PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/usr/local/lib/pkgconfig
sudo source /etc/profile
```
  #### 10.3 part 3
 ```
 pkg-config --libs opencv
 ```
 ### congratulations!!! you are already finished  
 ***RUN Test***  
 ***cd /root/opencv-2.4.8/samples/c/  
chmod a+x build_all.sh  
./build_all.sh  
./find_obj***  

 

 
 

