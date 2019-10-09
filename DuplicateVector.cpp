//
// Created by oxana on 5-10-19.
//

#include "DuplicateVector.h"

DuplicateVector::DuplicateVector(){
    duplicates_ = new std::vector<Image>;
}

DuplicateVector::~DuplicateVector() = default;

void DuplicateVector::addDuplicate(const Image& image) {
    duplicates_->push_back(image);
}

void DuplicateVector::printDuplicates() {
    std::cout << "The following " << getNumberOfDuplicates() << " images are duplicates: \n";
    for (Image duplicate : *duplicates_) {
        std::cout << duplicate.getPathStdString() << "\n";
    }
}

int DuplicateVector::getNumberOfDuplicates() {
    return int(duplicates_->size());
}

Image *DuplicateVector::getDuplicate(int index) {
    if (index >= getNumberOfDuplicates()) {
        std::cout << "Duplicate index out of bounds! \n";
        return nullptr;
    } else {
        return &duplicates_->at(index);
    }
}
