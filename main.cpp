#include <iostream>
#include "imageConverterPackage/ImageConverter.h"
#include "userImageControllerPackage/UserImageController.h"
#include <string>
#include <opencv2/opencv.hpp>

int main() {
    auto image = ImageConverter::cvReadImage("/home/nikodem/CLionProjects/ImageToAsciiConverter/window.jpeg");
    if (!image)
        return 1;
    for (int y = 0; y < image->rows; ++y) {
        for (int x = 0; x < image->cols; ++x) {
            cv::Vec3b pixel = image->at<cv::Vec3b>(y, x);

            uchar blue = pixel[0];
            uchar green = pixel[1];
            uchar red = pixel[2];

            std::cout << "Pixel at (" << x << ", " << y << "): "
                      << "R = " << static_cast<int>(red) << ", "
                      << "G = " << static_cast<int>(green) << ", "
                      << "B = " << static_cast<int>(blue) << ", "
                      << "Char = " << (ImageConverter::convertPixelToAscii(pixel)) << std::endl;
        }
    }

    cv::imshow("Image", *image);
    cv::waitKey(0);
    cv::destroyAllWindows();

    auto asciiImage = ImageConverter::convertImageToAscii(*image);

    for (int y = 0; y < asciiImage.rows; ++y) {
        for (int x = 0; x < asciiImage.cols; ++x) {
            char pixel = asciiImage.at<char>(y,x);

            std::cout << "Pixel at (" << x << ", " << y << "): "
                      << "Char = " << pixel << std::endl;
        }
    }

    cv::imshow("AsciiImage", asciiImage);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return UserImageController::startProgram();
}
