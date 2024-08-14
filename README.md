Overview
This project is a C++ application designed for resizing images using OpenCV. It provides functionality to resize images using different interpolation methods and evaluates their performance. The application demonstrates both standard OpenCV resizing capabilities and custom resizing methods.

Project Status
The project has been completed and includes several key components. It features an implementation of image resizing using OpenCV’s cv::resize function. Additionally, custom code for resizing images is provided, which uses manual bilinear interpolation. The project also includes performance evaluations for different interpolation methods.

Prerequisites
To build and run this project, ensure that the following prerequisites are met:

OpenCV 4.x: OpenCV must be installed on your system. The binaries should be located in C:\OpenCV\opencv\build\x64\vc16\bin.
Visual Studio 2022: This IDE is required for building and running the project. Make sure you have Visual Studio 2022 installed on your machine.
Installation
Follow these steps to set up the project on your local machine:

Clone the Repository

Use Git to clone the repository to your local machine with the following command:

git clone https://github.com/Geethikapegada68/Image-Resizing-Project.git

Open and Configure the Project

Open Visual Studio 2022.
Navigate to File > Open > Project/Solution, and open the ImageResize.sln file from the cloned repository.
Configure the project settings as follows:
Go to Project > Properties.
Set the Include Directories to C:\OpenCV\opencv\build\include.
Set the Library Directories to C:\OpenCV\opencv\build\x64\vc16\lib.
Under Linker > Input, add opencv_world4100.lib to the Additional Dependencies.
Build the Project

Build the project by selecting Build > Build Solution or pressing Ctrl+Shift+B.

Run the Application

After building, navigate to the output directory (e.g., Debug or Release) and run ImageResize.exe.

Command-Line Arguments
The application accepts the following command-line arguments:

input_image_path: The path to the input image that you want to resize.
output_image_path: The path where the resized image will be saved.
resize_width: The width of the resized image.
resize_height: The height of the resized image.
interpolation_method: The interpolation method to be used for resizing (e.g., cv::INTER_LINEAR).



Comments
The codebase includes detailed comments that explain the functionality of cv::resize, the custom resizing function, and the performance evaluation of various interpolation methods. These comments are intended to aid in understanding the implementation and evaluation processes used in the project.


