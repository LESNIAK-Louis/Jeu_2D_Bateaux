/** 
* \file IleBonus.hpp
* \brief Representation d'une ile bonus
* \author Louis Lesniak & Hugues Steiner
* \date 10 Nov. 2021
*/

#ifndef ILEBONUS_HPP
#define ILEBONUS_HPP

#include <string>
#include <vector>
#include <cmath>
#include "Point.hpp"
#include "Navire/Navire.hpp"
#include "../../definitions.hpp"

class IleBonus {
    private : 
        Point* centre;
        int taille;
        int forme;
        int rayonCapture;
        std::vector<Navire*>* defenseurs;
        int controle; //0 : neutre, 1...n : numéro de la flotte
        int bonusType;
        int bonusGain;

    public : 
        IleBonus(Point* centre, int taille, int forme, int rayonCapture, int controle, int bonustype, int bonusGain);
        ~IleBonus();

        Point* getCentre();
        int getTaille();
        int getForme();
        int getRayonCapture();
        int getNbDefenseur();
        Navire* getDefenseur(int index);
        int getControle();
        int getBonusType();
        int getBonusGain();

        void setCentre(Point* centre);
        void setTaille(int taille);
        void setForme(int forme);
        void setRayonCapture(int rayonCapture);
        void setControle(int controle);
        void setBonusType(int bonusType);
        void setBonusGain(int bonusGain);

        void addDefenseur(Navire* defenseur);
        void placerDefenseur();
        void removeDefenseur(Navire* defenseur);
        void replaceDefenseur(int index, Navire* defenseur);
        void removeAllDefenseurs();

        std::string toString();
};

#endif