#include "suduku.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    suduku w;
    w.show();
    return a.exec();
}
