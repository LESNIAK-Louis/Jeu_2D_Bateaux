/**
 * @file Flotte.cpp
 * @author Louis Lesniak & Hugues Steiner
 * @date 14/09/2021
 * Definition d'une flotte (~= un joueur)
*/


//TODO : Supression propre des tableaux
#include "Flotte.hpp"


Flotte::Flotte(int numero, Point* coord, Point* spawn, int ressource, int gain, int pv){
    this->numeroFlotte = numero;
    this->coordBase = coord;
    this->spawnPoint = spawn;
    this->qteRessource = ressource;
    this->gainRessource = gain;
    this->pvBase = pv;
    this->setCaracPatrouilleur(30,10,10,2, 100);
}

Flotte::~Flotte(){
    delete this->coordBase;
    delete this->spawnPoint;
    delete this->caracPatrouilleur;
    removeAllPatrouilleurs();
}

int Flotte::getNumero(){
    return this->numeroFlotte;
}

Point* Flotte::getCoordBase(){
    return this->coordBase;
}

Point* Flotte::getSpawnPoint(){
    return this->spawnPoint;
}

int Flotte::getQteRessource(){
    return this->qteRessource;
}

int Flotte::getGainRessource(){
    return this->gainRessource;
}
int Flotte::getPvBase(){
    return this->pvBase;
}

int* Flotte::getCaracPatrouilleur(int i){
    return &(this->caracPatrouilleur[i]);
}

int Flotte::getNbPatrouilleurs(){
    return this->patrouilleurs.size();
}

void Flotte::setNumero(int i){
    this->numeroFlotte = i;
}

void Flotte::setCoordBase(Point* p){
    this->coordBase = new Point(*p);
}

void Flotte::setSpawnPoint(Point* p){
    this->spawnPoint = new Point(*p);
}

void Flotte::setQteRessource(int q){
    this->qteRessource = q;
}

void Flotte::setGainRessource(int g){
    this->gainRessource = g;
}

void Flotte::setPvBase(int p){
    this->pvBase = p;
}

void Flotte::setCaracPatrouilleur(int v, int pMax, int degat, int cd, int p){
    this->caracPatrouilleur[0] = v;
    this->caracPatrouilleur[1] = pMax;
    this->caracPatrouilleur[2] = degat;
    this->caracPatrouilleur[3] = cd;
    this->caracPatrouilleur[4] = p;
}


void Flotte::newPatrouilleur(Patrouilleur* p){
    this->patrouilleurs.push_back(p);
}

void Flotte::removeAllPatrouilleurs(){
    while(this->getNbPatrouilleurs() != 0)
    {
        delete[] this->patrouilleurs.back();
        this->patrouilleurs.pop_back();
    }
}


        