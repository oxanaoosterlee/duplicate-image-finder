//
// Created by oxana on 9-10-19.
//

#include "MiniatureBox.h"
#include "PreviewBox.h"

MiniatureBox::MiniatureBox(){
    miniature_groupbox = new QGroupBox();
    layout = new QHBoxLayout();

    QLabel *default_text = new QLabel;
    default_text->setText("This image only has one duplicate");

    layout->addWidget(default_text);
    miniature_groupbox->setLayout(layout);
}

MiniatureBox::~MiniatureBox() {

}

QGroupBox *MiniatureBox::getWidget() {
    return miniature_groupbox;
}

void MiniatureBox::update(DuplicateVector *duplicate_vector, PreviewBox *image_preview) {
    std::cout << "Updating miniatures \n";
    miniatures_.clear();
    // Delete all previous miniatures
    while(layout->itemAt(0) != 0){
        delete layout->itemAt(0)->widget();
    }

    double miniaturesAmt = duplicate_vector->getNumberOfDuplicates();
    for (int i = 0; i < miniaturesAmt; i++){
        MiniatureImage* new_miniature = new MiniatureImage(nullptr, duplicate_vector->getDuplicate(i));
        QPixmap qpixmap = QPixmap();
        qpixmap.load(duplicate_vector->getDuplicate(i)->getPathQString());
        new_miniature->setPixmap(qpixmap.scaledToWidth(miniature_width,  Qt::SmoothTransformation));
//        QObject::connect(new_miniature, &MiniatureImage::clicked, image_preview, &PreviewBox::miniatureClicked);
        layout->addWidget(new_miniature);
        miniatures_.push_back(new_miniature);

    }

    layout->setSizeConstraint(QLayout::SetFixedSize);

    std::cout << "Updating miniatures finished \n";
}

void MiniatureBox::rememberLastClicked(Image *image) {
    std::cout << "Last clicked image is now: " << image->getPathStdString() << "\n";
    last_clicked_miniature_ = image;
}

void MiniatureBox::requestLastClicked(PreviewImage *previewImage) {
    std::cout << "Signalling the last clicked image is " << last_clicked_miniature_->getPathStdString() << "\n";
    emit lastClicked(previewImage, last_clicked_miniature_);
}

std::vector<MiniatureImage *> *MiniatureBox::getMiniatures() {
    return &miniatures_;
}
