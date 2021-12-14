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

void moveShips(Monde* monde){
    for (int f = 0; f < monde->getNbFlottes(); f++){
        for (int p = 0; p < monde->getFlotte(f)->getNbPatrouilleurs(); p++) {
            if (monde->getFlotte(f)->getPatrouilleur(p)->isMoving()){
                monde->getFlotte(f)->getPatrouilleur(p)->avancer();
            }
            /*for (int i = 0; i < monde->getNbIles(); i++) {
                while
            }*/
        }
    }
}

void unSelectAll(Monde* monde)
{
    for(int i = 0; i < monde->getNbFlottes(); i++)
    {
        for(int j = 0; j < monde->getFlotte(i)->getNbPatrouilleurs(); j++)
        {
            if(monde->getFlotte(i)->getPatrouilleur(j)->getIsSelected())
                monde->getFlotte(i)->getPatrouilleur(j)->setIsSelected(false);
        }
    }
}