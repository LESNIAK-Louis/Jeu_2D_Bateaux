/** 
* \file Rectangle.hpp
* \brief Représentation d'un Rectangle
* \author Louis Lesniak & Hugues Steiner
* \date 23 Dec. 2021
*/

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <string>
#include <cmath>
#include "Point.hpp"
#include "../../definitions.hpp"

class Rectangle
{
    public:
        Rectangle(Point* r1, Point* r2);
        ~Rectangle();
        
        Point* getTopLeft();
        Point* getTopRight();
        Point* getBotLeft();
        Point* getBotRight();
        Point* getCentre();
        int getHeight();
        int getWeight();

        void setTopLeft(Point* tl);
        void setTopRight(Point* tr);
        void setBotLeft(Point* bl);
        void setBotRight(Point* br);
        void setCentre(Point* c);
        void setHeight(int height);
        void setWeight(int weight);

    private:
        Point* topLeft;
        Point* topRight;
        Point* botLeft;
        Point* botRight;
        Point* centre;
        int height;
        int weight;

};

#endif