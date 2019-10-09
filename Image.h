//
// Created by oxana on 24-9-19.
//

#ifndef DUPLICATE_IMAGE_FINDER_IMAGE_H
#define DUPLICATE_IMAGE_FINDER_IMAGE_H

#include <iostream>
#include <filesystem>
#include <opencv2/core/core.hpp>
#include <QtCore>

class Image {

public:
    Image(cv::Mat image, QString path_name);
    ~Image();


    //  Getters and setters
    const QString& getPathQString();
    const std::string getPathStdString();
    const std::string getFilenameStdString();
    const cv::Mat &getImage();


private:
    cv::Mat image_;
    QString path_ ;
};


#endif //DUPLICATE_IMAGE_FINDER_IMAGE_H
