/**********************************************************************
* File:            mainwindow.cpp
* Description:     mainwindow
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

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);
  // workaround for buttonBox translation
  ui->buttonBox->button(QDialogButtonBox::Ok)->setText( "&Run" );
  ui->buttonBox->button(QDialogButtonBox::Close)->setText( "&Close" );

  // TODO(zdenop): get psm from cmd line ;-)

  setWindowTitle(QString(tr("QT4 Tesseract OCR GUI %1")).arg(ProductVersion));
  setWindowIcon(QIcon(":/Images/images/qt4tesseract.svg"));

  initForm();
}

MainWindow::~MainWindow() {
  delete ui;
}

/*
  Get Language name from ISO 639-1 code
  http://en.wikipedia.org/wiki/List_of_ISO_639-1_codes
  */
QString MainWindow::getLangName(QString lang) {
    QMap<QString,QString> map;
    map["abk"] = QObject::tr("Abkhaz");
    map["aar"] = QObject::tr("Afar");
    map["afr"] = QObject::tr("Afrikaans");
    map["aka"] = QObject::tr("Akan");
    map["sqi"] = QObject::tr("Albanian");
    map["amh"] = QObject::tr("Amharic");
    map["ara"] = QObject::tr("Arabic");
    map["arg"] = QObject::tr("Aragonese");
    map["hye"] = QObject::tr("Armenian");
    map["asm"] = QObject::tr("Assamese");
    map["ava"] = QObject::tr("Avaric");
    map["ave"] = QObject::tr("Avestan");
    map["aym"] = QObject::tr("Aymara");
    map["aze"] = QObject::tr("Azerbaijani");
    map["bam"] = QObject::tr("Bambara");
    map["bak"] = QObject::tr("Bashkir");
    map["eus"] = QObject::tr("Basque");
    map["bel"] = QObject::tr("Belarusian");
    map["ben"] = QObject::tr("Bengali");
    map["bih"] = QObject::tr("Bihari");
    map["bis"] = QObject::tr("Bislama");
    map["bos"] = QObject::tr("Bosnian");
    map["bre"] = QObject::tr("Breton");
    map["bul"] = QObject::tr("Bulgarian");
    map["mya"] = QObject::tr("Burmese");
    map["cat"] = QObject::tr("Catalan; Valencian");
    map["cha"] = QObject::tr("Chamorro");
    map["che"] = QObject::tr("Chechen");
    map["nya"] = QObject::tr("Chichewa; Chewa; Nyanja");
    map["zho"] = QObject::tr("Chinese");
    map["chv"] = QObject::tr("Chuvash");
    map["cor"] = QObject::tr("Cornish");
    map["cos"] = QObject::tr("Corsican");
    map["cre"] = QObject::tr("Cree");
    map["hrv"] = QObject::tr("Croatian");
    map["ces"] = QObject::tr("Czech");
    map["dan"] = QObject::tr("Danish");
    map["div"] = QObject::tr("Divehi; Dhivehi; Maldivian;");
    map["nld"] = QObject::tr("Dutch");
    map["dzo"] = QObject::tr("Dzongkha");
    map["eng"] = QObject::tr("English");
    map["epo"] = QObject::tr("Esperanto");
    map["est"] = QObject::tr("Estonian");
    map["ewe"] = QObject::tr("Ewe");
    map["fao"] = QObject::tr("Faroese");
    map["fij"] = QObject::tr("Fijian");
    map["fin"] = QObject::tr("Finnish");
    map["fra"] = QObject::tr("French");
    map["ful"] = QObject::tr("Fula; Fulah; Pulaar; Pular");
    map["glg"] = QObject::tr("Galician");
    map["kat"] = QObject::tr("Georgian");
    map["deu"] = QObject::tr("German");
    map["ell"] = QObject::tr("Greek, Modern");
    map["grn"] = QObject::tr("Guaraní");
    map["guj"] = QObject::tr("Gujarati");
    map["hat"] = QObject::tr("Haitian; Haitian Creole");
    map["hau"] = QObject::tr("Hausa");
    map["heb"] = QObject::tr("Hebrew (modern)");
    map["her"] = QObject::tr("Herero");
    map["hin"] = QObject::tr("Hindi");
    map["hmo"] = QObject::tr("Hiri Motu");
    map["hun"] = QObject::tr("Hungarian");
    map["ina"] = QObject::tr("Interlingua");
    map["ind"] = QObject::tr("Indonesian");
    map["ile"] = QObject::tr("Interlingue");
    map["gle"] = QObject::tr("Irish");
    map["ibo"] = QObject::tr("Igbo");
    map["ipk"] = QObject::tr("Inupiaq");
    map["ido"] = QObject::tr("Ido");
    map["isl"] = QObject::tr("Icelandic");
    map["ita"] = QObject::tr("Italian");
    map["iku"] = QObject::tr("Inuktitut");
    map["jpn"] = QObject::tr("Japanese");
    map["jav"] = QObject::tr("Javanese");
    map["kal"] = QObject::tr("Kalaallisut, Greenlandic");
    map["kan"] = QObject::tr("Kannada");
    map["kau"] = QObject::tr("Kanuri");
    map["kas"] = QObject::tr("Kashmiri");
    map["kaz"] = QObject::tr("Kazakh");
    map["khm"] = QObject::tr("Khmer");
    map["kik"] = QObject::tr("Kikuyu, Gikuyu");
    map["kin"] = QObject::tr("Kinyarwanda");
    map["kir"] = QObject::tr("Kirghiz, Kyrgyz");
    map["kom"] = QObject::tr("Komi");
    map["kon"] = QObject::tr("Kongo");
    map["kor"] = QObject::tr("Korean");
    map["kur"] = QObject::tr("Kurdish");
    map["kua"] = QObject::tr("Kwanyama, Kuanyama");
    map["lat"] = QObject::tr("Latin");
    map["ltz"] = QObject::tr("Luxembourgish, Letzeburgesch");
    map["lug"] = QObject::tr("Luganda");
    map["lim"] = QObject::tr("Limburgish, Limburgan, Limburger");
    map["lin"] = QObject::tr("Lingala");
    map["lao"] = QObject::tr("Lao");
    map["lit"] = QObject::tr("Lithuanian");
    map["lub"] = QObject::tr("Luba-Katanga");
    map["lav"] = QObject::tr("Latvian");
    map["glv"] = QObject::tr("Manx");
    map["mkd"] = QObject::tr("Macedonian");
    map["mlg"] = QObject::tr("Malagasy");
    map["msa"] = QObject::tr("Malay");
    map["mal"] = QObject::tr("Malayalam");
    map["mlt"] = QObject::tr("Maltese");
    map["mri"] = QObject::tr("Māori");
    map["mar"] = QObject::tr("Marathi (Marāṭhī)");
    map["mah"] = QObject::tr("Marshallese");
    map["mon"] = QObject::tr("Mongolian");
    map["nau"] = QObject::tr("Nauru");
    map["nav"] = QObject::tr("Navajo, Navaho");
    map["nob"] = QObject::tr("Norwegian Bokmål");
    map["nde"] = QObject::tr("North Ndebele");
    map["nep"] = QObject::tr("Nepali");
    map["ndo"] = QObject::tr("Ndonga");
    map["nno"] = QObject::tr("Norwegian Nynorsk");
    map["nor"] = QObject::tr("Norwegian");
    map["iii"] = QObject::tr("Nuosu");
    map["nbl"] = QObject::tr("South Ndebele");
    map["oci"] = QObject::tr("Occitan");
    map["oji"] = QObject::tr("Ojibwe, Ojibwa");
    map["chu"] = QObject::tr("Old Church Slavonic, Church Slavic, Church Slavonic, Old Bulgarian, Old Slavonic");
    map["orm"] = QObject::tr("Oromo");
    map["ori"] = QObject::tr("Oriya");
    map["oss"] = QObject::tr("Ossetian, Ossetic");
    map["pan"] = QObject::tr("Panjabi, Punjabi");
    map["pli"] = QObject::tr("Pāli");
    map["fas"] = QObject::tr("Persian");
    map["pol"] = QObject::tr("Polish");
    map["pus"] = QObject::tr("Pashto, Pushto");
    map["por"] = QObject::tr("Portuguese");
    map["que"] = QObject::tr("Quechua");
    map["roh"] = QObject::tr("Romansh");
    map["run"] = QObject::tr("Kirundi");
    map["ron"] = QObject::tr("Romanian, Moldavian, Moldovan");
    map["rus"] = QObject::tr("Russian");
    map["san"] = QObject::tr("Sanskrit (Saṁskṛta)");
    map["srd"] = QObject::tr("Sardinian");
    map["snd"] = QObject::tr("Sindhi");
    map["sme"] = QObject::tr("Northern Sami");
    map["smo"] = QObject::tr("Samoan");
    map["sag"] = QObject::tr("Sango");
    map["srp"] = QObject::tr("Serbian");
    map["gla"] = QObject::tr("Scottish Gaelic; Gaelic");
    map["sna"] = QObject::tr("Shona");
    map["sin"] = QObject::tr("Sinhala, Sinhalese");
    map["slk"] = QObject::tr("Slovak");
    map["slv"] = QObject::tr("Slovene");
    map["som"] = QObject::tr("Somali");
    map["sot"] = QObject::tr("Southern Sotho");
    map["spa"] = QObject::tr("Spanish; Castilian");
    map["sun"] = QObject::tr("Sundanese");
    map["swa"] = QObject::tr("Swahili");
    map["ssw"] = QObject::tr("Swati");
    map["swe"] = QObject::tr("Swedish");
    map["tam"] = QObject::tr("Tamil");
    map["tel"] = QObject::tr("Telugu");
    map["tgk"] = QObject::tr("Tajik");
    map["tha"] = QObject::tr("Thai");
    map["tir"] = QObject::tr("Tigrinya");
    map["bod"] = QObject::tr("Tibetan Standard, Tibetan, Central");
    map["tuk"] = QObject::tr("Turkmen");
    map["tgl"] = QObject::tr("Tagalog");
    map["tsn"] = QObject::tr("Tswana");
    map["ton"] = QObject::tr("Tonga (Tonga Islands)");
    map["tur"] = QObject::tr("Turkish");
    map["tso"] = QObject::tr("Tsonga");
    map["tat"] = QObject::tr("Tatar");
    map["twi"] = QObject::tr("Twi");
    map["tah"] = QObject::tr("Tahitian");
    map["uig"] = QObject::tr("Uighur, Uyghur");
    map["ukr"] = QObject::tr("Ukrainian");
    map["urd"] = QObject::tr("Urdu");
    map["uzb"] = QObject::tr("Uzbek");
    map["ven"] = QObject::tr("Venda");
    map["vie"] = QObject::tr("Vietnamese");
    map["vol"] = QObject::tr("Volapük");
    map["wln"] = QObject::tr("Walloon");
    map["cym"] = QObject::tr("Welsh");
    map["wol"] = QObject::tr("Wolof");
    map["fry"] = QObject::tr("Western Frisian");
    map["xho"] = QObject::tr("Xhosa");
    map["yid"] = QObject::tr("Yiddish");
    map["yor"] = QObject::tr("Yoruba");
    map["zha"] = QObject::tr("Zhuang, Chuang");
    map["zul"] = QObject::tr("Zulu");
    map["chi_tra"] = QObject::tr("Chinese (Traditional)");
    map["chi_sim"] = QObject::tr("Chinese (Simplified)");
    map["dan-frak"] = QObject::tr("Danish (Fraktur)");
    map["deu-frak"] = QObject::tr("German (Fraktur)");
    map["slk-frak"] = QObject::tr("Slovak (Fraktur)");
    map["swe-frak"] = QObject::tr("Swedish (Fraktur)");

    return map[lang];
}

void MainWindow::initLangs() {
  // Clean combobox with languages
    int langsCount = ui->comboBoxLang->count();
  if (langsCount > 0)
    for (int i = langsCount; i >= 0; i--) {
      ui->comboBoxLang->removeItem(0);
    }

  QList<QString> languages;
  languages = getLangugagelist();

  QString lang;
  foreach(lang, languages)
  if (getLangName(lang) == "")
    ui->comboBoxLang->addItem(lang, lang);
  else
    ui->comboBoxLang->addItem(getLangName(lang), lang);

  // sort language list
  QSortFilterProxyModel* proxy = new QSortFilterProxyModel(ui->comboBoxLang);
  proxy->setSourceModel(ui->comboBoxLang->model());
  ui->comboBoxLang->model()->setParent(proxy);
  ui->comboBoxLang->setModel(proxy);
  ui->comboBoxLang->model()->sort(0);
}

void MainWindow::initForm() {
  readSettings();

  connect(&process, SIGNAL(readyReadStandardError()),
          this, SLOT(processErrors()));
  connect(&process, SIGNAL(finished(int, QProcess::ExitStatus)),
          this, SLOT(processFinished(int, QProcess::ExitStatus)));
  connect(&process, SIGNAL(error(QProcess::ProcessError)),
          this, SLOT(processError(QProcess::ProcessError)));
  // TODO(zdenop): change of combobox or lineedit after init
  // emit signal for saving settings
}

QList<QString> MainWindow::getLangugagelist() {
  QProcess *lprocess = new QProcess(this);

  QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                     Organization, ProjectName);
  QString ocrCmd;

  if (settings.contains("OCR/program"))
    ocrCmd = settings.value("OCR/program").toString();
  // TODO(zdenop): check for missing setting or empty string

  if (!settings.value("OCR/sys_prefix").toBool()) {
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    env.insert("TESSDATA_PREFIX", settings.value("OCR/prefix").toString());
    lprocess->setProcessEnvironment(env);
    }

  QStringList arguments;
  arguments << "a" << "b" << "-l" << "_ICQ_";
  lprocess->start(ocrCmd, arguments);
  lprocess->waitForFinished(-1);

  QString s = QString::fromLocal8Bit(lprocess->
                                     readAllStandardError().constData());
  QStringList lines;
  QString line, langFile;
  lines = s.split("\n");
  for (int i = 0; i < lines.size(); ++i) {
    line = lines.at(i);
    if (line.contains("_ICQ_")) {
      // tesseract 3.01
      // Error opening data file /usr/local/share/tessdata/_ICQ_.traineddata
      langFile = line.replace("Error opening data file ", "");
      // tesseract 3.00 ;-)
      // Error openning data file /usr/local/share/tessdata/_ICQ_.traineddata
      langFile = langFile.replace("Error openning data file ", "");
      // tesseract 2.04 ;-)
      // Unable to load unicharset file /usr/share/tessdata/_ICQ_.unicharset
      langFile = langFile.replace("Unable to load unicharset file ", "");
    }
  }

  if (langFile == "")
    ui->tb_Log->appendHtml("<font color=red><b>" +
        tr("Unexpexted error: tesseract did not produced expected information!")
        + "</b></font>");

  // TODO(zdenop): Get TESSDATA_PREFIX from enviroment
  QFileInfo fi(langFile);
  QString tessdataPath = fi.absolutePath();
  QString extention = fi.suffix();

  QDir dir(tessdataPath);
  if (!dir.exists()) {
    QMessageBox msgBox;
    msgBox.setText(tr("Cannot find the tessdata directory!\n") +
                tr("Please check your configuration or tesseract instalation"));
    msgBox.exec();
    }

  QString filter = "*." + extention;
  QStringList filters;
  filters << filter.trimmed();
  dir.setNameFilters(filters);

  QList<QString> languages;
  QFileInfoList list = dir.entryInfoList();

  for (int i = 0; i < list.size(); ++i) {
    QFileInfo fileInfo = list.at(i);
    languages.append(QString("%1").arg(fileInfo.baseName()));
  }
  qSort(languages);

  return languages;
}

void MainWindow::on_buttonBox_accepted() {
  writeSettings();

  QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                     Organization, ProjectName);
  QString ocrCmd;

  if (settings.contains("OCR/program"))
    ocrCmd = settings.value("OCR/program").toString();

  // TODO(zdenop): check for missing setting or empty string

  QStringList args;

  QString in = ui->lineEditIn->text();
  args << in;
  QString out = ui->lineEditOut->text();
  out = out.replace(".txt", "").replace(".html", "");
  args << out;

  QString lang = ui->comboBoxLang->itemData(
                   ui->comboBoxLang->currentIndex()).toString();
  args << "-l" << lang;

  if (ui->comboBoxPSM->isEnabled()) {
    int PSM = ui->comboBoxPSM->currentIndex();
    args  << "-psm" << QString::number(PSM);
  }

  if (ui->comboBoxForm->currentIndex() == 1) {
    args << "hocr";
  }

  if (!settings.value("OCR/sys_prefix").toBool()) {
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    env.insert("TESSDATA_PREFIX", settings.value("OCR/prefix").toString());
    process.setProcessEnvironment(env);
    }

  ui->tb_Log->appendHtml(tr("OCR program started..."));
  ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
  process.start(ocrCmd, args);
}

void MainWindow::processErrors() {
  QByteArray newData = process.readAllStandardError();
  QString text = QString::fromLocal8Bit(newData);
  QString line;
  QStringList lines = text.split("\n");
  for (int i = 0; i < lines.size(); ++i) {
    line = lines.at(i);
    ui->tb_Log->appendHtml(lines.at(i));
  }
}

void MainWindow::processFinished(int exitCode,
                                 QProcess::ExitStatus exitStatus) {
  if (exitStatus == QProcess::CrashExit) {
    ui->tb_Log->appendHtml(tr("OCR program crashed"));
  } else if (exitCode != 0) {
    ui->tb_Log->appendHtml(tr("OCR program failed"));
  } else {
    ui->tb_Log->appendHtml(tr("<font color=green><b>Ouput created</b></font>"));
  }
  ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
}

void MainWindow::processError(QProcess::ProcessError error) {
  if (error == QProcess::FailedToStart)
    ui->tb_Log->appendHtml(tr("OCR program not found"));
  else
    ui->tb_Log->appendHtml(tr("<font color=red><b>Execute error (%1)</b></font>").arg(error));
}

void MainWindow::on_pushButtonIn_clicked() {
  QString filetype = "Image files (*.bmp *.png *.jpeg *.jpg *.tif *.tiff);;";
  filetype += "All files (*.*)";
  QString last_path = QDir::homePath();
  // TODO(zdenop): last_path,

  QString imageFile = QFileDialog::getOpenFileName(
                        this,
                        tr("Select image file..."),
                        last_path,
                        filetype);

  ui->lineEditIn->setText(imageFile);

  if (ui->checkBoxName->isChecked()) {
    int lastindex = imageFile.lastIndexOf(".");
    QString outName = imageFile.left(lastindex);
    if (ui->comboBoxForm->currentIndex() == 1)
      outName.append(".html");
    else
      outName.append(".txt");
    ui->lineEditOut->setText(outName);
  }
}

void MainWindow::on_pushButtonOut_clicked() {
  // TODO(zdenop): check box -> select base on input field
  QString currentFileName = ui->lineEditOut->text();
  QString fileName = QFileDialog::getSaveFileName(this,
                     tr("Save to file..."),
                     currentFileName,
                     tr("Text or html files (*.txt *.html);;All files (*)"));

  if (fileName.isEmpty())
    return;

  ui->lineEditOut->setText(fileName);

  int lastindex = fileName.length() - fileName.lastIndexOf(".");
  QString fileExt = fileName.right(lastindex);
  if (fileExt == ".txt")
    ui->comboBoxForm->setCurrentIndex(0);
  else if (fileExt == ".html")
    ui->comboBoxForm->setCurrentIndex(1);
}

void MainWindow::on_actionAbout_triggered() {
  QMessageBox aboutMB(this);

  QPixmap appLogo(":/Images/images/qt4tesseract.svg");
  aboutMB.setIconPixmap(appLogo);

  QString abouttext = tr("<h1>QT4 Tesseract OCR GUI</h1>");

  abouttext.append(tr("<p>This is a simple GUI for tesseract-ocr</p>"));
  abouttext.append(tr("<p>Project page: <a href=%1>%2</a></p>").
                   arg(ProjectUrl).arg(ProjectName));

  abouttext.append(tr("Copyright 2011 Zdenko Podobný</p>"));
  abouttext.append(tr("<p>This software is released under "
                      "<a href=\"http://www.apache.org/licenses/LICENSE-2.0\">"
                      "Apache License 2.0</a></p>"));
  abouttext.append(tr("<p>Translation is done on "
            "<a href=\"https://www.transifex.net/projects/p/qt4-tesseract\">"
            "Transifex.net</a></p>"));
  aboutMB.setText(abouttext);

  aboutMB.setParent(this);
  aboutMB.exec();
}

void MainWindow::on_actionConfiguration_triggered() {
  runSettingsDialog = new SettingsDialog(this);
  connect(runSettingsDialog,
        SIGNAL(configuration_changed()), this, SLOT(feature_limits()));
  runSettingsDialog->exec();
}

void MainWindow::on_actionAbout_QT_triggered() {
  QMessageBox::aboutQt(this, tr("About Qt"));
}

void MainWindow::readSettings() {
  // TODO(zdenop): not implemented yet
  ui->checkBoxOpen->setVisible(false);

  // default values
  ui->comboBoxForm->setCurrentIndex(0);
  ui->comboBoxPSM->setCurrentIndex(3);
  ui->checkBoxName->setChecked(true);

  // TODO(zdenop): last_path ocr_command

  QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                     Organization, ProjectName);

  if (!settings.contains("OCR/program"))
    on_actionConfiguration_triggered();

  settings.beginGroup("mainWindow");
  restoreGeometry(settings.value("geometry").toByteArray());
  restoreState(settings.value("state").toByteArray());
  settings.endGroup();

  ui->lineEditIn->setText(settings.value("Parameters/input").toString());
  ui->lineEditOut->setText(settings.value("Parameters/output").toString());
  ui->checkBoxName->setChecked(
        settings.value("Parameters/output_name").toBool());
  ui->checkBoxOpen->setChecked(
        settings.value("Parameters/output_open").toBool());

  feature_limits();

  int langindex = ui->comboBoxLang->findData(
        settings.value("Parameters/lang").toString());
  ui->comboBoxLang->setCurrentIndex(langindex);
}

void MainWindow::writeSettings() {
  QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                     Organization, ProjectName);

  settings.beginGroup("mainWindow");
  settings.setValue("geometry", saveGeometry());
  settings.setValue("state", saveState());
  settings.endGroup();

  settings.beginGroup("Parameters");
  settings.setValue("input", ui->lineEditIn->text());
  settings.setValue("output", ui->lineEditOut->text());
  settings.setValue("output_name", ui->checkBoxName->isChecked());
  settings.setValue("output_open", ui->checkBoxOpen->isChecked());
  settings.setValue("lang", ui->comboBoxLang->itemData(
                      ui->comboBoxLang->currentIndex()).toString());
  settings.setValue("format", ui->comboBoxForm->currentIndex());
  settings.setValue("psm", ui->comboBoxPSM->currentIndex());
  settings.endGroup();
}

void MainWindow::closeEvent(QCloseEvent* event) {
  writeSettings();
  event->accept();
}

void MainWindow::feature_limits() {
  initLangs();

  QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                     Organization, ProjectName);
  if (settings.value("OCR/version").toString() == "3.01") {
    ui->comboBoxPSM->setEnabled(true);
  } else {
    ui->comboBoxPSM->setEnabled(false);
  }

  ui->comboBoxForm->setCurrentIndex(
        settings.value("Parameters/format").toInt());
  ui->comboBoxPSM->setCurrentIndex(settings.value("Parameters/psm").toInt());

  // hocr/html is supported from 3.01
  if (settings.value("OCR/version").toFloat() > 3.00) {
      ui->comboBoxForm->setMaxVisibleItems(2);
  } else {
      ui->comboBoxForm->setMaxVisibleItems(1);
  }
}
