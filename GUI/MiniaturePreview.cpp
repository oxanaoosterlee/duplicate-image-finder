//
// Created by oxana on 9-10-19.
//

#include "MiniaturePreview.h"
#include "ImagePreview.h"

MiniaturePreview::MiniaturePreview(){
    miniature_groupbox = new QGroupBox();
    layout = new QHBoxLayout();

    QLabel *default_text = new QLabel;
    default_text->setText("This image only has one duplicate");

    layout->addWidget(default_text);
    miniature_groupbox->setLayout(layout);
}

MiniaturePreview::~MiniaturePreview() {

}

QGroupBox *MiniaturePreview::getWidget() {
    return miniature_groupbox;
}

void MiniaturePreview::update(DuplicateVector *duplicate_vector, ImagePreview *image_preview) {
    std::cout << "Updating miniatures \n";

    // Delete all previous miniatures
    while(layout->itemAt(0) != 0){
        delete layout->itemAt(0)->widget();
    }

    double miniaturesAmt = duplicate_vector->getNumberOfDuplicates();
    for (int i = 0; i < miniaturesAmt; i++){
        Miniature* new_miniature = new Miniature(nullptr, duplicate_vector->getDuplicate(i));
        new_miniature->setAlignment(Qt::AlignCenter);
        QPixmap qpixmap = QPixmap();
        qpixmap.load(duplicate_vector->getDuplicate(i)->getPathQString());
        new_miniature->setPixmap(qpixmap.scaledToWidth(miniature_width,  Qt::SmoothTransformation));
        new_miniature->setCursor(Qt::PointingHandCursor);
        QObject::connect(new_miniature, &Miniature::clicked, image_preview, &ImagePreview::changeToGrey);
        layout->addWidget(new_miniature);

    }

    layout->setSizeConstraint(QLayout::SetFixedSize);

    std::cout << "Updating miniatures finished \n";
}

