#include "Point.hpp"

Point::Point(int abs, int ord)
{
    this->abs = abs;
    this->ord = ord;
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

int Point::distance(Point* pt)
{
    int x = std::abs(this->getAbscisse() - pt->getAbscisse());
    int y = std::abs(this->getOrdonnee() - pt->getOrdonnee());
    return (int)sqrt(x*x + y*y);
}

bool Point::isEqual(Point* pt)
{
    return pt->getAbscisse() == this->getAbscisse() && pt->getOrdonnee() == this->getOrdonnee();
}

std::string Point::toString()
{
    return "<" + std::to_string(this->getAbscisse()) + ", " + std::to_string(this->getOrdonnee()) + ">\n";
}