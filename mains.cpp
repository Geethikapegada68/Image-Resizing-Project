#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>

// Custom resize function using bilinear interpolation
void customBilinearResize(const cv::Mat& src, cv::Mat& dst, int newWidth, int newHeight) {
    // Create the destination image with the new size
    dst.create(newHeight, newWidth, src.type());

    // Calculate the scaling factors
    float scaleX = static_cast<float>(src.cols) / newWidth;
    float scaleY = static_cast<float>(src.rows) / newHeight;

    for (int y = 0; y < newHeight; ++y) {
        for (int x = 0; x < newWidth; ++x) {
            // Calculate the position in the source image
            float srcX = x * scaleX;
            float srcY = y * scaleY;

            // Get the integer coordinates of the top-left corner of the pixel
            int x1 = static_cast<int>(srcX);
            int y1 = static_cast<int>(srcY);
            int x2 = std::min(x1 + 1, src.cols - 1);
            int y2 = std::min(y1 + 1, src.rows - 1);

            // Calculate the weights for interpolation
            float alpha = srcX - x1;
            float beta = srcY - y1;

            // Fetch the pixel values from the source image
            cv::Vec3b A = src.at<cv::Vec3b>(y1, x1);
            cv::Vec3b B = src.at<cv::Vec3b>(y1, x2);
            cv::Vec3b C = src.at<cv::Vec3b>(y2, x1);
            cv::Vec3b D = src.at<cv::Vec3b>(y2, x2);

            // Perform bilinear interpolation
            cv::Vec3b top = (1 - alpha) * A + alpha * B;
            cv::Vec3b bottom = (1 - alpha) * C + alpha * D;
            cv::Vec3b pixel = (1 - beta) * top + beta * bottom;

            // Assign the interpolated pixel to the destination image
            dst.at<cv::Vec3b>(y, x) = pixel;
        }
    }
}

// Function to resize an image using OpenCV's cv::resize
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
    
    std::cout << "OpenCV resize took " << elapsed.count() << " seconds." << std::endl;

    // Save the resized image to file
    if (!cv::imwrite(outputPath, resizedImage)) {
        std::cerr << "Error saving image: " << outputPath << std::endl;
    }
}

// Function to perform custom resizing and measure time
void customResizeImage(const std::string& inputPath, const std::string& outputPath, int newWidth, int newHeight) {
    // Load the image from file
    cv::Mat image = cv::imread(inputPath);
    if (image.empty()) {
        std::cerr << "Error loading image: " << inputPath << std::endl;
        return;
    }

    // Perform custom resizing
    cv::Mat resizedImage;
    auto start = std::chrono::high_resolution_clock::now();
    customBilinearResize(image, resizedImage, newWidth, newHeight);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    
    std::cout << "Custom resize took " << elapsed.count() << " seconds." << std::endl;

    // Save the resized image to file
    if (!cv::imwrite(outputPath, resizedImage)) {
        std::cerr << "Error saving image: " << outputPath << std::endl;
    }
}

int main() {
    // Paths for input and output images
    std::string inputPath = "C:\\G178_1-1080.BMP";
    std::string outputPathOpenCV = "output_opencv.jpg";
    std::string outputPathCustom = "output_custom.jpg";

    // Define new dimensions
    int newWidth = 800;
    int newHeight = 600;

    // Perform resizing using OpenCV
    resizeImage(inputPath, outputPathOpenCV, newWidth, newHeight, cv::INTER_LINEAR);

    // Perform custom resizing
    customResizeImage(inputPath, outputPathCustom, newWidth, newHeight);

    return 0;
}
