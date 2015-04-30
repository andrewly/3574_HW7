#include "serverscreen.h"
#include "ui_serverscreen.h"

ServerScreen::ServerScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::serverScreen)
{
    ui->setupUi(this);
	
	thread = new QThread();
	worker = new ServerWorks();
	worker ->movetothread(thread);
	
}

ServerScreen::~ServerScreen()
{
    delete ui;
}
