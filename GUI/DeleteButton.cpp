//
// Created by oxana on 13-10-19.
//

#include <QtWidgets/QFileIconProvider>
#include "DeleteButton.h"

DeleteButton::DeleteButton(QWidget* parent, PreviewImage* preview_image) : QPushButton(parent) {
    preview_image_ = preview_image;
    QFileIconProvider *icon_provider = new QFileIconProvider;
    QIcon trashcan = icon_provider->icon(QFileIconProvider::Trashcan);
    this->setIcon(trashcan);
    this->setFixedWidth(button_size);
    delete icon_provider;

    connect(this, &QPushButton::pressed, this, &DeleteButton::deleteImage);
}



void DeleteButton::deleteImage(){
    //todo: Implement cross-platformis  #sad
    std::cout << "Deleting image theoretically \n";
    emit(imageDeleted());
    //delete file;
}
