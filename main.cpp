#include <iostream>
#include "image_loader.h"
#include "comparison_algorithm.h"
#include <chrono>


using namespace std;
using namespace chrono;


int main() {

    ImageLoader image_loader;
    ComparisonAlgorithm algorithm;

    vector<string> index_list;
    index_list = image_loader.GetFileList("/home/oxana/Documents/Projects/Duplicate Image Search/Images/");
    for(auto it = index_list.begin() ; it != prev(index_list.end()); ++it){
        cv::Mat image1 = image_loader.LoadImage(*it);
        for(auto it2 = next(it) ; it2 != index_list.end() ; ++it2)  {
            cv::Mat image2 = image_loader.LoadImage(*it2);
            double distance = algorithm.CalculateEuclidianDistance(image1, image2);
            if (distance < 0.2) {
                cout << "Comparing " << *it << " and " << *it2 << "\n similarity: " << (1 - distance) * 100 << "% \n";
            }
        }
    }


    return 0;
}