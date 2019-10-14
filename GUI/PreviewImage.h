//
// Created by oxana on 11-10-19.
//

#ifndef DUPLICATE_IMAGE_FINDER_PREVIEWIMAGE_H
#define DUPLICATE_IMAGE_FINDER_PREVIEWIMAGE_H


#include <QtCore/QArgument>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QCheckBox>
#include "../Image.h"

class PreviewImage : public QLabel {
    Q_OBJECT

public slots:
    void checkBoxChanged(int state);

signals:
    void clicked(PreviewImage* preview_image);
    void signalCheckBoxChange(Qt::CheckState state);

public:
    PreviewImage(QWidget *parent=0, Image* image = nullptr);
    void mousePressEvent(QMouseEvent* event);
    void mouseHoverEvent(QHoverEvent* event);
    void setClickable(bool val);
    void updateImage(Image* image);
    Image* getImage();
    void updateCheckbox();


private:
    Image* image_;
    QCheckBox* checkbox_;
    bool clickable;

};



#endif //DUPLICATE_IMAGE_FINDER_PREVIEWIMAGE_H
