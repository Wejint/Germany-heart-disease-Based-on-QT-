#include "mainsecene.h"
#include <QApplication>
#include<brand.h>
#include<fruitbrand.h>
//加载图片


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainSecene w;
    QApplication::setAttribute(Qt::AA_Use96Dpi);
    qputenv("QT_SCALE_FACTOR",QString::number(1.0).toLatin1());
    w.show();

    return a.exec();
}
