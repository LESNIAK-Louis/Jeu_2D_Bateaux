/**
 * \file logique.cpp
 * \brief Module qui gère la partie logique du jeu
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#include "logique.hpp"


void pathFinding(Navire* navire, Ile* ile){
    int theta = 0;
    int anglePatIle = navire->getCentre()->trouverAngle(ile->getCentre());
    int anglePatrouilleur = navire->getAngle();
    double rayonIle = (TAILLE_ILE1)/2; 
    double distancePatIle = navire->getCentre()->distance(ile->getCentre());
    double param = rayonIle/distancePatIle;
    double angleTemp = std::asin(param) ;
    angleTemp *= (180/PI);
    int angleIncidenceMin = (int)ceil(angleTemp);
    angleIncidenceMin += 365;
    angleIncidenceMin %= 360;
    int angleIncidence = anglePatIle - anglePatrouilleur;
    float distTangente = sqrt(distancePatIle * distancePatIle - rayonIle * rayonIle);
    int absPat = navire->getAbscisse();
    int ordPat = navire->getOrdonnee();
    bool col = false;
    if (angleIncidence < angleIncidenceMin && angleIncidence >= 0) {
        //esquive en passant à gauche de l'ile (du point de vue du patrouilleur)
        theta = anglePatIle - angleIncidenceMin;
        theta += 360;
        theta %= 360;
        theta *= (PI/180);
        int absWayPoint = round(distTangente * sin(theta) + absPat);
        int ordWayPoint = round(ordPat - distTangente * cos(theta));
        navire->setWayPoint(new Point(absWayPoint, ordWayPoint));
        col = true;
    }
    if (angleIncidence > -angleIncidenceMin && angleIncidence < 0) {
        //esquive en passant à droite de l'ile (du point de vue du patrouilleur)
        theta = 180 - anglePatIle - angleIncidenceMin;
        theta += 360;
        theta %= 360;
        theta *= (PI/180);
        int absWayPoint = round(distTangente * sin(theta) + absPat);
        int ordWayPoint = round(ordPat + distTangente * cos(theta));
        navire->setWayPoint(new Point(absWayPoint, ordWayPoint));
        col = true;
    }  
    //Cette partie est pour le debuggage
    /*if (col && navire->estEnCollisionAvec(TAILLE_ILE1+10, ile->getCentre())){
        printf("\n#########COLLLISION!!!!!!!#######################\n");
        //if (theta < 0) {theta += 360;}
        theta += 360;
        theta %= 360;
        printf("Coordonnees patrouilleur = < %i , %i >\n", ile->getAbscisse(), ile->getOrdonnee());
        printf("Coordonnees ile = < %i , %i >\n", absPat, ordPat);
        printf("distTangente = %f\n", distTangente);
        printf("anglePatrouilleur = %i\n ", anglePatrouilleur);
        printf("anglePatIle = %i\n", anglePatIle);
        printf("\n angleIncidenceMin = %i\n", angleIncidenceMin);
        printf("\n angleIncidence = %i\n", angleIncidence);
        printf("theta = %i\n",theta);
    }*/

}
void moveShips(Monde* monde){
    for (int f = 0; f < monde->getNbFlottes(); f++){
        for (int p = 0; p < monde->getFlotte(f)->getNbPatrouilleurs(); p++) {  
            if (monde->getFlotte(f)->getPatrouilleur(p)->isMoving()){
                //Permet d'éviter la collision avec une ile
                for (int i = 0; i < monde->getNbIles(); i++) {
                    if (monde->getFlotte(f)->getPatrouilleur(p)->estEnCollisionAvec(TAILLE_ILE1+80, monde->getIle(i)->getCentre()) /*&& !monde->getFlotte(f)->getPatrouilleur(p)->estEnCollisionAvec(50-TAILLE_PATROUILLEUR, monde->getFlotte(f)->getPatrouilleur(p)->getDestination())*/ ) {
                        pathFinding(monde->getFlotte(f)->getPatrouilleur(p), monde->getIle(i));
                    }   
                }
                monde->getFlotte(f)->getPatrouilleur(p)->avancer(0);
                
            }
        }
    }
}


bool collisionCercles(Point* ctr1, int taille1, Point* ctr2, int taille2)
{
    return (ctr1->distance(ctr2) <= (taille1 + taille2)/2);
}