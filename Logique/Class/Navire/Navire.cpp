/**
 * \file Navire.cpp
 * \brief Definition des diffferent types de bateaux/vehicules
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

//TODO : Finir le constructeur à partir d'une flotte

#include "Navire.hpp"
#include "../../../definitions.hpp"

Navire::Navire(..........){
    this->setFlotte(flotte);
    this->setCentre(p);
    this->setMove(false);
    this->setAngle(0);
}

Navire::Navire(){
    this->setMove(false);
    this->setAngle(0);
}

Navire::~Navire()
{
    delete this->centre;
    delete this->destination;
    delete this->portee;
    delete this->cible;

}


//Getter

void* Navire::getFlotte(){
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

bool Navire::isMoving(){
    return this->move;
}

int Navire::getAngle() {
    return this->angle;
}

int Navire::getVitesse(){
    return this->vitesse;
}

Point* Navire::getDestination(){
    return this->destination;
}

int Navire::getPv(){
    return this->pv;
}

int Navire::getPvMax(){
    return this->pvMax;
}

int Navire::getDegatArme(){
    return this->degatArme;
}

int Navire::getCdArme(){
    return this->cdArme;
}

Navire* Navire::getCible(){
    return this->cible;
}



//Setter

void Navire::setFlotte(intIdFlotte){
    if(flotte == NULL) error("Flotte NULL en param | Constructeur - Navire");
    this->flotte = flotte;
}

void Navire::setCentre(Point* point){
    if(point == NULL) error("Point NULL en param | setCentre - Navire");
    if (this->centre != NULL) delete this->centre;
    this->centre = point;
}

void Navire::deplacer(int abs, int ord){
    this->centre->deplacer(abs, ord);
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

void Navire::setVitesse(int vitesse) {
    //if(vitesse == NULL) error("Pointeur NULL en param | setVitesse - Navire");
    this->vitesse = vitesse;
}

void Navire::setPvMax(int pvMax){
    if(pvMax == NULL) error("Pointeur NULL en param | setPvMax - Navire");
    this->pvMax = pvMax;
}

void Navire::setDegatArme(int degat){
    if(degat == NULL) error("Pointeur NULL en param | setDegatArme - Navire");
    this->degatArme = degat;
}

void Navire::setCdArme(int cd){
    if(cd == NULL) error("Pointeur NULL en param | setCdArme - Navire");
    this->cdArme = cd;
}

void Navire::setPortee(int por){
    if(por == NULL) error("Pointeur NULL en param | setPotee - Navire");
    this->portee = por;
}

void Navire::setCible(Navire navire){
    if(navire == NULL) error("Navire NULL en param | setCible - Navire");
    this->cible = navire;
}