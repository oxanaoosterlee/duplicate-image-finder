#include <iostream>
#include "indexer.h"
#include "comparison_algorithm.h"
#include <chrono>
#include <QtCore>

using namespace std;
using namespace chrono;



int main() {

    ImageIndexer image_loader;
    ComparisonAlgorithm algorithm;

    vector<Image> all_images;

    all_images = image_loader.GenerateAllImagesList("/home/oxana/Documents/Projects/Duplicate Image Search/Images");
    algorithm.FindDuplicates(&all_images);

    for (auto image : all_images){
        image.printDuplicates();
    }
    return 0;
}