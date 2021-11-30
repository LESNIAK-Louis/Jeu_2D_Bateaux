/** 
* \file testPatrouilleur.cpp
* \brief Les tests relatifs à la classe Ile
* \author Louis Lesniak & Hugues Steiner
* \date 10 Nov. 2021
*/

#include "../Navire/Patrouilleur.hpp"

void testGets()
{
    Patrouilleur* patrouilleur = new Patrouilleur(new Point(5,6), 0, 10, 30);
    if(patrouilleur->getCentre()->getAbscisse() != 5 || patrouilleur->getCentre()->getOrdonnee() != 6) error("Position non correspondante | getCentre - testPatrouilleur");
    if(patrouilleur->getPv() != 10) error("Pv non correspondant | getPv - testPatrouilleur");
    if(patrouilleur->getVitesse() != 30) error("Vitesse non correspondante | getVitesse - testPatrouilleur");
    patrouilleur->~Navire();
}

/*void testSets()
{  
    Ile* ile = new Ile(new Point(4,2), 2, 1);

    ile->setCentre(new Point(2,3));
    ile->setTaille(1);
    ile->setForme(2);

    if(ile->getCentre()->getAbscisse() != 2 || ile->getCentre()->getOrdonnee() != 3) error("Position non correspondante | setCentre - testIle");
    if(ile->getTaille() != 1) error("Taille non correspondante | setTaille - testIle");
    if(ile->getForme() != 2) error("Forme non correspondante | setForme - testIle");

    ile->~Ile();
}*/

int main()
{
    testGets();
    //testSets();

    return 0;
}
