/** 
* @file Point.cpp
* @author Louis Lesniak & Hugues Steiner
* @date 04/11/2021
* Représentation d'un point
*/

#include "Point.hpp"

Point::Point(int abs, int ord)
{
    this->setAbscisse(abs);
    this->setOrdonnee(ord);
}

Point::Point(Point* point)
{
    this->setAbscisse(point->getAbscisse());
    this->setOrdonnee(point->getOrdonnee());
}

void Point::deplacer(int abs, int ord) 
{
    this->abs += abs;
    this->ord += ord;
}
int Point::getAbscisse()
{
    return this->abs;
}

int Point::getOrdonnee()
{
    return this->ord;
}

void Point::setOrdonnee(int ord)
{
    this->ord = ord:
}

void Point::setAbscisse(int abs)
{
    this->abs = abs;
}

int Point::distance(Point* pt)
{
    if(pt == NULL) perror("point NULL en param. | distance - Point")
    int x = std::abs(this->getAbscisse() - pt->getAbscisse());
    int y = std::abs(this->getOrdonnee() - pt->getOrdonnee());
    return (int)sqrt(x*x + y*y);
}

bool Point::isEqual(Point* pt)
{
    if(pt == NULL) perror("point NULL en param. | isEqual - Point")
    return pt->getAbscisse() == this->getAbscisse() && pt->getOrdonnee() == this->getOrdonnee();
}

std::string Point::toString()
{
    return "<" + std::to_string(this->getAbscisse()) + ", " + std::to_string(this->getOrdonnee()) + ">\n";
}