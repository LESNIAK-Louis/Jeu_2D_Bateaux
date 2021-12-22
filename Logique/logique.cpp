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
                //Permet d'éviter la collision avec une ile
                for (int i = 0; i < monde->getNbIles(); i++) {
                    if (monde->getFlotte(f)->getPatrouilleur(p)->estEnCollisionAvec(TAILLE_ILE1 , monde->getIle(i)->getCentre()) ) {
                        int angleRelatif = monde->getFlotte(f)->getPatrouilleur(p)->getCentre()->trouverAngle(monde->getIle(i)->getCentre()) - monde->getFlotte(f)->getPatrouilleur(p)->getAngle();
                        if (angleRelatif > 0 && angleRelatif < 90){
                            monde->getFlotte(f)->getPatrouilleur(p)->modifierAngle(-90);
                        }
                        if (angleRelatif > -90 && angleRelatif <= 0){
                            monde->getFlotte(f)->getPatrouilleur(p)->modifierAngle(90);
                        }
                    }
                }
                monde->getFlotte(f)->getPatrouilleur(p)->avancer();
            }
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