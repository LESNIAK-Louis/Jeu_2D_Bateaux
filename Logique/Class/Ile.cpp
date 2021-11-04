/**
* @file Ile.cpp
* @author Louis Lesniak & Hugues Steiner
* @date 04/11/2021
* Definition des fonctions propres aux iles
*/

#include "Ile.hpp"

//Constructeur
Ile::Ile(int abs, int ord, int t, int f)
{
    this->setCentre(new Point(abs, ord));
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
    if(centre == NULL) perror("centre NULL en param | setCentre - Ile");
    return this->centre = centre;
}

void Ile::setTaille(int taille)
{
    if(taille < 0) perror("taille < 0 | setTaille - Ile");
    return this->taille = taille;
}

void Ile::setForme(int forme)
{
    if(forme < 0) perror"forme < 0 | setForme - Ile";
    return this->forme = forme;
}

std::string Ile::toString()
{
    return "<" + std::to_string(this->getAbscisse()) + ", " + std::to_string(this->getOrdonnee()) + "> Taille = " + std::to_string(this->getTaille()) + "\n";
}