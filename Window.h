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

class Window : public QWidget {

public:
    explicit Window(QWidget *parent = 0);

private:

    void createImagePreviewGroupbox();
    void createImageInfoGroupBox();
    void createNavigationGroupBox();

    QVBoxLayout *main_layout;
    QGroupBox *image_preview_groupbox;
    QGroupBox *image_info_groupbox;
    QGroupBox *navigation_bar_groupbox;


    QPushButton *search_button;
    QLineEdit *search_folder_input;
};

#endif //DUPLICATE_IMAGE_FINDER_WINDOW_H
