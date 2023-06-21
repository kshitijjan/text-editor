#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QFile>
#include<QFileDialog>
#include<QTextStream>
#include<QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include<QProcess>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
    isBold = false;
    isSuperscript = false;
    isSubscript = false;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    file_path = "";
    ui->textEdit->setText("");
}


void MainWindow::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Open the File");
    QFile file(file_name);
    file_path = file_name;
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"..","file not open");
        return ;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}


void MainWindow::on_actionSave_triggered()
{
    QFile file(file_path);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"..","file not open");
        return ;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}


void MainWindow::on_actionSave_as_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this,"Open the File");
    QFile file(file_name);
    file_path = file_name;
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"..","file not open");
        return ;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionBold_triggered()
{
    QFont font = ui->textEdit->currentFont();
    font.setBold(!isBold);
    ui->textEdit->setCurrentFont(font);
    isBold = !isBold;
}



void MainWindow::on_actionSuperscript_triggered()
{
    QTextCharFormat format;
    format.setVerticalAlignment(QTextCharFormat::AlignSuperScript);
    format.setFontPointSize(ui->textEdit->currentFont().pointSize());
    ui->textEdit->mergeCurrentCharFormat(format);

    isSuperscript = !isSuperscript;
    isSubscript = false;
}


void MainWindow::on_actionSubscript_triggered()
{
    QTextCharFormat format;
    format.setVerticalAlignment(QTextCharFormat::AlignSubScript);
    format.setFontPointSize(ui->textEdit->currentFont().pointSize());
    ui->textEdit->mergeCurrentCharFormat(format);

    isSubscript = !isSubscript;
    isSuperscript = false;
}


void MainWindow::on_actionAbout_Me_triggered()
{
    QString filePath = ":/pdf/resources/kshitij-resume-updated.txt";
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        QString fileContent = stream.readAll();

        ui->textEdit->setPlainText(fileContent);

        file.close();
    } else {
        QMessageBox::warning(this, "Error", "Failed to open the text file.");
    }
}

