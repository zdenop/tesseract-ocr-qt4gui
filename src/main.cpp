/*
 *
*/

#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //check if translation directory exists
    QString m_path;
    QString appdir = QCoreApplication::applicationDirPath();
    QStringList paths;
    paths.append(appdir + "/translations/");
    paths.append(appdir + "/../translations/");
    paths.append(appdir + "/../share/" +
                 QCoreApplication::applicationName().toLower() +
                 "/translations/");
    paths.append("/usr/share/cowboxer/translations/");
    paths.append(appdir + "/../resource/translations");
    paths.append(appdir + "/../resources/translations");
    foreach (const QString& path, paths) {
      if (QFile::exists(path)) {
        m_path = path;
        break;
      }
    }
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QString locale = QLocale::system().name();
    locale.truncate(locale.lastIndexOf('_'));
    QTranslator translator;
    translator.load("qt4tesseract_" + locale, m_path);
    app.installTranslator(&translator);

    app.setStyle(QStyleFactory::create("Plastique"));
    app.setApplicationName("QT4 tesseract-ocr gui");
    MainWindow w;
    w.show();
    return app.exec();
}
