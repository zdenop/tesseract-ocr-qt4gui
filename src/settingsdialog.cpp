/**********************************************************************
* File:        settingsdialog.cpp
* Description: Settings Dialog
* Author:      Zdenko Podobny
* Created:     2011-08-17
*
* (C) Copyright 2011, Zdenko Podobny
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**    http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*
**********************************************************************/

#include "settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget* parent) : QDialog(parent) {
  setFixedSize(420, 370);
  setupUi(this);
  //setWindowTitle(tr("%1 :: Configuration...").arg(ProjectName));

  initSettings();

  QObject::connect(buttonBox, SIGNAL(accepted()), this, SLOT(saveSettings()));
  QObject::connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

SettingsDialog::~SettingsDialog() {}

void SettingsDialog::saveSettings() {
  QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                     Organization, ProjectName);

  settings.setValue("OCR/program", ln_prog->text());
  settings.setValue("OCR/version", lbl_VERSION->text());
  settings.setValue("OCR/prefix", ln_prefix->text());
  settings.setValue("OCR/sys_prefix", cb_prefix->isChecked());

  on_pb_check_clicked();

  emit configuration_changed();
  emit accept();
}

void SettingsDialog::initSettings() {
  QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                     Organization, ProjectName);

  if (settings.contains("OCR/program"))
    ln_prog->setText(settings.value("OCR/program").toString());
  if (settings.contains("OCR/version"))
    lbl_VERSION->setText(settings.value("OCR/version").toString());
  if (settings.contains("OCR/prefix"))
    ln_prefix->setText(settings.value("OCR/prefix").toString());
  if (settings.contains("OCR/sys_prefix"))
    cb_prefix->setChecked(settings.value("OCR/sys_prefix").toBool());

  on_cb_prefix_toggled();
}

void SettingsDialog::on_cb_prefix_toggled() {
  if (cb_prefix->isChecked()) {
    ln_prefix->setEnabled(false);
    pb_prefix->setEnabled(false);
  } else {
    ln_prefix->setEnabled(true);
    pb_prefix->setEnabled(true);
  }
}

void SettingsDialog::on_pb_check_clicked() {
  QString ocrCmd = ln_prog->text();

  QStringList arguments;
  QProcess *lprocess = new QProcess(this);
  arguments << "-v";
  lprocess->start(ocrCmd, arguments);
  lprocess->waitForFinished(-1);

  QString s = QString::fromLocal8Bit(lprocess->
                                     readAllStandardError().constData());
  QStringList lines;
  QString line;
  lines = s.split("\n");
  for (int i = 0; i < lines.size(); ++i) {
    line = lines.at(i);
    if (line.contains("tesseract 3.01")) {
      lbl_VERSION->setText("3.01");
      return;
    } else if (line.contains(
                   QString("Usage:%1 imagename outputbase [-l lang] [configfile").arg(ocrCmd))) {
      lbl_VERSION->setText("3.00");
      return;
    } else if (line.contains(
                   QString("%1:Error:Usage:%1 imagename outputbase [-l lang] [configfile").arg(ocrCmd))) {
        lbl_VERSION->setText("2.04");
        return;
    } else {
      lbl_VERSION->setText("unknown");
      return;
    }
  }
}
