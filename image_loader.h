//
// Created by oxana on 22-9-19.
//

#ifndef PROJECT_IMAGE_LOADER_H
#define PROJECT_IMAGE_LOADER_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

class ImageLoader{
public:
    ImageLoader();
    cv::Mat load_image(std::string filename);
    cv::Mat resize_image(cv::Mat large_image);

};



#endif //PROJECT_IMAGE_LOADER_H
