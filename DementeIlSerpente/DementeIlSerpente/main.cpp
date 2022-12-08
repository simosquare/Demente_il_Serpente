#include "dementeilserpente.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DementeIlSerpente window;
    window.setWindowTitle("DementeIlSerpente");
    window.show();

    return a.exec();
}
