/*
 *
*/

#include <QtGui/QApplication>
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("QT4 tesseract-ocr gui");
    MainWindow w;
    w.show();
    return a.exec();
}
