//
// Created by oxana on 9-10-19.
//

#ifndef DUPLICATE_IMAGE_FINDER_IMAGEINFO_H
#define DUPLICATE_IMAGE_FINDER_IMAGEINFO_H

#include <QtGui>
#include <QtWidgets>
#include <QWidget>
#include "../Image.h"


class ImageInfo {

public:
    ImageInfo();
    virtual ~ImageInfo();
    QGroupBox *getWidget();
    void update(Image *left_image, Image *right_image);

private:
    QGroupBox *image_info_groupbox;
    QLabel* left_image_text;
    QLabel* right_image_text;
    QLabel* label_text;
};


#endif //DUPLICATE_IMAGE_FINDER_IMAGEINFO_H
