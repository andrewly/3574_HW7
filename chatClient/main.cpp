#include <QCoreApplication>
#include "login.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
	
	login l;
	l.show();
	
    return a.exec();
}
