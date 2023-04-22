
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFile>

using namespace std;

//Global var
QString str;
//----------

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile data("data.txt");
    data.open(QIODeviceBase::ReadWrite);
    QTextStream stream(&data);
    ::str=stream.readAll();
    data.close();

    ui->textEdit->setPlainText(str);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString input = ui->infobox->text();
    string input_str = input.toStdString();
    string file = str.toStdString();

    int count = 0;

    if(!input.isEmpty())
    {
        for(int i = 0; i < str.toStdString().length(); i++)
        {
            if(file.substr(i, input_str.length()) == input_str)
                count++;
        }

        if(count)
        {
            ui->result->setText(input + " apperars in text " + QString("%1").arg(count) + " times");
        }
        else
            ui->result->setText("No such text found");
    }
    else
        ui->result->setText("Input is empty");
}

