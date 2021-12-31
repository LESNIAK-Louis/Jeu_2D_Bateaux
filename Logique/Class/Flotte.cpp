/**
 * @file Flotte.cpp
 * @author Louis Lesniak & Hugues Steiner
 * @date 14/09/2021
 * Definition d'une flotte (~= un joueur)
*/
#include "Flotte.hpp"


/* Liste chainée */

selectedNavire* consVide()
{
    return NULL;
}

selectedNavire* consListe(Navire* nav, selectedNavire* liste)
{
    selectedNavire* listeNew = (selectedNavire*)malloc(sizeof(*listeNew));
    if (listeNew == NULL) error("Erreur allocation liste");
    listeNew->nav = nav;
    listeNew->suivant = liste;
    return listeNew;
}

Navire* prem(selectedNavire* liste)
{
    if(liste->nav == NULL) error("Prem su element null liste");
    return liste->nav;
}

selectedNavire* rest(selectedNavire* liste){ return liste->suivant; }

bool estVide(selectedNavire* liste) { return liste == NULL; }

void freeListe(selectedNavire* L)
{
    if (estVide(L))
        return;
    freeListe(rest(L));
    free(L);
}

/* Class Flotte */ 

Flotte::Flotte(int numero, Point* coord, Point* spawn, int ressource, int gain, int pv){
    this->numeroFlotte = numero;
    this->coordBase = coord;
    this->spawnPoint = spawn;
    this->qteRessource = ressource;
    this->gainRessource = gain;
    this->pvBase = pv;
    this->setCaracPatrouilleur(VITESSE_PATROUILLEUR,PV_MAX_PATROUILLEUR,DEGAT_PATROUILLEUR, CADENCE_TIR_PATROUILLEUR, PORTEE_PATROUILLEUR);
    this->patrouilleurs = new std::vector<Patrouilleur*>();
    this->listeSelected = consVide();
}

Flotte::~Flotte(){
    delete this->coordBase;
    delete this->spawnPoint;
    this->removeAllPatrouilleurs();
    delete this->patrouilleurs;
    freeListe(this->listeSelected);
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

void Flotte::setCaracPatrouilleur(int v, int pMax, int degat, int cadence, int p){
    this->caracPatrouilleur[0] = v;
    this->caracPatrouilleur[1] = pMax;
    this->caracPatrouilleur[2] = degat;
    this->caracPatrouilleur[3] = cadence;
    this->caracPatrouilleur[4] = p;
}

selectedNavire* Flotte::getListeSelected()
{
    return this->listeSelected;
}

void Flotte::viderListeSelected()
{
    freeListe(this->getListeSelected());
    this->listeSelected = consVide();
}

void Flotte::addElemListeSelected(Navire* nav)
{
    this->listeSelected = consListe(nav,this->listeSelected);
}

void Flotte::deplacerSelected(Point* destination)
{
    selectedNavire* listeTemp = this->getListeSelected();
    while(!estVide(listeTemp))
    {
        if(listeTemp->nav == NULL) error("elem NULL dans la liste");
        listeTemp->nav->setDestination(destination);
        listeTemp = rest(listeTemp);
    }
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
    this->addPatrouilleur(p);
}

void Flotte::addPatrouilleur(Patrouilleur* p){
    if(p == NULL) error("Patrouilleur NULL en param | ajouterPatrouilleur");
    this->patrouilleurs->push_back(p);
}

void Flotte::removeAllPatrouilleurs(){
    while(this->getNbPatrouilleurs() != 0)
    {
        this->patrouilleurs->back()->~Patrouilleur();
        this->patrouilleurs->pop_back();
    }
}

void Flotte::removePatrouilleur(int i){
    //this->patrouilleurs->at(i)->~Patrouilleur();
    this->patrouilleurs->erase(patrouilleurs->begin() + i);
    this->reduireNumeroPatrouilleur(i);
}

void Flotte::reduireNumeroPatrouilleur(int indice){
    for (int i = indice; i < this->getNbPatrouilleurs(); i++){
        this->patrouilleurs->at(i)->reduireId();
    }
}

void Flotte::updatePatrouilleur(){
    for (int i = 0; i < this->getNbPatrouilleurs() + 1; i++){
        this->patrouilleurs->at(i)->setVitesse(this->getCaracPatrouilleur(0));
        this->patrouilleurs->at(i)->setPvMax(this->getCaracPatrouilleur(1));
        this->patrouilleurs->at(i)->setDegatArme(this->getCaracPatrouilleur(2));
        this->patrouilleurs->at(i)->setCandenceTir(this->getCaracPatrouilleur(3));
        this->patrouilleurs->at(i)->setPortee(this->getCaracPatrouilleur(4));
    }
}

std::string Flotte::formattedInfo()
{
    std::string info;
    info = "F" + std::to_string(this->getNumero()) + "{" + 
    this->getCoordBase()->formattedInfo() + ";" +
    this->getSpawnPoint()->formattedInfo() + ";" +
    std::to_string(this->getQteRessource()) + ";" +
    std::to_string(this->getGainRessource()) + ";" +
    std::to_string(this->getPvBase()) + ";" +
    std::to_string(this->getNbPatrouilleurs());
    if(this->getNbPatrouilleurs() != 0)
    {
        info += ";[";
        for(int k = 0; k <  this->getNbPatrouilleurs()-1; k++)
            info +=  this->getPatrouilleur(k)->formattedInfo() + ";";
        info +=  this->getPatrouilleur(this->getNbPatrouilleurs()-1)->formattedInfo() + "]}";
    }

    return info;
        
}