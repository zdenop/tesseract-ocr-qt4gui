/**********************************************************************
* File:                SettingsDialog.h
* Description: Settings Dialog
* Author:            Zdenko Podobny
* Created:         2011-02-11
*
* (C) Copyright 2010, Marcel Kolodziejczyk
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

#ifndef SRC_INCLUDE_SETTINGSDIALOG_H_
#define SRC_INCLUDE_SETTINGSDIALOG_H_

#include <QtCore/QDebug>
#include <QtCore/QProcess>
#include <QtCore/QSettings>
#include "ui_settings.h"

const QString ProductVersion("1.00");
const QString ProjectUrl("https://github.com/zdenop/qt4-tesseract");
const QString ProjectName("QT4 Tesseract OCR");
const QString Organization("tesseract-ocr");

class SettingsDialog : public QDialog, public Ui::SettingsDialog {
  Q_OBJECT

  public:
    explicit SettingsDialog(QWidget* pard = 0);
    ~SettingsDialog();
    void initSettings();

  signals:
    void configuration_changed();

  private slots:
    void on_cb_prefix_toggled();
    void saveSettings();
    void on_pb_check_clicked();
};

#endif  // SRC_INCLUDE_SETTINGSDIALOG_H_
