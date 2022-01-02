/** 
* \file testPoint.cpp
* \brief Les tests relatifs à la classe Point
* \author Louis Lesniak & Hugues Steiner
* \date 10 Nov. 2021
*/

#include "../Point.hpp"

void testGets()
{
    Point* pt = new Point(3,2);
    if(pt->getAbscisse() != 3 || pt->getOrdonnee() != 2) perror("Gets non correspondants | testGets - Point");
    delete pt;
}

void testDistance()
{
    Point* pt1 = new Point(2,2);
    Point* pt2 = new Point(4,4);
    if(pt1->distance(pt2) != 2) perror("La distance n'est pas la bonne | testDistance - Point");
    delete pt1; delete pt2;
}

void testIsEqual()
{
    Point* pt1 = new Point(2,2);
    Point* pt2 = new Point(2,2);
    Point* pt3 = new Point(1,2);
    Point* pt4 = new Point(2,1);
    if(!pt1->isEqual(pt2) || pt3->isEqual(pt4) || pt2->isEqual(pt4) || pt2->isEqual(pt3)) perror("Resultats non normal | testIsEqual - Point");
    delete pt1; delete pt2; delete pt3; delete pt4;
}

void testDeplacer()
{
    Point* pt = new Point(2,2);
    pt->deplacer(2,2);
    if(pt->getAbscisse() != 4 || pt->getOrdonnee() != 4) perror("Le deplacement a echoue | testDeplacer - Point");
    delete pt;
}

void testTrouverAngle()
{
    Point* p1 = new Point(0,0);
    Point* p2 = new Point(2,2);
    Point* p3 = new Point(-1,-3);
    Point* p4 = new Point(2,0);
    if (p1->trouverAngle(p2) != 45) error ("Le calcul de l'angle n'est pas bon. | testTrouverAngle - Point");
    if (p2->trouverAngle(p1) != 225) error ("Le calcul de l'angle n'est pas bon. | testTrouverAngle - Point");
    if (p1->trouverAngle(p3) != 198) error ("Le calcul de l'angle n'est pas bon. | testTrouverAngle - Point");
    if (p1->trouverAngle(p4) != 90) error ("Le calcul de l'angle n'est pas bon. | testTrouverAngle - Point");
    delete p1;
    delete p2;
    delete p3;
    delete p4;
}


int main()
{
    testGets();
    testDistance();
    testIsEqual();
    testDeplacer();
    testTrouverAngle();
    return 0;
}