/** 
* \file IleBonus.cpp
* \brief Definition des fonctions propres aux iles bonus
* \author Louis Lesniak & Hugues Steiner
* \date 10 Nov. 2021
*/

#include "IleBonus.hpp"

//Constructeur
IleBonus::IleBonus(Point* centre, int taille, int forme, int rayonCapture, int controle, int bonusType, int bonusGain)
{
    if(centre == NULL) error("centre NULL en param | Constructeur - Ile");
    this->setCentre(centre);
    this->setTaille(taille);
    this->setForme(forme);
    this->setRayonCapture(rayonCapture);
    this->setControle(controle);
    this->setBonusType(bonusType);
    this->setBonusGain(bonusGain);
    this->tempsDebut = 0;
}

IleBonus::~IleBonus()
{   
    delete this->centre;
    this->removeAllDefenseurs();
    this->defenseurs;
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
    return this->defenseurs.size();
}

Patrouilleur* IleBonus::getDefenseur(int index)
{
    if(index < 0 || index >= this->getNbDefenseur()) error("index out of range | getDefenseur - IleBonus");
    return this->defenseurs[index];
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
    if(centre == NULL) error("centre NULL en param | setCentre - IleBonus");
    if(this->centre != NULL) delete this->centre;
    this->centre = centre;
}

void IleBonus::setTaille(int taille)
{
    if(taille < 0) error("taille < 0 | setTaille - IleBonus");
    this->taille = taille;
}

void IleBonus::setForme(int forme)
{
    if(forme < 0) error("forme < 0 | setForme - IleBonus");
    this->forme = forme;
}

void IleBonus::setRayonCapture(int rayonCapture)
{
    if(rayonCapture < 0) error("rayonCapture < 0 | setRayonCapture - IleBonus");
    this->rayonCapture = rayonCapture;
}

void IleBonus::setControle(int controle)
{
    if(controle < 0) error("controle < 0 | setControle - IleBonus");
    this->controle = controle;
}

void IleBonus::setBonusType(int bonusType)
{
    if(bonusType < 0) error("bonusType < 0 | setBonusType - IleBonus");
    this->bonusType = bonusType;
}

void IleBonus::setBonusGain(int bonusGain)
{
    if(bonusGain < 0) error("bonusGain < 0 | setBonusGain - IleBonus");
    this->bonusGain = bonusGain;
}

void IleBonus::setTempsDebut(int tempsDebut)
{
    if(tempsDebut < 0) error("tempsDebut < 0 | setTempsDebut - IleBonus");
    this->tempsDebut = tempsDebut;
}

void IleBonus::addDefenseur(Patrouilleur* defenseur)
{
    if(defenseur == NULL) error("defenseur NULL en param | addDefenseur - IleBonus");
    this->defenseurs.push_back(defenseur);
}

void IleBonus::removeDefenseur(int index)
{
    if(index < 0 || index >= this->getNbDefenseur()) error("index out of range | removeDefenseur - IleBonus");
    if(this->defenseurs[index] != NULL) delete this->defenseurs[index];
    this->defenseurs.erase(this->defenseurs.begin() + index);
}

void IleBonus::replaceDefenseur(int index, Patrouilleur* defenseur)
{
    if(defenseur == NULL) error("defenseur NULL en param | replaceDefenseur - IleBonus");
    if(index < 0 || index >= this->getNbDefenseur()) error("index out of range | replaceDefenseur - IleBonus");
    if(this->defenseurs[index] != NULL) delete this->defenseurs[index];
    this->defenseurs[index] = defenseur;
}

void IleBonus::removeAllDefenseurs()
{
    while(this->getNbDefenseur() != 0)
    {
        delete[] this->defenseurs.back();
        this->defenseurs.pop_back();
    }
}

std::string IleBonus::toString()
{
    return "Centre : <" + std::to_string(this->getCentre()->getAbscisse()) + ", " + std::to_string(this->getCentre()->getOrdonnee()) + ">\n"
    + "Taille : " + std::to_string(this->getTaille()) + "\n"
    + "Forme : " + std::to_string(this->getForme()) + "\n"
    + "RayonCapture : " + std::to_string(this->getRayonCapture()) + "\n"
    + "Nombre de defenseurs" + std::to_string(this->getNbDefenseur()) + "\n"
    + "Controle : " + std::to_string(this->getControle()) + "\n"
    + "Type du bonus : " + std::to_string(this->getBonusType()) + "\n"
    + "Gain bonus : " + std::to_string(this->getBonusGain()) + "\n"
    + "Temps debut capture : " + std::to_string(this->getTempsDebut());
}