/**
 * @file Flotte.hpp
 * @author Louis Lesniak & Hugues Steiner
 * @date 14/09/2021
 * Definition d'une flotte (~= un joueur)
*/
#ifndef FLOTTE_HPP
#define FLOTTE_HPP


#include <stdio.h>
#include <stdbool.h>
#include <string>
#include <vector>
#include "Point.hpp"
#include "../../definitions.hpp"
#include "Navire/Navire.hpp"
#include "Navire/Patrouilleur.hpp"


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
        int caracPatrouilleur[NB_CARAC_PATROUILLEUR]; //index : 0: vitesse; 1: pvMax; 2: degatArme; 3: cadence; 4: portée; 5: nombre d'améliorations
        std::vector<Patrouilleur*>* patrouilleurs;

        selectedNavire* listeSelected;

    public : 
        Flotte(int numero, Point* coord, Point* spawn, int ressource, int gain, int pv);

        ~Flotte();
        void removeAllPatrouilleurs();

        int getNumero();
        Point* getCoordBase();
        Point* getSpawnPoint();
        int getQteRessource();
        int getGainRessource();
        int getPvBase();
        int getCaracPatrouilleur(int i);
        int getNbPatrouilleurs();
        Patrouilleur* getPatrouilleur(int i);

        selectedNavire* getListeSelected();
        void viderListeSelected();
        void addElemListeSelected(Navire* nav);
        void deplacerSelected(Point* destination);

        void setNumero(int i);
        void setCoordBase(Point* p);
        void setSpawnPoint(Point* p);
        void setQteRessource(int q);
        void setGainRessource(int g);

        void setPvBase(int p);
        void setCaracPatrouilleur(int v, int pMax, int degat, int cd, int p);

        void addRessource();
        void addRessource(int i);
        void augmenterGainRessource(int a);

        void newPatrouilleur();
        void addPatrouilleur(Patrouilleur* p);
        void removePatrouilleur(int i);

        /**
         * @brief Réduit de 1 le numéro des patrouilleurs à l'indice i et au delà : 
         * 
         * @param indice 
         */
        void reduireNumeroPatrouilleurs(int indice);

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
        void updatePatrouilleur();

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

        std::string formattedInfo();

};

#endif