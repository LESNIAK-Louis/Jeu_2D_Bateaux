/** 
* @file Ile.hpp
* @author Louis Lesniak & Hugues Steiner
* @date 07/11/2021
* Representation d'une ile
*/

#ifndef  ILE_H
#define ILE_H

#include <string> 
#include "Point.hpp"
#include "../../definitions.hpp"


class Ile
{
    private : 
        Point* centre;
        int taille;
        int forme;

    public : 
        Ile(Point* centre, int taille, int forme);
        ~Ile();

        Point* getCentre();
        int getTaille();
        int getForme();

        void setCentre(Point* centre);
        void setTaille(int taille);
        void setForme(int forme);
        std::string toString();
};

#endif