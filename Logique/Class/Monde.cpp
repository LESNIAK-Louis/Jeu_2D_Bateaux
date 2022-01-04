/** 
* \file Monde.cpp
* \brief Representation du jeu
* \author Louis Lesniak & Hugues Steiner
* \date 30 Nov. 2021
*/

#include "Monde.hpp"

Monde::Monde(int nbIles, int nbIlesBonus, int time, int difficulte)
{
    this->flottes = new std::vector<Flotte*>();
    this->nbIles = nbIles;
    this->iles = (Ile**)malloc(sizeof(Ile*)*nbIles);
    this->nbIlesBonus = nbIlesBonus;
    this->ilesBonus = (IleBonus**)malloc(sizeof(IleBonus*)*nbIlesBonus);
    this->timer = time;
    this->difficulte = difficulte;
    this->vainqueur = "Non";
}

Monde::~Monde()
{
    void removeAllFlottes();
    if(this->flottes != NULL)
        delete this->flottes;
    void removeAllIles();
    if(this->iles != NULL)
        free(this->iles);
    void removeAllIlesBonus();
    if(this->ilesBonus != NULL)
        free(this->ilesBonus);
}

int Monde::getNbFlottes()
{
    return this->flottes->size();
}

int Monde::getNbSpritesPersistants()
{
    return this->spritesPersistants->size();
}

int Monde::getNbIles()
{
    return this->nbIles;
}

int Monde::getNbIlesBonus()
{
    return this->nbIlesBonus;
}

Flotte* Monde::getFlotte(int index)
{
    if(index >= this->getNbFlottes()) error("index out of range | getFlotte - Monde");
    return this->flottes->at(index);
}

spritePersistant* Monde::getSpritePersistant(int index)
{
    if(index >= this->getNbSpritesPersistants()) error("index out of range | getSpritePersistant - Monde");
    return this->spritesPersistants->at(index);
}

Ile* Monde::getIle(int index)
{
    if(index >= this->getNbIles()) error("index out of range | getIle - Monde");
    return this->iles[index];
}

IleBonus* Monde::getIleBonus(int index)
{   
    if(index >= this->getNbIlesBonus()) error("index out of range | getIleBonus - Monde");
    return this->ilesBonus[index];
}

int Monde::getTimer()
{
    return this->timer;
}

int Monde::getDifficulte()
{
    return this->difficulte;
}

std::string Monde::getVainqueur(){
    return vainqueur;
}

void Monde::setIle(int index, Ile* ile)
{
    if(index >= this->getNbIles()) error("index out of range | setIle - Monde");
    if(ile == NULL) error("ile a set NULL | setIle - Monde");
    this->iles[index] = ile;
}

void Monde::setIleBonus(int index, IleBonus* ilebonus)
{
    if(index >= this->getNbIlesBonus()) error("index out of range | setIleBonus - Monde");
    if(ilebonus == NULL) error("ilebonus a set NULL | setIleBonus - Monde");
    this->ilesBonus[index] = ilebonus;
}

void Monde::setTimer(int time)
{
    if(time < 0) error("param time negatif | setTimer - Monde");
    this->timer = time;
}

void Monde::setDifficulte(int difficulte)
{
    this->difficulte = difficulte;
}

void Monde::setVainqueur(std::string nomVainqueur)
{
    vainqueur = nomVainqueur;
}

void Monde::addFlotte(Flotte* flotte)
{
    if(flotte == NULL) error("flotte a add NULL | addFlotte - Monde");
    this->flottes->push_back(flotte);
}

void Monde::removeFlotte(int index)
{
    if(index >= this->getNbFlottes()) error("index out of range | removeFlotte - Monde");
    if(this->flottes->at(index) != NULL)
        delete this->flottes->at(index);
    this->flottes->erase(this->flottes->begin() + index);
}

void Monde::addSpritePersistant(Point* p, const char* type, int tempsDebut, int duree)
{
    spritePersistant* s = new spritePersistant();
    s->point = p;
    s->type = type;
    s->tempsDebut = tempsDebut;
    s->duree = duree;
    spritesPersistants->push_back(s);
}

void Monde::removeSpritePersistant(int index)
{
    if(index >= getNbSpritesPersistants()) error("index out of range | removeSpritePersistant - Monde");
    if(spritesPersistants->at(index) != NULL)
        delete spritesPersistants->at(index);
    this->spritesPersistants->erase(spritesPersistants->begin() + index);
}

void Monde::removeAllSpritesPersistant()
{
    for(int i = 0; i < this->getNbSpritesPersistants(); i++)
    {
        spritePersistant* sP = spritesPersistants->back();
        if(sP!=NULL) delete sP;
        this->spritesPersistants->pop_back();
    }
}

void Monde::removeAllFlottes()
{
    for(int i = 0; i < this->getNbFlottes(); i++)
    {
        Flotte* flotte = this->flottes->back();
        if(flotte!=NULL) delete flotte;
        this->flottes->pop_back();
    }
}

void Monde::removeAllIles()
{
    for(int i = 0; i < this->getNbIles(); i++)
    {
        if(this->iles[i] != NULL)
            delete this->iles[i];
    }
    this->nbIles = 0;
}

void Monde::removeAllIlesBonus()
{
    for(int i = 0; i < this->getNbIlesBonus(); i++)
    {
        if(this->ilesBonus[i] != NULL)
            delete this->ilesBonus[i];
    }
    this->nbIlesBonus = 0;
}

void Monde::updateControleIleBonus()
{
    for(int k = 0; k < this->getNbIlesBonus(); k++)
    {
        if(this->getIleBonus(k)->getNbDefenseur() == 0)
        {
            int capture = -1;
            for(int i = 0; i < this->getNbFlottes(); i++)
            {
                if(this->getIleBonus(k)->getControle() == i) break;
                for(int j = 0; j < this->getFlotte(i)->getNbNavires(); j++)
                {
                    if(this->getFlotte(i)->getNavire(j)->estEnCollisionAvec(this->getIleBonus(k)->getRayonCapture() + this->getIleBonus(k)->getTaille()/2, this->getIleBonus(k)->getCentre()))
                    {
                        if(capture == -1) // Si n'a pas été capturée ou si est en cours de capture
                            capture = i;
                        else capture = -1; // Si deux navire de deux flottes differentes sont en conflit pour la capture
                        break;
                    }
                }
            }
            if(capture != -1 && capture != this->getIleBonus(k)->getControle()) // L'ile n'est plus sous controle neutre
            {
                // On retire le bonus a la flotte qui perd le controle
                if(this->getIleBonus(k)->getControle() != -1)
                    this->getFlotte(this->getIleBonus(k)->getControle())->augmenterGainRessource(-this->getIleBonus(k)->getBonusGain());
                
                this->getIleBonus(k)->setControle(capture);
                this->getFlotte(capture)->augmenterGainRessource(this->getIleBonus(k)->getBonusGain());
            }
        }
    }
}

void Monde::actionBot(){
    srand(time(0));
    Point* cibleJoueur = new Point(getFlotte(0)->getCoordBase()->getAbscisse() - TAILLE_BASE - 5, getFlotte(0)->getCoordBase()->getOrdonnee() - TAILLE_BASE - 5);
    for (int f = 1; f < getNbFlottes(); f++){
        if (getFlotte(f)->getNbPatrouilleurs() < 5) {
        getFlotte(f)->acheterPatrouilleur();
        int random = (rand() % 99 ) + 1;
            if (random < 15) {
                getFlotte(f)->getNavire(getFlotte(f)->getNbNavires()-1)->setDestination(cibleJoueur);
            }
        }
        getFlotte(f)->ameliorerPatrouilleurs();
        getFlotte(f)->acheterCroiseur();
        getFlotte(f)->acheterPatrouilleur();
        int random = (rand() % 1000) + 1;
        if (random < 10){
            for (int n = 1; n < getFlotte(f)->getNbNavires(); n++){
                getFlotte(f)->getNavire(n)->setDestination(cibleJoueur);
            }
        }
    } 
}

std::string Monde::formattedInfo()
{
    std::string info = std::to_string(this->getNbIles()) + ";" +
    std::to_string(this->getNbIlesBonus()) + ";" +
    std::to_string(this->getTimer()) + ";" +
    std::to_string(this->getDifficulte());
    for(int i = 0 ; i < this->getNbFlottes(); i++)
        info += '\n' + this->getFlotte(i)->formattedInfo();
    for(int i = 0 ; i < this->getNbIles(); i++)
        info += '\n' + this->getIle(i)->formattedInfo();
    for(int i = 0 ; i < this->getNbIlesBonus(); i++)
        info += '\n' + this->getIleBonus(i)->formattedInfo();

    return info;
        
}