/**
 * \file logique.cpp
 * \brief Module qui gère la partie logique du jeu
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#include "logique.hpp"

void moveSelectedShips(Monde* monde, int x, int y)
{
    for(int i = 0; i < monde->getNbFlottes(); i++)
    {
        for(int j = 0; j < monde->getFlotte(i)->getNbPatrouilleurs(); j++)
        {
            if(monde->getFlotte(i)->getPatrouilleur(j)->getIsSelected())
                monde->getFlotte(i)->getPatrouilleur(j)->getCentre()->deplacer(x,y);
        }
    }
}