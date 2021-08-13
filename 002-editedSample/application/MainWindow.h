//
// Created by hakan on 12.08.2021.
//

#ifndef USBDONGLE_MAINWINDOW_H
#define USBDONGLE_MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;


private:
    Ui::MainWindow *ui;
};


#endif //USBDONGLE_MAINWINDOW_H
