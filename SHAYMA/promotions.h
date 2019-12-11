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
    Promotions(int,int,int,int);
    int get_ref();
    int get_pourcentage();
    int get_jour();
    int get_duree();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool recherche(int);
    bool modifier(int,int,int,int);

private:
    int ref;
    int pourcentage;
    int jour;
    int duree;
};

#endif // PROMOTIONS_H
