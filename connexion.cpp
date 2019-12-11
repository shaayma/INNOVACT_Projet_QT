#include "connexion.h"
#include <QSqlError>
#include <QString>

Connexion::Connexion(){
                      }
bool Connexion::ouvrirConnexion()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
                           db.setDatabaseName("Source_Projet2A");
                           db.setUserName("shayma");//inserer nom de l'utilisateur
                           db.setPassword("1234");//inserer mot de passe de cet utilisateur

if (db.open())
    test=true;

else throw QString ("Erreur Paramétres"+db.lastError().text());
return  test;
}
void Connexion::fermerConnexion()
{db.close();}
