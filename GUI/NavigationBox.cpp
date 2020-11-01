//
// Created by oxana on 13-10-19.
//

#include <iostream>
#include "NavigationBox.h"

/**
 * Shows the following elements:
 * - An input line with the to-be-searched directory and a button to select a directory.
 * - Buttons to navigate through duplicate vectors (previous, next).
 * - An indicator which duplicate vector of how many it is showing.
 */
NavigationBox::NavigationBox(QWidget *parent) : QGroupBox(parent) {

    // WIDGETS

    // Widget for search directory/folder entry
    search_dir_line = new QLineEdit(this);
    search_dir_line->setReadOnly(true);

    // Button for selecting search directory
    select_dir_btn = new QPushButton("Select folder", this);

    // Button for starting the search for duplicates
    search_btn = new QPushButton("Search", this);

    // Navigation buttons (previous and next)
    next_btn = new QPushButton("Next", this);
    prev_btn = new QPushButton("Previous", this);

    // Text label showing index of current DuplicateVector and the total.
    index_label = new QLabel("", this);

    // Initialize buttons to not be clickable at start of program.
    next_btn->setEnabled(false);
    prev_btn->setEnabled(false);
    search_btn->setEnabled(false);

    // LAYOUT
    layout = new QHBoxLayout;
    layout->addWidget(select_dir_btn);
    layout->addWidget(search_dir_line);
    layout->addWidget(search_btn);
    layout->addWidget(prev_btn);
    layout->addWidget(next_btn);
    layout->addWidget(index_label);
    this->setLayout(layout);

    // CONNECTS

    // Open directory dialog when pressing 'select folder' button.
    connect(select_dir_btn, &QPushButton::clicked, this, &NavigationBox::selectFolderButtonClicked);

}


/**
 * Opens a dialog for selecting a directory/folder.
 */
void NavigationBox::selectFolderButtonClicked() {
    std::cout << "Select folder button clicked" << "\n";
    QString dirname = QFileDialog::getExistingDirectory(this, tr("Select search root folder"),
                                                        "/home/oxana/Documents/Projects/Duplicate Image Search/Images"
                                                        );
    std::cout << "dirname is: "  << dirname.toStdString() << "\n";

    // When a valid directory has been chosen, show the directory name in the line widget
    // and enable the 'search' button for the user.
    if (!dirname.isEmpty()){
        search_dir_line->setText(dirname);
        search_btn->setEnabled(true);
    }
}


QPushButton *NavigationBox::get_search_btn() const {
    return search_btn;
}

QPushButton *NavigationBox::get_next_btn() const {
    return next_btn;
}

QPushButton *NavigationBox::get_prev_btn() const {
    return prev_btn;
}

/**
 * Get the directory for which duplicates are being found.
 * @return String
 */
QString NavigationBox::get_search_dir() {
    return search_dir_line->text();
}

/**
 * Show the index of the current shown DuplicateVector and the total amount of DuplicateVectors.
 * @param current_index int
 * @param total int
 */
void NavigationBox::update_index_label(int current_index, int total) {

    // Because in the rest of the program 0-indexing is used, add +1 to the current index to make it more intuitive.
    current_index += 1;

    // Generate string that is shown.
    QString str;
    QTextStream(&str) <<  current_index << "/" << total;
    this->index_label->setText(str);
}
