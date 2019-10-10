//
// Created by oxana on 10-10-19.
//

#include "Miniature.h"

Miniature::Miniature(QWidget *parent, Image *image) : QLabel(parent) {
 image_ = image;
}

void Miniature::mousePressEvent(QMouseEvent *event) {
    std::cout << "Miniature is clicked on \n";
    emit clicked(image_);
}

