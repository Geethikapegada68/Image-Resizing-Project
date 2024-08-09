#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>

void resizeWithOpenCV(const cv::Mat& src, cv::Mat& dst, int interpolation);
void measurePerformance(const cv::Mat& src, int interpolation);

int main() {
    // Load the image
    cv::Mat img = cv::imread("C:/Users/Geethika Pegada/Documents/CPP/G178_2-1080.BMP");
    if (img.empty()) {
        std::cerr << "Error: Could not load image!" << std::endl;
        return 1;
    }

    // Measure performance for each interpolation method
    measurePerformance(img, cv::INTER_NEAREST);
    measurePerformance(img, cv::INTER_LINEAR);
    measurePerformance(img, cv::INTER_CUBIC);

    return 0;
}

void resizeWithOpenCV(const cv::Mat& src, cv::Mat& dst, int interpolation) {
    cv::resize(src, dst, cv::Size(src.cols / 2, src.rows / 2), 0, 0, interpolation);
}

void measurePerformance(const cv::Mat& src, int interpolation) {
    cv::Mat dst;
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 1000; ++i) {
        resizeWithOpenCV(src, dst, interpolation);
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::string method;
    if (interpolation == cv::INTER_NEAREST) method = "INTER_NEAREST";
    else if (interpolation == cv::INTER_LINEAR) method = "INTER_LINEAR";
    else if (interpolation == cv::INTER_CUBIC) method = "INTER_CUBIC";

    std::cout << "Time taken for 1000 iterations using " << method << ": " << duration << " ms" << std::endl;
}
