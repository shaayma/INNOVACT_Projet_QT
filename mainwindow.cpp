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



MainWindow::MainWindow (QWidget *parent) :
    QMainWindow(parent),
  ui (new Ui::MainWindow)
{
ui->setupUi(this);

ui->tabpromotions->setModel(tmppromotions.afficher());
QPixmap pix("C:/Users/dell/Desktop/Mes etudes/2A/Projet C++/image");
ui->label_pic->setPixmap(pix.scaled(1540,900,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Ajouter_Button_clicked()
{
    int ref = ui->lineEdit_reference->text().toInt();
    int pourcentage= ui->lineEdit_pourcentage->text().toInt();
    QString jour=ui->lineEdit_debut->text();
    QString duree=ui->lineEdit_fin->text();

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
    QString jour=ui->lineEdit_debut->text();
    QString duree=ui->lineEdit_fin->text();

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



void MainWindow::on_lineEdit_supp_2_textChanged(const QString &text)
{
    Promotions p;
    ui->tabpromotions->setModel(p.rechercheAvancee(text));
}


void MainWindow::on_pushButton_clicked()
{
    ui->tabpromotions->setModel(tmppromotions.tri());
}



void MainWindow::on_Modifier_clicked()
{
    int n=ui->Modif_ref->text().toInt();
    int s=ui->modif_pour->text().toInt();
    QDate dP = ui->modif_debut->date();
    QString d=dP.toString();
    QDate dPr = ui->modif_fin->date();
    QString dr=dPr.toString();
   /* QString d="1/1/2000";*/
     Promotions P(n,s,d,dr);
     bool test=tmppromotions.modifier(P);
     if(test==true)
   {
         ui->tabpromotions->setModel(tmppromotions.afficher());//refresh
   QMessageBox::information(nullptr, QObject::tr("modifierr une promotion"),
                     QObject::tr("promotion modifiée.\n"

                                 "Click Cancel to exit."), QMessageBox::Cancel);

   }
     else
         QMessageBox::critical(nullptr, QObject::tr("modifier une promotion"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

}
