/** 
* \file IleBonus.hpp
* \brief Representation d'une ile bonus
* \author Louis Lesniak & Hugues Steiner
* \date 10 Nov. 2021
*/

#ifndef ILEBONUS_H
#define ILEBONUS_H

#include <string>
#include <vector>
#include "Point.hpp"
#include "Navire/Patrouilleur.hpp"
#include "../../definitions.hpp"

class IleBonus {
    private : 
        Point* centre;
        int taille;
        int forme;
        int rayonCapture;
        std::vector<Patrouilleur*> defenseurs;
        int controle; //0 : neutre, 1...n : numéro de la flotte
        int bonusType;
        int bonusGain;
        int tempsDebut;
    public : 
        IleBonus(Point* centre, int taille, int forme, int rayonCapture, int controle, int bonustype, int bonusGain);
        ~IleBonus();

        Point* getCentre();
        int getTaille();
        int getForme();
        int getRayonCapture();
        int getNbDefenseur();
        Patrouilleur* getDefenseur(int index);
        int getControle();
        int getBonusType();
        int getBonusGain();
        int getTempsDebut();

        void setCentre(Point* centre);
        void setTaille(int taille);
        void setForme(int forme);
        void setRayonCapture(int rayonCapture);
        void setControle(int controle);
        void setBonusType(int bonusType);
        void setBonusGain(int bonusGain);
        void setTempsDebut(int tempsDebut);

        void addDefenseur(Patrouilleur* defenseur);
        void removeDefenseur(int index);
        void replaceDefenseur(int index, Patrouilleur* defenseur);
        void removeAllDefenseurs();

        std::string toString();
};

#endif