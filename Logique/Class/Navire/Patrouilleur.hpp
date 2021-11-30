/**
 * \file Patrouilleur.hpp
 * \brief Definition des diffferent types de bateaux/vehicules
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#ifndef PATROUILLEUR_HPP
#define PATROUILLEUR_HPP

#include "Navire.hpp"
#include "../../../definitions.hpp"

class Patrouilleur : public Navire
{
   public :
   Patrouilleur(int idFlotte, int id, Point* pos, Point* dest, int vitesse,  int pvMax, int degatArme, int cdArme, int portee);
   
};

#endif