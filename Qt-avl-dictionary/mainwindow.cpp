#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QPixmap>
#include <QTextStream>
#include <QPalette>
#include <QSize>
AVL<QString> tree;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString word;
        QFile file("C:\\Users\\Dawid\\Documents\\Qt-avl-dictionary\\dictionary.txt");
        if (!file.open(QFile::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this,"Warning","File not open");
        }
        QTextStream in(&file);

        while (in.atEnd()) {
            tree.insert(word);

        }
}
MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_clicked()
{
    QString searchingWord = ui->lineEdit->text();
    if(searchingWord.isEmpty()){
            QMessageBox::warning(this,"UWAGA!!!","Musisz wpisać słowo do wyszukania");

        }
    if(tree.exists(searchingWord) && !searchingWord.isEmpty()){
            ui->label->setText("Podane słowo istnieje w słowniku");

        }else if(!tree.exists(searchingWord)){
            ui->label->setText("Podane słowo nie istnieje w słowniku");
        }

}
