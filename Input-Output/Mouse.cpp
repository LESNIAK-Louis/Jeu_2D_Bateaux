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
    if(this->startPosMouse != NULL)
        delete this->startPosMouse;
    if(this->endPosMouse != NULL)
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
    return this->getStartPosMouse()->distance(this->getEndPosMouse()) < TAILLE_POINTEUR_SOURIS;
}

SDL_Rect* Mouse::getRectangleSelection()
{
    int height = std::abs(this->getStartPosMouse()->getOrdonnee() - this->getEndPosMouse()->getOrdonnee());
    int weight = std::abs(this->getStartPosMouse()->getAbscisse() - this->getEndPosMouse()->getAbscisse());
    
    //Top Left :
    int x = (this->getStartPosMouse()->getAbscisse() < this->getEndPosMouse()->getAbscisse())?(this->getStartPosMouse()->getAbscisse()):(this->getEndPosMouse()->getAbscisse());
    int y = (this->getStartPosMouse()->getOrdonnee() < this->getEndPosMouse()->getOrdonnee())?(this->getStartPosMouse()->getOrdonnee()):(this->getEndPosMouse()->getOrdonnee());
    
    SDL_Rect* rect = (SDL_Rect*)malloc(sizeof(SDL_Rect));
    *rect = {x,y,weight,height};
    return rect;
}

int Mouse::getAbscisse(){
    return this->getCurrentPosMouse()->getAbscisse();
}

int Mouse::getOrdonnee(){
    return this->getCurrentPosMouse()->getOrdonnee();
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
        this->setStartPosMouse(this->getCurrentPosMouse());
        this->setIsSelecting(true);
    }
}

void Mouse::updateSelection()
{
    if(this->isSelecting())
        this->setEndPosMouse(this->getCurrentPosMouse());
}

void Mouse::endSelection()
{
    if(this->isSelecting())
    {
        this->setEndPosMouse(this->getCurrentPosMouse());
        this->setIsSelecting(false);
    }
}

bool Mouse::estEnCollisionAvec(SDL_Rect rect){
    return (this->getAbscisse() >= rect.x && this->getAbscisse() <= rect.x + rect.w && this->getOrdonnee() >= rect.y && this->getOrdonnee() <= rect.y + rect.h ) ;
}

/*bool Mouse::collisionAvecSelection(Point* centre, int rayon)
{
    SDL_Rect* rect = this->getRectangleSelection();
    Point* temp = new Point(centre->getAbscisse(),centre->getOrdonnee());
    // On regarde de quel côté du rectangle est le cercle : 
    if (centre->getAbscisse() < rect->x) temp->setAbscisse(rect->x); // gauche
    else if (centre->getAbscisse() > rect->x + rect->w) temp->setAbscisse(rect->x); // droite
    if (centre->getOrdonnee() < rect->y) temp->setAbscisse(rect->y); // haut
    else if (centre->getOrdonnee() > rect->y + rect->h) temp->setAbscisse(rect->y + rect->h); // bas

    int distance = temp->distance(centre);
    delete temp;
    free(rect);
    if(distance <= rayon)
        return true;
    return false;
}*/

bool Mouse::collisionAvecSelection(Point* centre)
{
    SDL_Rect* rect = this->getRectangleSelection();
    return (centre->getAbscisse() >= rect->x && centre->getAbscisse() <= rect->x + rect->w && centre->getOrdonnee() >= rect->y && centre->getOrdonnee() <= rect->y + rect->h);
}
