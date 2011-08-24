/**********************************************************************
* File:            mainwindow.h
* Description:     main window
* Author:          Zdenko Podobny
* Created:         2011-08-18
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

#ifndef SRC_MAINWINDOW_H_
#define SRC_MAINWINDOW_H_

#include <QtCore/QDir>
#include <QtCore/QDebug>
#include <QtCore/QProcess>
#include <QtCore/QSettings>
#include <QtCore/QTextCodec>
#include <QtCore/QTimer>
#include <QtCore/QTranslator>
#include <QtGui/QApplication>
#include <QtGui/QCloseEvent>
#include <QtGui/QFileDialog>
#include <QtGui/QMainWindow>
#include <QtGui/QMessageBox>
#include <QtGui/QSplashScreen>
#include <QtGui/QStyleFactory>
#include <QSortFilterProxyModel>

#include "settingsdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

  public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    SettingsDialog* runSettingsDialog;

  protected:
    void initForm();
    void closeEvent(QCloseEvent* event);

  private:
    Ui::MainWindow *ui;
    QProcess process;
    QList<QString> getLangugagelist();
    QString getLangName(QString lang);
    void initLangs();
    void readSettings();
    void writeSettings();

  private slots:
    void on_actionConfiguration_triggered();
    void on_actionAbout_triggered();
    void on_actionAbout_QT_triggered();
    void on_buttonBox_accepted();
    void on_pushButtonIn_clicked();
    void on_pushButtonOut_clicked();

    void processErrors();
    void processFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void processError(QProcess::ProcessError error);
    void feature_limits();
    void setOutName(bool status);
    void setOutExt(QString filename);
    void formatChanged(int);
};

#endif  // SRC_MAINWINDOW_H_
