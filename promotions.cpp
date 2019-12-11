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

Promotions::Promotions(int ref, int pourcentage, QString jour, QString duree)
{
  this->ref=ref;
  this->pourcentage=pourcentage;
  this->jour=jour;
  this->duree=duree;
}

int Promotions::get_ref(){return  ref;}
int Promotions::get_pourcentage(){return  pourcentage;}
QString Promotions::get_jour(){return  jour;}
QString Promotions::get_duree(){return duree;}



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

bool Promotions::rechercher(int ref)
{
    QSqlQuery query;
    QString res=QString::number(ref);
    query.prepare("select * from TABPROMOTIONS where REF = :ref");
    query.bindValue(":ref", res);
    query.exec();
    int i=0;//resultat
    while(query.next())//parcourir le resultat de la requete
        i++;
    if (i>0)
        return true;
    return false;
}


bool Promotions::modifier(Promotions p)
{
QSqlQuery query;

query.prepare("update TABPROMOTIONS set ref=:ref,pourcentage=:pourcentage,jour=:jour,duree=:duree where ref =:ref");
query.bindValue(":ref", ref);
query.bindValue(":pourcentage", pourcentage);
query.bindValue(":jour",jour);
query.bindValue(":duree",duree);
return  query.exec();
}

QSqlQueryModel *Promotions::rechercheAvancee(QString text)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from TABPROMOTIONS where ref like '%"+text+"%'"+"  ORDER BY ref");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Ref"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Pourcentage"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Jour"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Duree"));
    return model;
}


QSqlQueryModel *Promotions::tri()
{

    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select *from TABPROMOTIONS ORDER BY ref");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Ref"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Pourcentage"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Jour"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Duree"));
    return model;

}
