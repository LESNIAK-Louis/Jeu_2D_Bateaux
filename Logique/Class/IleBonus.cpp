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
    this->centre = centre;
    this->setTaille(taille);
    this->setForme(forme);
    this->setRayonCapture(rayonCapture);
    this->setControle(controle);
    this->setBonusType(bonusType);
    this->setBonusGain(bonusGain);
    this->defenseurs = new std::vector<Navire*>();
}

IleBonus::~IleBonus()
{   
    if(this->centre != NULL)
        delete this->centre;
    this->removeAllDefenseurs();
    if(this->defenseurs != NULL)
        delete this->defenseurs;
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
    return this->defenseurs->size();
}

Navire* IleBonus::getDefenseur(int index)
{
    if(index < 0 || index >= this->getNbDefenseur()) error("index out of range | getDefenseur - IleBonus");
    return this->defenseurs->at(index);
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

void IleBonus::addDefenseur(Navire* defenseur)
{
    if(defenseur == NULL) error("defenseur NULL en param | addDefenseur - IleBonus");
    this->defenseurs->push_back(defenseur);
}

void IleBonus::placerDefenseur()
{
    if(this->getNbDefenseur() != 0)
    {
        double angleIntervalle = PI*2 / this->getNbDefenseur();
        int rayon = this->getTaille()/2 + this->getRayonCapture()/2;
        
        for(int i = 0; i < this->getNbDefenseur(); i++)
        {
            double x = this->getCentre()->getAbscisse() + rayon*cos((angleIntervalle*i));
            double y = this->getCentre()->getOrdonnee() + rayon*sin((angleIntervalle*i));
            this->getDefenseur(i)->setCentre(new Point((int)x,(int)y));
            this->getDefenseur(i)->setAngle(this->getDefenseur(i)->getCentre()->trouverAngle(this->getCentre())+90);
        }
    }
}

void IleBonus::removeDefenseur(Navire* defenseur)
{
    if(defenseur == NULL) error("defenseur NULL en param| removeDefenseur - IleBonus");
    int index = 0;
    for(int i = 0; i < this->getNbDefenseur(); i++)
    {
        if (defenseur == this->getDefenseur(i))
        {
            index = i;
            break;
        }
    }
    if(this->defenseurs->at(index) != defenseur) error("defenseur a supprimer non trouve | removeDefenseur - IleBonus");
    if(this->defenseurs->at(index) != NULL) delete this->defenseurs->at(index);
    this->defenseurs->erase(this->defenseurs->begin() + index);
}

void IleBonus::replaceDefenseur(int index, Navire* defenseur)
{
    if(defenseur == NULL) error("defenseur NULL en param | replaceDefenseur - IleBonus");
    if(index < 0 || index >= this->getNbDefenseur()) error("index out of range | replaceDefenseur - IleBonus");
    if(this->defenseurs->at(index) != NULL) delete this->defenseurs->at(index);
    this->defenseurs->at(index) = defenseur;
}

void IleBonus::removeAllDefenseurs()
{
    while(this->getNbDefenseur() != 0)
    {
        Navire* nav = this->defenseurs->back();
        if(nav != NULL)
            delete this->defenseurs->back();
        this->defenseurs->pop_back();
    }
}

std::string IleBonus::formattedInfo()
{
     std::string info;
    info = "B{" + this->getCentre()->formattedInfo() + ";"
    + std::to_string(this->getTaille()) + ";"
    + std::to_string(this->getForme()) + ";"
    + std::to_string(this->getRayonCapture()) + ";"
    + std::to_string(this->getControle()) + ";"
    + std::to_string(this->getBonusType()) + ";"
    + std::to_string(this->getBonusGain()) + ";";

    std::string patrouilleur = "";
    std::string croiseur = "";
    int nbPatrouilleur = 0;
    int nbCroiseur = 0;
    for(int i = 0; i < this->getNbDefenseur(); i++)
    {
        if(this->getDefenseur(i)->getType() == "Patrouilleur")
        {
            nbPatrouilleur++;
            patrouilleur += this->getDefenseur(i)->formattedInfo() + ";";
        }
        else if (this->getDefenseur(i)->getType() == "Croiseur")
        {
            nbCroiseur++;
            croiseur += this->getDefenseur(i)->formattedInfo() + ";";
        }
    }

    info += std::to_string(nbPatrouilleur) + ";"
    + std::to_string(nbCroiseur);
    if(nbPatrouilleur > 0)
        info += ";[" + patrouilleur.substr(0, patrouilleur.length()-2) + "]";
    if(nbCroiseur > 0)
        info += ";[" + croiseur.substr(0, patrouilleur.length()-2) + "]";
    info += "}";

    return info;
}