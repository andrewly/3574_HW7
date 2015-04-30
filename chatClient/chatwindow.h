#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QDialog>
#include <QString>
#include <QThread>

namespace Ui {
class chatWindow;
}

class chatWindow : public QDialog
{
    Q_OBJECT

public:
    explicit chatWindow(QString name, QWidget *parent = 0);
    ~chatWindow();
	setUserName(QString name);

private slots:
    void on_userChat_returnPressed();

    void on_pushButton_clicked();

private:
    Ui::chatWindow *ui;
	Qstring userName;
	
	QThread *thread;
	ChatWindow *chat;
};

#endif // CHATWINDOW_H
