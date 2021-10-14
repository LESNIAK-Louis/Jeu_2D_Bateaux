/**file Bateaux.cpp
 *@author Louis Lesniak & Hugues Steiner
*date 14/09/2021
*Definition des diffferent types de bateaux/vehicules
*/

#include <stdio.h>
#include <stdbool.h>
#include "Point"


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
}