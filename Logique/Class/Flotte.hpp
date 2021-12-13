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

#include "Navire/Patrouilleur.hpp"

class Flotte 
{
    private : 
        int numeroFlotte;
        Point* coordBase;
        Point* spawnPoint;
        int qteRessource;
        int gainRessource;
        int pvBase;
        int caracPatrouilleur[NB_CARAC_PATROUILLEUR]; //index : 0: vitesse; 1: pvMax; 2: degatArme; 3: cooldown; 4: portée;
        std::vector<Patrouilleur*>* patrouilleurs;

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
        //Réduit de 1 le numéro des patrouilleurs à l'indice i et au delà : 
        void reduireNumeroPatrouilleur(int indice);
        void updatePatrouilleur();

        std::string formattedInfo();

};

#endif