/**
 * \file logique.cpp
 * \brief Module qui gère la partie logique du jeu
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#include "logique.hpp"


void pathFinding(Navire* navire, Point* centreIle, int tailleIle){
    int theta = 0;
    int angleNavIle = navire->getCentre()->trouverAngle(centreIle);
    int angleNavire = navire->getAngle();
    double rayonIle = (tailleIle)/2; 
    double distanceNavIle = navire->getCentre()->distance(centreIle);
    double param = rayonIle/distanceNavIle;
    double angleTemp = std::asin(param) ;
    angleTemp *= (180/PI);
    int angleIncidenceMin = (int)ceil(angleTemp);
    angleIncidenceMin += 365;
    angleIncidenceMin %= 360;
    int angleIncidence = angleNavIle - angleNavire;
    float distTangente = sqrt(distanceNavIle * distanceNavIle - rayonIle * rayonIle);
    int absNav = navire->getAbscisse();
    int ordNav = navire->getOrdonnee();
    //bool col = false;
    if (angleIncidence < angleIncidenceMin && angleIncidence >= 0) {
        //esquive en passant à gauche de l'ile (du point de vue du navire)
        theta = angleNavIle - angleIncidenceMin;
        theta += 360;
        theta %= 360;
        theta *= (PI/180);
        int absWayPoint = round(distTangente * sin(theta) + absNav);
        int ordWayPoint = round(ordNav - distTangente * cos(theta));
        Point* waypoint = new Point(absWayPoint, ordWayPoint);
        navire->setWayPoint(waypoint);
        if(waypoint != NULL)
            delete waypoint;
        //col = true;
    }
    if (angleIncidence > -angleIncidenceMin && angleIncidence < 0) {
        //esquive en passant à droite de l'ile (du point de vue du navire)
        theta = 180 - angleNavIle - angleIncidenceMin;
        theta += 360;
        theta %= 360;
        theta *= (PI/180);
        int absWayPoint = round(distTangente * sin(theta) + absNav);
        int ordWayPoint = round(ordNav + distTangente * cos(theta));
        Point* waypoint = new Point(absWayPoint, ordWayPoint);
        navire->setWayPoint(waypoint);
        if(waypoint != NULL)
            delete waypoint;
        //col = true;
    }  
    //Cette partie est pour le debuggage
    /*if (col && navire->estEnCollisionAvec(TAILLE_ILE1+10, ile->getCentre())){
        printf("\n#########COLLLISION!!!!!!!#######################\n");
        //if (theta < 0) {theta += 360;}
        theta += 360;
        theta %= 360;
        printf("Coordonnees navire = < %i , %i >\n", centreIle->getAbscisse(), centreIle->getOrdonnee());
        printf("Coordonnees ile = < %i , %i >\n", absNav, ordNav);
        printf("distTangente = %f\n", distTangente);
        printf("angleNavire = %i\n ", angleNavire);
        printf("angleNavIle = %i\n", angleNavIle);
        printf("\n angleIncidenceMin = %i\n", angleIncidenceMin);
        printf("\n angleIncidence = %i\n", angleIncidence);
        printf("theta = %i\n",theta);
    }*/

}
void moveShips(Monde* monde){
    for (int f = 0; f < monde->getNbFlottes(); f++){
        for (int p = 0; p < monde->getFlotte(f)->getNbNavires(); p++) {  
            if (monde->getFlotte(f)->getNavire(p)->isMoving()){
                //Permet d'éviter la collision avec une ile
                for (int i = 0; i < monde->getNbIles(); i++) {
                    if (monde->getFlotte(f)->getNavire(p)->estEnCollisionAvec(monde->getIle(i)->getTaille()+80, monde->getIle(i)->getCentre()) /*&& !monde->getFlotte(f)->getNavire(p)->estEnCollisionAvec(50-TAILLE_Navire, monde->getFlotte(f)->getNavire(p)->getDestination())*/ ) {
                        pathFinding(monde->getFlotte(f)->getNavire(p), monde->getIle(i)->getCentre(), monde->getIle(i)->getTaille());
                    }   
                }
                for (int i = 0; i < monde->getNbIlesBonus(); i++) {
                    if (monde->getFlotte(f)->getNavire(p)->estEnCollisionAvec(monde->getIleBonus(i)->getTaille()+80, monde->getIleBonus(i)->getCentre()) /*&& !monde->getFlotte(f)->getNavire(p)->estEnCollisionAvec(50-TAILLE_Navire, monde->getFlotte(f)->getNavire(p)->getDestination())*/ ) {
                        pathFinding(monde->getFlotte(f)->getNavire(p), monde->getIleBonus(i)->getCentre(), monde->getIleBonus(i)->getTaille());
                    }   
                }
                //Evite la collision avec une base
                for (int i = 0; i < monde->getNbFlottes(); i++){
                    if (monde->getFlotte(f)->getNavire(p)->estEnCollisionAvec(TAILLE_BASE+80,monde->getFlotte(i)->getCoordBase()) /*&& !monde->getFlotte(f)->getNavire(p)->estEnCollisionAvec(50-TAILLE_Navire, monde->getFlotte(f)->getNavire(p)->getDestination())*/ ) {
                        pathFinding(monde->getFlotte(f)->getNavire(p), monde->getFlotte(i)->getCoordBase(), TAILLE_BASE/2);
                    } 
                }
                monde->getFlotte(f)->getNavire(p)->avancer(0);
                
            }
        }
    }
}

void tirsBateaux(Monde* monde, unsigned int currentTime)
{
    
    for(int i = 0; i < monde->getNbFlottes(); i++) // Le tir depuis les flottes
    {
        for(int j = 0; j < monde->getFlotte(i)->getNbNavires(); j++)
        {
            bool shot = false;
            // Tir sur flotte adverse 
            for(int k = 0; k < monde->getNbFlottes(); k++)
            {
                if(k != i)
                {
                    for(int l = 0; l < monde->getFlotte(k)->getNbNavires(); l++)
                    {
                        if(monde->getFlotte(i)->getNavire(j)->peutTirer(currentTime))
                        {
                            if(monde->getFlotte(i)->getNavire(j)->estEnCollisionAvec(monde->getFlotte(i)->getNavire(j)->getPortee() + monde->getFlotte(k)->getNavire(l)->getTaille()/2, monde->getFlotte(k)->getNavire(l)->getCentre()))
                            {
                                monde->getFlotte(k)->getNavire(l)->ajouterPV(-monde->getFlotte(i)->getNavire(j)->getDegatArme());
                                if(monde->getFlotte(k)->getNavire(l)->getPv() <= 0) 
                                {
                                    monde->getFlotte(k)->removeNavire(l);
                                    if (monde->getFlotte(k)->getNavire(l)->getType().compare("Base") == 0)
                                    {
                                        switch (k) 
                                        {
                                            case 0:
                                                monde->setVainqueur("Bot");
                                                break;
                                            default:
                                                monde->setVainqueur("Joueur");
                                                break;
                                        }
                                    }
                                }
                                    
                                shot = true;
                                break;
                            }
                        }
                    }
                    if(shot)
                    { 
                        monde->getFlotte(i)->getNavire(j)->setDernierTir(currentTime);
                        break;
                    }
                }
            }
            if(!shot)
            {
                // Tir sur IleBonus
                for(int k = 0; k < monde->getNbIlesBonus(); k++)
                {
                    for(int l = 0; l < monde->getIleBonus(k)->getNbDefenseur(); l++)
                    {
                        if(monde->getFlotte(i)->getNavire(j)->peutTirer(currentTime))
                        {
                            if(monde->getFlotte(i)->getNavire(j)->estEnCollisionAvec(monde->getFlotte(i)->getNavire(j)->getPortee() + monde->getIleBonus(k)->getDefenseur(l)->getTaille()/2, monde->getIleBonus(k)->getDefenseur(l)->getCentre()))
                            {
                                monde->getIleBonus(k)->getDefenseur(l)->ajouterPV(-monde->getFlotte(i)->getNavire(j)->getDegatArme());
                                if(monde->getIleBonus(k)->getDefenseur(l)->getPv() <= 0)
                                    monde->getIleBonus(k)->removeDefenseur(monde->getIleBonus(k)->getDefenseur(l));
                                shot = true;
                                break;
                            }
                        }
                    }
                    if(shot)
                    {
                        monde->getFlotte(i)->getNavire(j)->setDernierTir(currentTime);
                        break;
                    }
                }
            }
        }
    }
   
    for(int i = 0; i < monde->getNbIlesBonus(); i++) // Le tir depuis les iles bonus
    {
        for(int j = 0; j < monde->getIleBonus(i)->getNbDefenseur(); j++)
        {
            if(monde->getIleBonus(i)->getDefenseur(j)->peutTirer(currentTime))
            {
                
                bool shot = false;
                for(int k = 0; k < monde->getNbFlottes(); k++)
                {
                    for(int l = 0; l < monde->getFlotte(k)->getNbNavires(); l++)
                    {
                        if(monde->getIleBonus(i)->getDefenseur(j)->estEnCollisionAvec(monde->getIleBonus(i)->getDefenseur(j)->getPortee(), monde->getFlotte(k)->getNavire(l)->getCentre()))
                        {
                            
                            monde->getFlotte(k)->getNavire(l)->ajouterPV(-monde->getIleBonus(i)->getDefenseur(j)->getDegatArme());
                            if(monde->getFlotte(k)->getNavire(l)->getPv() <= 0)
                                monde->getFlotte(k)->removeNavire(l);
                            shot = true;
                            
                        }
                    }
                    if(shot)
                    {
                        monde->getIleBonus(i)->getDefenseur(j)->setDernierTir(currentTime);
                        break;
                    }
                }
            }
        }
    }
}


bool collisionCercles(Point* ctr1, int taille1, Point* ctr2, int taille2)
{
    return (ctr1->distance(ctr2) <= (taille1 + taille2)/2);
}