//
// Created by oxana on 9-10-19.
//

#include <QtCore/QString>
#include "ImagePreview.h"

ImagePreview::ImagePreview() {

    QString image = "/home/oxana/Documents/Projects/Duplicate Image Search/Images/img4.jpg";

    image_preview_groupbox = new QGroupBox;
    QHBoxLayout *layout = new QHBoxLayout;

    QPixmap *qpixmap = new QPixmap;
    qpixmap->load(image);

    image_left = new QLabel();
    image_right = new QLabel();
    image_left->setAlignment(Qt::AlignCenter);
    image_right->setAlignment(Qt::AlignCenter);

    image_left->setPixmap(qpixmap->scaled(200,200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    image_right->setPixmap(qpixmap->scaled(200,200, Qt::KeepAspectRatio, Qt::SmoothTransformation));


    layout->addWidget(image_left);
    layout->addWidget(image_right);

    image_preview_groupbox->setLayout(layout);
}

ImagePreview::~ImagePreview() {

}

QGroupBox *ImagePreview::getWidget() {
    return image_preview_groupbox;
}

void ImagePreview::update(Image *left_image, Image *right_image) {
    std::cout << "Updating image preview" << "\n";

    QPixmap qpixmap1;
    qpixmap1.load(left_image->getPathQString());
    image_left->setPixmap(qpixmap1.scaled(400,400, Qt::KeepAspectRatio, Qt::SmoothTransformation));


    QPixmap qpixmap2;
    qpixmap2.load(right_image->getPathQString());
    image_right->setPixmap(qpixmap2.scaled(400,400, Qt::KeepAspectRatio, Qt::SmoothTransformation));

}

void ImagePreview::changeToGrey() {
    std::cout << "Changed to grey \n";
}
