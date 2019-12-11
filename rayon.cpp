#include "rayon.h"
#include <QDebug>
#include <QWidget>
#include <QDate>
#include <QDebug>
#include <QtWidgets>
#include <QString>

Rayon::Rayon(int num)
{
  this->num=num;
}

int Rayon::get_num(){return  num;}



bool Rayon::modifier_r(int num,QString adresse)
{
    QSqlQuery query;



       query.prepare("UPDATE Rayon SET Num=:num,ADRESSE=:adresse");
       query.bindValue(":NUM", num);
       query.bundValue(":ADRESSE",adresse);



    return query.exec();
}
QSqlQueryModel * client::tri()
{
QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from client order by ID asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Tel"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Idreserv"));
return model;
}


QSqlQueryModel *client::recherchernomclient(QString nomc)

{


QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CLIENT where NOM like '"+nomc+"' ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adress"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("Tel"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("Idreserv"));

return model;
}
