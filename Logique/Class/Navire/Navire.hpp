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
#include <string>
#include <vector>
#include "../Point.hpp"
#include "../../../definitions.hpp"


class Navire
{
    protected :
       
        int idFlotte;
        Point* centre;
        bool move;
        int angle;
        int pv;
        int vitesse;
        Point* destination;
        int pvMax;
        int degatArme;
        int cdArme; //cool down pour le tir
        int portee;
        Navire* cible;

    public : 
        Navire();
        Navire(void* flotte, Point* p);

        ~Navire();

        void* getFlotte();
        Point* getCentre();
        int getAbscisse();
        int getOrdonnee();
        bool isMoving();
        int getAngle();
        int getPv();
        int getVitesse();
        Point* getDestination();
        int getPvMax();
        int getDegatArme();
        int getCdArme();
        int getPortee();
        Navire* getCible();

        void setFlotte(int idFlotte);
        void setCentre(Point* centre);
        void deplacer(int abs, int ord);
        void setMove(bool b);
        void setAngle(int angle);
        void setPv(int pv);
        void setVitesse(int vitesse);
        void setDestination(Point p);
        void setPvMax(int pvMax);
        void setDegatArme(int degat);
        void setCdArme(int cd);
        void setPortee(int p);
        void setCible(Navire navire);
};


#endif