#include "chatwindow.h"
#include "ui_chatwindow.h"

chatWindow::chatWindow(QString name, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chatWindow)
{
    ui->setupUi(this);
	
	thread = new QThread();
	chat = new ChatWorks(name);
	chat->moveToThread(thread);
	userChat.addItem("General Chat");
}

chatWindow::~chatWindow()
{
    delete ui;
}

void chatWindow::on_userChat_returnPressed()
{
	QString message = userChat->text();
	QString target = combobox->itemData(combobox->currentIndex());
	sendMessage(message, target);
}

void chatWindow::on_pushButton_clicked()
{
	exitChat();
	~chatWindow();
	this -> end();
}
