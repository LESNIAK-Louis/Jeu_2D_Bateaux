/**
 * \file Patrouilleur.cpp
 * \brief Definition des diffferent types de bateaux/vehicules
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#include "Patrouilleur.hpp"


Patrouilleur::Patrouilleur(int idFlotte, int id, Point* pos, Point* dest, int vitesse,  int pvMax, int degatArme, int cdArme, int portee) : Navire{ idFlotte, id, pos, dest, vitesse, pvMax, degatArme, cdArme, portee} {
    this->taille = TAILLE_PATROUILLEUR;
    this->type = "Patrouilleur";
}
