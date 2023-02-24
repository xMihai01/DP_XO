#include "DP_XO.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    DP_XO w;
    w.show();
    return a.exec();
}
