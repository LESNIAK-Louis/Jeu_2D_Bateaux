/**file Ile.cpp
*@author Louis Lesniak & Hugues Steiner
*date 14/09/2021
*Definition des fonctions propres aux iles
*/

#include "Ile.hpp"

//Constructeur
Ile::Ile(int abs, int ord, int t, int f)
{
    this->centre = new Point(abs, ord);
    this->taille = t;
    this->forme = f;
}


//Getteur
Point* Ile::getCentre()
{
    return this->centre;
}

int Ile::getTaille()
{
    return this->taille;
}

int Ile::getForme()
{
    return this->forme;
}

int Ile::getAbscisse() {
    return this->getCentre()->getAbscisse();
}

int Ile::getOrdonnee() {
    return this->getCentre()->getOrdonnee();
}

std::string Ile::toString()
{
    return "<" + std::to_string(this->getAbscisse()) + ", " + std::to_string(this->getOrdonnee()) + "> Taille = " + std::to_string(this->getTaille()) + "\n";
}