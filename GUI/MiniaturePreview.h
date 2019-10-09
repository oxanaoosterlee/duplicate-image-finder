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

class MiniaturePreview {
public:
    MiniaturePreview();
    virtual ~MiniaturePreview();
    QGroupBox *getWidget();
    void update(DuplicateVector *duplicate_vector);

private:
    QGroupBox *miniature_groupbox;
    QHBoxLayout *layout;
    int miniature_width = 100;
};


#endif //DUPLICATE_IMAGE_FINDER_MINIATUREPREVIEW_H
