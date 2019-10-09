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
#include "ImagePreview.h"
#include "MiniaturePreview.h"
#include "ImageInfo.h"


class MainWindow : public QWidget {

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);



public slots:
    void nextButtonClicked();
    void searchButtonClicked();
    void prevButtonClicked();

private:
    void createNavigationGroupBox();


    QVBoxLayout *main_layout;


    ImageIndexer *image_indexer;
    ImagePreview image_preview;
    MiniaturePreview miniature_preview;
    ImageInfo image_info;


    QPushButton *search_button;
    QLineEdit *search_folder_input;
    QGroupBox *button_bar_groupbox;


    int duplicate_vector_index;



};

#endif //DUPLICATE_IMAGE_FINDER_MAINWINDOW_H
