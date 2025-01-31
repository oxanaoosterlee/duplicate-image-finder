//

// Created by oxana on 24-9-19.
//

#include "Image.h"
#include <utility>

Image::Image(cv::Mat image, QString path_name) {
    image_ = std::move(image);
    path_ = std::move(path_name);
    selected_ = Qt::Unchecked;
}


Image::~Image() = default;


const QString &Image::getPathQString() {
    return path_;
}

const std::string Image::getPathStdString() {
    return path_.toStdString();
}

const std::string Image::getFilenameStdString() {
    QFileInfo info = QFileInfo(path_);
    return info.fileName().toStdString();
}


const cv::Mat &Image::getImage() {
    return image_;
}

Qt::CheckState Image::getSelected() const {
    return selected_;
}

void Image::setSelected(Qt::CheckState selected) {
    selected_ = selected;
}

