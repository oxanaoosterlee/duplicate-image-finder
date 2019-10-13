//
// Created by oxana on 11-10-19.
//

#include "PreviewImage.h"




PreviewImage::PreviewImage(QWidget *parent, Image *image) : QLabel(parent) {
    image_ = image;
    this->setAlignment(Qt::AlignCenter);
    setClickable(false);
}


void PreviewImage::mousePressEvent(QMouseEvent *event) {
    if (clickable) {
        std::cout << "Image preview image clicked \n";
        emit clicked(this);
    }
}

void PreviewImage::userUndoClick() {
    setClickable(false);
}

void PreviewImage::setClickable(bool val) {
    clickable = val;
    if (clickable){
        this->setCursor(Qt::PointingHandCursor);
    }
    else{this->setCursor(Qt::ArrowCursor);}

}

void PreviewImage::updateImage(Image *image) {
    image_ = image;
    QPixmap qpixmap;
    qpixmap.load(image_->getPathQString());
    this->setPixmap(qpixmap.scaled(400,400, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}


Image *PreviewImage::getImage() {
    return image_;
}
