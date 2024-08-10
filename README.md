# Image Resizing Project

## Overview

This project is a C++ application for resizing images using OpenCV. It provides functionality to resize images with different interpolation methods and evaluates their performance.

## Project Status

The project has been completed. It includes:

- An implementation of image resizing using OpenCV’s `cv::resize` function.
- Custom code for resizing images.
- Performance evaluation of different interpolation methods.

## Prerequisites

- **OpenCV 4.x**: Ensure OpenCV is installed. The binaries are expected to be located in `C:\OpenCV\opencv\build\x64\vc16\bin`.
- **Visual Studio 2022**: Required for building and running the project.

## Installation

1. **Clone the Repository**

   
   git clone https://github.com/Geethikapegada68/Image-Resizing-Project.git
Open and Configure the Project

Open Visual Studio 2022.
Select File > Open > Project/Solution.
Navigate to and open ImageResize.sln from the cloned repository.
Configure the project settings:
Go to Project > Properties.
Set Include Directories to C:\OpenCV\opencv\build\include.
Set Library Directories to C:\OpenCV\opencv\build\x64\vc16\lib.
Under Linker > Input, add opencv_world4100.lib to Additional Dependencies.
Build the Project

Select Build > Build Solution or press Ctrl+Shift+B.

Run the Application

Navigate to the output directory (e.g., Debug or Release).
Run ImageResize.exe.
Command-Line Arguments


ImageResize.exe [input_image_path] [output_image_path] [resize_width] [resize_height] [interpolation_method]
input_image_path: Path to the input image.
output_image_path: Path to save the resized image.
resize_width: Width of the resized image.
resize_height: Height of the resized image.
interpolation_method: Method for resizing (e.g., cv::INTER_LINEAR).
Example
ImageResize.exe input.jpg output.jpg 800 600 cv::INTER_LINEAR
Comments
The code includes detailed comments explaining the use of cv::resize, the custom resizing function, and the performance evaluation of various interpolation methods.
