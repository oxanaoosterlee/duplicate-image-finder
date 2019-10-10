//
// Created by oxana on 9-10-19.
//

#ifndef DUPLICATE_IMAGE_FINDER_MINIATUREPREVIEW_H
#define DUPLICATE_IMAGE_FINDER_MINIATUREPREVIEW_H

#include <QtGui>
#include <QtWidgets>
#include <QWidget>
#include "../Image.h"
#include "../DuplicateVector.h"
#include "Miniature.h"
#include "ImagePreview.h"

class MiniaturePreview {
public:
    MiniaturePreview();
    virtual ~MiniaturePreview();
    QGroupBox *getWidget();
    void update(DuplicateVector *duplicate_vector, ImagePreview *image_preview);
    QWidget* getMiniature(int pos);

private:
    QGroupBox *miniature_groupbox;
    QHBoxLayout *layout;
    int miniature_width = 100;
};


#endif //DUPLICATE_IMAGE_FINDER_MINIATUREPREVIEW_H

