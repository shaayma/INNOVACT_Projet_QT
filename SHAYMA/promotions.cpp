#include "promotions.h"
#include <QDebug>
#include <QWidget>
#include <QDate>
#include <QDebug>
#include <QtWidgets>
#include <QString>

Promotions::Promotions()
{
    ref=0;
    pourcentage=0;
}

Promotions::Promotions(int ref, int pourcentage, int jour, int duree)
{
  this->ref=ref;
  this->pourcentage=pourcentage;
  this->jour=jour;
  this->duree=duree;
}

int Promotions::get_ref(){return  ref;}
int Promotions::get_pourcentage(){return  pourcentage;}
int Promotions::get_jour(){return  jour;}
int Promotions::get_duree(){return duree;}



bool Promotions::ajouter()
{
QSqlQuery query;


    QString res1=QString::number(ref);
    QString res2=QString::number(pourcentage);

query.prepare("INSERT INTO TABPROMOTIONS (REF, POURCENTAGE, JOUR, DUREE) "
                    "VALUES (:ref, :pourcentage, :jour, :duree)");
query.bindValue(":ref", res1);
query.bindValue(":pourcentage", res2);
query.bindValue(":jour",jour);
query.bindValue(":duree",duree);



return    query.exec();
}



QSqlQueryModel * Promotions::afficher()
{
  QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from TABPROMOTIONS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Ref"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Pourcentage"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Jour"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Duree"));

    return model;
}

bool Promotions::supprimer(int ref)
{
QSqlQuery query;
QString res= QString::number(ref);
query.prepare("Delete from TABPROMOTIONS where REF = :ref ");
query.bindValue(":ref", ref);
return    query.exec();
}


bool Promotions::recherche(int ref)
{

    QSqlQuery query;
    QString res=QString::number(ref);
    query.prepare("select * from offre where ref = :ref");
    query.bindValue(":ref", res);
    query.exec();
    return query.first();
}


bool Promotions::modifier(int ref, int pourcentage, int jour,int duree)
{
QSqlQuery query;
/*QString res= QString::number(ref);*/
/*QString res2= QString::number(pourcentage);*/
query.prepare("update promotion set ref=:ref,pourcentage=:pourcentage,jour=:jour,duree=:duree where ref =:ref");
query.bindValue(":ref", ref);
query.bindValue(":pourcentage", pourcentage);
query.bindValue(":jour",jour);
query.bindValue(":duree",duree);
return  query.exec();
}
