#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "promotions.h"
#include <QMainWindow>
#include <QDate>
#include <QWidget>
#include <QDebug>
#include <QtWidgets>
#include <QString>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_Supp_Button_clicked();

    void on_ok_clicked();

    void on_Ajouter_Button_clicked();


private:
    Ui::MainWindow *ui;
    Promotions tmppromotions;
};
#endif // MAINWINDOW_H
