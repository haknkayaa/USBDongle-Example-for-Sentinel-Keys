//
// Created by hakan on 12.08.2021.
//

#ifndef USBDONGLE_CORE_H
#define USBDONGLE_CORE_H

#include <QtWidgets>

class Core : public QObject {
Q_OBJECT

private:
    QTimer *timer;
    volatile bool flag;
    QObject *parent;
public:
    Core(QObject *parent = 0);


private:
    void run(void);

public
    slots:

    void CoreStart();

private
    slots:

    void TimerTick(void);
};


#endif //USBDONGLE_CORE_H
