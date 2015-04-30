#ifndef SERVERSCREEN_H
#define SERVERSCREEN_H

#include <QDialog>
#include "serverWorks.h"

namespace Ui {
class ServerScreen;
}

class ServerScreen : public QDialog
{
    Q_OBJECT

public:
    explicit ServerScreen(QWidget *parent = 0);
    ~ServerScreen();

private:
    Ui::ServerScreen *ui;
	
	QThread *thread;
	ServerWorks worker;
};

#endif // SERVERSCREEN_H
