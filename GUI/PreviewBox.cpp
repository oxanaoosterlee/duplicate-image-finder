//
// Created by oxana on 9-10-19.
//

#include <QtCore/QString>
#include "PreviewBox.h"

PreviewBox::PreviewBox() {



    image_preview_groupbox = new QGroupBox;
    QHBoxLayout *layout = new QHBoxLayout;

    image_previews_.push_back(new PreviewImage);
    image_previews_.push_back(new PreviewImage);

    for (PreviewImage* image_preview : image_previews_ ){
        layout->addWidget(image_preview);
    }

    image_preview_groupbox->setLayout(layout);
}

PreviewBox::~PreviewBox() {

}

QGroupBox *PreviewBox::getWidget() {
    return image_preview_groupbox;
}

void PreviewBox::update(Image *left_image, Image *right_image) {
    std::cout << "Updating image preview" << "\n";

    image_previews_[0]->updateImage(left_image);
    image_previews_[1]->updateImage(right_image);
}



void PreviewBox::makePreviewsClickable(bool val = true) {
    std::cout << "Previews clickable is now: " << val << "\n";
    for (auto preview : image_previews_){
        preview->setClickable(val);
    }
}

void PreviewBox::receiveMiniatureChange(PreviewImage* preview_image, Image* image) {
    std::cout << "Changing preview to selected miniature. \n";
    preview_image->updateImage(image);
    makePreviewsClickable(false);

}

std::vector<PreviewImage*>* PreviewBox::getPreviews(){
    return &image_previews_;
}
