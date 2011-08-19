/**********************************************************************
* File:            main.cpp
* Description:     main
* Author:          Zdenko Podobny
* Created:         2011-08-04
*
* (C) Copyright 2011, Zdenko Podobny
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**        http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*
**********************************************************************/

#include "src/mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  // splashscreen
  QSplashScreen *splash =
    new QSplashScreen(QPixmap(":/Images/images/qt4tesseract.svg"),
                      Qt::WindowStaysOnTopHint);
  splash->show();

  QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
  QString locale = QLocale::system().name().section('_', 0, 0);
  QTranslator translator;
  translator.load(QString("qt4tesseract_") + locale,
                          ":/Languages/translations");
  app.installTranslator(&translator);

  app.setStyle(QStyleFactory::create("Plastique"));
  app.setApplicationName("QT4 tesseract-ocr gui");

  MainWindow window;
  window.show();

  // close splash after 4s
  QTimer::singleShot(2000, splash, SLOT(close()));
  return app.exec();
}
