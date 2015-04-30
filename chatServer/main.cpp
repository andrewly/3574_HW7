#include <QCoreApplication>
#include "serverscreen.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
	ServerScreen s;
	s.show();
    return a.exec();
}
