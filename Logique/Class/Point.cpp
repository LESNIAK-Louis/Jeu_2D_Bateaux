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

void Point::copierPoint(Point* point){
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
    return round(sqrt((double)x*x + (double)y*y));
}

bool Point::isEqual(Point* pt)
{
    if(pt == NULL) error("point NULL en param. | isEqual - Point");
    return pt->getAbscisse() == this->getAbscisse() && pt->getOrdonnee() == this->getOrdonnee();
}


int Point::trouverAngle(Point* p2){
   if ((double)(p2->getOrdonnee() - this->getOrdonnee() == 0)){ // les points ont à la même hauteur
        if (this->getAbscisse() <= p2->getAbscisse()){
            return 90;
        }else {
            return 270;
        }
    }
    if (this->getAbscisse() == p2->getAbscisse()) { //les points sont l'un en dessous de l'autre
        if (this->getOrdonnee() <= p2->getOrdonnee()){
            return 180;
        }else {
            return 0;
        }
    }
    double param = ((double)(p2->getAbscisse() - this->getAbscisse())) / ((double)(p2->getOrdonnee() - this->getOrdonnee()));
    if (param<0){
        param = -param;
    }
    double angle = std::atan( param  );
    angle *= (180/PI);
    if (p2->getAbscisse() >= this->getAbscisse() && p2->getOrdonnee() > this->getOrdonnee() ){ //p2 est en bas à droite de p1
        angle = 180-angle;
    }
    if (p2->getAbscisse() <= this->getAbscisse() && p2->getOrdonnee() > this->getOrdonnee()){ //p2 est en bas à gauche de p1
        angle += 180;
    }
    if (p2->getAbscisse() < this->getAbscisse() && p2->getOrdonnee() < this->getOrdonnee()){ //p2 est en haut à gauche de p1
        angle = 360-angle;
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