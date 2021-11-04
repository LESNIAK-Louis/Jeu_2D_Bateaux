/** 
* @file Ile.hpp
* @author Louis Lesniak & Hugues Steiner
* @date 04/11/2021
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
        ~Ile();

        Point* getCentre();
        int getTaille();
        int getForme();

        void setCentre(Point centre);
        void setTaille(int taille);
        void setForme(int forme);
        std::string toString();
};

#endif