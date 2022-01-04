#include "Menu.hpp"
#include "Game.hpp"

/* Temporaire */
#include "Logique/Class/Monde.hpp"
#include <iostream>

Monde* temporaire()
{
    Monde* monde;
    //monde = readSave("Save.txt");
    monde = new Monde(1,1, 0,1);
    monde->addFlotte(new Flotte(0, new Point(150,150), new Point(200,200), OR_INITIAL, GAIN_INITIAL,PV_MAX_BASE));
    monde->getFlotte(0)->creerBase();
    monde->addFlotte(new Flotte(1, new Point(LARGEUR_ECRAN - 150 ,HAUTEUR_ECRAN - 150), new Point(LARGEUR_ECRAN - 170 ,HAUTEUR_ECRAN - 70), OR_INITIAL,GAIN_INITIAL + 1,PV_MAX_BASE));
    monde->getFlotte(1)->creerBase();  
    monde->setIle(0, new Ile(new Point(300, 300), TAILLE_ILE1 , 1));
    
    /*monde->getFlotte(0)->newPatrouilleur();
    monde->getFlotte(1)->newPatrouilleur();
    monde->getFlotte(1)->getPatrouilleur(0)->setDestination(new Point(600,300)); */

    monde->setIleBonus(0, new IleBonus(new Point(500, 500), TAILLE_ILE2 , 1, 80, -1, 0 ,50));
    monde->getIleBonus(0)->addDefenseur(new Patrouilleur(-1,0,new Point(500, 500), new Point(500, 500), VITESSE_PATROUILLEUR,PV_MAX_PATROUILLEUR,DEGATS_PATROUILLEUR,CADENCE_TIR_PATROUILLEUR,PORTEE_PATROUILLEUR));
    monde->getIleBonus(0)->addDefenseur(new Patrouilleur(-1,1,new Point(500, 500), new Point(500, 500), VITESSE_PATROUILLEUR,PV_MAX_PATROUILLEUR,DEGATS_PATROUILLEUR,CADENCE_TIR_PATROUILLEUR,PORTEE_PATROUILLEUR));
    monde->getIleBonus(0)->addDefenseur(new Patrouilleur(-1,2,new Point(300, 150), new Point(300, 150), VITESSE_PATROUILLEUR,PV_MAX_PATROUILLEUR,DEGATS_PATROUILLEUR,CADENCE_TIR_PATROUILLEUR,PORTEE_PATROUILLEUR));
    monde->getIleBonus(0)->addDefenseur(new Patrouilleur(-1,3,new Point(300, 150), new Point(300, 150), VITESSE_PATROUILLEUR,PV_MAX_PATROUILLEUR,DEGATS_PATROUILLEUR,CADENCE_TIR_PATROUILLEUR,PORTEE_PATROUILLEUR));
    monde->getIleBonus(0)->addDefenseur(new Patrouilleur(-1,4,new Point(300, 150), new Point(300, 150), VITESSE_PATROUILLEUR,PV_MAX_PATROUILLEUR,DEGATS_PATROUILLEUR,CADENCE_TIR_PATROUILLEUR,PORTEE_PATROUILLEUR));
    monde->getIleBonus(0)->addDefenseur(new Patrouilleur(-1,5,new Point(300, 150), new Point(300, 150), VITESSE_PATROUILLEUR,PV_MAX_PATROUILLEUR,DEGATS_PATROUILLEUR,CADENCE_TIR_PATROUILLEUR,PORTEE_PATROUILLEUR));
    monde->getIleBonus(0)->addDefenseur(new Patrouilleur(-1,4,new Point(300, 150), new Point(300, 150), VITESSE_PATROUILLEUR,PV_MAX_PATROUILLEUR,DEGATS_PATROUILLEUR,CADENCE_TIR_PATROUILLEUR,PORTEE_PATROUILLEUR));
    monde->getIleBonus(0)->addDefenseur(new Patrouilleur(-1,5,new Point(300, 150), new Point(300, 150), VITESSE_PATROUILLEUR,PV_MAX_PATROUILLEUR,DEGATS_PATROUILLEUR,CADENCE_TIR_PATROUILLEUR,PORTEE_PATROUILLEUR));
    monde->getIleBonus(0)->placerDefenseur();
   
    
    
    return monde;
}
/* ####### */

int main()
{
    initSDL();
    bool arreterApplication = false;
    bool newGame =  true;
    while(!arreterApplication)
    {
        Menu* menu = new Menu(&arreterApplication, &newGame); delete menu;
        Game* jeu = new Game(&arreterApplication, &newGame); delete jeu;
    }

    quitSDL();
    return 0;
}