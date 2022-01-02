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
    this->setCaracPatrouilleur(VITESSE_PATROUILLEUR,PV_MAX_PATROUILLEUR, DEGATS_PATROUILLEUR, CADENCE_TIR_PATROUILLEUR, PORTEE_PATROUILLEUR);
    this->caracPatrouilleur[5] = 0;
    this->navires = new std::vector<Navire*>();
    this->listeSelected = consVide();
    nbPatrouilleurs = 0;
    nbCroiseurs = 0;
}

Flotte::~Flotte(){
    delete this->coordBase;
    delete this->spawnPoint;
    this->removeAllNavires();
    delete this->navires;
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


int Flotte::getNbNavires(){
    return this->navires->size();
}

int Flotte::getNbPatrouilleurs(){
    return this->nbPatrouilleurs;
}

Navire* Flotte::getNavire(int i){
    return this->navires->at(i);
}

Navire* Flotte::getPatrouilleur(int i){
	return this->navires->at(i);
}

Navire* Flotte::getCroiseur(int i){
	return this->navires->at(getNbPatrouilleurs() + i);
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

void Flotte::setNbPatrouilleurs(int i){
    nbPatrouilleurs = i;
}

void Flotte::setNbCroiseurs(int i){
    nbCroiseurs = i;
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
    addRessource(this->getGainRessource());
}

void Flotte::addRessource(int i){
	this->qteRessource += i;
    if (getQteRessource() > OR_MAX){
        this->setQteRessource(OR_MAX);
    }
}

void Flotte::augmenterGainRessource(int a){
    this->gainRessource += a;
}

/* GESTION DES NAVIRES */
void Flotte::removeAllNavires(){
    while(this->getNbNavires() != 0)
    {
        this->navires->back()->~Navire();
        this->navires->pop_back();
    }
}

void Flotte::removeNavire(int i){
    std::string s = "p";
    switch ( s[0] ) {
        case 'p':
            removePatrouilleur(i);
        break;
        case 'c':
            //removeCroiseur(i+1 - getNbPatrouilleurs());
        break;

    }
}

void Flotte::stopSelected(){
    stopSelectedAux(listeSelected);
}

void Flotte::stopSelectedAux(selectedNavire* liste){
    if (!estVide(liste)){
        liste->nav->stop();
        stopSelectedAux(liste->suivant);
    }
}

void Flotte::deleteSelected(){
    deleteSelectedAux(listeSelected);
}

void Flotte::deleteSelectedAux(selectedNavire* liste){
    if (!estVide(liste)){
        printf("OK1");
        deleteSelectedAux(liste->suivant);
        printf("OK3");
        removePatrouilleur(liste->nav->getId());
        printf("OK3");
    }
}

/* GESTION DES PATROUILLEURS */
void Flotte::newPatrouilleur(){
    Patrouilleur* p = new Patrouilleur(this->getNumero(), this->getNbPatrouilleurs(), this->getSpawnPoint(), this->getSpawnPoint(), this->getCaracPatrouilleur(0), this->getCaracPatrouilleur(1), this->getCaracPatrouilleur(2), this->getCaracPatrouilleur(3), this->getCaracPatrouilleur(4));
    this->addPatrouilleur(p);
}

void Flotte::addPatrouilleur(Patrouilleur* p){
    if(p == NULL) error("Patrouilleur NULL en param | ajouterPatrouilleur");
    this->navires->insert(navires->begin() + getNbPatrouilleurs(), p);
    setNbPatrouilleurs(getNbPatrouilleurs() + 1);
}

void Flotte::removeAllPatrouilleurs(){
    while(this->getNbPatrouilleurs() != 0)
    {
        this->navires->back()->~Navire();
        this->navires->pop_back();
        setNbPatrouilleurs(getNbPatrouilleurs() - 1);
    }
}

void Flotte::removePatrouilleur(int i){
    if (i < getNbPatrouilleurs() ) {
        this->navires->at(i)->~Navire() ;
        this->navires->erase(navires->begin() + i);
        setNbPatrouilleurs(getNbPatrouilleurs() - 1);
        this->reduireNumeroPatrouilleurs(i);
    }
    
}

void Flotte::reduireNumeroPatrouilleurs(int indice){
    for (int i = indice; i < this->getNbPatrouilleurs(); i++){
        this->navires->at(i)->reduireId();
    }
}

void Flotte::ameliorerPatrouilleurs(){
    ameliorerPVMaxPatrouilleurs();
    ameliorerVitessePatrouilleurs();
    ameliorerDegatsPatrouilleurs();
    ameliorerCadencePatrouilleurs();
    ameliorerPorteePatrouilleurs();
    updatePatrouilleurs();
    caracPatrouilleur[5]++;
}

void Flotte::ameliorerPVMaxPatrouilleurs(){
    caracPatrouilleur[0] += AMELIO_VITESSE_PATROUILLEUR;
}

void Flotte::ameliorerVitessePatrouilleurs(){
    caracPatrouilleur[1] += AMELIO_PV_MAX_PATROUILLEUR;
}

void Flotte::ameliorerDegatsPatrouilleurs(){
    caracPatrouilleur[2] += AMELIO_DEGATS_PATROUILLEUR;
}

void Flotte::ameliorerCadencePatrouilleurs(){
    caracPatrouilleur[3] += AMELIO_CADENCE_PATROUILLEUR;
}

void Flotte::ameliorerPorteePatrouilleurs(){
    caracPatrouilleur[4] += AMELIO_PORTEE_PATROUILLEUR;
}

void Flotte::updatePatrouilleurs(){
    for (int i = 0; i < this->getNbPatrouilleurs(); i++){
        this->navires->at(i)->setVitesse(this->getCaracPatrouilleur(0));
        this->navires->at(i)->setPvMax(this->getCaracPatrouilleur(1));
        this->navires->at(i)->setDegatArme(this->getCaracPatrouilleur(2));
        this->navires->at(i)->setCadenceTir(this->getCaracPatrouilleur(3));
        this->navires->at(i)->setPortee(this->getCaracPatrouilleur(4));
    }
}


/* GESTION DES CROISEURS */
/*
void Flotte::newCroiseur(){
    Croiseur* c = new Croiseur(this->getNumero(), this->getNbCroiseurs(), this->getSpawnPoint(), this->getSpawnPoint(), this->getCaracCroiseur(0), this->getCaracCroiseur(1), this->getCaracCroiseur(2), this->getCaracCroiseur(3), this->getCaracCroiseur(4));
    this->addCroiseur(c);
}

void Flotte::addCroiseur(Croiseur* c){
    if(c == NULL) error("Croiseur NULL en param | ajouterCroiseur");
    this->navires->insert(navires->begin() + getNbPatrouilleurs() + getNbCroiseurs(), c);
    setNbCroiseurs(getNbCroiseurs() + 1);
}

void Flotte::removeAllCroiseurs(){
    while(this->getNbCroiseurs() != 0)
    {
        this->navires->back()->~Navire();
        this->navires->pop_back();
        setNbPatrouilleurs(getNbCroiseurs() - 1);
    }
}

void Flotte::removeCroiseur(int i){
    if (i < getNbCroiseurs() ) {
        this->navires->erase(navires->begin() + i);
        setNbPatrouilleurs(getNbPatrouilleurs() - 1);
        this->reduireNumeroPatrouilleurs(i);
    }
    
}

void Flotte::reduireNumeroPatrouilleurs(int indice){
    for (int i = indice; i < this->getNbPatrouilleurs(); i++){
        this->navires->at(i)->reduireId();
    }
}

void Flotte::ameliorerPatrouilleurs(){
    ameliorerPVMaxPatrouilleurs();
    ameliorerVitessePatrouilleurs();
    ameliorerDegatsPatrouilleurs();
    ameliorerCadencePatrouilleurs();
    ameliorerPorteePatrouilleurs();
    updatePatrouilleurs();
    caracPatrouilleur[5]++;
}

void Flotte::ameliorerPVMaxPatrouilleurs(){
    caracPatrouilleur[0] += AMELIO_VITESSE_PATROUILLEUR;
}

void Flotte::ameliorerVitessePatrouilleurs(){
    caracPatrouilleur[1] += AMELIO_PV_MAX_PATROUILLEUR;
}

void Flotte::ameliorerDegatsPatrouilleurs(){
    caracPatrouilleur[2] += AMELIO_DEGATS_PATROUILLEUR;
}

void Flotte::ameliorerCadencePatrouilleurs(){
    caracPatrouilleur[3] += AMELIO_CADENCE_PATROUILLEUR;
}

void Flotte::ameliorerPorteePatrouilleurs(){
    caracPatrouilleur[4] += AMELIO_PORTEE_PATROUILLEUR;
}

void Flotte::updatePatrouilleurs(){
    for (int i = 0; i < this->getNbPatrouilleurs(); i++){
        this->navires->at(i)->setVitesse(this->getCaracPatrouilleur(0));
        this->navires->at(i)->setPvMax(this->getCaracPatrouilleur(1));
        this->navires->at(i)->setDegatArme(this->getCaracPatrouilleur(2));
        this->navires->at(i)->setCadenceTir(this->getCaracPatrouilleur(3));
        this->navires->at(i)->setPortee(this->getCaracPatrouilleur(4));
    }
}
*/


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