/** 
* @file IleBonus.hpp
* @author Louis Lesniak & Hugues Steiner
* @date 04/11/2021
*/


#include <string> 
#include "Point.hpp"
#include "Navire/Patrouilleur.hpp"

#ifndef ILESBONUS_H
#define ILESBONUS_H

class IleBonus {
    private : 
        Point* centre;
        int taille;
        int forme;
        int rayonCapture;
        int nbDefenseur;
        Patrouilleur[] defenseur;
        int controle; //0 : neutre, 1...n : numéro de la flotte
        int bonusType;
        int bonusGain;
        int tempsDebut;
    public : 
        IleBonus();
        ~IleBonus();

        Point getCentre();
        int getTaille();
        int getForme();
        int getRayonCapture();
        int getNbDefenseur():
        Patrouilleur[] getDefenseur(int index);
        // return tab ?
        int getControle();
        int getBonusType();
        int getBonusGain();
        int getTempsDebut();

        void setCentre(Point* centre)
        void setTaille(int taille);
        void setForme(int forme);
        void setRayonCapture(int rayonCapture);
        void setNbDefenseur(int nbDefenseur):
        // setDefenseur ?
        void setControle(int controle);
        void setBonusType(int bonusType);
        void setBonusGain(int bonusGain);
        void setTempsDebut(int tempsDebut);

        std::string toString();
};

