/** file iles.hpp
*@author Louis Lesniak & Hugues Steiner
*date 14/09/2021
*/


#include <string> 
#include "Point.h"

#ifndef  ILES_H
#define ILES_H

class Iles {
    private : 
        Point* centre;
        int taille;
        int forme;
    public : 
        void Iles();
        Point getCentre();
        int getTaille();
        int getForme();
        std::string toString();
};

