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
        SDL_Rect* getRectangleSelection();
        int getAbscisse();
        int getOrdonnee();
        bool isSelecting();
        bool isSimpleClick();

        void setStartPosMouse(Point* point);
        void setEndPosMouse(Point* point);
        void setIsSelecting(bool isSelecting);

        void startSelection();
        void updateSelection();
        void endSelection();

        /**
         * @brief Determine si la souris est dans un rectangle
         * @param rect 
         */
        bool estEnCollisionAvec(SDL_Rect rect);

        /**
         * @brief Determine si le cercle passé en parametre est en collision avec le rectangle de selection
         * @param centre centre du cercle
         * @param rayon rayon du cercle
         */
        bool collisionAvecSelection(Point* centre, int rayon);
};


#endif