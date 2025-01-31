//
// Created by oxana on 22-9-19.
//
#include "Algorithm.h"

using namespace std;

Algorithm::Algorithm()= default;
Algorithm::~Algorithm() = default;


// Calculates the IMED between two images
double Algorithm::CalculateIMED(const cv::Mat& image1, const cv::Mat& image2){
    double euclidian_distance = 0;

    double sum = 0;
    // P_i: (i,j)
    // P_j: (k,l)
    for (int i=0; i < 64; i++){
        for(int j=0; j < 64; j++){
            for (int k = 0; k < 64; k++){
                for (int l = 0; l < 64; l++){
                    sum += exp(-(pow((i-k),2) + pow((j - l),2))/2) *
                            (getPixelIntensity(image1, i, j) - getPixelIntensity(image2, i, j)) *
                            (getPixelIntensity(image1, k, l) - getPixelIntensity(image2, k, l));
                }
            }
        }

    }

    euclidian_distance = sqrt((1/(2*M_1_PI)) * sum);
    return euclidian_distance;
}

// Returns the intensity of pixel (x,y) of image.
int Algorithm::getPixelIntensity(cv::Mat image, int x, int y){
    cv::Scalar intensity = image.at<uchar>(x,y);
    return int(intensity[0]);
}

// Calculate the normalized Euclidian Distance between two images.
double Algorithm::calculateEuclidianDistance(const cv::Mat &image1, const cv::Mat &image2){
    return (1/ (64.0 * 255)) * cv::norm(image1, image2, cv::NORM_L2);
}

////todo: Change to pointer
//void Algorithm::FindDuplicates(std::vector<Image> *all_images) {
//    double treshold = 0.2;
//    double euclidian_distance;
//
//    // Compare img1 to img2
//    for(auto img1_ptr = all_images->begin() ; img1_ptr < prev(all_images->end()); ++img1_ptr){
//        for(auto img2_ptr = next(img1_ptr); img2_ptr < all_images->end(); ++img2_ptr){
//            euclidian_distance = calculateEuclidianDistance(img1_ptr->getImage(), img2_ptr->getImage());
//            cout << "Comparing " << img1_ptr->getFileNameString() << " to " << img2_ptr->getFileNameString() << ": " << (1-euclidian_distance) * 100 << "% \n";
//            if (euclidian_distance < treshold){
//
//                img1_ptr -> addDuplicateImage(img2_ptr -> getPath(), euclidian_distance);
//                all_images->erase(img2_ptr);
//            }
//        }
//    }
//}
//

