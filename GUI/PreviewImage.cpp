//
// Created by oxana on 11-10-19.
//

#include <QtWidgets/QGridLayout>
#include "PreviewImage.h"




PreviewImage::PreviewImage(QWidget *parent, Image *image) : QLabel(parent) {
    image_ = image;
    setClickable(false);


    //Set checkbox
    checkbox_ = new QCheckBox(this);
    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(checkbox_, 0, 0);
    this->setLayout(layout);
    connect(checkbox_, &QCheckBox::stateChanged, this, &PreviewImage::checkBoxChanged);

}

void PreviewImage::checkBoxChanged(int state) {
    std::cout << "Checkbox of " << image_->getPathStdString() << " is " << state << "\n";
    Qt::CheckState checkstate = checkbox_->checkState();
    image_->setSelected(checkstate);
    emit(signalCheckBoxChange(checkstate));
}


void PreviewImage::mousePressEvent(QMouseEvent *event) {
    if (clickable) {
        std::cout << "Image preview image clicked \n";
        emit clicked(this);
    }
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
    checkbox_->setCheckState(image_->getSelected());
    QPixmap qpixmap;
    qpixmap.load(image_->getPathQString());
    this->setPixmap(qpixmap.scaled(400,400, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    this->resize(qpixmap.size());
    this->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

}


Image *PreviewImage::getImage() {
    return image_;
}

void PreviewImage::updateCheckbox() {
    checkbox_->setCheckState(image_->getSelected());
}
