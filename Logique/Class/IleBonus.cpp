/** 
* @file IleBonus.cpp
* @author Louis Lesniak & Hugues Steiner
* @date 04/11/2021
* Definition des fonctions propres aux iles
*/

#include "IleBonus.hpp"

//Constructeur
IleBonus::IleBonus(int abs, int ord, int t, int f)
{
    this->setCentre(new Point(abs, ord));
    this->setTaille(t);
    this->setForme(f);
}

IleBonus::~IleBonus()
{   
    delete[] this->centre;
    delete[] this->defenseur;
}

Point* IleBonus::getCentre()
{
    return this->centre;
}

int IleBonus::getTaille()
{
    return this->taille;
}

int IleBonus::getForme()
{
    return this->forme;
}

int IleBonus::getRayonCapture()
{
    return this->rayonCapture;
}

int IleBonus::getNbDefenseur()
{
    return this->nbDefenseur;
}

Patrouilleur[] getDefenseur(int index)
{
    if(index < 0 || index >= this->getNbDefenseur()) perror("index out of range | getDefenseur - IleBonus");
    return this->defenseur[index];
}


int IleBonus::getControle()
{
    return this->controle;
}

int IleBonus::getBonusType()
{
    return this->bonusType;
}

int IleBonus::getBonusGain()
{
    return this->bonusGain;
}

int IleBonus::getTempsDebut()
{
    return this->tempsDebut;
}

void IleBonus::setCentre(Point* centre)
{
    if(centre == NULL) perror("centre NULL en param | setCentre - IleBonus");
    return this->centre = centre;
}

void IleBonus::setTaille(int taille)
{
    if(taille < 0) perror("taille < 0 | setTaille - IleBonus");
    return this->taille = taille;
}

void IleBonus::setForme(int forme)
{
    if(forme < 0) perror("forme < 0 | setForme - IleBonus");
    return this->forme = forme;
}

void IleBonus::setRayonCapture(int rayonCapture)
{
    if(rayonCapture < 0) perror("rayonCapture < 0 | setRayonCapture - IleBonus");
    return this->rayonCapture = rayonCapture;
}

void IleBonus::setNbDefenseur(int nbDefenseur)
{
    if(nbDefenseur < 0) perror("nbDefenseur < 0 | setNbDefenseur - IleBonus");
    return this->nbDefenseur = nbDefenseur;
}

void IleBonus::setControle(int controle)
{
    if(controle < 0) perror("controle < 0 | setControle - IleBonus");
    return this->controle = controle;
}

void IleBonus::setBonusType(int bonusType)
{
    if(bonusType < 0) perror("bonusType < 0 | setBonusType - IleBonus");
    return this->bonusType = bonusType;
}

void IleBonus::setBonusGain(int bonusGain)
{
    if(bonusGain < 0) perror("bonusGain < 0 | setBonusGain - IleBonus");
    return this->bonusGain = bonusGain;
}

void IleBonus::setTempsDebut(int tempsDebut)
{
    if(tempsDebut < 0) perror("tempsDebut < 0 | setTempsDebut - IleBonus");
    return this->tempsDebut = tempsDebut;
}

int IleBonus::toString()
{
    return "Centre : " + "<" + std::to_string(this->getCentre()->getAbscisse()) + ", " + std::to_string(this->getCentre()->getOrdonnee()) + ">" + "\n"
    + "Taille : " + std::to_string(this->getTaille()) + "\n"
    + "Forme : " + std::to_string(this->getForme()) + "\n"
    + "RayonCapture : " + std::to_string(this->getRayonCapture()) + "\n"
    + "Nombre de defenseurs" + std::to_string(this->getNbDefenseur()) + "\n"
    + "Controle : " + std::to_string(this->getControle()) + "\n"
    + "Type du bonus : " + std::to_string(this->getBonusType()) + "\n"
    + "Gain bonus : " + std::to_string(this->getBonusGain()) + "\n"
    + "Temps debut capture : " + std::to_string(this->getTempsDebut());
}