/** 
* \file Ile.hpp
* \brief Representation d'une ile
* \author Louis Lesniak & Hugues Steiner
* \date 10 Nov. 2021
*/

#ifndef  ILE_HPP
#define ILE_HPP

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
        Ile(Ile* ile);
        ~Ile();

        Point* getCentre();
        int getTaille();
        int getForme();
        int getAbscisse();
        int getOrdonnee();

        void setCentre(Point* centre);
        void setTaille(int taille);
        void setForme(int forme);
        std::string toString();
        std::string formattedInfo();
};

#endif