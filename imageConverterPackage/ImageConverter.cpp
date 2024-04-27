//
// Created by nikodem on 22.12.23.
//

#include "ImageConverter.h"
#include <vector>
#include <iostream>
#include <opencv2/opencv.hpp>

namespace ImageConverter {

    const static int intervalSize = 64;
    const static int startingAsciiCharValue = 58;

    std::vector<uint8_t> readImage(const std::string& imageFilePath) {
        std::ifstream file(imageFilePath, std::ios::binary);

        if (!file.is_open()) {
            std::cerr << "Error: Unable to open the file: " << imageFilePath << std::endl;
            return {};
        }

        file.seekg(0, std::ios::end);
        std::streampos fileSize = file.tellg();
        file.seekg(0, std::ios::beg);

        std::vector<uint8_t> fileData(fileSize);
        file.read(reinterpret_cast<char *>(&fileData[0]), fileSize);

        file.close();

        return fileData;
    }

    int calculateInterval(int value)
    {
        int interval_index = 0;
        while (value > interval_index*intervalSize)
            interval_index++;
        return interval_index;
    }

    uint8_t convertPixelToAscii(const cv::Vec3b& pixel)
    {
        return static_cast<uchar>(
                startingAsciiCharValue +
                (calculateInterval(static_cast<int>(pixel[0])) * 16) +
                (calculateInterval(static_cast<int>(pixel[1])) * 4) +
                (calculateInterval(static_cast<int>(pixel[2]))));
    }

    cv::Mat convertImageToAscii(const cv::Mat& image)
    {
        cv::Mat asciiImage(image.rows, image.cols, CV_8UC1);
        for (int y = 0; y < image.rows; ++y) {
            for (int x = 0; x < image.cols; ++x) {
                asciiImage.at<uchar>(y, x) = convertPixelToAscii(image.at<cv::Vec3b>(y, x));
            }
        }
        return asciiImage;
    }

    std::optional<cv::Mat> cvReadImage(const std::string& imageFilePath)
    {
        cv::Mat image = cv::imread(imageFilePath, cv::IMREAD_COLOR);
        if (image.empty()) {
            std::cerr << "[Error] Unable to read the image file: " << imageFilePath << std::endl;
            return {};
        }
        return image;
    }

} // ImageConverter