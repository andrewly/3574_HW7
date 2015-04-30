#include "login.h"
#include "ui_login.h"

logIn::logIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logIn)
{
    ui->setupUi(this);
	
	thread = new QThread();
	worker = new LoginWork();
	
	gray->setColor(QPalette::ButtonText,Qt::gray);
	green->setColor(QPalette::ButtonText,Qt::green);
	
	worker ->moveToThread(thread);
}

logIn::~logIn()
{
    delete ui;
}

void logIn::on_username_cursorPositionChanged(int arg1, int arg2)
{
	if ( arg1 > 0)
	{
		connect -> setPalette(*gray);
	}
	else
	{
		connect -> setPalette(*green);
	}
}


void logIn::on_connect_clicked()
{
	//get and send text method
	worker.logInCheck(username->text());
}
