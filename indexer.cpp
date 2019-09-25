//
// Created by oxana on 22-9-19.
//

#include <iostream>
#include "indexer.h"
#include <filesystem>

///media/Data/Pictures/Nova

// Load image and directly apply greyscale and rescaling
cv::Mat ImageIndexer::LoadImage(std::string filename) {
    cv::Mat image = cv::imread(filename, cv::IMREAD_GRAYSCALE );
    if (image.data == NULL){
        std::cout << "Could not open image " << filename << std::endl;
    }
    return ResizeImage(image);
}

// Scale image to 64x64
cv::Mat ImageIndexer::ResizeImage(cv::Mat large_image){
    cv::Mat resized_image;
    cv::resize(large_image, resized_image, cv::Size(64,64));
    return resized_image;

}



void ImageIndexer::DisplayImage(cv::Mat image){
    cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE );// Create a window for display.
    cv::imshow( "Display window", image );                   // Show our image inside it.
    cv::waitKey(0);

}

std::vector<Image> ImageIndexer::GenerateAllImagesList(std::string root_path){
    std::vector<Image> image_list;
    std::filesystem::path root_dir(root_path);
    //todo: try/catch statement for invalid path
    //todo: add more extensions if necessary
    std::vector<std::string> extensions = {".jpg", ".JPG", ".PNG", ".png"};
    for(auto& file: std::filesystem::recursive_directory_iterator(root_dir)){
        for(auto &it : extensions){
            std::filesystem::path path = file.path();
            if(path.extension() == it){
                Image new_image = Image(LoadImage(path.string()), path.string());
                image_list.push_back(new_image);
            }
        }
    }
    return image_list;
}
