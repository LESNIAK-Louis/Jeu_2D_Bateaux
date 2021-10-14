#ifndef POINT
#define POINT

#include <string>
#include <cmath>

class Point
{
    public:
        Point(int abs, int ord);
        void deplacer(int abs, int ord);
        int getOrdonnee();
        int getAbscisse();
        int distance(Point* pt);
        bool isEqual(Point* pt);
        std::string toString();

    private:
        int abs;
        int ord;

};

#endif