/*
 *
*/

#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    a.setStyle(QStyleFactory::create("Plastique"));
    a.setApplicationName("QT4 tesseract-ocr gui");
    MainWindow w;
    w.show();
    return a.exec();
}
