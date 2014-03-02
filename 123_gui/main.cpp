#include "mainwindow.h"
#include <QApplication>
#include <QtTest>
#include <QMessageBox>

class Main : public QObject
{
	Q_OBJECT

public:
	Main();

private Q_SLOTS:
	void initTestCase();
	void testCase1();
private:
	MainWindow *w;
	template <typename T>
	bool alala(T) { qDebug() << "fail"; return false; }

};

template <>
bool Main::alala<QMessageBox *>(QMessageBox *) { return true; }

template <>
bool Main::alala<QWidget *>(QWidget *) { return true; }

Main::Main()
{
}

void Main::initTestCase() {

}

void Main::testCase1()
{
	QVERIFY2(true, "Failure");
	w = new MainWindow();
	w->show();
	QTest::qWaitForWindowExposed(w);

	QWidget *w1 = w->findChild<QWidget *>("textEdit");
	QWidget *w2 = w->findChild<QWidget *>("textEdit_2");
	QVERIFY(w1 != 0 && w2 != 0);
	QTest::keyClicks(w1, "alalal");
	QTest::qWait(1000);
	QTest::keyClicks(w2, "123");
	QTest::qWait(1000);

	QWidget *w3 = w->findChild<QWidget *>("pushButton");

	QTest::mouseClick(w3, Qt::LeftButton);
	QWidgetList list = QApplication::topLevelWidgets();

	foreach (QWidget *el, list) {
		if (dynamic_cast<QMessageBox *>(el) != 0) {
			qDebug() << el->findChild<QWidget *>("qt_msgbox_buttonbox")->children();
		}
	}

//	QTest::qWaitForWindowExposed(w.findChild<QWidget *>("alala"));
	QTest::qWait(1000);
	//QTest::mouseClick(w, Qt::LeftButton);

	QTest::qWait(3000);
}

QTEST_MAIN(Main)

#include "main.moc"

//int main(int argc, char *argv[])
//{
//	QApplication a(argc, argv);
//	MainWindow w;
//	w.show();

//	return a.exec();
//}
