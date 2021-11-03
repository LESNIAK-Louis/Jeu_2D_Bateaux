/**file Bateaux.cpp
 *@author Louis Lesniak & Hugues Steiner
*date 14/09/2021
*Definition des diffferent types de bateaux/vehicules
*/

#include <stdio.h>
#include <stdbool.h>
#include "Point.hpp"


class Patrouilleur
{
    private : 
        bool move;
        int *vitesse;
        int pvMax;
        int pv;
        int degatArme;
        int cdArme; //cool down pour le tir
        int cible;

    public : 


        
        bool getMove();
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