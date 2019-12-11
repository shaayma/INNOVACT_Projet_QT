#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "promotions.h"
#include "connexion.h"
#include <QMessageBox>
#include <QtWidgets>
#include <QDate>
#include <QString>
#include <QDateTime>
#include <QDebug>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tabpromotions->setModel(tmppromotions.afficher());

}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Ajouter_Button_clicked()
{
    int ref = ui->lineEdit_reference->text().toInt();
    int pourcentage= ui->lineEdit_pourcentage->text().toInt();
    int jour=ui->lineEdit_debut->text().toInt();
    int duree=ui->lineEdit_fin->text().toInt();

  Promotions P(ref,pourcentage,jour,duree);

  bool test=P.ajouter();
    if(test)
    {
      ui->tabpromotions->setModel(tmppromotions.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Ajouter une promotion"),
                  QObject::tr("Promotion ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une promotion"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}



void MainWindow::on_Supp_Button_clicked()
{
int ref = ui->lineEdit_supp->text().toInt();
bool test=tmppromotions.supprimer(ref);

    if(test)
    {
    ui->tabpromotions->setModel(tmppromotions.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer une promotion"),
                QObject::tr("promotion supprimée.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une promotion"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_ok_clicked()
{
    int ref=ui->lineEdit_reference->text().toInt();
    int pourcentage=ui->lineEdit_pourcentage->text().toInt();
    int jour=ui->lineEdit_debut->text().toInt();
    int duree=ui->lineEdit_fin->text().toInt();

    Promotions p(ref,pourcentage,jour,duree);

   bool test= p.ajouter();
   if(test)
     {
     QMessageBox::information(nullptr, QObject::tr("Ajouter une promotion"),
                       QObject::tr("Promotion ajoutée.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

     }
       else
           QMessageBox::critical(nullptr, QObject::tr("Ajouter une promotion"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

   ui->lineEdit_reference->clear();
   ui->lineEdit_pourcentage->clear();
   ui->lineEdit_debut->clear();
}


