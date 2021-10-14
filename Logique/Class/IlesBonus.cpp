/**file Iles.cpp
*@author Louis Lesniak & Hugues Steiner
*date 14/09/2021
*Definition des fonctions propres aux iles
*/

#include "Iles.hpp"

//Constructeur
Iles::Iles(int abs, int ord, int t, int f)
{
    this->centre = new Point(abs, ord);
    this->taille = t;
    this->forme = f;
}

Point Iles::getCentre()
{
    return this->centre;
}

int Iles::getTaille()
{
    return this->taille;
}

int Iles::getForme()
{
    return this->forme;
}