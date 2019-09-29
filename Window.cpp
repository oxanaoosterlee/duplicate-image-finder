//
// Created by oxana on 26-9-19.
//

#include "Window.h"

Window::Window(QWidget *parent) :
        QWidget(parent)
{
    // Set size of the window
    setFixedSize(1000,1000);

    // Create and position the button
    search_button = new QPushButton("Hello World", this);
    search_button->setGeometry(10, 10, 80, 30);
    search_folder_input = new QLineEdit(this);
    main_layout = new QVBoxLayout;

    createImagePreviewGroupbox();
    main_layout -> addWidget(image_preview_groupbox);
    setLayout(main_layout);
    setWindowTitle("test");


}


void Window::createImagePreviewGroupbox() {
    image_preview_groupbox = new QGroupBox();
    QHBoxLayout* layout = new QHBoxLayout;

    QString image = "/home/oxana/Documents/Projects/Duplicate Image Search/Images/img5.jpg";
    QPixmap* qpixmap = new QPixmap();
    qpixmap->load(image);
    QLabel* imageLabel = new QLabel();
    QLabel* imageLabel2 = new QLabel();
    imageLabel->setScaledContents(true);
    imageLabel2->setScaledContents(true);
    imageLabel->setPixmap(*qpixmap);
    imageLabel2->setPixmap(*qpixmap);

    layout -> addWidget(imageLabel);
    layout -> addWidget(imageLabel2);

    image_preview_groupbox->setLayout(layout);
}

void Window::createNavigationGroupBox() {
    navigation_bar_groupbox = new QGroupBox;
    

}
