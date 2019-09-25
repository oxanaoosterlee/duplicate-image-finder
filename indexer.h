//
// Created by oxana on 22-9-19.
//

#ifndef PROJECT_IMAGE_LOADER_H
#define PROJECT_IMAGE_LOADER_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include "Image.h"

class ImageIndexer{
public:
    cv::Mat LoadImage(std::string filename);
    cv::Mat ResizeImage(cv::Mat large_image);
    std::vector<std::string> GetFileNameList(std::string root_path);
    std::vector<Image> GenerateAllImagesList(std::string root_path);
    void DisplayImage(cv::Mat image);

};



#endif //PROJECT_IMAGE_LOADER_H
