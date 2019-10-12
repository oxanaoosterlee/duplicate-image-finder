//
// Created by oxana on 10-10-19.
//

#include "MiniatureImage.h"

MiniatureImage::MiniatureImage(QWidget *parent, Image *image) : QLabel(parent) {
 image_ = image;
 this->setCursor(Qt::PointingHandCursor);
 QPixmap qpixmap = QPixmap();
 qpixmap.load(image->getPathQString());
 this->setPixmap(qpixmap.scaledToWidth(miniature_width,  Qt::SmoothTransformation));

}

void MiniatureImage::mousePressEvent(QMouseEvent *event) {
    std::cout << "MiniatureImage is clicked on \n";
    emit clicked(image_);
}

void MiniatureImage::updateImage(Image *image) {
    image_ = image;

}

