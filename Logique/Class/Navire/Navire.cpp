/**
 * \file Navire.cpp
 * \brief Definition des diffferent types de bateaux/vehicules
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

//TODO : Pathfinding à faire

#include "Navire.hpp"

Navire::Navire(int idFlotte, int id, Point* pos, Point* dest, int vitesse, int pvMax, int degatArme, int cdArme, int portee){
    this->setIdFlotte(idFlotte);
    this->setId(id);
    this->setCentre(pos);
    this->setDestination(dest);
    this->setMove(pos->isEqual(dest));
    //this->setChemin();
    this->setAngle(0);
    this->pvMax = pvMax;
    this->setPv(pvMax);
    this->vitesse = vitesse;
    this->degatArme = degatArme;
    this->cdArme = cdArme;
    this->portee = portee;    
    this->isSelected = false;
}

Navire::Navire(){
    this->setMove(false);
    this->setAngle(0);
}

Navire::~Navire()
{
    delete this->centre;
    delete this->destination;
    delete this->wayPoint;
    delete this->cible;
}


//Getter

int Navire::getIdFlotte(){
    return this->idFlotte;
}

int Navire::getId(){
    return this->id;
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

Point* Navire::getNextWayPoint(){
    return this->wayPoint;
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

bool Navire::getIsSelected()
{
    return this->isSelected;
}



//Setter

void Navire::setIdFlotte(int idFlotte){
    this->idFlotte = idFlotte;
}

void Navire::setId(int id){
    this->idFlotte = id;
}

void Navire::reduireId(){
    this->setId(this->getId() - 1);
}

void Navire::setCentre(Point* point){
    if(point == NULL) error("Point NULL en param | setCentre - Navire");
    if (this->centre != NULL) delete this->centre;
    this->centre = point;
}

void Navire::setDestination(Point* point){
    this->destination = point;
}

/*
####################   FONCTION DE PATHFINDING A REALISER #################################################
*/
void Navire::setChemin() {
    //this->chemin = this->getCentre()->findPathTo(this->destination);
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

void Navire::ajouterPV(int pv){
    this->setPv(this->getPv() + pv);
    if (this->pv > this->pvMax) {
        this->setPv(this->getPvMax());
    }
}

void Navire::setVitesse(int vitesse) {
    this->vitesse = vitesse;
}

void Navire::setPvMax(int pvMax){
    this->pvMax = pvMax;
}

void Navire::setDegatArme(int degat){
    this->degatArme = degat;
}

void Navire::setCdArme(int cd){
    this->cdArme = cd;
}

void Navire::setPortee(int por){
    this->portee = por;
}

void Navire::setCible(Navire* navire){
    if(navire == NULL) error("Navire NULL en param | setCible - Navire");
    this->cible = navire;
}

void Navire::setIsSelected(bool isSelected)
{
    this->isSelected = isSelected;
}