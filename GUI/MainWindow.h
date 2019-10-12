//
// Created by oxana on 26-9-19.
//

#ifndef DUPLICATE_IMAGE_FINDER_MAINWINDOW_H
#define DUPLICATE_IMAGE_FINDER_MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QtGui>
#include <QtWidgets>
#include "../Image.h"
#include "../Algorithm.h"
#include "../DuplicateVector.h"
#include "../ImageIndexer.h"
#include "PreviewBox.h"
#include "MiniatureBox.h"
#include "ImageInfo.h"


class MainWindow : public QWidget {

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);



public slots:
    void nextButtonClicked();
    void searchButtonClicked();
    void prevButtonClicked();
    void selectFolderButtonClicked();

private:
    void createNavigationGroupBox();
    void updateWindowWithDuplicateVector(DuplicateVector *duplicate_vector);
    void updateWindowWithImages(Image* left_image, Image* right_image);

    QVBoxLayout *main_layout;


    ImageIndexer *image_indexer;
    PreviewBox *preview_box;
    MiniatureBox *miniature_box;
    ImageInfo image_info;


    QLineEdit *search_folder_input;
    QGroupBox *button_bar_groupbox;


    int duplicate_vector_index;


    QPushButton *search_button;
    QPushButton *next_button;
    QPushButton *prev_button;

    QLabel *updateMessage;

    void updateConnections();
    void initConnections();

};

#endif //DUPLICATE_IMAGE_FINDER_MAINWINDOW_H
