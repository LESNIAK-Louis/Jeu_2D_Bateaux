/**
 * \file Mouse.cpp
 * \brief Etat de la souris
 * \author Louis Lesniak & Hugues Steiner
 * \date 22 Dec. 2021
*/

#include "Mouse.hpp"

Mouse::Mouse()
{
    this->selecting = false;
    this->startPosMouse = NULL;
    this->endPosMouse = NULL;
}

Mouse::~Mouse()
{
    delete this->startPosMouse;
    delete this->endPosMouse;
}

Point* Mouse::getStartPosMouse()
{
    return this->startPosMouse;
}

Point* Mouse::getEndPosMouse()
{
    return this->endPosMouse;
}

Point* Mouse::getCurrentPosMouse()
{
    int x;
    int y;
    SDL_GetMouseState(&x, &y);
    return new Point(x,y);
}

bool Mouse::isSelecting()
{
    return this->selecting;
}

bool Mouse::isSimpleClick()
{
    return this->getStartPosMouse()->distance(this->getEndPosMouse()) == 0;
}

Rectangle* Mouse::getRectangleSelection()
{
    return new Rectangle(this->getStartPosMouse(), this->getEndPosMouse());
}

void Mouse::setStartPosMouse(Point* point)
{
    if(point == NULL) error("Point NULL en param | setStartPosMouse - Mouse");
    if (this->startPosMouse != NULL) delete this->startPosMouse;
    this->startPosMouse = point;
}

void Mouse::setEndPosMouse(Point* point)
{
    if(point == NULL) error("Point NULL en param | setEndPosMouse - Mouse");
    if (this->endPosMouse != NULL) delete this->endPosMouse;
    this->endPosMouse = point;
}

void Mouse::setIsSelecting(bool isSelecting)
{
    this->selecting = isSelecting;
}

void Mouse::startSelection()
{
    if(!this->isSelecting())
    {
        this->setStartPosMouse(getCurrentPosMouse());
        this->setIsSelecting(true);
    }
}

void Mouse::updateSelection()
{
    if(this->isSelecting())
        this->setEndPosMouse(getCurrentPosMouse());
}

void Mouse::endSelection()
{
    if(this->isSelecting())
    {
        this->setEndPosMouse(getCurrentPosMouse());
        this->setIsSelecting(false);
    }
}
