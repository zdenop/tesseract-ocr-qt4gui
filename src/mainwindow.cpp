/*
 *
*/

//#include <QSettings>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>

#include "mainwindow.h"
#include "ui_mainwindow.h"

const QString ProductVersion("1.00");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(QString(tr("QT4 tesseract-ocr GUI %1")).arg(ProductVersion));
    initForm();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initForm()
{
    // TODO(zdenop): from settings
    ui->lineEditIn->setText("~/eurotext.tif");
    //ui->lineEditOut->setText("/home/zdeno/test_back");
    // TODO(zdenop): from settings
    ui->actionConfiguration->setVisible(false);

    QMap<QString, QString> map;
    map["bul"] = QObject::tr("Bulgarian");
    map["cat"] = QObject::tr("Catalan");
    map["ces"] = QObject::tr("Czech");
    map["chi_tra"] = QObject::tr("Chinese (Traditional)");
    map["chi_sim"] = QObject::tr("Chinese (Simplified)");
    map["dan"] = QObject::tr("Danish");
    map["dan-frak"] = QObject::tr("Danish (Fraktur)");
    map["nld"] = QObject::tr("Dutch");
    map["eng"] = QObject::tr("English");
    map["fin"] = QObject::tr("Finnish");
    map["fra"] = QObject::tr("French");
    map["deu"] = QObject::tr("German");
    map["deu-frak"] = QObject::tr("German (Fraktur)");
    map["ell"] = QObject::tr("Greek");
    map["hun"] = QObject::tr("Hungarian");
    map["ind"] = QObject::tr("Indonesian");
    map["ita"] = QObject::tr("Italian");
    map["jpn"] = QObject::tr("Japanese");
    map["kor"] = QObject::tr("Korean");
    map["lav"] = QObject::tr("Latvian");
    map["lit"] = QObject::tr("Lithuanian");
    map["nor"] = QObject::tr("Norwegian");
    map["pol"] = QObject::tr("Polish");
    map["por"] = QObject::tr("Portuguese");
    map["ron"] = QObject::tr("Romanian");
    map["rus"] = QObject::tr("Russian");
    map["slk"] = QObject::tr("Slovak");
    map["slk-frak"] = QObject::tr("Slovak (Fraktur)");
    map["slv"] = QObject::tr("Slovenian");
    map["spa"] = QObject::tr("Spanish");
    map["srp"] = QObject::tr("Serbian");
    map["swe"] = QObject::tr("Swedish");
    map["swe-frak"] = QObject::tr("Swedish (Fraktur)");
    map["tgl"] = QObject::tr("Tagalog");
    map["tur"] = QObject::tr("Turkish");
    map["ukr"] = QObject::tr("Ukrainian");
    map["vie"] = QObject::tr("Vietnamese");

    // TODO(zdenop): get from cmd line ;-)
    QList<QString> languages;
    languages = getLangugagelist();

    QString lang;
    foreach(lang, languages)
      if (map[lang] == "")
        ui->comboBoxLang->addItem(lang,lang);
      else
         ui->comboBoxLang->addItem(map[lang],lang);

    // TODO(zdenop): get from cmd line ;-)
    ui->comboBoxPSM->setCurrentIndex(3);

    connect(&process, SIGNAL(readyReadStandardError()),
            this, SLOT(processErrors()));
    connect(&process, SIGNAL(finished(int, QProcess::ExitStatus)),
            this, SLOT(processFinished(int, QProcess::ExitStatus)));
    connect(&process, SIGNAL(error(QProcess::ProcessError)),
            this, SLOT(processError(QProcess::ProcessError)));

    // TODO(zdenop): change of combobox or lineedit after init emit signal for saving settings
}

QList<QString> MainWindow::getLangugagelist() {
    QProcess *lprocess = new QProcess(this);;
    QString ocrCmd = "/usr/local/bin/tesseract";

    // workaround for windows
    QFile f (ocrCmd);
    if( !f.exists() )
        ocrCmd = "tesseract";

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
            langFile = line.replace("Error openning data file ","");
            }
    }

    // TODO(zdenop): Get TESSDATA_PREFIX from enviroment
    QFileInfo fi(langFile);
    QString tessdataPath = fi.absolutePath();
    QString extention = fi.suffix();
    qDebug() <<"tessdataPath:" << tessdataPath;
    qDebug() <<"extention:" << extention;

    QDir dir(tessdataPath);
    if (!dir.exists())
        qWarning("Cannot find the tessdata directory");

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
    // TODO(zdenop): take it from settings
    QString ocrCmd = "/usr/local/bin/tesseract";

    // workaround for windows
    QFile f (ocrCmd);
    if( !f.exists() )
        ocrCmd = "tesseract";

    QStringList args;

    QString in = ui->lineEditIn->text();
    QString out = ui->lineEditOut->text();
    out = out.replace(".txt","").replace(".html","");

    QString lang = ui->comboBoxLang->itemData(ui->comboBoxLang->currentIndex()).toString();
    int PSM = ui->comboBoxPSM->currentIndex();
    QString format;
    if (ui->comboBoxForm->currentIndex() == 1)
        format = "hocr";
    else
        format = "";
    args << in << out << "-l" << lang << "-psm" << QString::number(PSM) << format;
    statusBar()->showMessage(tr("OCR program is running..."));
    process.start(ocrCmd, args);

    qDebug() << "args: " << args;

}

void MainWindow::processErrors() {
    QByteArray newData = process.readAllStandardError();
    QString text = QString::fromLocal8Bit(newData);
    qDebug() << text;
}

void MainWindow::processFinished(int exitCode,
                                    QProcess::ExitStatus exitStatus)
{
    if (exitStatus == QProcess::CrashExit) {
        statusBar()->showMessage(tr("OCR program crashed"), 4000);
    } else if (exitCode != 0) {
        statusBar()->showMessage(tr("OCR program failed"), 4000);
    } else {
        statusBar()->showMessage(tr("File created"), 4000);
    }
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
}

void MainWindow::processError(QProcess::ProcessError error) {
    if (error == QProcess::FailedToStart)
        statusBar()->showMessage(tr("OCR program not found"), 4000);
}

void MainWindow::on_pushButtonIn_clicked() {
    QString filetype = "Image files (*.bmp *.png *.jpeg *.jpg *.tif *.tiff);;";
    filetype += "All files (*.*)";
    QString last_path = QDir::homePath();
    //TODO(zdenop): last_path,

    QString imageFile = QFileDialog::getOpenFileName(
                          this,
                          tr("Select image file..."),
                          last_path,
                          filetype);

    ui->lineEditIn->setText(imageFile);

    int lastindex = imageFile.lastIndexOf(".");
    QString outName = imageFile.left(lastindex);
    if (ui->comboBoxForm->currentIndex() == 1)
        outName.append(".html");
    else
        outName.append(".txt");
    ui->lineEditOut->setText(outName);
}

void MainWindow::on_pushButtonOut_clicked() {
    // TODO(zdenop):check box -> select base on input field
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
  QString abouttext = tr("<h1>QT4 tesseract-ocr GUI</h1>");

  abouttext.append(tr("<p>This is a simple GUI for tesseract-ocr</p>"));
  /*abouttext.append(tr("<p>Project page: <a href=%1>%2</a></p>").
                   arg(PROJECT_URL).arg(PROJECT_URL_NAME));*/
  abouttext.append(tr("Copyright 2011 Zdenko Podobný</p>"));
  abouttext.append(tr("<p>This software is released under "
                      "<a href=\"http://www.apache.org/licenses/LICENSE-2.0\">Apache License 2.0</a></p>"));
  QMessageBox::about(this, tr("About application"), abouttext);
}


void MainWindow::on_actionAbout_QT_triggered() {
  QMessageBox::aboutQt(this, tr("About Qt"));
}
