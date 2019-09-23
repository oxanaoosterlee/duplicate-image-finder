//
// Created by oxana on 22-9-19.
//

#include <iostream>
#include "image_loader.h"
#include <filesystem>


///media/Data/Pictures/Nova

// Load image and directly apply greyscale and rescaling
cv::Mat ImageLoader::LoadImage(std::string filename) {
    cv::Mat image = cv::imread(filename, cv::IMREAD_GRAYSCALE );
    if (image.data == NULL){
        std::cout << "Could not open image " << filename << std::endl;
    }
    return ResizeImage(image);
}

// Scale image to 64x64
cv::Mat ImageLoader::ResizeImage(cv::Mat large_image){
    cv::Mat resized_image;
    cv::resize(large_image, resized_image, cv::Size(64,64));
    return resized_image;

}

// Returns a list of the paths of all images found in the designated folder and its subfolders.
std::vector<std::string> ImageLoader::GetFileList(std::string root_path){
    std::vector<std::string> image_list;
    std::filesystem::path dir(root_path);
    //todo: try/catch statement for invalid path
    //todo: add more extensions if necessary
    std::vector<std::string> extensions = {".jpg", ".JPG", ".PNG", ".png"};
    for(auto& file: std::filesystem::recursive_directory_iterator(dir)){
        for(auto &it : extensions){
            if(file.path().extension() == it){
                image_list.push_back(file.path().string());
            }
        }
    }
    return image_list;
}

void ImageLoader::DisplayImage(cv::Mat image){
    cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE );// Create a window for display.
    cv::imshow( "Display window", image );                   // Show our image inside it.
    cv::waitKey(0);

}

