
#include "UserImageController.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include "../imageConverterPackage/ImageConverter.h"

namespace UserImageController
{

    int startProgram()
    {
        auto videoCapture = cv::VideoCapture(0);
        cv::Mat frame;
        if(!videoCapture.isOpened())
        {
            std::cerr << "Error: can't use video camera" << std::endl;
            return 1;
        }

        while (cv::waitKey(33) != 113)
        {
            if(videoCapture.read(frame)) {
                cv::imshow("", ImageConverter::convertImageToAscii(frame));
            } else {
                videoCapture.release();
                cv::destroyAllWindows();
                return 1;
            }
        }
        videoCapture.release();
        cv::destroyAllWindows();
        return 0;
    }
}