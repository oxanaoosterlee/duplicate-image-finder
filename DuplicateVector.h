//
// Created by oxana on 5-10-19.
//

#ifndef DUPLICATE_IMAGE_FINDER_DUPLICATEVECTOR_H
#define DUPLICATE_IMAGE_FINDER_DUPLICATEVECTOR_H


#include "Image.h"

class DuplicateVector {
public:
    DuplicateVector();
    ~DuplicateVector();

    // Duplicates related
    void addDuplicate(const Image& image);
    void printDuplicates();
    int getNumberOfDuplicates();

    Image* getDuplicate(int index);

private:
    std::vector<Image>* duplicates_;

};


#endif //DUPLICATE_IMAGE_FINDER_DUPLICATEVECTOR_H
