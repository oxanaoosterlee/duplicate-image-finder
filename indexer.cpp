//
// Created by oxana on 22-9-19.
//

#include <iostream>
#include "indexer.h"
#include <QDirIterator>

///media/Data/Pictures/Nova

// Load image and directly apply greyscale and rescaling
cv::Mat ImageIndexer::LoadImage(const std::string& filename) {
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
    QString root = QString::fromStdString(root_path);
    //QString root = QString("/home/oxana/Documents/Projects/Duplicate Image Search/Images")
    //todo: try/catch statement for invalid path
    //todo: add more extensions if necessary
    //todo: no images found error/handler

    QStringList extensions = {"*.jpg", "*.JPG", "*.PNG", "*.png"};
    QDirIterator it(root, extensions, QDir::NoFilter, QDirIterator::Subdirectories);//, QDirIterator::Subdirectories);
    while(it.hasNext()) {
        it.next();
        Image new_image = Image(LoadImage(it.filePath().toStdString()), it.filePath());
        std::cout << "image: " << new_image.getFileNameString() << "\n";
        image_list.push_back(new_image);
    }
    return image_list;
}
