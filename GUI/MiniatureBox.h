//
// Created by oxana on 9-10-19.
//

#ifndef DUPLICATE_IMAGE_FINDER_MINIATUREBOX_H
#define DUPLICATE_IMAGE_FINDER_MINIATUREBOX_H

#include <QtGui>
#include <QtWidgets>
#include <QWidget>
#include "../Image.h"
#include "../DuplicateVector.h"
#include "MiniatureImage.h"
#include "PreviewBox.h"

class MiniatureBox :  public QWidget{
    Q_OBJECT

public slots:
    void rememberLastClicked(Image* image);
    void requestLastClicked(PreviewImage* previewImage);

    signals:
    void lastClicked(PreviewImage* previewImage, Image* image);

public:
    MiniatureBox(QWidget *parent = nullptr);
    virtual ~MiniatureBox();
    QGroupBox *getWidget();


    void update(DuplicateVector *duplicate_vector, PreviewBox *image_preview);

    // Gets a pointer to the list of miniatures.
    std::vector<MiniatureImage*>* getMiniatures();


private:
    QGroupBox *miniature_groupbox;
    QHBoxLayout *layout;

    // List of all current miniatures shown
    std::vector<MiniatureImage*> miniatures_;


    Image* last_clicked_miniature_;


};


#endif //DUPLICATE_IMAGE_FINDER_MINIATUREBOX_H

