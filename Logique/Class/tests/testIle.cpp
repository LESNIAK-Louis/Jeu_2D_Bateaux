/** 
* @file testIle.cpp
* @author Louis Lesniak & Hugues Steiner
* @date 07/11/2021
* Les tests relatifs à la classe Ile
*/

#include "../Ile.hpp"

void testGets()
{
    Ile* ile = new Ile(new Point(4,2), 2, 1);
    if(ile->getCentre()->getAbscisse() != 4 || ile->getCentre()->getOrdonnee() != 2) error("Position non correspondante | getCentre - testIle");
    if(ile->getTaille() != 2) error("Taille non correspondante | getTaille - testIle");
    if(ile->getForme() != 1) error("Forme non correspondante | getForme - testIle");

    ile->~Ile();
}

void testSets()
{  
    Ile* ile = new Ile(new Point(4,2), 2, 1);

    ile->setCentre(new Point(2,3));
    ile->setTaille(1);
    ile->setForme(2);

    if(ile->getCentre()->getAbscisse() != 2 || ile->getCentre()->getOrdonnee() != 3) error("Position non correspondante | setCentre - testIle");
    if(ile->getTaille() != 1) error("Taille non correspondante | setTaille - testIle");
    if(ile->getForme() != 2) error("Forme non correspondante | setForme - testIle");

    ile->~Ile();
}

int main()
{
    testGets();
    testSets();

    return 0;
}