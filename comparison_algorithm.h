//
// Created by oxana on 22-9-19.
//

#ifndef PROJECT_IMED_ALGORITHM_H
#define PROJECT_IMED_ALGORITHM_H

#include <opencv2/core/core.hpp>

class ComparisonAlgorithm {
public:
    double CalculateIMED(cv::Mat image1, cv::Mat image2);
    int GetPixelIntensity(cv::Mat image, int x, int y);
    double CalculateEuclidianDistance(cv::Mat image1, cv::Mat image2);


};


#endif //PROJECT_IMED_ALGORITHM_H
