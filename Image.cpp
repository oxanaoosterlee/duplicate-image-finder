//
// Created by oxana on 24-9-19.
//

#include "Image.h"
#include <QtCore>


Image::Image(cv::Mat image, QString path_name) {
    image_ = image;
    path_ = path_name;
}

void Image::addDuplicateImage(QString path, double percentage) {
    duplicate_image_t new_duplicate_image;
    new_duplicate_image.path = path;
    new_duplicate_image.percentage = percentage;
    duplicate_images_.push_back(new_duplicate_image);

}

const cv::Mat &Image::getImage() {
    return image_;
}

const std::string Image::getPathString() {
    return path_.toStdString();
}

const QString & Image::getPath() const {
    return path_;
}

void Image::printDuplicates() {
    if (duplicate_images_.empty()){
        std::cout << getFileNameString() << " has no duplicates! \n";
    }
    else {
        std::cout << getFileNameString() << " has duplicates: \n";
        for (const auto& duplicate : duplicate_images_){
            std::cout << duplicate.path.toStdString() << " (" << (1-duplicate.percentage)*100 << "%)" "\n";
        }
    }

}

const std::string Image::getFileNameString() {
    QFileInfo info = QFileInfo(path_);
    return info.fileName().toStdString();
}

