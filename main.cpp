#include <iostream>
#include "image_loader.h"
#include "comparison_algorithm.h"
#include <chrono>

using namespace std::chrono;


int main() {
    //todo: loop through all images in folder

    ImageLoader image_loader;
    ComparisonAlgorithm algorithm;

    cv::Mat image1 = image_loader.load_image("/home/oxana/Documents/Projects/Duplicate Image Search/Images/img10.jpg");
    cv::Mat image2 = image_loader.load_image("/home/oxana/Documents/Projects/Duplicate Image Search/Images/img11.jpg");

    auto start = high_resolution_clock::now();
    double distance = algorithm.CalculateEuclidianDistance(image1, image2);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "duration(us): " << duration.count() << std::endl;


    std::cout << "distance is " << distance << std::endl;
    std::cout << "images are " << (1-distance) * 100 << "% similar" << std::endl;

    // Display image
    cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE );// Create a window for display.
    cv::imshow( "Display window", image1 );                   // Show our image inside it.
    cv::waitKey(0);

    return 0;
}