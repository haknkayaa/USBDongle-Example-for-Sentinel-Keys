//
// Created by hakan on 12.08.2021.
//

#include <iostream>
#include <algorithm>
#include <sstream>
#include <stdio.h>

#include <string.h>

#include "thirdparty/license/hasp_api_cpp.h"
#include "thirdparty/vendor_code.h"
using namespace std;

#include "Core.h"

// Implementation
Core::Core(QObject *parent)
:  QObject(parent) {
    this->flag = false;
    this->parent = parent;
}

void Core::CoreStart(void) {
    // the thread affinity of timer is my thread
    this->timer = new QTimer();
    this->timer->setInterval(100000);
    QObject::connect(this->timer, SIGNAL(timeout()), this, SLOT(Timer_Tick()));

    while (!flag) {
        haspStatus status;

        Chasp hasp1(ChaspFeature::defaultFeature());
        status = hasp1.login(vendorCode);

        if (!HASP_SUCCEEDED(status)) {

            cout << "Başarısız" << endl;


            QMessageBox msgBox;
            msgBox.setWindowTitle("USB Dongle Key Not Found!");
            msgBox.setText("Try Again??");
            msgBox.setStandardButtons(QMessageBox::Yes);
            msgBox.addButton(QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);

            if(msgBox.exec() == QMessageBox::Yes){
                // do something
            }else {
               QApplication::quit();
               return;
            }

        } else {
            cout << "Başarılı" << endl;
            QApplication::processEvents();

        }
        QApplication::processEvents();
    }
}

void Core::TimerTick(void) {
    flag = true;
}