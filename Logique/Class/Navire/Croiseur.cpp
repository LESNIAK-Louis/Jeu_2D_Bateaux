/**
 * \file Croiseur.cpp
 * \brief Definition des croiseurs
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#include "../../../definitions.hpp"
#include "Croiseur.hpp"


Croiseur::Croiseur(int idFlotte, int id, Point* pos, Point* dest, int vitesse,  int pvMax, int degatArme, int cdArme, int portee) : Navire{ idFlotte, id, pos, dest, vitesse, pvMax, degatArme, cdArme, portee} {
    this->taille = TAILLE_CROISEUR;

}

std::string returnType(){ return "croiseur";}

