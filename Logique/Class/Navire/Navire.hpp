/**file Navire.hpp
 *@author Louis Lesniak & Hugues Steiner
*date 14/09/2021
*Definition des diffferent types de bateaux/vehicules
*/

#include <stdio.h>
#include <stdbool.h>
#include "./Point.hpp"

#ifndef NAVIRE_HPP
#define NAVIRE_HPP

class Navire
{
    protected : 
        bool move;
        int angleDeplacement;
        int *vitesse;
        int pvMax;
        int pv;
        int degatArme;
        int cdArme; //cool down pour le tir
        Navire cible;

    public : 

        bool getMove();
        int getAngleDeplacement();
        int getVitesse();
        int getPVMax()
        int getPv();
        int getDegatArme();
        int getCdArme();
        int getCible();

        bool setMove();
        int setVitesse();
        int setPVMax()
        int setPv();
        int setDegatArme();
        int setCdArme();
        int setCible();
}

#endif