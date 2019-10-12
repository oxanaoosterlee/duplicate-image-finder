//
// Created by oxana on 10-10-19.
//

#include "MiniatureImage.h"

MiniatureImage::MiniatureImage(QWidget *parent, Image *image) : QLabel(parent) {
 image_ = image;
 this->setCursor(Qt::PointingHandCursor);
}

void MiniatureImage::mousePressEvent(QMouseEvent *event) {
    std::cout << "MiniatureImage is clicked on \n";
    emit clicked(image_);
}

