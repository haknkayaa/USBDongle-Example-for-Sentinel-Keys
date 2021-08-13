#include <QApplication>

#include "MainWindow.h"
#include "Core.h"


int main(int argc, char **argv) {

    QApplication app(argc, argv);
    MainWindow window;


    QThread * thread = new QThread();
    Core * pCore = new Core(window.window());
    pCore->moveToThread(thread);
    QObject::connect(thread, SIGNAL(started()), pCore, SLOT(CoreStart()));
    thread->start();
    QApplication::processEvents();

    window.show();
    return app.exec();
}
