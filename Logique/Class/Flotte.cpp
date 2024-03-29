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
    if (listeNew == NULL) error("Erreur allocation liste | consListe");
    listeNew->nav = nav;
    listeNew->suivant = liste;
    return listeNew;
}

Navire* prem(selectedNavire* liste)
{
    if(liste->nav == NULL) error("element null liste | Prem");
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

selectedNavire* supprimerElement(selectedNavire* liste, Navire* navire)
{
    if(navire == NULL) error("Element null a supprimer | supprimerElement");
    selectedNavire* temp;
    selectedNavire* previous;
    
    if (liste == NULL) 
        return liste;

    previous = liste;

    if (prem(previous) == navire)
    {
        liste = rest(liste);
        if(previous != NULL)
            free(previous);
        return liste;
    }
    temp = rest(previous); 
    while(temp != NULL) 
    {
        if (prem(temp) == navire)
        {
            previous->suivant = rest(temp);
            if(temp != NULL)
                free(temp);
            return liste;
        }
        previous = temp; 
        temp = rest(temp);
    }
    return liste;
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
    this->setCaracCroiseur(VITESSE_CROISEUR,PV_MAX_CROISEUR, DEGATS_CROISEUR, CADENCE_TIR_CROISEUR, PORTEE_CROISEUR);
    this->caracPatrouilleur[5] = 0;
    this->caracCroiseur[5] = 0;
    this->navires = new std::vector<Navire*>();
    this->listeSelected = consVide();
    this->nbPatrouilleurs = 0;
    this->nbCroiseurs = 0;
}

Flotte::~Flotte(){
    if(this->coordBase != NULL)
        delete this->coordBase;
    if(this->spawnPoint != NULL)  
        delete this->spawnPoint;
    this->removeAllNavires();
    if(this->navires != NULL)  
        delete this->navires;
    if(this->listeSelected != NULL)
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
   for (int i = 0; i < getNbNavires(); i++){
       if (getNavire(i)->getType().compare("Base") == 0){
           return getNavire(i)->getPv();
       }
   }
   error("Base introuvable | getPvBase");
}

int Flotte::getCaracPatrouilleur(int i){
    return this->caracPatrouilleur[i];
}

int Flotte::getCaracCroiseur(int i){
    return this->caracCroiseur[i];
}


int Flotte::getNbNavires(){
    return this->navires->size();
}

int Flotte::getNbPatrouilleurs(){
    return this->nbPatrouilleurs;
}

int Flotte::getNbCroiseurs(){
    return this->nbCroiseurs;
}

Navire* Flotte::getNavire(int i){
    return this->navires->at(i);
}
Navire* Flotte::getBase(){
    for (int i = 0; i < getNbNavires(); i++){
        if (getNavire(i)->getType().compare("Base") == 0) {
            return getNavire(i);
        }
    }
    error("Base introuvable | getBase");
}

Navire* Flotte::getPatrouilleur(int i){
	int nbPat = -1;
    int j = 0;
    while (j < getNbNavires() && nbPat != i){
        if (getNavire(j)->getType().compare("Patrouilleur") == 0) {
            nbPat++;
        }
        if (nbPat != i) { j++ ;}
    }
    if (getNavire(j)->getType().compare("Patrouilleur") != 0) {
        error("Le patrouilleur i n'existe pas | getPatrouilleur()");
    }
    return getNavire(j);
}

Navire* Flotte::getCroiseur(int i){
	int nbCrois = -1;
    int j = 0;
    while (j < getNbNavires() && nbCrois != i){
        if (getNavire(j)->getType().compare("Croiseur") == 0) {
            nbCrois++;
        }
        if (nbCrois != i) { j++ ;}
    }
    if (getNavire(j)->getType().compare("Croiseur") != 0) {
        error("Le croiseur i n'existe pas | getCroiseur()");
    }
    return getNavire(j);
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

void Flotte::setCaracPatrouilleur(int v, int pMax, int degat, int cadence, int p){
    this->caracPatrouilleur[0] = v;
    this->caracPatrouilleur[1] = pMax;
    this->caracPatrouilleur[2] = degat;
    this->caracPatrouilleur[3] = cadence;
    this->caracPatrouilleur[4] = p;
}

void Flotte::setCaracCroiseur(int v, int pMax, int degat, int cadence, int p){
    this->caracCroiseur[0] = v;
    this->caracCroiseur[1] = pMax;
    this->caracCroiseur[2] = degat;
    this->caracCroiseur[3] = cadence;
    this->caracCroiseur[4] = p;
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
        Navire* nav = this->navires->back();
        if(nav != NULL)
            delete nav;
        this->navires->pop_back();
    }
}

void Flotte::removeNavire(int i){

    if(getNavire(i) == NULL) error("navire NULL en param| removeNavire - Flotte");

    if(this->getNumero() == 0) // On regarde si le beateau est dans la liste de selection avant de le supprimer
    {
        selectedNavire* newListe = supprimerElement(this->listeSelected, getNavire(i));
        this->listeSelected = newListe;
    }
    
    if (getNavire(i)->getType() == "Patrouilleur")
        this->setNbPatrouilleurs(this->getNbPatrouilleurs() - 1);
    else if (getNavire(i)->getType() == "Croiseur")
        this->setNbCroiseurs(this->getNbCroiseurs() - 1);
    else
            error("Type de bateau invalide | removeNavire - Flotte");  

    reduireNumeroNavires(i);
    navires->erase(navires->begin() + i);
}

void Flotte::reduireNumeroNavires(int indice){
    for (int i = indice; i < this->getNbNavires(); i++){
        this->navires->at(i)->reduireId();
    }
}

void Flotte::addNavire(Navire* nav)
{
    if(nav == NULL) error("Navire NULL en param | addNavire");
    this->navires->push_back(nav);
    
    if(nav->getType() == "Patrouilleur")
        this->setNbPatrouilleurs(this->getNbPatrouilleurs() + 1);
    else if(nav->getType() == "Croiseur")
        this->setNbCroiseurs(this->getNbCroiseurs()+1);
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
        if (!estVide(liste->suivant)) {
             deleteSelectedAux(liste->suivant);
        }
        if (liste->nav->getType().compare("Base") != 0) {
            removeNavire(liste->nav->getId());
        }
        
    }
}

/*CEATION DE LA BASE*/
void Flotte::creerBase(){
    Base* b = new Base(getNumero(), getNbNavires(), getCoordBase(),  getCoordBase(), 0, PV_MAX_BASE, DEGATS_BASE, CADENCE_TIR_BASE, PORTEE_BASE);
    this->navires->push_back(b);
}

/* GESTION DES PATROUILLEURS */
void Flotte::newPatrouilleur(){
    Patrouilleur* p = new Patrouilleur(this->getNumero(), this->getNbNavires(), this->getSpawnPoint(), this->getSpawnPoint(), this->getCaracPatrouilleur(0), this->getCaracPatrouilleur(1), this->getCaracPatrouilleur(2), this->getCaracPatrouilleur(3), this->getCaracPatrouilleur(4));
    this->addPatrouilleur(p);
}

void Flotte::addPatrouilleur(Patrouilleur* p){
    if(p == NULL) error("Patrouilleur NULL en param | ajouterPatrouilleur");
    this->navires->push_back(p);
    this->setNbPatrouilleurs(this->getNbPatrouilleurs() + 1);
}

void Flotte::acheterPatrouilleur(){
    if (getQteRessource() >= COUT_PATROUILLEUR) {
        newPatrouilleur();
        addRessource(-COUT_PATROUILLEUR);
    }
}

void Flotte::ameliorerPatrouilleurs(){
    if (getCaracPatrouilleur(5) < NB_AMELIO_MAX && getQteRessource() >= COUT_AMELIORATION_PATROUILLEUR ) { //on vérifie si les navires ont déjà été améliorés au maximum et que la flotte a suffsiament de ressources
        ameliorerPVMaxPatrouilleurs();
        ameliorerVitessePatrouilleurs();
        ameliorerDegatsPatrouilleurs();
        ameliorerCadencePatrouilleurs();
        ameliorerPorteePatrouilleurs();
        updatePatrouilleurs();
        caracPatrouilleur[5]++;
        addRessource(-COUT_AMELIORATION_PATROUILLEUR);
    }
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
    for (int i = 0; i < this->getNbNavires(); i++){
        if (getNavire(i)->getType().compare("Patrouilleur") == 0) {
            this->navires->at(i)->setVitesse(this->getCaracPatrouilleur(0));
            this->navires->at(i)->setPvMax(this->getCaracPatrouilleur(1));
            this->navires->at(i)->setDegatArme(this->getCaracPatrouilleur(2));
            this->navires->at(i)->setCadenceTir(this->getCaracPatrouilleur(3));
            this->navires->at(i)->setPortee(this->getCaracPatrouilleur(4));
        }
    }
}


/* GESTION DES CROISEURS */

void Flotte::newCroiseur(){
    Croiseur* c = new Croiseur(this->getNumero(), this->getNbNavires(), this->getSpawnPoint(), this->getSpawnPoint(), this->getCaracCroiseur(0),  this->getCaracCroiseur(1), this->getCaracCroiseur(2), this->getCaracCroiseur(3), this->getCaracCroiseur(4));
    this->addCroiseur(c);
}

void Flotte::addCroiseur(Croiseur* c){
    if(c == NULL) error("Croiseur NULL en param | ajouterCroiseur");
    this->navires->push_back(c);
    this->setNbCroiseurs(this->getNbCroiseurs() + 1);
}

void Flotte::acheterCroiseur(){
    if (getQteRessource() >= COUT_CROISEUR) {
        newCroiseur();
        addRessource(-COUT_CROISEUR);
    }
}

void Flotte::ameliorerCroiseurs(){
    if (getCaracCroiseur(5) < NB_AMELIO_MAX && getQteRessource() >= COUT_AMELIORATION_CROISEUR ) { //on vérifie si les navires ont déjà été améliorés au maximum et que la flotte a suffsiament de ressources
        ameliorerPVMaxCroiseurs();
        ameliorerVitesseCroiseurs();
        ameliorerDegatsCroiseurs();
        ameliorerCadenceCroiseurs();
        ameliorerPorteeCroiseurs();
        updateCroiseurs();
        caracCroiseur[5]++;
        addRessource(-COUT_AMELIORATION_CROISEUR);
    }
}

void Flotte::ameliorerPVMaxCroiseurs(){
    caracCroiseur[0] += AMELIO_VITESSE_CROISEUR;
}

void Flotte::ameliorerVitesseCroiseurs(){
    caracCroiseur[1] += AMELIO_PV_MAX_CROISEUR;
}

void Flotte::ameliorerDegatsCroiseurs(){
    caracCroiseur[2] += AMELIO_DEGATS_CROISEUR;
}

void Flotte::ameliorerCadenceCroiseurs(){
    caracCroiseur[3] += AMELIO_CADENCE_CROISEUR;
}

void Flotte::ameliorerPorteeCroiseurs(){
    caracCroiseur[4] += AMELIO_PORTEE_CROISEUR;
}

void Flotte::updateCroiseurs(){
    for (int i = 0; i < this->getNbNavires(); i++){
        if (getNavire(i)->getType().compare("Croiseur") == 0) {
            this->navires->at(i)->setVitesse(this->getCaracCroiseur(0));
            this->navires->at(i)->setPvMax(this->getCaracCroiseur(1));
            this->navires->at(i)->setDegatArme(this->getCaracCroiseur(2));
            this->navires->at(i)->setCadenceTir(this->getCaracCroiseur(3));
            this->navires->at(i)->setPortee(this->getCaracCroiseur(4));
        }
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
    std::to_string(this->getNbNavires());
    if(this->getNbNavires() != 0)
    {
        info += ";[";
        for(int k = 0; k <  this->getNbNavires()-1; k++)
            info +=  this->getNavire(k)->formattedInfo() + ";";
        info +=  this->getNavire(this->getNbNavires()-1)->formattedInfo() + "]";
    }
    info += "}";

    return info;
        
}