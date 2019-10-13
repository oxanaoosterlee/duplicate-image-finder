//
// Created by oxana on 13-10-19.
//

#ifndef DUPLICATE_IMAGE_FINDER_DELETEBUTTON_H
#define DUPLICATE_IMAGE_FINDER_DELETEBUTTON_H


#include <QtWidgets/QPushButton>
#include "PreviewImage.h"

class DeleteButton : public QPushButton {
Q_OBJECT

signals:
    void imageDeleted();

public slots:

    void deleteImage();

public:
    explicit DeleteButton(QWidget *parent = 0, PreviewImage *preview_image = nullptr);

private:
    PreviewImage *preview_image_;
    int button_size = 100;
    void MoveToTrash(QString file);
};


#endif //DUPLICATE_IMAGE_FINDER_DELETEBUTTON_H
