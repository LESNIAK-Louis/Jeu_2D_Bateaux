/**
 * @file Flotte.hpp
 * @author Louis Lesniak & Hugues Steiner
 * @date 14/09/2021
 * Definition d'une flotte (~= un joueur)
*/
#ifndef FLOTTE_HPP
#define FLOTTE_HPP

#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string>
#include <vector>
#include "Point.hpp"
#include "../../definitions.hpp"
#include "Navire/Navire.hpp"
#include "Navire/Base.hpp"
#include "Navire/Patrouilleur.hpp"
#include "Navire/Croiseur.hpp"


// Liste requis pour la notation
typedef struct selectedNavire selectedNavire;
struct selectedNavire
{
    Navire* nav;
    selectedNavire* suivant;
};

selectedNavire* consVide();
selectedNavire* consListe(Navire* nav, selectedNavire* liste);
Navire* prem(selectedNavire* liste);
selectedNavire* rest(selectedNavire* liste);
bool estVide(selectedNavire* liste);
void freeListe(selectedNavire* liste);
selectedNavire* supprimerElement(Navire* liste, Navire* navire);

// class Flotte
class Flotte 
{
    private : 
        int numeroFlotte;
        Point* coordBase;
        Point* spawnPoint;
        int qteRessource;
        int gainRessource;
        int pvBase;
        int caracPatrouilleur[NB_CARAC_BATEAU]; //index : 0: vitesse; 1: pvMax; 2: degatArme; 3: cadence; 4: portée; 5: nombre d'améliorations
        int caracCroiseur[NB_CARAC_BATEAU]; //index : 0: vitesse; 1: pvMax; 2: degatArme; 3: cadence; 4: portée; 5: nombre d'améliorations
        int nbPatrouilleurs;
        int nbCroiseurs;
        std::vector<Navire*>* navires;

        selectedNavire* listeSelected;

    public : 
        Flotte(int numero, Point* coord, Point* spawn, int ressource, int gain, int pv);

        ~Flotte();
        
        int getNumero();
        Point* getCoordBase();
        Point* getSpawnPoint();
        int getQteRessource();
        int getGainRessource();
        int getPvBase();
        int getCaracPatrouilleur(int i);
        int getCaracCroiseur(int i);
        int getNbNavires();
        int getNbPatrouilleurs();
        int getNbCroiseurs();
        Navire* getNavire(int i);
        Navire* getBase();
        Navire* getPatrouilleur(int i);
        Navire* getCroiseur(int i);

        selectedNavire* getListeSelected();
        void viderListeSelected();
        void addElemListeSelected(Navire* nav);
        void deplacerSelected(Point* destination);

        void setNumero(int i);
        void setCoordBase(Point* p);
        void setSpawnPoint(Point* p);
        void setNbPatrouilleurs(int i);
        void setNbCroiseurs(int i);
        void setQteRessource(int q);
        void setGainRessource(int g);

        void setPvBase(int p);
        void setCaracPatrouilleur(int v, int pMax, int degat, int cd, int p);
        void setCaracCroiseur(int v, int pMax, int degat, int cd, int p);

        void addRessource();
        void addRessource(int i);
        void augmenterGainRessource(int a);


        void removeAllNavires();
        
        /**
         * @brief supprime le navire à l'indice i
         * 
         * @param i 
         */
        void removeNavire(int i);
        void reduireNumeroNavires(int indice);
        

         /**
         * @brief Annule les ordres en cours pour les bateaux selectionnés
         * 
         */
        void stopSelected();

        /**
         * @brief Fonction auxiliaire de stopSelected
         * 
         * @param liste la lsite des bateaux selectionnés de la flotte
         */
        void stopSelectedAux(selectedNavire* liste);

        /**
         * @brief supprime les bateaux selectionnés
         * 
         */
        void deleteSelected();

        void deleteSelectedAux(selectedNavire* liste);

        /**
         * @brief Fonction qui crée la base
         * 
         */
        void creerBase();

        /**
         * @brief Crée un nouveau patrouilleur et l'ajoute à la flotte
         * 
         */
        void newPatrouilleur();

        /**
         * @brief ajoute un patrouilleur à la flotte
         * 
         * @param p le patrouilleur à ajouter
         */
        void addPatrouilleur(Patrouilleur* p);
        /**
         * @brief améliore les caractéristiques des patrouilleurs
         * 
         */
        void ameliorerPatrouilleurs();

        void ameliorerVitessePatrouilleurs();
        void ameliorerPVMaxPatrouilleurs();
        void ameliorerDegatsPatrouilleurs();
        void ameliorerCadencePatrouilleurs();
        void ameliorerPorteePatrouilleurs();
        void updatePatrouilleurs();

        /**
         * @brief Crée un nouveau croiseur et l'ajoute à la flotte
         * 
         */
        void newCroiseur();

        /**
         * @brief ajoute un croiseur à la flotte
         * 
         * @param c le croiseur à ajouter
         */
        void addCroiseur(Croiseur* c);

        /**
         * @brief améliore les caractéristiques des croiseurs
         * 
         */
        void ameliorerCroiseurs();

        void ameliorerVitesseCroiseurs();
        void ameliorerPVMaxCroiseurs();
        void ameliorerDegatsCroiseurs();
        void ameliorerCadenceCroiseurs();
        void ameliorerPorteeCroiseurs();
        void updateCroiseurs();
        std::string formattedInfo();

};

#endif