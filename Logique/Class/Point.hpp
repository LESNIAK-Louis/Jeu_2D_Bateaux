/** 
* @file Point.hpp
* @author Louis Lesniak & Hugues Steiner
* @date 04/11/2021
* Représentation d'un Point
*/

#ifndef POINT
#define POINT

#include <string>
#include <cmath>

class Point
{
    public:
        Point(int abs, int ord);
        Point(Point* point);
        void deplacer(int abs, int ord);
        int getOrdonnee();
        int getAbscisse();

        int setOrdonnee(int ord);
        int setAbscisse(int abs);

        int distance(Point* pt);
        bool isEqual(Point* pt);
        
        std::string toString();

    private:
        int abs;
        int ord;

};

#endif