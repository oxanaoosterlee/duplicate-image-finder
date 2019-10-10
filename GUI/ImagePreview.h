//
// Created by oxana on 9-10-19.
//

#ifndef DUPLICATE_IMAGE_FINDER_IMAGEPREVIEW_H
#define DUPLICATE_IMAGE_FINDER_IMAGEPREVIEW_H

#include <QtGui>
#include <QtWidgets>
#include <QWidget>
#include "../Image.h"

class ImagePreview : public QWidget{
    Q_OBJECT

public slots:
    void changeToGrey();

public:
    ImagePreview();
    virtual ~ImagePreview();
    QGroupBox *getWidget();
    void update(Image *left_image, Image *right_image);



private:
    QGroupBox *image_preview_groupbox;
    QLabel *image_left;
    QLabel *image_right;
};


#endif //DUPLICATE_IMAGE_FINDER_IMAGEPREVIEW_H
