#include "../Point.hpp"
#include <cassert>

void testGets()
{
    Point* pt = new Point(3,2);
    assert(pt->getAbscisse() == 3 && pt->getOrdonnee() == 2);

}

void testDistance()
{
    Point* pt1 = new Point(2,2);
    Point* pt2 = new Point(4,4);
    assert(pt1->distance(pt2) == 2);
    free(pt1); free(pt2);
}

void testIsEqual()
{
    Point* pt1 = new Point(2,2);
    Point* pt2 = new Point(2,2);
    Point* pt3 = new Point(1,2);
    Point* pt4 = new Point(2,1);
    assert(pt1->isEqual(pt2) && !(pt3->isEqual(pt4)) && !(pt2->isEqual(pt4)) && !(pt2->isEqual(pt3)));
    free(pt1); free(pt2); free(pt3); free(pt4);
}

void testDeplacer()
{
    Point* pt = new Point(2,2);
    pt->deplacer(2,2);
    assert(pt->getAbscisse() == 4 && pt->getOrdonnee() == 4);
    free(pt);
}


int main()
{
    testGets();
    testDistance();
    testIsEqual();
    testDeplacer();
    return 0;
}