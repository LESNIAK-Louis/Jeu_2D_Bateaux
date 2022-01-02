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


int main()
{
    SDL_Window* fenetre; // Déclaration de la fenêtre
    SDL_Event evenements; // Événements liés à la fenêtre
    SDL_Renderer* ecran;
    bool terminer = false;

    initSDL(&fenetre, &ecran, 600, 600);

    std::vector<SDL_Texture*> textures;
    std::vector<TTF_Font*> polices;

    textures.push_back(charger_image("Ressources/fond.bmp", ecran));
    textures.push_back(charger_image_transparente("Ressources/obj.bmp", ecran, 255, 255, 255));
    textures.push_back(charger_image_transparente("Ressources/sprites.bmp", ecran, 0, 255, 255));

    SDL_Rect SrcR = {0,0,objW,objH};
    SDL_Rect DestR = {350, 350, objW/3, objH/3};

    SDL_Rect DestR_sprite[6];
    SDL_Rect SrcR_sprite[6];
    for(int i=0; i<6; i++)
    {
        SrcR_sprite[i].x = i > 2 ? (i-3)*(chatW) : i*(chatW);
        SrcR_sprite[i].y = i > 2 ? chatH : 0;
        SrcR_sprite[i].w = chatW; // Largeur de l’objet en pixels (à récupérer)
        SrcR_sprite[i].h = chatH; // Hauteur de l’objet en pixels (à récupérer)

        DestR_sprite[i].x = i > 2 ? 60*(i+1)+100 : 60*(i+1);
        DestR_sprite[i].y = i > 2 ? 60 : 120;
        DestR_sprite[i].w = chatW; // Largeur du sprite
        DestR_sprite[i].h = chatH; // Hauteur du sprite
    }

    // TTF
    polices.push_back(charger_police("Ressources/arial.ttf", 28));
    SDL_Color color = {0,0,0,0};
    textures.push_back(charger_texte("TP sur Makefile et SDL", ecran, polices[0], color));
    SDL_Rect text_pos {10,100,texteW,texteH}; // Position du texte

    while(!terminer)
    {
        SDL_RenderClear(ecran);
        SDL_RenderCopy(ecran, textures[0], NULL, NULL);
        SDL_RenderCopy(ecran, textures[1], &SrcR, &DestR);

        for(int i = 0; i < 6;i++)
            SDL_RenderCopy(ecran, textures[2], &SrcR_sprite[i], &DestR_sprite[i]);
            
        //Appliquer la surface du texte sur l’écran
        SDL_RenderCopy(ecran,textures[3],NULL,&text_pos);
        //SDL_PollEvent ...
        SDL_RenderPresent(ecran);
        
        gestion_evenements(&evenements);
        SDL_Delay(20);
    }

    cleanSDL(ecran, fenetre, &textures, &polices);
    return 0;
}*/

#include <iostream>

int main()
{
    Monde* monde;
    //monde = readSave("Save.txt");
    monde = new Monde(1,0,1,1);
    monde->addFlotte(new Flotte(0, new Point(50,50), new Point(200,200), 0,10,500));
    monde->addFlotte(new Flotte(1, new Point(400,400), new Point(400,400), 0,10,500));
    monde->setIle(0, new Ile(new Point(300, 300), TAILLE_ILE1 , 1));
    monde->getFlotte(0)->newPatrouilleur();
    //monde->getFlotte(0)->newPatrouilleur();
    monde->getFlotte(1)->newPatrouilleur();
    monde->getFlotte(0)->newPatrouilleur();
    /*monde->getFlotte(0)->newPatrouilleur();
    monde->getFlotte(0)->newPatrouilleur();
    monde->getFlotte(0)->newPatrouilleur();
    monde->getFlotte(0)->newPatrouilleur();
    monde->getFlotte(0)->newPatrouilleur();
    monde->getFlotte(1)->newPatrouilleur();*/

    //monde->getFlotte(1)->getPatrouilleur(0)->setCentre(new Point(150, 250));
    /*monde->getFlotte(0)->getPatrouilleur(4)->setAngle(90);

    monde->getFlotte(0)->getPatrouilleur(2)->setCentre(new Point(80-32, 150));
    monde->getFlotte(0)->getPatrouilleur(2)->setAngle(90);

    monde->getFlotte(0)->getPatrouilleur(3)->setCentre(new Point(80-32, 150+32));
    monde->getFlotte(0)->getPatrouilleur(3)->setAngle(90);

    monde->getFlotte(0)->getPatrouilleur(5)->setCentre(new Point(80+32, 150-32));
    monde->getFlotte(0)->getPatrouilleur(5)->setAngle(90);

    monde->getFlotte(0)->getPatrouilleur(6)->setCentre(new Point(80+32, 150));
    monde->getFlotte(0)->getPatrouilleur(6)->setAngle(90);

    monde->getFlotte(0)->getPatrouilleur(7)->setCentre(new Point(80+32, 150+32));
    monde->getFlotte(0)->getPatrouilleur(7)->setAngle(90);*/

    monde->getFlotte(0)->getPatrouilleur(0)->setDestination(new Point(400,420));
    monde->getFlotte(0)->getPatrouilleur(1)->setDestination(new Point(222,222));
    /*monde->getFlotte(0)->getPatrouilleur(1)->setDestination(new Point(250, 150));
    monde->getFlotte(0)->getPatrouilleur(2)->setDestination(new Point(150, 150));
    monde->getFlotte(0)->getPatrouilleur(3)->setDestination(new Point(150, 250));
    monde->getFlotte(1)->getPatrouilleur(0)->setDestination(new Point(300,300));*/

    Game* jeu = new Game(monde);
    SDL_Texture* fond = charger_image("Ressources/fond.bmp", jeu->getEcran());
    SDL_Texture* textureIle = charger_image("Ressources/ile.bmp", jeu->getEcran());
    SDL_Texture* texturePatrouilleur = charger_image("Ressources/test_bateau.bmp", jeu->getEcran());
    //SDL_Texture* texturePoint = charger_image("Ressources/point.bmp", jeu->getEcran());

    while(!jeu->getTerminer()){
        SDL_RenderClear(jeu->getEcran());
        SDL_RenderCopy(jeu->getEcran(), fond, NULL, NULL);
        afficherMonde(jeu->getEcran(), monde, textureIle, texturePatrouilleur);
        SDL_Rect DestR = {monde->getIle(0)->getAbscisse()-(TAILLE_ILE1/2), monde->getIle(0)->getOrdonnee()-(TAILLE_ILE1/2),TAILLE_ILE1, TAILLE_ILE1};
        SDL_RenderCopy(jeu->getEcran(), textureIle, NULL, &DestR);
        moveShips(monde);
        //std::cout << "Pat 0 angle : " << monde->getFlotte(0)->getPatrouilleur(0)->getAngle()<< "\n";
        //std::cout << "Pat 0" + monde->getFlotte(0)->getPatrouilleur(0)->getCentre()->toString()<< "\n";
        /*std::cout << "Pat 0 dest : " + monde->getFlotte(0)->getPatrouilleur(0)->getDestination()->toString()<< "\n";
        std::cout << "Pat 1" + monde->getFlotte(0)->getPatrouilleur(1)->getCentre()->toString()<< "\n";
        std::cout << "Pat 1 dest : " + monde->getFlotte(0)->getPatrouilleur(1)->getDestination()->toString()<< "\n";*/
        gestion_evenements(jeu);
        SDL_RenderPresent(jeu->getEcran());
        SDL_Delay(50);
    }


    save("Save.txt", jeu->getMonde());
    delete jeu;


    return 0;
}