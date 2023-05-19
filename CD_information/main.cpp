#include "cd_information.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CD_Information CD;
    CD.show();
    return a.exec();
}
