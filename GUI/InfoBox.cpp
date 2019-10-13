//
// Created by oxana on 9-10-19.
//

#include "InfoBox.h"
#include "../Algorithm.h"

InfoBox::InfoBox(QWidget *parent) : QGroupBox(parent){

    QGridLayout *layout = new QGridLayout();

    percentage = new QLabel("..%");
    QLabel* path_label = new QLabel("Directory");
    QLabel* file_size_label = new QLabel("File size");
    QLabel* creation_date_label = new QLabel("Creation date & time");

    filename_left = new QLabel(this);
    path_left = new QLabel(this);
    filesize_left = new QLabel(this);
    creation_date_left = new QLabel(this);

    filename_right = new QLabel(this);
    path_right= new QLabel(this);
    filesize_right = new QLabel(this);
    creation_date_right = new QLabel(this);

    layout->addWidget(percentage, 0, 1);
    layout->addWidget(path_label, 1, 1);
    layout->addWidget(file_size_label, 2, 1);
    layout->addWidget(creation_date_label, 3, 1);

    layout->addWidget(filename_left, 0, 0);
    layout->addWidget(path_left, 1, 0);
    layout->addWidget(filesize_left, 2, 0);
    layout->addWidget(creation_date_left, 3, 0);

    layout->addWidget(filename_right, 0, 2);
    layout->addWidget(path_right, 1, 2);
    layout->addWidget(filesize_right, 2, 2);
    layout->addWidget(creation_date_right, 3, 2);


    this->setLayout(layout);

    for (auto widget : this->findChildren<QLabel*>()){
        widget->setWordWrap(true);
    }
}

InfoBox::~InfoBox() {

}

QGroupBox *InfoBox::getWidget() {
    return image_info_groupbox;
}


void InfoBox::update(Image *left_image, Image *right_image) {
    std::cout << "Updating image info. \n";
    QFileInfo left_image_info = QFileInfo(left_image->getPathQString());
    QFileInfo right_image_info = QFileInfo(right_image->getPathQString());

    filename_left->setText(left_image_info.fileName());
    path_left->setText(left_image_info.absolutePath());
    filesize_left->setText(QString::number(left_image_info.size() / 1e6, 'f', 2) + "MB");
    creation_date_left->setText(left_image_info.lastModified().toString("dd'-'MM'-'yyyy '  'HH':'mm':'ss"));

    filename_right->setText(right_image_info.fileName());
    path_right->setText(right_image_info.absolutePath());
    filesize_right->setText(QString::number(right_image_info.size() / 1e6, 'f', 2) + "MB");
    creation_date_right->setText(right_image_info.lastModified().toString("dd'-'MM'-'yyyy '  'HH':'mm':'ss"));


    double percentageValue = (1.0 - Algorithm::calculateEuclidianDistance(left_image->getImage(), right_image->getImage()))*100;
    percentage->setText(QString::number(percentageValue, 'f', 2) + "% similar");

    std::cout << "Info updated \n";
}

