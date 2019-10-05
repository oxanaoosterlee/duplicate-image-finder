#include <iostream>
#include "indexer.h"
#include "comparison_algorithm.h"
#include "GUI/MainWindow.h"
#include <chrono>
#include <QtCore>
#include <QApplication>
#include <QPushButton>

using namespace std;
using namespace chrono;



int main(int argc, char **argv) {

//    ImageIndexer image_loader;
//    ComparisonAlgorithm algorithm;
//
//    vector<Image> all_images;
//
//    all_images = image_loader.GenerateAllImagesList("/home/oxana/Documents/Projects/Duplicate Image Search/Images");
//    algorithm.FindDuplicates(&all_images);
//
//    for (auto image : all_images){
//        image.printDuplicates();
//    }

    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();

    return 0;
}