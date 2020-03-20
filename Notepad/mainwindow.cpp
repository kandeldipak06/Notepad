#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //set the text edit area to fill the screen
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionnew_triggered()
{
    //clear the current file
    currentFile.clear();

    //clear the text edit section in widget
    ui->textEdit->setText(QString("Start here"));


}

void MainWindow::on_actionopen_triggered()
{
     //openUp a dialogue box
    QString filename = QFileDialog::getOpenFileName(this, "Open A File");
    //create a file with the above filename
    QFile file(filename);
    currentFile = filename;

    //open file and check for errors

    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot open File:" + file.errorString());
        return;
    }
    //set window title to file currently working with
    setWindowTitle(filename);

    //create a interface for reading text
    QTextStream in(&file);
    //copy all the text from file to in
    QString text = in.readAll();
    //now put all the text in widget screen
    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::on_actionsave_triggered()
{
    //open dialogue box for saving and get the name of file to be saved with
    QString filename = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(filename);

    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot save File:" + file.errorString());
        return;
    }

    currentFile = filename;
    setWindowTitle(filename);

    //create a insterface for writing in file
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}

void MainWindow::on_actionprint_triggered()
{
    //object to interact with printers in the network
    QPrinter printer;
    //set the printer a name
    printer.setPrinterName("Printer Name");
    //dialogue to print to the user so they choose from the list of printer
    QPrintDialog pDialog(&printer, this);
    //verify the connection with the printer
    if(pDialog.exec() == QDialog::Rejected){
        QMessageBox::warning(this, "Warning", "Cannot Access Printer");
        return;
    }
    ui->textEdit->print(&printer);


}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
   ui->textEdit->paste();
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionUndo_triggered()
{
   ui->textEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}
