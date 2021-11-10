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
    delete[] pt;
}

void testDistance()
{
    Point* pt1 = new Point(2,2);
    Point* pt2 = new Point(4,4);
    if(pt1->distance(pt2) != 2) perror("La distance n'est pas la bonne | testDistance - Point");
    delete[] pt1; delete[] pt2;
}

void testIsEqual()
{
    Point* pt1 = new Point(2,2);
    Point* pt2 = new Point(2,2);
    Point* pt3 = new Point(1,2);
    Point* pt4 = new Point(2,1);
    if(!pt1->isEqual(pt2) || pt3->isEqual(pt4) || pt2->isEqual(pt4) || pt2->isEqual(pt3)) perror("Resultats non normal | testIsEqual - Point");
    delete[] pt1; delete[] pt2; delete[] pt3; delete[] pt4;
}

void testDeplacer()
{
    Point* pt = new Point(2,2);
    pt->deplacer(2,2);
    if(pt->getAbscisse() != 4 || pt->getOrdonnee() != 4) perror("Le deplacement a echoue | testDeplacer - Point");
    delete[] pt;
}


int main()
{
    testGets();
    testDistance();
    testIsEqual();
    testDeplacer();
    return 0;
}