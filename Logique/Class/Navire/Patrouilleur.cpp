/**
 * \file Patrouilleur.cpp
 * \brief Definition des diffferent types de bateaux/vehicules
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#include "../../../definitions.hpp"
#include "Patrouilleur.hpp"

/*Patrouilleur::Patrouilleur(Point* p, int angle, int pMax, int v) : Navire{p, angle, pMax} {
    this->setVitesse(v);
}*/

Patrouilleur::Patrouilleur(Flotte* f) : Navire{f} {
    this->setVitesse( (this->flotte->getCaracPatrouilleur(0)) );
    this->setPvMax( (this->getFlotte()->getCaracPatrouilleur(1)) );
    this->pv = *(this->pvMax);
    this->setDegatArme( (this->getFlotte()->getCaracPatrouilleur(2)) );
    this->setCdArme( (this->getFlotte()->getCaracPatrouilleur(3)) );
    this->setPortee( (this->getFlotte()->getCaracPatrouilleur(4)) );

}
