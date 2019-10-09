#include <iostream>
#include <chrono>
#include <QtCore>
#include <QApplication>
#include <QPushButton>
#include "GUI/MainWindow.h"

using namespace std;
using namespace chrono;



int main(int argc, char **argv) {

    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}