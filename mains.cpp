#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>

// Define paths and parameters
const std::string inputPath = "C:\\G178_1-1080.BMP";
const std::string outputPath = "output.jpg";
const int width = 800;
const int height = 600;
const int interpolation = cv::INTER_LINEAR; // You can change this to other interpolation methods if needed

void resizeImage(const std::string& inputPath, const std::string& outputPath, int width, int height, int interpolation) {
    // Load the image from file
    cv::Mat image = cv::imread(inputPath);
    if (image.empty()) {
        std::cerr << "Error loading image: " << inputPath << std::endl;
        return;
    }

    // Resize the image
    cv::Mat resizedImage;
    auto start = std::chrono::high_resolution_clock::now();
    cv::resize(image, resizedImage, cv::Size(width, height), 0, 0, interpolation);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    
    std::cout << "Resizing took " << elapsed.count() << " seconds." << std::endl;

    // Save the resized image to file
    if (!cv::imwrite(outputPath, resizedImage)) {
        std::cerr << "Error saving image: " << outputPath << std::endl;
    }
}

int main() {
    // Perform image resizing
    resizeImage(inputPath, outputPath, width, height, interpolation);

    return 0;
}

