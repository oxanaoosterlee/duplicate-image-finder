//
// Created by oxana on 26-9-19.
//

#include "MainWindow.h"
#include <thread>

MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent) {
    // Set size of the window
    setFixedSize(1000, 800);
    main_layout = new QVBoxLayout();

    preview_box = new PreviewBox(this);
    miniature_box = new MiniatureBox(this);
    image_info = ImageInfo();
    createNavigationGroupBox();

    main_layout = new QVBoxLayout;
    main_layout->addWidget(preview_box->getWidget());
    main_layout->addWidget(miniature_box->getWidget());
    main_layout->addWidget(image_info.getWidget());
    main_layout->addWidget(button_bar_groupbox);
    //main_layout->addWidget(updateMessage);


    image_indexer = new ImageIndexer();
    initConnections();
    setLayout(main_layout);
    setWindowTitle("Similar Image Finder");


}

void MainWindow::createNavigationGroupBox() {
    // search_folder_input = new QLineEdit(this);
    button_bar_groupbox = new QGroupBox;
    QHBoxLayout *layout = new QHBoxLayout;

    QPushButton *select_folder_button = new QPushButton("Select folder", this);
    search_folder_input = new QLineEdit(this);
    search_button = new QPushButton("Search", this);
    next_button = new QPushButton("Next", this);
    prev_button = new QPushButton("Previous", this);

    // All buttons are initally not pressable.
    next_button->setEnabled(false);
    prev_button->setEnabled(false);
    search_button->setEnabled(false);


    layout->addWidget(select_folder_button);
    layout->addWidget(search_folder_input);
    layout->addWidget(search_button);
    layout->addWidget(prev_button);
    layout->addWidget(next_button);

    search_folder_input->setReadOnly(true);

    connect(next_button, &QPushButton::clicked, this, &MainWindow::nextButtonClicked);
    connect(search_button, &QPushButton::clicked, this, &MainWindow::searchButtonClicked);
    connect(prev_button, &QPushButton::clicked, this, &MainWindow::prevButtonClicked);
    connect(select_folder_button, &QPushButton::clicked, this, &MainWindow::selectFolderButtonClicked);


    button_bar_groupbox->setLayout(layout);
}

void MainWindow::searchButtonClicked() {
    // std::string path = "/home/oxana/Documents/Projects/Duplicate Image Search/Images";
    //image_indexer->setPath(QString::fromStdString(path));

    image_indexer->setPath(search_folder_input->text());
    image_indexer->indexImages();
    image_indexer->generateDuplicateVectors();
    duplicate_vector_index = 0;

    DuplicateVector *duplicateVector = image_indexer->getDuplicateVector(duplicate_vector_index);
    updateWindowWithDuplicateVector(duplicateVector);

    next_button->setEnabled(true);

}

void MainWindow::nextButtonClicked() {
    std::cout << "Next button clicked" << "\n";
    duplicate_vector_index++;
    if (duplicate_vector_index == image_indexer->getNumberOfDuplicateVectors() - 1) {
        next_button->setEnabled(false);
    }
    prev_button->setEnabled(true);
    DuplicateVector *duplicateVector = image_indexer->getDuplicateVector(duplicate_vector_index);
    updateWindowWithDuplicateVector(duplicateVector);

    std::cout << "Finished" << "\n";
}

void MainWindow::prevButtonClicked() {
    std::cout << "Previous button clicked" << "\n";
    duplicate_vector_index--;
    if (duplicate_vector_index == 0) {
        prev_button->setEnabled(false);
    }
    next_button->setEnabled(true);
    DuplicateVector *duplicateVector = image_indexer->getDuplicateVector(duplicate_vector_index);
    updateWindowWithDuplicateVector(duplicateVector);

}

void MainWindow::selectFolderButtonClicked() {
    std::cout << "Select folder button clicked" << "\n";
    QString dirname = QFileDialog::getExistingDirectory(this, tr("Select search root folder"), "/home/oxana/Documents/Projects/Duplicate Image Search/Images" );
    std::cout << "dirname is: "  << dirname.toStdString() << "\n";
        if (!dirname.isEmpty()){
        search_folder_input->setText(dirname);
        search_button->setEnabled(true);
}       }

void MainWindow::updateWindowWithDuplicateVector(DuplicateVector *duplicate_vector) {
    preview_box->update(duplicate_vector->getDuplicate(0), duplicate_vector->getDuplicate(1));
    miniature_box->update(duplicate_vector, preview_box);
    image_info.update(duplicate_vector->getDuplicate(0), duplicate_vector->getDuplicate(1));
    updateConnections();

}

void MainWindow::updateWindowWithImages(Image *left_image, Image *right_image) {
    preview_box->update(left_image, right_image);
    image_info.update(left_image, right_image);
}


void MainWindow::updateConnections(){
    // Each miniature to miniaturebox and previewbox
    // Each preview image to miniaturebox
    std::cout << "Update connections \n";

    for (MiniatureImage* miniature : *miniature_box->getMiniatures()){
        QObject::connect(miniature, &MiniatureImage::clicked, miniature_box, &MiniatureBox::rememberLastClicked);
        connect(miniature, &MiniatureImage::clicked, preview_box, &PreviewBox::makePreviewsClickable);
    }


}

void MainWindow::initConnections(){
    std::cout << "Init connections \n";
    for (auto image : *preview_box->getPreviews()){
        connect(image, &PreviewImage::clicked, miniature_box, &MiniatureBox::requestLastClicked);
    }
    connect(miniature_box, &MiniatureBox::lastClicked, preview_box, &PreviewBox::receiveMiniatureChange);

}

