//
// Created by oxana on 13-10-19.
//

#ifndef DUPLICATE_IMAGE_FINDER_NAVIGATIONBOX_H
#define DUPLICATE_IMAGE_FINDER_NAVIGATIONBOX_H


#include <QWidget>
#include <QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QHBoxLayout>
#include <stdio.h>
#include <QFileDialog>

class NavigationBox : public QGroupBox {
    Q_OBJECT

public slots:

    signals:

public:
    NavigationBox(QWidget *parent = nullptr);

    QPushButton *getSearchBtn() const;

    QPushButton *getNextBtn() const;

    QPushButton *getPrevBtn() const;

    QString getSearchFolder();

private:
    QHBoxLayout* layout;

    QPushButton* select_folder_btn;
    QPushButton* search_btn;
    QPushButton* next_btn;
    QPushButton* prev_btn;

    QLineEdit* search_folder_lineedit;

    void selectFolderButtonClicked();
};


#endif //DUPLICATE_IMAGE_FINDER_NAVIGATIONBOX_H
