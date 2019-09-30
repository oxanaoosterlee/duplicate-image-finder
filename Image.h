//
// Created by oxana on 24-9-19.
//
#include <iostream>
#include <filesystem>
#include <opencv2/core/core.hpp>
#include <QtCore>

#ifndef DUPLICATE_IMAGE_FINDER_IMAGEWITHDUPLICATES_H
#define DUPLICATE_IMAGE_FINDER_IMAGEWITHDUPLICATES_H


class Image {


private:
    cv::Mat image_;
    QString path_;
public:
    const QString & getPath() const;

private:


    struct duplicate_image_t  {QString path; double percentage;};
    std::vector<duplicate_image_t> duplicate_images_;

public:
    Image(cv::Mat image, QString path_name);

    const cv::Mat &getImage();
    const std::string getPathString();
    const std::string getFileNameString();
    void addDuplicateImage(QString path, double percentage);
    void printDuplicates();
    std::vector<duplicate_image_t> getDuplicateImages();



};


#endif //DUPLICATE_IMAGE_FINDER_IMAGEWITHDUPLICATES_H
