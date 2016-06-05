#include "formamicroondas.h"
#include <QApplication>
#include <iostream>
#include <QTime>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FormaMicroondas w;
    w.show();

    QTime time = QTime::currentTime();

    return a.exec();
}
