/**
* \file Ile.cpp
* \brief Definition des fonctions propres aux iles
* \author Louis Lesniak & Hugues Steiner
* \date 10 Nov. 2021
*/

#include "Ile.hpp"

//Constructeur
Ile::Ile(Point* centre, int t, int f)
{
    if(centre == NULL) error("centre NULL en param | Constructeur - Ile");
    this->setCentre(centre);
    this->setTaille(t);
    this->setForme(f);
}

Ile::~Ile()
{
    delete[] this->centre;
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

void Ile::setCentre(Point* centre)
{
    if(centre == NULL) error("centre NULL en param | setCentre - Ile");
    if(this->centre != NULL) delete[] this->centre;
    this->centre = centre;
}

void Ile::setTaille(int taille)
{
    if(taille < 0) error("taille < 0 | setTaille - Ile");
    this->taille = taille;
}

void Ile::setForme(int forme)
{
    if(forme < 0) error("forme < 0 | setForme - Ile");
    this->forme = forme;
}

std::string Ile::toString()
{
    return "<" + std::to_string(this->getCentre()->getAbscisse()) + ", " + std::to_string(this->getCentre()->getOrdonnee()) + ">" + "\n" + "Taille = " + std::to_string(this->getTaille()) + "\n";
}