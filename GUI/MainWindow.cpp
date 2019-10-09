//
// Created by oxana on 26-9-19.
//

#include "MainWindow.h"
#include <thread>

MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent) {
    // Set size of the window
    setFixedSize(1000, 800);
    main_layout = new QVBoxLayout;

    image_preview = ImagePreview();
    miniature_preview = MiniaturePreview();
    image_info = ImageInfo();
    createNavigationGroupBox();

    main_layout = new QVBoxLayout;
    main_layout->addWidget(image_preview.getWidget());
    main_layout->addWidget(miniature_preview.getWidget());
    main_layout->addWidget(image_info.getWidget());
    main_layout->addWidget(button_bar_groupbox);
    main_layout->addWidget(updateMessage);


    image_indexer = new ImageIndexer();
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
    Image *left_image = duplicateVector->getDuplicate(0);
    Image *right_image = duplicateVector->getDuplicate(1);

    image_preview.update(left_image, right_image);
    miniature_preview.update(duplicateVector);
    image_info.update(left_image, right_image);

}

void MainWindow::nextButtonClicked() {
    std::cout << "Next button clicked" << "\n";
    if (duplicate_vector_index < image_indexer->getNumberOfDuplicateVectors() - 1) {
        duplicate_vector_index++;
    } else {
        return;
    }

    DuplicateVector *duplicateVector = image_indexer->getDuplicateVector(duplicate_vector_index);
    Image *left_image = duplicateVector->getDuplicate(0);
    Image *right_image = duplicateVector->getDuplicate(1);


    image_preview.update(left_image, right_image);
    miniature_preview.update(duplicateVector);
    image_info.update(left_image, right_image);

    std::cout << "Finished" << "\n";
}

void MainWindow::prevButtonClicked() {
    std::cout << "Previous button clicked" << "\n";
    if (duplicate_vector_index > 0) {
        duplicate_vector_index--;
    } else {
        return;
    }

    DuplicateVector *duplicateVector = image_indexer->getDuplicateVector(duplicate_vector_index);
    Image *left_image = duplicateVector->getDuplicate(0);
    Image *right_image = duplicateVector->getDuplicate(1);
    image_preview.update(left_image, right_image);
    miniature_preview.update(duplicateVector);
    image_info.update(left_image, right_image);
}

void MainWindow::selectFolderButtonClicked() {
    std::cout << "Select folder button clicked" << "\n";
    QString dirname = QFileDialog::getExistingDirectory(this, tr("Select search root folder"), "/home" );
    search_folder_input->setText(dirname);
}





