/** 
* \file Rectangle.cpp
* \brief Représentation d'un Rectangle
* \author Louis Lesniak & Hugues Steiner
* \date 23 Dec. 2021
*/

#include "Rectangle.hpp"

Rectangle::Rectangle(Point* r1, Point* r2)
{
    if(r1 == NULL || r2 == NULL) error("Point NULL en param | Rectangle - Rectangle");
    this->setHeight(std::abs(r1->getOrdonnee() - r2->getOrdonnee()));
    this->setWeight(std::abs(r1->getAbscisse() - r2->getAbscisse()));

    this->topLeft = new Point( ((r1->getAbscisse() < r2->getAbscisse())?(r1->getAbscisse()):(r2->getAbscisse())), ((r1->getOrdonnee() < r2->getOrdonnee())?(r1->getOrdonnee()):(r2->getOrdonnee())) );
    this->botLeft = new Point( ((r1->getAbscisse() < r2->getAbscisse())?(r1->getAbscisse()):(r2->getAbscisse())), ((r1->getOrdonnee() > r2->getOrdonnee())?(r1->getOrdonnee()):(r2->getOrdonnee())) );

    this->topRight = new Point( ((r1->getAbscisse() > r2->getAbscisse())?(r1->getAbscisse()):(r2->getAbscisse())), ((r1->getOrdonnee() < r2->getOrdonnee())?(r1->getOrdonnee()):(r2->getOrdonnee())) );
    this->botRight  = new Point( ((r1->getAbscisse() > r2->getAbscisse())?(r1->getAbscisse()):(r2->getAbscisse())), ((r1->getOrdonnee() > r2->getOrdonnee())?(r1->getOrdonnee()):(r2->getOrdonnee())) );
    this->centre = new Point(this->getTopLeft()->getAbscisse()+this->getWeight()/2, this->getTopLeft()->getOrdonnee()+this->getHeight()/2);
}

Rectangle::~Rectangle()
{
    delete this->topLeft;
    delete this->topRight;
    delete this->botLeft;
    delete this->botRight;
    delete this->centre;
}

Point* Rectangle::getTopLeft()
{
    return this->topLeft;
}

Point* Rectangle::getTopRight()
{
    return this->topRight;
}

Point* Rectangle::getBotLeft()
{
    return this->botLeft;
}

Point* Rectangle::getBotRight()
{
    return this->botRight;
}

Point* Rectangle::getCentre()
{
    return this->centre;
}

int Rectangle::getHeight()
{
    return this->height;
}

int Rectangle::getWeight()
{
    return this->weight;
}

void Rectangle::setTopLeft(Point* tl)
{
    if(tl == NULL) error("Point NULL en param | setTopLeft - Rectangle");
    if (this->topLeft != NULL) delete this->topLeft;
    this->topLeft = tl;
}

void Rectangle::setTopRight(Point* tr)
{
    if(tr == NULL) error("Point NULL en param | setTopRight - Rectangle");
    if (this->topRight != NULL) delete this->topRight;
    this->topRight = tr;
}

void Rectangle::setBotLeft(Point* bl)
{
    if(bl == NULL) error("Point NULL en param | setBotLeft - Rectangle");
    if (this->botLeft != NULL) delete this->botLeft;
    this->botLeft = bl;
}

void Rectangle::setBotRight(Point* br)
{
    if(br == NULL) error("Point NULL en param | setBotRight - Rectangle");
    if (this->botRight != NULL) delete this->botRight;
    this->botRight = br;
}

void Rectangle::setCentre(Point* c)
{
    if(c == NULL) error("Point NULL en param | setCentre - Rectangle");
    if (this->centre != NULL) delete this->centre;
    this->centre = c;
}

void Rectangle::setHeight(int height)
{
    this->height = height;
}

void Rectangle::setWeight(int weight)
{
    this->weight = weight;
}