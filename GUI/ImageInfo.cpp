//
// Created by oxana on 9-10-19.
//

#include "ImageInfo.h"
#include "../Algorithm.h"

ImageInfo::ImageInfo() {
    image_info_groupbox = new QGroupBox();
    QHBoxLayout *layout = new QHBoxLayout;
    left_image_text = new QLabel;
    right_image_text = new QLabel;
    label_text = new QLabel;

    left_image_text->setText("blabla \n joejoe \n blala");
    left_image_text->setAlignment(Qt::AlignCenter);

    right_image_text->setText("blabla \n joejoe \n blala");
    right_image_text->setAlignment(Qt::AlignCenter);

    label_text->setText("blabla \n joejoe \n blala");
    label_text->setAlignment(Qt::AlignCenter);


    layout->addWidget(left_image_text);
    layout->addWidget(label_text);
    layout->addWidget(right_image_text);

    image_info_groupbox->setLayout(layout);
}

ImageInfo::~ImageInfo() {

}

QGroupBox *ImageInfo::getWidget() {
    return image_info_groupbox;
}

//todo: make this a grid instead of qstrings!

void ImageInfo::update(Image *left_image, Image *right_image) {
    std::cout << "Updating image info. \n";
    QFileInfo left_image_info = QFileInfo(left_image->getPathQString());
    QFileInfo right_image_info = QFileInfo(right_image->getPathQString());

    QString left_info = left_image_info.fileName() + "\n" +
                        left_image_info.absolutePath() + "\n" +
                        QString::number(left_image_info.size() / 1e6, 'f', 2) + "MB" + "\n" +
                        left_image_info.lastModified().toString("dd'-'MM'-'yyyy '  'HH':'mm':'ss") + "\n";

    QString right_info = right_image_info.fileName() + "\n" +
                         right_image_info.absolutePath() + "\n" +
                         QString::number(right_image_info.size() / 1e6, 'f', 2) + "MB" + "\n" +
                         right_image_info.birthTime().toString("dd'-'MM'-'yyyy '  'HH':'mm':'ss") + "\n";

    //todo: calculate percentage
    double percentage = (1.0 - Algorithm::calculateEuclidianDistance(left_image->getImage(), right_image->getImage()))*100;
    QString label_info = QString::number(percentage, 'f', 2) + "% similar" + "\n" +
                         "Directory" + "\n" +
                         "File size" + "\n" +
                         "Creaton date & time" + "\n";

    left_image_text->setText(left_info);
    right_image_text->setText(right_info);
    label_text->setText(label_info);

    std::cout << "Info updated \n";
}
