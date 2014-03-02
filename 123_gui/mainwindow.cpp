#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QTextEdit>
MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::showWidget(QWidget *w) {
	w->show();
}

void MainWindow::on_textEdit_textChanged()
{
	qDebug() << "dsgf";
}

void MainWindow::on_pushButton_clicked()
{
	QMessageBox msgBox(this);
	msgBox.setModal( true );
	msgBox.setText("Message");
	msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
	msgBox.exec();
	//QMessageBox::information(this, "akak", "akak");
	//qDebug() << QApplication::topLevelWidgets();
}
