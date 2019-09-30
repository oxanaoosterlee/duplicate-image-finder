//
// Created by oxana on 26-9-19.
//

#ifndef DUPLICATE_IMAGE_FINDER_WINDOW_H
#define DUPLICATE_IMAGE_FINDER_WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QtGui>
#include <QtWidgets>
#include "../Image.h"

class Window : public QWidget {

    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);



public slots:
    void updateImagePreview();
    void searchButtonClicked();
    void prevButtonClicked();

private:

    void createImagePreviewGroupbox();
    void createImageInfoGroupBox();
    void createNavigationGroupBox();


    QVBoxLayout *main_layout;
    QGroupBox *image_preview_groupbox;
    QGroupBox *image_info_groupbox;
    QGroupBox *navigation_bar_groupbox;

    QLabel* image_left;
    QLabel* image_right;

    QPushButton *search_button;
    QLineEdit *search_folder_input;

    std::vector<Image> all_images;
    std::vector<Image>::iterator first_image_ptr;
};

#endif //DUPLICATE_IMAGE_FINDER_WINDOW_H
