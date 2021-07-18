#include <QApplication>
#include <QPushButton>
#include "dialog.h"

#include "include/PublicUtil.h"

int main(int argc, char *argv[]) {
    TriangleV::PublicUtil temp;

    QApplication a(argc, argv);

    Dialog window;
    window.show();

    return QApplication::exec();
}
