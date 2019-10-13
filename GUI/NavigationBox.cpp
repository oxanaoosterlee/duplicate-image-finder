//
// Created by oxana on 13-10-19.
//

#include <iostream>
#include "NavigationBox.h"

NavigationBox::NavigationBox(QWidget *parent) : QGroupBox(parent) {

    QHBoxLayout *layout = new QHBoxLayout;

    // Generate all widgets
    search_folder_lineedit = new QLineEdit(this);
    search_folder_lineedit->setReadOnly(true);

    select_folder_btn = new QPushButton("Select folder", this);
    search_btn = new QPushButton("Search", this);
    next_btn = new QPushButton("Next", this);
    prev_btn = new QPushButton("Previous", this);

    // The following buttons are initally not pressable.
    next_btn->setEnabled(false);
    prev_btn->setEnabled(false);
    search_btn->setEnabled(false);

    //Add all widgets to the layout

    layout->addWidget(select_folder_btn);
    layout->addWidget(search_folder_lineedit);
    layout->addWidget(search_btn);
    layout->addWidget(prev_btn);
    layout->addWidget(next_btn);
    this->setLayout(layout);

    // Connects
    connect(select_folder_btn, &QPushButton::clicked, this, &NavigationBox::selectFolderButtonClicked);

}



void NavigationBox::selectFolderButtonClicked() {
    std::cout << "Select folder button clicked" << "\n";
    QString dirname = QFileDialog::getExistingDirectory(this, tr("Select search root folder"), "/home/oxana/Documents/Projects/Duplicate Image Search/Images" );
    std::cout << "dirname is: "  << dirname.toStdString() << "\n";
    if (!dirname.isEmpty()){
        search_folder_lineedit->setText(dirname);
        search_btn->setEnabled(true);
    }
}


QPushButton *NavigationBox::getSearchBtn() const {
    return search_btn;
}

QPushButton *NavigationBox::getNextBtn() const {
    return next_btn;
}

QPushButton *NavigationBox::getPrevBtn() const {
    return prev_btn;
}

QString NavigationBox::getSearchFolder() {
    return search_folder_lineedit->text();
}

