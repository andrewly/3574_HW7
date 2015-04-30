#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QtGui>
#include <QThread>
#include "loginWork.h"

namespace Ui {
class logIn;
}

class logIn : public QDialog
{
    Q_OBJECT

public:
    explicit logIn(QWidget *parent = 0);
    ~logIn();

private slots:
    void on_username_cursorPositionChanged(int arg1, int arg2);

    void on_connect_clicked();

private:
    Ui::logIn *ui;
	
	QPalette* gray = new QPalette();
	QPalette* green = new QPalette();
	
	QThread *thread;
	LoginWork worker;

	
};

#endif // LOGIN_H
