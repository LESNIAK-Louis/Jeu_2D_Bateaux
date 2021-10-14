/** file IleBonus.hpp
*@author Louis Lesniak & Hugues Steiner
*date 14/09/2021
*/


#include <string> 
#include "Point.hpp"
#include "Bateaux.hpp"

#ifndef  ILESBONUS_H
#define ILESBONUS_H

class Iles {
    private : 
        Point centre;
        int taille;
        int forme;
        int rayonCapture;
        int nbDefenseur;
        BPatrouilleur[] defenseur;
        int controle; //0 : neutre, 1...n : numéro de la flotte
        int bonusType;
        int bonusGain;
        int tempsDebut;
    public : 
        void Iles();
        Point getCentre();
        int getTaille();
        int getForme();
        std::string toString();
};

