/** file iles.hpp
*@author Louis Lesniak & Hugues Steiner
*date 14/09/2021
*/

#ifndef  ILE_H
#define ILE_H

#include <string> 
#include "Point.hpp"


class Ile
{
    private : 
        Point* centre;
        int taille;
        int forme;

    public : 
        Ile(int abs, int ord, int t, int f);
        Point* getCentre();
        int getTaille();
        int getForme();
        int getAbscisse();
        int getOrdonnee();
        std::string toString();
};

#endif