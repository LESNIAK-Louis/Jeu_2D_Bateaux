/**file Navire.hpp
 *@author Louis Lesniak & Hugues Steiner
*date 14/09/2021
*Definition des diffferent types de bateaux/vehicules
*/

#ifndef NAVIRE_HPP
#define NAVIRE_HPP

#include <stdio.h>
#include <stdbool.h>
#include "../Point.hpp"
#include "../Flotte.hpp"


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

        void setFlotte(Flotte* f);
        void setCentre(Point* p);
        void setMove(bool b);
        void setAngle(int a);
        void setPv(int p);
        void setVitesse(int* v);
        void setPvMax(int* p);
        void setDegatArme(int*d);
        void setCdArme(int* c);
        void setCible(Navire* navire);
};


#endif