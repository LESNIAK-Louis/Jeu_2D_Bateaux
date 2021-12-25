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
                int deltaAngle = 0;
                for (int i = 0; i < monde->getNbIles(); i++) {
                    
                    if (monde->getFlotte(f)->getPatrouilleur(p)->estEnCollisionAvec(TAILLE_ILE1+50, monde->getIle(i)->getCentre()) /*&& !monde->getFlotte(f)->getPatrouilleur(p)->estEnCollisionAvec(50-TAILLE_PATROUILLEUR, monde->getFlotte(f)->getPatrouilleur(p)->getDestination())*/ ) {
                        int anglePatIle = monde->getFlotte(f)->getPatrouilleur(p)->getCentre()->trouverAngle(monde->getIle(i)->getCentre());
                        int anglePatrouilleur = monde->getFlotte(f)->getPatrouilleur(p)->getAngle();
                        //if (anglePatrouilleurIle > 180){ anglePatrouilleurIle = 360 - anglePatrouilleurIle;}
                        //printf("AnglePat = %i \n", anglePat);
                        double tailleIle = TAILLE_ILE1; 
                        double distancePatIle = monde->getFlotte(f)->getPatrouilleur(p)->getCentre()->distance(monde->getIle(i)->getCentre());
                        double param = tailleIle/(2*distancePatIle);
                        double angleTemp = std::atan((double)param) ;
                        angleTemp *= (180/PI);
                        int angleIncidenceMin = (int)ceil(angleTemp);
                        int angleIncidence = anglePatIle - anglePatrouilleur;
                        angleIncidence += 360;
                        angleIncidence %= 360;
                        
                        float hypo = sqrt(tailleIle * tailleIle + distancePatIle * distancePatIle);
                        int theta = anglePatIle;
                        int absPat = monde->getFlotte(f)->getPatrouilleur(p)->getAbscisse();
                        int ordPat = monde->getFlotte(f)->getPatrouilleur(p)->getOrdonnee();
                        bool col = false;
                        if (angleIncidence < angleIncidenceMin && angleIncidence >= 0) {
                            //esquive en passant à gauche de l'ile (du point de vue du patrouilleur)
                            theta -= angleIncidenceMin-5;
                            col = true;
                        }
                        if (angleIncidence > -angleIncidenceMin && angleIncidence < 0) {
                            //esquive en passant à droite de l'ile (du point de vue du patrouilleur)
                            theta += angleIncidenceMin+5;
                            col = true;
                        }  
                        if (col){
                            printf("COLLISION INC !!!!!!\n");
                            theta += 360;
                            theta %= 360;
                            printf("Coordonnees patrouilleur = < %i , %i >\n", absPat, ordPat);
                            printf("Hypo = %f\n", hypo);
                            printf("\n angleIncidenceMin = %i\n", angleIncidenceMin);
                            printf("anglePatrouilleur = %i\n ", anglePatrouilleur);
                            printf("anglePatIle = %i\n", anglePatIle);
                            printf("theta = %i\n",theta);
                            theta *= (PI/180);

                            int absWayPoint = round(hypo * sin(theta) + absPat);
                            int ordWayPoint = round(ordPat - hypo * cos(theta));
                            printf("Coordonnees wayPoint = < %i , %i >\n", absWayPoint, ordWayPoint);
                            monde->getFlotte(f)->getPatrouilleur(p)->setWayPoint(new Point(absWayPoint, ordWayPoint));

                        }
                    }   
                }
                monde->getFlotte(f)->getPatrouilleur(p)->avancer(0);
                
            }
        }
    }
}


/*
 printf("AnglePatrouilleurIle = %i \n", anglePatrouilleurIle);
                        printf("AnglePat = %i \n", anglePat);
                        printf("Angle relatif = %i\n\n", angleRelatif);
                        if ((angleRelatif >= 5 && angleRelatif < 90) || angleRelatif >270 ){
                            deltaAngle = -80;
                        }
                        if ((angleRelatif > -90 && angleRelatif <0) || (angleRelatif < -270)){
                            deltaAngle = 80;
                        }

*/

void unSelectAll(Monde* monde)
{
    /*for(int i = 0; i < monde->getNbFlottes(); i++)
    {
        for(int j = 0; j < monde->getFlotte(i)->getNbPatrouilleurs(); j++)
        {
            if(monde->getFlotte(i)->getPatrouilleur(j)->getIsSelected())
                monde->getFlotte(i)->getPatrouilleur(j)->setIsSelected(false);
        }
    }*/
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