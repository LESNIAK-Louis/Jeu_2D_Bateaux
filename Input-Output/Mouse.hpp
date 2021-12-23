/**
 * \file Mouse.hpp
 * \brief Etat de la souris
 * \author Louis Lesniak & Hugues Steiner
 * \date 22 Dec. 2021
*/

#ifndef MOUSE_HPP
#define MOUSE_HPP

#include <SDL2/SDL.h>
#include "../Logique/Class/Point.hpp"
#include "../Logique/Class/Rectangle.hpp"
#include "../definitions.hpp"

class Mouse
{
    protected :
        Point* startPosMouse;
        Point* endPosMouse;
        bool selecting;

    public : 
        Mouse();
        ~Mouse();

        Point* getStartPosMouse();
        Point* getEndPosMouse();
        Point* getCurrentPosMouse();
        Rectangle* getRectangleSelection();
        bool isSelecting();
        bool isSimpleClick();

        void setStartPosMouse(Point* point);
        void setEndPosMouse(Point* point);
        void setIsSelecting(bool isSelecting);

        void startSelection();
        void updateSelection();
        void endSelection();
};


#endif