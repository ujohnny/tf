#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QWidget;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	void showWidget(QWidget *w);


private slots:

	void on_textEdit_textChanged();

	void on_pushButton_clicked();

private:
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
