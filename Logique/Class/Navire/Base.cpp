/**
 * \file Base.cpp
 * \brief Definition du type de la base
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#include "Base.hpp"


Base::Base(int idFlotte, int id, Point* pos, Point* dest, int vitesse,  int pvMax, int degatArme, int cdArme, int portee) : Navire{ idFlotte, id, pos, dest, vitesse, pvMax, degatArme, cdArme, portee} {
    this->taille = TAILLE_BASE;
    this->type = "Base";
}
