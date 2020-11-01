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
#include <QTextStream>
#include <stdio.h>
#include <QFileDialog>
#include <QtWidgets/QLabel>

class NavigationBox : public QGroupBox {
    Q_OBJECT

public slots:

    signals:

public:
    NavigationBox(QWidget *parent = nullptr);

    QPushButton *get_search_btn() const;
    QPushButton *get_next_btn() const;
    QPushButton *get_prev_btn() const;

    QString get_search_dir();

    void update_index_label(int current_index, int total);

private:
    QHBoxLayout* layout;

    QPushButton* select_dir_btn;
    QPushButton* search_btn;
    QPushButton* next_btn;
    QPushButton* prev_btn;

    QLineEdit* search_dir_line;

    QLabel* index_label;

    void selectFolderButtonClicked();
};


#endif //DUPLICATE_IMAGE_FINDER_NAVIGATIONBOX_H
