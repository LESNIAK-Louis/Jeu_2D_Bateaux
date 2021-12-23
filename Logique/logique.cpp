/**
 * \file logique.cpp
 * \brief Module qui gère la partie logique du jeu
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#include "logique.hpp"

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

bool collisionCercleRectangle(Point* centre, int rayon, Rectangle* rect)
{

    Point* temp = new Point(centre->getAbscisse(),centre->getOrdonnee());
    // On regarde de quel côté du rectangle est le cercle : 
    if (centre->getAbscisse() < rect->getTopLeft()->getAbscisse()) temp->setAbscisse(rect->getTopLeft()->getAbscisse()); // gauche
    else if (centre->getAbscisse() > rect->getTopRight()->getAbscisse()) temp->setAbscisse(rect->getTopLeft()->getAbscisse()); // droite
    if (centre->getOrdonnee() < rect->getTopLeft()->getOrdonnee()) temp->setAbscisse(rect->getTopLeft()->getOrdonnee()); // haut
    else if (centre->getOrdonnee() > rect->getBotLeft()->getOrdonnee()) temp->setAbscisse(rect->getBotLeft()->getOrdonnee()); // bas

    int distance = temp->distance(centre);
    delete temp;
    if(distance <= rayon)
        return true;
    return false;
}

bool collisionRectangles(Rectangle* r1, Rectangle* r2)
{
    return std::abs(r1->getCentre()->getAbscisse() - r2->getCentre()->getAbscisse()) <= (r1->getWeight()+r2->getWeight())/2
    && std::abs(r1->getCentre()->getOrdonnee() - r2->getCentre()->getOrdonnee()) <= (r1->getHeight()+r2->getHeight())/2;
}

bool collisionCercles(Point* ctr1, int taille1, Point* ctr2, int taille2)
{
    return (ctr1->distance(ctr2) <= (taille1 + taille2)/2);
}