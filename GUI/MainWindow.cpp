//
// Created by oxana on 26-9-19.
//

#include "MainWindow.h"
#include <thread>

MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent) {
    // Set size of the window
    setWindowTitle("Similar Image Finder");
    setFixedSize(1000, 800);


    preview_box = new PreviewBox(this);
    miniature_box = new MiniatureBox(this);
    info_box = new InfoBox(this);
    navigation_box = new NavigationBox(this);


    // Build layout
    main_layout = new QVBoxLayout;
    main_layout->addWidget(preview_box->getWidget());
    main_layout->addWidget(info_box);
    main_layout->addWidget(miniature_box);
    main_layout->addWidget(navigation_box);
    //main_layout->addWidget(updateMessage);
    setLayout(main_layout);

    // Initialize the image indexer, and establish all required inter-widget connections.
    image_indexer = new ImageIndexer();
    initConnections();
}

void MainWindow::searchButtonClicked() {
    // std::string path = "/home/oxana/Documents/Projects/Duplicate Image Search/Images";
    //image_indexer->setPath(QString::fromStdString(path));

    image_indexer->setPath(navigation_box->get_search_dir());
    image_indexer->indexImages();
    image_indexer->generateDuplicateVectors();
    duplicate_vector_index = 0;

    DuplicateVector *duplicateVector = image_indexer->getDuplicateVector(duplicate_vector_index);
    updateWindowWithDuplicateVector(duplicateVector);

    navigation_box->get_next_btn()->setEnabled(true);

}

void MainWindow::nextButtonClicked() {
    std::cout << "Next button clicked" << "\n";
    duplicate_vector_index++;
    if (duplicate_vector_index == image_indexer->getNumberOfDuplicateVectors() - 1) {
        navigation_box->get_next_btn()->setEnabled(false);
    }
    navigation_box->get_prev_btn()->setEnabled(true);
    DuplicateVector *duplicateVector = image_indexer->getDuplicateVector(duplicate_vector_index);
    updateWindowWithDuplicateVector(duplicateVector);

    std::cout << "Finished" << "\n";
}

void MainWindow::prevButtonClicked() {
    std::cout << "Previous button clicked" << "\n";
    duplicate_vector_index--;
    if (duplicate_vector_index == 0) {
        navigation_box->get_prev_btn()->setEnabled(false);
    }
    navigation_box->get_next_btn()->setEnabled(true);
    DuplicateVector *duplicateVector = image_indexer->getDuplicateVector(duplicate_vector_index);
    updateWindowWithDuplicateVector(duplicateVector);

}


void MainWindow::updateWindowWithDuplicateVector(DuplicateVector *duplicate_vector) {
    preview_box->update(duplicate_vector->getDuplicate(0), duplicate_vector->getDuplicate(1));
    miniature_box->update(duplicate_vector, preview_box);
    info_box->update(duplicate_vector->getDuplicate(0), duplicate_vector->getDuplicate(1));
    navigation_box->update_index_label(duplicate_vector_index, image_indexer->getNumberOfDuplicateVectors());
    updateConnections();

}

void MainWindow::updateWindowWithImages(Image *left_image, Image *right_image) {
    preview_box->update(left_image, right_image);
    info_box->update(left_image, right_image);
}


void MainWindow::updateConnections(){
    // Each miniature to miniaturebox and previewbox
    // Each preview image to miniaturebox
    std::cout << "Update connections \n";

    for (MiniatureImage* miniature : *miniature_box->getMiniatures()){
        QObject::connect(miniature, &MiniatureImage::clicked, miniature_box, &MiniatureBox::rememberLastClicked);
        connect(miniature, &MiniatureImage::clicked, preview_box, &PreviewBox::makePreviewsClickable);
        connect(miniature, &MiniatureImage::signalCheckBoxChange, preview_box, &PreviewBox::updateCheckboxes);
    }
}

void MainWindow::initConnections(){
    std::cout << "Init connections \n";

    // Miniature / preview images
    for (auto image : *preview_box->getPreviews()){
        connect(image, &PreviewImage::clicked, miniature_box, &MiniatureBox::requestLastClicked);
        connect(image, &PreviewImage::signalCheckBoxChange, miniature_box, &MiniatureBox::updateCheckboxes);
    }

    for (MiniatureImage* miniature : *miniature_box->getMiniatures()){
        QObject::connect(miniature, &MiniatureImage::clicked, miniature_box, &MiniatureBox::rememberLastClicked);
        connect(miniature, &MiniatureImage::clicked, preview_box, &PreviewBox::makePreviewsClickable);
        connect(miniature, &MiniatureImage::signalCheckBoxChange, preview_box, &PreviewBox::updateCheckboxes);
    }


    connect(miniature_box, &MiniatureBox::lastClicked, preview_box, &PreviewBox::receiveMiniatureChange);
    connect(preview_box, &PreviewBox::requestInfoUpdate, info_box, &InfoBox::update);

    // Navigation buttons
    connect(navigation_box->get_next_btn(), &QPushButton::clicked, this, &MainWindow::nextButtonClicked);
    connect(navigation_box->get_search_btn(), &QPushButton::clicked, this, &MainWindow::searchButtonClicked);
    connect(navigation_box->get_prev_btn(), &QPushButton::clicked, this, &MainWindow::prevButtonClicked);
}

