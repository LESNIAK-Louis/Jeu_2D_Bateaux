/**
 * \file Base.hpp
 * \brief Definition des diffferent types de bateaux/vehicules
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#ifndef BASE_HPP
#define BASE_HPP

#include "Navire.hpp"
#include "../../../definitions.hpp"

class Base : public Navire
{
   public :
   Base(int idFlotte, int id, Point* pos, Point* dest, int vitesse,  int pvMax, int degatArme, int cdArme, int portee);
};



#endif