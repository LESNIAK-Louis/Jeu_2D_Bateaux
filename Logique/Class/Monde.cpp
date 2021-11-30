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
    this->mines = new std::vector<Mine*>();
    this->torpilles = new std::vector<Torpille*>();
    this->timer = time;
    this->difficulte = difficulte;
}

Monde::~Monde()
{
    void removeAllFlottes();
    delete this->flottes;
    void removeAllMines();
    delete this->mines;
    void removeAllTorpilles();
    delete this->torpilles;
    void removeAllIles();
    free(this->iles);
    void removeAllIlesBonus();
    free(this->ilesBonus);
}

int Monde::getNbFlottes()
{
    return this->flottes->size();
}

int Monde::getNbIles()
{
    return this->nbIles;
}

int Monde::getNbIlesBonus()
{
    return this->nbIlesBonus;
}

int Monde::getNbMines()
{
    return this->mines->size();
}

int Monde::getNbTorpilles()
{
    return this->torpilles->size();
}

Flotte* Monde::getFlotte(int index)
{
    if(index >= this->getNbFlottes()) error("index out of range | getFlotte - Monde");
    return this->flottes->at(index);
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

Mine* Monde::getMine(int index)
{
    if(index >= this->getNbMines()) error("index out of range | getMine - Monde");
    return this->mines->at(index);
}

Torpille* Monde::getTorpille(int index)
{
    if(index >= this->getNbTorpilles()) error("index out of range | getTorpille - Monde");
    return this->torpilles->at(index);
}

int Monde::getTimer()
{
    return this->timer;
}

int Monde::getDifficulte()
{
    return this->difficulte;
}

void Monde::setIle(int index, Ile* ile)
{
    if(index >= this->getNbIles()) error("index out of range | setIle - Monde");
    if(ile == NULL) error("ile a set NULL | setIle - Monde");
    this->iles[index] = ile;
}

void Monde::setIleBonus(int index, IleBonus* ilebonus)
{
    if(index >= this->getNbIlesBonus()) error("index out of range | setIle - Monde");
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

void Monde::addFlotte(Flotte* flotte)
{
    if(flotte == NULL) error("flotte a add NULL | addFlotte - Monde");
    this->flottes->push_back(flotte);
}

void Monde::addMine(Mine* mine)
{
    if(mine == NULL) error("mine a add NULL | addMine - Monde");
    this->mines->push_back(mine);
}

void Monde::addTorpille(Torpille* torpille)
{
    if(torpille == NULL) error("mine a add NULL | addTorpille - Monde");
    this->torpilles->push_back(torpille);
}

void Monde::removeFlotte(int index)
{
    if(index >= this->getNbFlottes()) error("index out of range | removeFlotte - Monde");
    this->flottes->at(index)->~Flotte();
    this->flottes->erase(this->flottes->begin() + index);
}

void Monde::removeMine(int index)
{
    if(index >= this->getNbMines()) error("index out of range | removeMine - Monde");
    this->mines->at(index)->~Mine();
    this->mines->erase(this->mines->begin() + index);
}

void Monde::removeTorpille(int index)
{
    if(index >= this->getNbTorpilles()) error("index out of range | removeTorpille - Monde");
    this->torpilles->at(index)->~Torpille();
    this->torpilles->erase(this->torpilles->begin() + index);
}

void Monde::removeAllFlottes()
{
    for(int i = 0; i < this->getNbFlottes(); i++)
    {
        this->flottes->back()->~Flotte();
        this->flottes->pop_back();
    }
}

void Monde::removeAllTorpilles()
{
    for(int i = 0; i < this->getNbTorpilles(); i++)
    {
        this->torpilles->back()->~Torpille();
        this->torpilles->pop_back();
    }
}

void Monde::removeAllMines()
{
    for(int i = 0; i < this->getNbMines(); i++)
    {
        this->mines->back()->~Mine();
        this->mines->pop_back();
    }
}

void Monde::removeAllIles()
{
    for(int i = 0; i < this->getNbIles(); i++)
    {
        this->iles[i]->~Ile();
    }
    this->nbIles = 0;
}

void Monde::removeAllIlesBonus()
{
    for(int i = 0; i < this->getNbIlesBonus(); i++)
    {
        this->ilesBonus[i]->~IleBonus();
    }
    this->nbIlesBonus = 0;
}

std::string Monde::toString()
{
    return "Nombre Flottes : " + std::to_string(this->flottes->size()) + "\n"
    + "Nombre Iles : " + std::to_string(this->nbIles) + "\n"
    + "Nombre IlesBonus : " + std::to_string(this->nbIlesBonus) + "\n"
    + "Nombre Mines : " + std::to_string(this->mines->size()) + "\n"
    + "Nombre Torpilles : " + std::to_string(this->torpilles->size()) + "\n"
    + "Timer : " + std::to_string(this->timer) + "s" + "\n"
    + "Difficulte : " + std::to_string(this->difficulte);
}