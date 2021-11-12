/**
 * \file Patrouilleur.cpp
 * \brief Definition des diffferent types de bateaux/vehicules
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#include "../../../definitions.hpp"
#include "Patrouilleur.hpp"

Patrouilleur::Patrouilleur(Point* p, int angle, int pMax, int v) : Navire{p, angle, pMax} {
    this->setVitesse(v);
}
