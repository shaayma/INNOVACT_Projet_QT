#ifndef RAYON_H
#define RAYON_H
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QSqlQueryModel>

class RayonData;

class Rayon
{
public:
    Rayon();
    Rayon(int,QString);

    int get_num();
    QString get_adresse();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool recherche(int);
    bool modifier_r(int,QString);

private:
    int num;
    QString adresse;
};

#endif // RAYON_H
