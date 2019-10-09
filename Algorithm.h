//
// Created by oxana on 22-9-19.
//

#ifndef DUPLICATE_IMAGE_FINDER_ALGORITHM_H
#define DUPLICATE_IMAGE_FINDER_ALGORITHM_H

#include <opencv2/core/core.hpp>
#include "Image.h"

class Algorithm {
public:
    Algorithm();
    ~Algorithm();
    double CalculateIMED(const cv::Mat& image1, const cv::Mat& image2);
    static int getPixelIntensity(cv::Mat image, int x, int y);
    static double calculateEuclidianDistance(const cv::Mat &image1, const cv::Mat &image2);

};


#endif //DUPLICATE_IMAGE_FINDER_ALGORITHM_H
