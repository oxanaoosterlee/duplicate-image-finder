//
// Created by oxana on 24-9-19.
//
#include <iostream>
#include <filesystem>
#include <opencv2/core/core.hpp>

#ifndef DUPLICATE_IMAGE_FINDER_IMAGEWITHDUPLICATES_H
#define DUPLICATE_IMAGE_FINDER_IMAGEWITHDUPLICATES_H


class Image {


private:
    cv::Mat image_;
    std::filesystem::path path_;
public:
    const std::filesystem::path &getPath() const;

private:


    struct duplicate_image_t  {std::filesystem::path path; double percentage;};
    std::vector<duplicate_image_t> duplicate_images_;

public:
    Image(cv::Mat image, std::filesystem::path path_name);

    const cv::Mat &getImage();
    const std::string getPathString();
    const std::string getFileNameString();
    void addDuplicateImage(std::filesystem::path path, double percentage);
    void printDuplicates();



};


#endif //DUPLICATE_IMAGE_FINDER_IMAGEWITHDUPLICATES_H
