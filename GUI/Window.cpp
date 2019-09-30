//
// Created by oxana on 26-9-19.
//

#include "Window.h"
#include "../comparison_algorithm.h"
#include "../indexer.h"

Window::Window(QWidget *parent) :
        QWidget(parent)
{
    // Set size of the window
    setFixedSize(1500,500);


    main_layout = new QVBoxLayout;


    createImagePreviewGroupbox();
    createNavigationGroupBox();

    main_layout = new QVBoxLayout;
    main_layout -> addWidget(image_preview_groupbox);
    main_layout -> addWidget(navigation_bar_groupbox);



    setLayout(main_layout);
    setWindowTitle("test");

}


void Window::createImagePreviewGroupbox() {
    QString image = "/home/oxana/Documents/Projects/Duplicate Image Search/Images/img4.jpg";

    image_preview_groupbox = new QGroupBox();
    QHBoxLayout* layout = new QHBoxLayout;

    QPixmap* qpixmap = new QPixmap;
    qpixmap->load(image);

    image_left = new QLabel(this);
    image_right = new QLabel(this);
    image_left->setAlignment(Qt::AlignCenter);
    image_right->setAlignment(Qt::AlignCenter);

    image_left->setPixmap(qpixmap->scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    image_right->setPixmap(qpixmap->scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));


    layout -> addWidget(image_left);
    layout -> addWidget(image_right);

    image_preview_groupbox->setLayout(layout);
}

void Window::updateImagePreview(){
    do {first_image_ptr++;}
    while(
        first_image_ptr->getDuplicateImages().size() == 0
    );
    std::cout << "left image: " << first_image_ptr->getPathString() << "\n";

    auto qpixmap1 = new QPixmap;
    qpixmap1->load(first_image_ptr->getPath());
    image_left->setPixmap(qpixmap1->scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    std::cout << "size: " << first_image_ptr->getDuplicateImages().size() << "\n";
    std::cout << "right image: " << first_image_ptr->getDuplicateImages().front().path.toStdString() << "\n";
    auto qpixmap2 = new QPixmap;
    qpixmap2->load(first_image_ptr->getDuplicateImages().at(0).path);
    image_right->setPixmap(qpixmap2->scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void Window::createNavigationGroupBox() {
    // search_folder_input = new QLineEdit(this);
    navigation_bar_groupbox = new QGroupBox;
    QHBoxLayout* layout = new QHBoxLayout;

    QPushButton* search_button = new QPushButton("Search", this);
    QPushButton* next_button = new QPushButton("Next", this);
    QPushButton* prev_button = new QPushButton("Previous", this);

    layout->addWidget(search_button);
    layout->addWidget(prev_button);
    layout->addWidget(next_button);

    connect(next_button, &QPushButton::clicked, this, &Window::updateImagePreview);
    connect(search_button, &QPushButton::clicked, this, &Window::searchButtonClicked);
    connect(prev_button, &QPushButton::clicked, this, &Window::prevButtonClicked);

    navigation_bar_groupbox -> setLayout(layout);
}

void Window::searchButtonClicked(){
    ImageIndexer image_loader;
    ComparisonAlgorithm algorithm;
    //all_images = image_loader.GenerateAllImagesList("/home/oxana/Documents/Projects/Duplicate Image Search/Images");
    all_images = image_loader.GenerateAllImagesList("/media/Data/Pictures/Vakanties/2015 Edinburgh");
    algorithm.FindDuplicates(&all_images);
    first_image_ptr = all_images.begin();
    for (auto image : all_images){
        image.printDuplicates();
    }

}

void Window::prevButtonClicked(){
    do{first_image_ptr--;}
    while(
            first_image_ptr->getDuplicateImages().size() == 0
            );
    std::cout << "left image: " << first_image_ptr->getPathString() << "\n";

    auto qpixmap1 = new QPixmap;
    qpixmap1->load(first_image_ptr->getPath());
    image_left->setPixmap(qpixmap1->scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    std::cout << "size: " << first_image_ptr->getDuplicateImages().size() << "\n";
    std::cout << "right image: " << first_image_ptr->getDuplicateImages().front().path.toStdString() << "\n";
    auto qpixmap2 = new QPixmap;
    qpixmap2->load(first_image_ptr->getDuplicateImages().at(0).path);
    image_right->setPixmap(qpixmap2->scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}