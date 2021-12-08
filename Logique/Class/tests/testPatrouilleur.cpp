/** 
* \file testPatrouilleur.cpp
* \brief Les tests relatifs à la classe Ile
* \author Louis Lesniak & Hugues Steiner
* \date 10 Nov. 2021
*/

#include "../Navire/Patrouilleur.hpp"
#include <iostream>
#include <cmath>

void testGets()
{
    Patrouilleur* patrouilleur = new Patrouilleur(1, 1, new Point(5,6), new Point(5,6), 30, 10, 3, 2, 60);
    if(patrouilleur->getCentre()->getAbscisse() != 5 || patrouilleur->getCentre()->getOrdonnee() != 6) error("Position non correspondante | getCentre - testPatrouilleur");
    if(patrouilleur->getPv() != 10) error("Pv non correspondant | getPv - testPatrouilleur");
    if(patrouilleur->getVitesse() != 30) error("Vitesse non correspondante | getVitesse - testPatrouilleur");
    std::cout << "test";
    patrouilleur->setAngle(50);
    printf("Angle = %i  :  Vitesse horizontale = %i; vitesse verticale : %i\n",patrouilleur->getAngle(), patrouilleur->getVitesseHorizontale(), patrouilleur->getVitesseVerticale());
    patrouilleur->setAngle(100);
    printf("Angle = %i  :  Vitesse horizontale = %i; vitesse verticale : %i\n",patrouilleur->getAngle(), patrouilleur->getVitesseHorizontale(), patrouilleur->getVitesseVerticale());
    patrouilleur->setAngle(210);
    printf("Angle = %i  :  Vitesse horizontale = %i; vitesse verticale : %i\n",patrouilleur->getAngle(), patrouilleur->getVitesseHorizontale(), patrouilleur->getVitesseVerticale());
    patrouilleur->setAngle(320);
    printf("Angle = %i  :  Vitesse horizontale = %i; vitesse verticale : %i\n",patrouilleur->getAngle(), patrouilleur->getVitesseHorizontale(), patrouilleur->getVitesseVerticale());
    patrouilleur->~Navire();
}


int main()
{
    testGets();

    return 0;
}
