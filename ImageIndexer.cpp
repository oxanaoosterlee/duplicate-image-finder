//
// Created by oxana on 22-9-19.
//

#include <iostream>
#include "ImageIndexer.h"
#include "Algorithm.h"
#include <utility>

/** Index all images in the directory denoted by root_path, and its subdirectories**/
ImageIndexer::ImageIndexer() {
    indexed_images_ = new std::vector<Image>;
    duplicate_vectors_ = new std::vector<DuplicateVector>;
}

ImageIndexer::~ImageIndexer() = default;

void ImageIndexer::setPath(QString path) {
    root_path_ = std::move(path);
}

void ImageIndexer::indexImages() {
    std::cout << "Indexing images from path " << root_path_.toStdString() << "\n";


    //QString root = QString("/home/oxana/Documents/Projects/Duplicate Image Search/Images")
    //todo: try/catch statement for invalid path
    //todo: no images found error/handler

    QDirIterator it(root_path_, indexed_extensions, QDir::NoFilter, QDirIterator::Subdirectories);

    while (it.hasNext()) {
        it.next();
        cv::Mat loaded_image = LoadAndResizeImage(it.filePath().toStdString());
        Image new_image = Image(loaded_image, QString(it.filePath()));
        std::cout << "image: " << new_image.getFilenameStdString() << "\n";
        indexed_images_->push_back(new_image);
    }
    std::cout << "Done indexing images \n";
}


// Load image and directly apply greyscale and rescaling to 64x64'
cv::Mat ImageIndexer::LoadAndResizeImage(const std::string &filename) {
    cv::Mat original_image_grey = cv::imread(filename, cv::IMREAD_GRAYSCALE);
    if (original_image_grey.data == nullptr) {
        std::cout << "Could not open image " << filename << std::endl;
    }
    cv::Mat resized_image;
    cv::resize(original_image_grey, resized_image, cv::Size(64, 64));
    return resized_image;
}

void ImageIndexer::generateDuplicateVectors() {
    std::cout << "Generating duplicate vectors \n";

    double treshold = 0.1;
    double euclidian_distance;
    for (auto img1_ptr = indexed_images_->begin(); img1_ptr < indexed_images_->end(); ++img1_ptr) {
        DuplicateVector new_duplicate_vector;
        for (auto img2_ptr = next(img1_ptr); img2_ptr < indexed_images_->end(); ++img2_ptr) {
            euclidian_distance = Algorithm::calculateEuclidianDistance(img1_ptr->getImage(), img2_ptr->getImage());
            std::cout << "Comparing " << img1_ptr->getFilenameStdString() << " to "
                      << img2_ptr->getFilenameStdString()
                      << ": " << (1 - euclidian_distance) * 100 << "% \n";
            if (euclidian_distance < treshold) {
                new_duplicate_vector.addDuplicate(*img2_ptr);
                indexed_images_->erase(img2_ptr);
            }
        }

        if (new_duplicate_vector.getNumberOfDuplicates() != 0) {
            std::cout << "Made a duplicate vector with \n";
            new_duplicate_vector.printDuplicates();
            new_duplicate_vector.addDuplicate(*img1_ptr);
            duplicate_vectors_->push_back(new_duplicate_vector);
            //todo: check memory allocation of duplicate_vector
        }
    }

    delete indexed_images_;
    printAllDuplicates();
    std::cout << "Done generating duplicate vectors \n";
    return;
}


void ImageIndexer::DisplayImage(const cv::Mat &image) {
    cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE);// Create a window for display.
    cv::imshow("Display window", image);                   // Show our image inside it.
    cv::waitKey(0);
}

void ImageIndexer::printAllDuplicates() {
    for (auto vector : *duplicate_vectors_) {
        vector.printDuplicates();
    }
}

DuplicateVector *ImageIndexer::getDuplicateVector(int index) {
    return &duplicate_vectors_->at(index);
}

int ImageIndexer::getNumberOfDuplicateVectors() {
    return int(duplicate_vectors_->size());
}




