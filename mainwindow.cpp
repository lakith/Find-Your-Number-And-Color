#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include<iostream>
#include<string.h>
#include<QDebug>
#include <QRegExpValidator>
#include <QMessageBox>
#include<QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Lucky Number");

    QRegExp rx( "^(0[1-9]|1[012])[-/.](0[1-9]|[12][0-9]|3[01])[-/.](19|20)\\d\\d$");
    QValidator *validator = new QRegExpValidator(rx, this);
    ui->lineEdit->setValidator(validator);

    ui->lineEdit->setPlaceholderText("mm/dd/yyyy");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString birtday = ui->lineEdit->text();
    QByteArray ba;
    int len = birtday.length();

    if(len==0){
        QMessageBox *msgBox2 = new QMessageBox(this);
        msgBox2->setText("Please Enter Your Birthday");
        msgBox2->exec();
    }
    else {
    char *charArray;
    ba = birtday.toLatin1();
    charArray = ba.data();
    int a = charArray[0];
    int b = charArray[1];
    int c = charArray[3];
    qDebug()<< "debug data"<<a-48;
    qDebug()<< "debug data"<<b-48;
    int lucky=0;

    for(int i = 0; i<len ;i++){

        if(i==2||i==5){
            continue;
        }

        int num = 0;
        num += charArray[i];
        lucky += (num-48);
    }
    QString number = QString::number(lucky);
    QString message = "Your Lucky Number is "+number;
    QMessageBox *msgBox = new QMessageBox(this);
    msgBox->setText(message);
    msgBox->exec();

    qDebug() << lucky;
    }
}
