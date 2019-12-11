#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include "connexion.h"
#include <QMessageBox>
#include "promotions.h"
#include <QString>


int main(int argc, char *argv[])
{  QApplication a(argc, argv);

    Connexion c;

  bool test=c.ouvrirConnexion();
  MainWindow w;
  if(test)
  {w.show();

      QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                  QObject::tr("connection avec succés.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

  }
  else
      QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                  QObject::tr("connection failed.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

    return a.exec();}
