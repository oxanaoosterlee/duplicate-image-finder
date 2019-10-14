//
// Created by oxana on 10-10-19.
//

#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include "MiniatureImage.h"

MiniatureImage::MiniatureImage(QWidget *parent, Image *image) : QLabel(parent) {

    // Set image
    image_ = image;
    QPixmap qpixmap = QPixmap();
    qpixmap.load(image->getPathQString());
    this->setPixmap(qpixmap.scaled(miniature_width, miniature_width, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    this->resize(qpixmap.size());
    this->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

    // Set cursor
    this->setCursor(Qt::PointingHandCursor);

    //Set checkbox
    checkbox_ = new QCheckBox(this);
    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(checkbox_, 0, 0);
    checkbox_->setCheckState(image_->getSelected());
    this->setLayout(layout);
    connect(checkbox_, &QCheckBox::stateChanged, this, &MiniatureImage::checkBoxChanged);
}

void MiniatureImage::mousePressEvent(QMouseEvent *event) {
    std::cout << "MiniatureImage is clicked on \n";
    emit clicked(image_);
}


// Sets the 'selected' variable of the image of the miniature of the checkbox that was (unchecked).
void MiniatureImage::checkBoxChanged(int state){
    std::cout << "Checkbox of " << image_->getPathStdString() << " is " << state << "\n";
    Qt::CheckState checkstate = checkbox_->checkState();
    image_->setSelected(checkstate);
    emit(signalCheckBoxChange(checkstate));
}

void MiniatureImage::updateImage(Image *image) {
    image_ = image;
}

void MiniatureImage::updateCheckbox() {
    checkbox_->setCheckState(image_->getSelected());
}
