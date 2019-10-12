//
// Created by oxana on 10-10-19.
//

#ifndef DUPLICATE_IMAGE_FINDER_MINIATUREIMAGE_H
#define DUPLICATE_IMAGE_FINDER_MINIATUREIMAGE_H


// Implements a clickable miniature

#include <QtWidgets/QLabel>
#include <QMouseEvent>
#include "../Image.h"
#include <QObject>

class MiniatureImage : public QLabel {
    Q_OBJECT

//public slots:
//    void userUndoClick();

signals:
    void clicked(Image* image);

public:
    explicit MiniatureImage(QWidget *parent=0, Image* image = nullptr);
    void mousePressEvent(QMouseEvent* event);


private:
    Image* image_;
};


#endif //DUPLICATE_IMAGE_FINDER_MINIATUREIMAGE_H
