#ifndef PROMOTIONS_H
#define PROMOTIONS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QWidget>
#include <QDebug>
#include <QDate>
#include <QtWidgets>


class Promotions
{
public:

    Promotions();
    Promotions(int,int,QString,QString);
    int get_ref();
    int get_pourcentage();
    QString get_jour();
    QString get_duree();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool rechercher(int);
    QSqlQueryModel*rechercheAvancee(QString text);
    bool modifier(Promotions);
    QSqlQueryModel *tri();

private:
    int ref;
    int pourcentage;
    QString jour;
    QString duree;
};

#endif // PROMOTIONS_H
