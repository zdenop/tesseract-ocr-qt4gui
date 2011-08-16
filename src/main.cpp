/*
 *
*/

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //splashscreen
    QSplashScreen *splash =
        new QSplashScreen(QPixmap(":/Images/images/qt4tesseract.svg"),
                                              Qt::WindowStaysOnTopHint );
    splash->show();
    //splash->showMessage("Start ...");

    //splash->showMessage("Starting translation…");
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QString locale = QLocale::system().name().section( '_', 0, 0 );
    QTranslator translator;
    translator.load( QString( "qt4tesseract_" ) + locale, ":/Languages/translations" );
    app.installTranslator(&translator);

    app.setStyle(QStyleFactory::create("Plastique"));
    app.setApplicationName("QT4 tesseract-ocr gui");

    MainWindow window;
    window.show();
    QTimer::singleShot(2000, splash, SLOT(close()));// close splash after 4s
    //QTimer::singleShot(3000, &window, SLOT(show()));// mainwindow reappears after 4s
    return app.exec();
}
