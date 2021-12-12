/** 
* \file Point.cpp
* \brief Représentation d'un point
* \author Louis Lesniak & Hugues Steiner
* \date 10 Nov. 2021
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

void Point::deplacer(int delta_abs, int delta_ord) 
{
    this->abs += delta_abs;
    this->ord += delta_ord;
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
    this->ord = ord;
}

void Point::setAbscisse(int abs)
{
    this->abs = abs;
}

int Point::distance(Point* pt)
{
    if(pt == NULL) error("point NULL en param. | distance - Point");
    int x = std::abs(this->getAbscisse() - pt->getAbscisse());
    int y = std::abs(this->getOrdonnee() - pt->getOrdonnee());
    return (int)sqrt(x*x + y*y);
}

bool Point::isEqual(Point* pt)
{
    if(pt == NULL) error("point NULL en param. | isEqual - Point");
    return pt->getAbscisse() == this->getAbscisse() && pt->getOrdonnee() == this->getOrdonnee();
}


int Point::trouverAngle(Point* p2){
    if (this->getOrdonnee() == p2->getOrdonnee()){ // les points ont à la même hauteur
        if (this->getAbscisse() <= p2->getAbscisse()){
            return 90;
        }else {
            return 270;
        }
    }
    double angle = std::atan( ((double) (p2->getAbscisse() - this->getAbscisse())) / ((double)(p2->getOrdonnee() - this->getOrdonnee()))  );
    angle *= (180/3.1415);
    if (p2->getAbscisse() >= this->getAbscisse() && p2->getOrdonnee() > this->getOrdonnee() ){ //p2 est en bas à droite de p1
        angle += 90;
    }
    if (p2->getAbscisse() <= this->getAbscisse() && p2->getOrdonnee() > this->getOrdonnee()){ //p2 est en bas à gauche de p1
        angle += 180;
    }
    if (p2->getAbscisse() < this->getAbscisse() && p2->getOrdonnee() < this->getOrdonnee()){ //p2 est en haut à gauche de p1
        angle += 270;
    }
    return round(angle);
}


std::string Point::toString()
{
    return "<" + std::to_string(this->getAbscisse()) + ", " + std::to_string(this->getOrdonnee()) + ">\n";
}

std::string Point::formattedInfo()
{
    return "<" + std::to_string(this->getAbscisse()) + ";" + std::to_string(this->getOrdonnee()) + ">";
}