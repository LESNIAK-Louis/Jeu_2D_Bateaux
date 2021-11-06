/**file Navire.cpp
 *@author Louis Lesniak & Hugues Steiner
*date 14/09/2021
*Definition des diffferent types de bateaux/vehicules
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
void Navire::setFlotte(Flotte* f){
    this->flotte = f;
}

void Navire::setCentre(Point* p){
    this->centre->setAbscisse(p->getAbscisse());
    this->centre->setOrdonnee(p->getOrdonnee());
}

void Navire::setMove(bool b) {
    this->move = b;
}

void Navire::setAngle(int a){
    a%=360;
    this->angle = a;
}

void Navire::setPv(int p){
    this->pv = p;
}

void Navire::setVitesse(int* v) {
    this->vitesse = v;
}

void Navire::setPvMax(int* p){
    this->pvMax = p;
}

void Navire::setDegatArme(int* d){
    this->degatArme = d;
}

void Navire::setCdArme(int* c){
    this->cdArme = c;
}

void Navire::setCible(Navire* navire){
    this->cible = navire;
}