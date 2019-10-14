//
// Created by oxana on 9-10-19.
//

#include "MiniatureBox.h"
#include "PreviewBox.h"

MiniatureBox::MiniatureBox(QWidget *parent) : QGroupBox(parent){
    QHBoxLayout* completeLayout = new QHBoxLayout();
    miniature_groupbox = new QGroupBox(this);
    layout = new QHBoxLayout();
    layout->setAlignment(layout, Qt::AlignTop);
    miniature_groupbox->setLayout(layout);
    miniature_groupbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    // Make miniaturebox scrollable
    scroll_area = new QScrollArea(this);
    scroll_area->setFixedSize(400, 150);
    scroll_area->setWidget(miniature_groupbox);
    scroll_area->setWidgetResizable(true);

    completeLayout->addWidget(scroll_area, Qt::AlignLeft);
    completeLayout->addStretch();
    this->setLayout(completeLayout);

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
    while(layout->itemAt(0) != nullptr){
        delete layout->itemAt(0)->widget();
    }

    double miniaturesAmt = duplicate_vector->getNumberOfDuplicates();
    for (int i = 0; i < miniaturesAmt; i++){
        MiniatureImage* new_miniature = new MiniatureImage(this, duplicate_vector->getDuplicate(i));
        layout->addWidget(new_miniature);
        miniatures_.push_back(new_miniature);

    }

    //layout->setSizeConstraint(QLayout::SetFixedSize);

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

void MiniatureBox::updateCheckboxes() {
    for (auto miniature : miniatures_){
        miniature->updateCheckbox();
    }
}
