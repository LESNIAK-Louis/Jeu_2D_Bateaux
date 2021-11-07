/**
 * @file Navire.cpp
 * @author Louis Lesniak & Hugues Steiner
 * @date 14/09/2021
 * Definition des diffferent types de bateaux/vehicules
*/

#include "Navire.hpp"

Navire::Navire(Flotte* flotte){
    this->setFlotte(flotte);
    this->setCentre(this->getFlotte()->getSpawnPoint());
    this->setMove(false);
    this->setAngle(0);
    this->setPv(this->getPvMax());
}

//Getter
Flotte* getFlotte(){
    return this->flotte;
}

Point* Navire::getCentre(){
    return this->centre;
}

int Navire::getAbscisse(){
    return this->getCentre()->getAbscisse();
}

int Navire::getOrdonnee(){
    return this->getCentre()->getOrdonnee();
}

bool Navire::getMove(){
    return this->move;
}

int Navire::getAngle() {
    return this->angle;
}

int Navire::getVitesse(){
    return *(this->vitesse);
}

int Navire::getPv(){
    return this->pv;
}

int Navire::getPvMax(){
    return *(this->pvMax);
}

int Navire::getDegatArme(){
    return *(this->degatArme);
}

int Navire::getCdArme(){
    return *(this->cdArme);
}

Navire* Navire::getCible(){
    return this->cible;
}

//Setter
void Navire::setFlotte(Flotte* flotte){
    if(flotte == NULL) error("Flotte NULL en param | Constructeur - Navire");
    this->flotte = flotte;
}

void Navire::setCentre(Point* point){
    if(point == NULL) error("Point NULL en param | setCentre - Navire");
    this->centre->setAbscisse(point->getAbscisse());
    this->centre->setOrdonnee(point->getOrdonnee());
}

void Navire::setMove(bool b) {
    this->move = b;
}

void Navire::setAngle(int angle){
    angle%=360;
    this->angle = angle;
}

void Navire::setPv(int pv){
    this->pv = pv;
}

void Navire::setVitesse(int* vitesse) {
    if(vitesse == NULL) error("Pointeur NULL en param | setVitesse - Navire");
    this->vitesse = vitesse;
}

void Navire::setPvMax(int* pvMax){
    if(pvMax == NULL) error("Pointeur NULL en param | setPvMax - Navire");
    this->pvMax = pvMax;
}

void Navire::setDegatArme(int* degat){
    if(degat == NULL) error("Pointeur NULL en param | setDegatArme - Navire");
    this->degatArme = degat;
}

void Navire::setCdArme(int* cd){
    if(cd == NULL) error("Pointeur NULL en param | setCdArme - Navire");
    this->cdArme = cd;
}

void Navire::setCible(Navire* navire){
    if(navire == NULL) error("Navire NULL en param | setCible - Navire");
    this->cible = navire;
}