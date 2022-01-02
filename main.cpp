#include "Graphique/fonctions_SDL.hpp"
#include "Logique/Class/Monde.hpp"
#include "Input-Output/input.hpp"
#include "Logique/logique.hpp"
#include "Input-Output/fichier.hpp"
#include "Game.hpp"
/*
#define objW 640
#define objH 192

#define chatW 285/3
#define chatH 250/2

#define texteW 300
#define texteH 35
*/

#include <iostream>

int main()
{
    Monde* monde;
    //monde = readSave("Save.txt");
    monde = new Monde(1,0,1,1);
    monde->addFlotte(new Flotte(0, new Point(50,50), new Point(200,200), OR_INITIAL, GAIN_INITIAL,PV_MAX_FLOTTE));
    monde->addFlotte(new Flotte(1, new Point(400,400), new Point(400,400), 0,10,500));
    monde->setIle(0, new Ile(new Point(300, 300), TAILLE_ILE1 , 1));
    
    monde->getFlotte(1)->newPatrouilleur();
   
   monde->getFlotte(1)->getPatrouilleur(0)->setDestination(new Point(300,300));

    Game* jeu = new Game(monde);

    textures_s textures;
    init_textures(jeu->getEcran(), &textures);

    while(!jeu->getTerminer()){
        SDL_RenderClear(jeu->getEcran());

        SDL_RenderCopy(jeu->getEcran(), (&textures)->fond, NULL, NULL);
        afficherMonde(jeu->getEcran(), monde, &textures);
        moveShips(monde);
        monde->getFlotte(0)->addRessource();

        
        gestion_evenements(jeu);
        SDL_RenderPresent(jeu->getEcran());
        SDL_Delay(50);
    }

    save("Save.txt", jeu->getMonde());
    delete jeu;


    return 0;
}