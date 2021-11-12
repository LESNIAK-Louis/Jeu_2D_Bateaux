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
#include "./Point.hpp"
#include "./Navire/Patrouilleur.hpp"
#include "../../definitions.hpp"



class Flotte 
{
    private : 
        int numeroFlotte;
        Point* coordBase;
        int qteOr;
        int gainOr;
        int pvBase;
        int caracPatrouilleur[4]; //index : 0: vitesse; 1: pvMax; 2: degatArme; 3: cooldown
        std::vector<Patrouilleur*> patrouilleurs;

    public : 
        Flotte(int numero);

        int getNumero();
        Point* getCoordBase();
        int getQteOr();
        int getGainOr();
        int getPvBase();
        int getcaracPatrouilleur(int i);

        void setNumero(int i);
        void setCoordBase(Point* p);
        void setQteOr(int q);
        void setGainOr(int g);
        void setPvBase(int p);
        void setcaracPatrouilleur(int v, int pv, int pMax, int degat, int cd);
        
};

#endif