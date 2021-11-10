/** 
* \file testIle.cpp
* \brief Les tests relatifs à la classe IleBonus
* \author Louis Lesniak & Hugues Steiner
* \date 10 Nov. 2021
*/

#include "../IleBonus.hpp"

void testGets()
{
    IleBonus* ile = new IleBonus(new Point(4,2), 2, 1, 0, 0, 0, 0);
    if(ile->getCentre()->getAbscisse() != 4 || ile->getCentre()->getOrdonnee() != 2) error("Position non correspondante | getCentre - testIleBonus");
    if(ile->getTaille() != 2) error("Taille non correspondante | getTaille - testIleBonus");
    if(ile->getForme() != 1) error("Forme non correspondante | getForme - testIleBonus");

    ile->~IleBonus();
}

void testSets()
{  
    IleBonus* ile = new IleBonus(new Point(4,2), 2, 1, 0, 0, 0, 0);

    ile->setCentre(new Point(2,3));
    ile->setTaille(1);
    ile->setForme(2);

    if(ile->getCentre()->getAbscisse() != 2 || ile->getCentre()->getOrdonnee() != 3) error("Position non correspondante | setCentre - testIleBonus");
    if(ile->getTaille() != 1) error("Taille non correspondante | setTaille - testIleBonus");
    if(ile->getForme() != 2) error("Forme non correspondante | setForme - testIleBonus");

    ile->~IleBonus();
}

int main()
{
    testGets();
    testSets();

    return 0;
}