//
// Created by oxana on 9-10-19.
//

#ifndef DUPLICATE_IMAGE_FINDER_PREVIEWBOX_H
#define DUPLICATE_IMAGE_FINDER_PREVIEWBOX_H

#include <QtGui>
#include <QtWidgets>
#include <QWidget>
#include "../Image.h"
#include "PreviewImage.h"


class PreviewBox : public QWidget{
    Q_OBJECT

public slots:
    void makePreviewsClickable(bool val);
    void receiveMiniatureChange(PreviewImage* preview_image, Image* image);

signals:
    void requestInfoUpdate(Image* left_image, Image* right_image);
    void fileDeleted();

public:
    PreviewBox(QWidget *parent = nullptr);
    virtual ~PreviewBox();
    QGroupBox *getWidget();
    void update(Image *left_image, Image *right_image);
    std::vector<PreviewImage*>*  getPreviews();



private:
    QGroupBox* image_preview_groupbox;
    std::vector<PreviewImage*> image_previews_;
    QPushButton* generateDeleteButton();

};


#endif //DUPLICATE_IMAGE_FINDER_PREVIEWBOX_H
