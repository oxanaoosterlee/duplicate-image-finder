//
// Created by oxana on 22-9-19.
//

#include <iostream>
#include "image_loader.h"


// Load image and directly apply greyscale and rescaling
cv::Mat ImageLoader::load_image(std::string filename) {
    cv::Mat image = cv::imread(filename, cv::IMREAD_GRAYSCALE );
    if (image.data == NULL){
        std::cout << "Could not open image " << filename << std::endl;
    }
    return resize_image(image);
}

// Scale image to 64x64
cv::Mat ImageLoader::resize_image(cv::Mat large_image){
    cv::Mat resized_image;
    cv::resize(large_image, resized_image, cv::Size(64,64));
    return resized_image;

}