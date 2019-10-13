//
// Created by oxana on 9-10-19.
//

#ifndef DUPLICATE_IMAGE_FINDER_INFOBOX_H
#define DUPLICATE_IMAGE_FINDER_INFOBOX_H

#include <QtGui>
#include <QtWidgets>
#include <QWidget>
#include "../Image.h"
#include "PreviewImage.h"


class InfoBox : public QGroupBox{
    Q_OBJECT

public slots:
    void update(Image *left_image, Image *right_image);

public:
    InfoBox(QWidget* parent = nullptr);
    virtual ~InfoBox();
    QGroupBox *getWidget();


private:
    QGroupBox *image_info_groupbox;

    QLabel* percentage;


    QLabel* filename_left;
    QLabel* path_left;
    QLabel* filesize_left;
    QLabel* creation_date_left;

    QLabel* filename_right;
    QLabel* path_right;
    QLabel* filesize_right;
    QLabel* creation_date_right;

};


#endif //DUPLICATE_IMAGE_FINDER_INFOBOX_H
