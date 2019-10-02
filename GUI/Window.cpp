//
// Created by oxana on 26-9-19.
//

#include "Window.h"
#include "../comparison_algorithm.h"
#include "../indexer.h"

Window::Window(QWidget *parent) :
        QWidget(parent) {
    // Set size of the window
    setFixedSize(1500, 1000);


    main_layout = new QVBoxLayout;


    createImagePreviewGroupbox();
    createImageInfoGroupBox();
    createNavigationGroupBox();

    main_layout = new QVBoxLayout;
    main_layout->addWidget(image_preview_groupbox);
    main_layout->addWidget(image_info_groupbox);
    main_layout->addWidget(button_bar_groupbox);


    setLayout(main_layout);
    setWindowTitle("test");

}


void Window::createImagePreviewGroupbox() {
    QString image = "/home/oxana/Documents/Projects/Duplicate Image Search/Images/img4.jpg";

    image_preview_groupbox = new QGroupBox();
    QHBoxLayout *layout = new QHBoxLayout;

    QPixmap *qpixmap = new QPixmap;
    qpixmap->load(image);

    image_left = new QLabel(this);
    image_right = new QLabel(this);
    image_left->setAlignment(Qt::AlignCenter);
    image_right->setAlignment(Qt::AlignCenter);

    image_left->setPixmap(qpixmap->scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    image_right->setPixmap(qpixmap->scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));


    layout->addWidget(image_left);
    layout->addWidget(image_right);

    image_preview_groupbox->setLayout(layout);
}

void Window::createImageInfoGroupBox() {
    image_info_groupbox = new QGroupBox();
    QHBoxLayout *layout = new QHBoxLayout;
    image_1_text = new QLabel;
    image_2_text = new QLabel;
    label_text = new QLabel;

    image_1_text->setText("blabla \n joejoe \n blala");
    image_1_text->setAlignment(Qt::AlignCenter);

    image_2_text->setText("blabla \n joejoe \n blala");
    image_2_text->setAlignment(Qt::AlignCenter);

    label_text->setText("blabla \n joejoe \n blala");
    label_text->setAlignment(Qt::AlignCenter);


    layout->addWidget(image_1_text);
    layout->addWidget(label_text);
    layout->addWidget(image_2_text);

    image_info_groupbox->setLayout(layout);

}

void Window::updateImageInfo(){
    QFileInfo left_image_info = QFileInfo(first_image_ptr->getPath());
    QFileInfo right_image_info = QFileInfo(second_image_ptr->path);

    QString left_info = left_image_info.fileName() + "\n" +
                        left_image_info.absolutePath() + "\n" +
                        QString::number(left_image_info.size() / 1e6, 'f', 2) + "MB" + "\n" +
                        left_image_info.lastModified().toString("dd'-'MM'-'yyyy '  'HH':'mm':'ss") + "\n";

    QString right_info = right_image_info.fileName() + "\n" +
                        right_image_info.absolutePath() + "\n" +
                        QString::number(right_image_info.size() / 1e6, 'f', 2) + "MB" + "\n" +
                        right_image_info.birthTime().toString("dd'-'MM'-'yyyy '  'HH':'mm':'ss") + "\n";


    QString label_info =    QString::number((1-second_image_ptr->percentage)*100, 'f', 2) + "% similar"  + "\n" +
                            "Directory" + "\n" +
                            "File size" + "\n" +
                            "Creaton date & time" + "\n";

    image_1_text->setText(left_info);
    image_2_text->setText(right_info);
    label_text->setText(label_info);

}

void Window::createNavigationGroupBox() {
    // search_folder_input = new QLineEdit(this);
    button_bar_groupbox = new QGroupBox;
    QHBoxLayout *layout = new QHBoxLayout;

    QPushButton *search_button = new QPushButton("Search", this);
    QPushButton *next_button = new QPushButton("Next", this);
    QPushButton *prev_button = new QPushButton("Previous", this);

    layout->addWidget(search_button);
    layout->addWidget(prev_button);
    layout->addWidget(next_button);

    connect(next_button, &QPushButton::clicked, this, &Window::nextButtonClicked);
    connect(search_button, &QPushButton::clicked, this, &Window::searchButtonClicked);
    connect(prev_button, &QPushButton::clicked, this, &Window::prevButtonClicked);

    button_bar_groupbox->setLayout(layout);
}

void Window::searchButtonClicked() {
    ImageIndexer image_loader;
    ComparisonAlgorithm algorithm;
    //all_images = image_loader.GenerateAllImagesList("/home/oxana/Documents/Projects/Duplicate Image Search/Images");
    all_images = image_loader.GenerateAllImagesList("/home/oxana/Documents/Projects/Duplicate Image Search/Images");
    algorithm.FindDuplicates(&all_images);
    first_image_ptr = all_images.begin();
    for (auto image : all_images) {
        image.printDuplicates();
    }

}

void Window::nextButtonClicked() {
    do { first_image_ptr++; }
    while (
            first_image_ptr->getDuplicateImagesAmt() == 0
            );

    second_image_ptr = first_image_ptr->getDuplicateImagesIterator();

    updateImagePreview(first_image_ptr->getPath(), second_image_ptr->path);
    updateImageInfo();
}

void Window::prevButtonClicked() {
    do { first_image_ptr--; }
    while (
            first_image_ptr->getDuplicateImagesAmt() == 0
            );
    std::cout << "left image: " << first_image_ptr->getPathString() << "\n";

    second_image_ptr = first_image_ptr->getDuplicateImagesIterator();

    updateImagePreview(first_image_ptr->getPath(), second_image_ptr->path);
    updateImageInfo();
}

void Window::updateImagePreview(QString left_path, QString right_path) {
    std::cout << "left image: " << left_path.toStdString() << "\n";
    std::cout << "right image: " << right_path.toStdString() << "\n";

    auto qpixmap1 = new QPixmap;
    qpixmap1->load(left_path);
    image_left->setPixmap(qpixmap1->scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));


    auto qpixmap2 = new QPixmap;
    qpixmap2->load(first_image_ptr->getDuplicateImagesIterator()->path);
    image_right->setPixmap(qpixmap2->scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

