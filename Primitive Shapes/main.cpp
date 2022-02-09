#include <QApplication>
#include <ctime>
#include "myglwidget.h"

int main(int argc, char *argv[])
{
    // Standard QT main structure

    QApplication app(argc, argv);
    MyGLWidget glWidget;
    glWidget.show();
    return app.exec();
}
