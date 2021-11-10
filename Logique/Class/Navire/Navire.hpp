/**
 * \file Navire.hpp
 * \brief Definition des diffferent types de bateaux/vehicules
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#ifndef NAVIRE_HPP
#define NAVIRE_HPP

#include <stdio.h>
#include <stdbool.h>
#include "../Point.hpp"
#include "../Flotte.hpp"
#include "../../../definitions.hpp"


class Navire
{
    protected :
       
        Flotte* flotte;
        Point* centre;
        bool move;
        int angle;
        int pv;
        int *vitesse;
        int *pvMax;
        int *degatArme;
        int *cdArme; //cool down pour le tir
        int *portee;
        Navire* cible;

    public : 
        Navire(Flotte*);

        Flotte* getFlotte();
        Point* getCentre();
        int getAbscisse();
        int getOrdonnee();
        bool getMove();
        int getAngle();
        int getPv();
        int getVitesse();
        int getPvMax();
        int getDegatArme();
        int getCdArme();
        Navire* getCible();

        void setFlotte(Flotte* flotte);
        void setCentre(Point* centre);
        void setMove(bool b);
        void setAngle(int angle);
        void setPv(int pv);
        void setVitesse(int* vitesse);
        void setPvMax(int* pvMax);
        void setDegatArme(int* degat);
        void setCdArme(int* cd);
        void setCible(Navire* navire);
};


#endif