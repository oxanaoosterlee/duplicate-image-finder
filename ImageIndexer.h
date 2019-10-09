//
// Created by oxana on 22-9-19.
//

#ifndef DUPLICATE_IMAGE_FINDER_IMAGEINDEXER_H
#define DUPLICATE_IMAGE_FINDER_IMAGEINDEXER_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include "Image.h"
#include "DuplicateVector.h"

class ImageIndexer {
public:
    ImageIndexer();

    ~ImageIndexer();

    void indexImages();

    void generateDuplicateVectors();

    void printAllDuplicates();

    void setPath(QString path);

    static void DisplayImage(const cv::Mat& image); //Used for debugging.
    DuplicateVector *getDuplicateVector(int index);

    int getNumberOfDuplicateVectors();

private:
    std::vector<Image> *indexed_images_;
    std::vector<DuplicateVector> *duplicate_vectors_;

    QString root_path_;
    QStringList indexed_extensions = {"*.jpg", "*.JPG", "*.PNG",
                                      "*.png"}; //todo: add more indexed_extensions if necessary
    static cv::Mat LoadAndResizeImage(const std::string &filename);

};


#endif //DUPLICATE_IMAGE_FINDER_IMAGEINDEXER_H
