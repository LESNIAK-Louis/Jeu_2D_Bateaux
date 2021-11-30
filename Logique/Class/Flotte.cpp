/**
 * @file Flotte.cpp
 * @author Louis Lesniak & Hugues Steiner
 * @date 14/09/2021
 * Definition d'une flotte (~= un joueur)
*/


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
    this->removeAllPatrouilleurs();
    delete this->patrouilleurs;
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

int Flotte::getCaracPatrouilleur(int i){
    return this->caracPatrouilleur[i];
}

int Flotte::getNbPatrouilleurs(){
    return this->patrouilleurs->size();
}

Patrouilleur* Flotte::getPatrouilleur(int i){
	return this->patrouilleurs->at(i);
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

void Flotte::addRessource(){
    this->qteRessource += this->getGainRessource();
}

void Flotte::addRessource(int i){
	this->qteRessource += i;
}

void Flotte::augmenterGainRessource(int a){
    this->gainRessource += a;
}


void Flotte::newPatrouilleur(){
    Patrouilleur* p = new Patrouilleur(this->getNumero(), this->getNbPatrouilleurs(), this->getSpawnPoint(), this->getSpawnPoint(), this->getCaracPatrouilleur(0), this->getCaracPatrouilleur(1), this->getCaracPatrouilleur(2), this->getCaracPatrouilleur(3), this->getCaracPatrouilleur(4));
    this->patrouilleurs->push_back(p);
}

void Flotte::removeAllPatrouilleurs(){
    while(this->getNbPatrouilleurs() != 0)
    {
        this->patrouilleurs->back()->~Navire();
        this->patrouilleurs->pop_back();
    }
}

void Flotte::removePatrouilleur(int i){
    this->patrouilleurs->at(i)->~Navire();
    this->patrouilleurs->erase(patrouilleurs->begin() + i);
    this->reduireNumeroPatrouilleur(i);
}

void Flotte::reduireNumeroPatrouilleur(int indice){
    for (int i = indice; i < this->getNbPatrouilleurs() + 1; i++){
        this->patrouilleurs->at(i)->reduireId();
    }
}

void Flotte::updatePatrouilleur(){
    for (int i = 0; i < this->getNbPatrouilleurs() + 1; i++){
        this->patrouilleurs->at(i)->setVitesse(this->getCaracPatrouilleur(0));
        this->patrouilleurs->at(i)->setPvMax(this->getCaracPatrouilleur(1));
        this->patrouilleurs->at(i)->setDegatArme(this->getCaracPatrouilleur(2));
        this->patrouilleurs->at(i)->setCdArme(this->getCaracPatrouilleur(3));
        this->patrouilleurs->at(i)->setCdArme(this->getCaracPatrouilleur(4));
    }
}