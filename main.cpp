#include "Graphique/fonctions_SDL.hpp"
#include "Graphique/jeu.hpp"
#include "Graphique/menu.hpp"
#include "Logique/Class/Monde.hpp"
#include "Input-Output/input.hpp"
#include "Logique/logique.hpp"
#include "Input-Output/fichier.hpp"
#include "Game.hpp"

#include <iostream>

int main()
{
    initSDL();
    Monde* monde;
    //monde = readSave("Save.txt");
    monde = new Monde(1,1, 0,1);
    monde->addFlotte(new Flotte(0, new Point(50,50), new Point(200,200), OR_INITIAL, GAIN_INITIAL,PV_MAX_FLOTTE));
    monde->addFlotte(new Flotte(1, new Point(400,400), new Point(400,400), 0,10,500));
    monde->setIle(0, new Ile(new Point(300, 300), TAILLE_ILE1 , 1));
    
    monde->getFlotte(0)->newPatrouilleur();
    monde->getFlotte(0)->setNbPatrouilleurs(1);
    monde->getFlotte(1)->newPatrouilleur();
    monde->getFlotte(1)->setNbPatrouilleurs(1);

    monde->setIleBonus(0, new IleBonus(new Point(500, 500), TAILLE_ILE2 , 1, 80, -1, 0 ,50));
    monde->getIleBonus(0)->addDefenseur(new Patrouilleur(-1,0,new Point(500, 500), new Point(500, 500), 50,50,50,2,50));
    monde->getIleBonus(0)->addDefenseur(new Patrouilleur(-1,1,new Point(500, 500), new Point(500, 500), 50,50,50,2,50));
    monde->getIleBonus(0)->addDefenseur(new Patrouilleur(-1,2,new Point(300, 150), new Point(300, 150), 50,50,50,2,50));
    monde->getIleBonus(0)->addDefenseur(new Patrouilleur(-1,3,new Point(300, 150), new Point(300, 150), 50,50,50,2,50));
    monde->getIleBonus(0)->addDefenseur(new Patrouilleur(-1,4,new Point(300, 150), new Point(300, 150), 50,50,50,2,50));
    monde->getIleBonus(0)->addDefenseur(new Patrouilleur(-1,5,new Point(300, 150), new Point(300, 150), 50,50,50,2,50));
    monde->getIleBonus(0)->addDefenseur(new Patrouilleur(-1,4,new Point(300, 150), new Point(300, 150), 50,50,50,2,50));
    monde->getIleBonus(0)->addDefenseur(new Patrouilleur(-1,5,new Point(300, 150), new Point(300, 150), 50,50,50,2,50));
    monde->getIleBonus(0)->placerDefenseur();


    monde->getFlotte(0)->getPatrouilleur(0)->setDestination(new Point(750,750));
    monde->getFlotte(0)->getPatrouilleur(0)->ajouterPV(-5);
   
    monde->getFlotte(1)->getPatrouilleur(0)->setDestination(new Point(600,300));

    Game* jeu = new Game(monde);
    delete jeu;

    return 0;
}