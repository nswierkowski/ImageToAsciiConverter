#pragma once

#ifndef UNTITLED_IMAGECONVERTER_H
#define UNTITLED_IMAGECONVERTER_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <opencv2/opencv.hpp>

namespace ImageConverter {

    const static int defaultBufferLength = 1024;

    /* Reads the image into the byte vector */
    std::vector<uint8_t> readImage(const std::string& imageFilePath);

    /* Reads the image using an openCV library */
    std::optional<cv::Mat> cvReadImage(const std::string& imageFilePath);

    cv::Mat convertImageToAscii(const cv::Mat& image);

    uint8_t convertPixelToAscii(const cv::Vec3b& pixel);

} // ImageConverter

#endif //UNTITLED_IMAGECONVERTER_H
