/**
 * \file Croiseur.hpp
 * \brief Definition des croiseurs
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#ifndef CROISEUR_HPP
#define CROISEUR_HPP

#include "Navire.hpp"
#include "../../../definitions.hpp"

class Croiseur : public Navire
{
   public :
   Croiseur(int idFlotte, int id, Point* pos, Point* dest, int vitesse,  int pvMax, int degatArme, int cdArme, int portee);
   std::string returnType();
};



#endif