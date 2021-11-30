/** 
* \file testFlotte.cpp
* \brief Les tests relatifs à la classe Flotte
* \author Louis Lesniak & Hugues Steiner
* \date 10 Nov. 2021
*/

#include "../Flotte.hpp"

void testGets()
{
    Flotte* f = new Flotte(1, new Point(5,5), new Point(6,6), 0, 10, 500);
    f->addRessource();
    if (f->getQteRessource() != 10) error("Problème lors de l'ajout de ressources");
    if (f->getNbPatrouilleurs() != 0) error("Problème lors de la création d'un patrouilleur dans une flotte.");
    f->newPatrouilleur();
    if (f->getNbPatrouilleurs() != 1) error("Problème lors de la création d'un patrouilleur dans une flotte.");
    if (f->getPatrouilleur(0)->getId() != 0) error("Problème lors de l'attribution de l'identifiant du patrouilleur.");
}


int main()
{
    testGets();

    return 0;
}
