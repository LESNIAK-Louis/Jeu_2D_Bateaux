#include "Graphique/fonctions_SDL.hpp"
#include "Logique/Class/Monde.hpp"
#include "Input-Output/input.hpp"
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
    SDL_Window* fenetre; SDL_Event evenements;SDL_Renderer* ecran; bool terminer = false;
    initSDL(&fenetre, &ecran, 600, 600);
    SDL_Texture* fond = charger_image("Ressources/fond.bmp", ecran);
    SDL_Texture* bateau = charger_image("Ressources/test_bateau.bmp", ecran);

    Monde* monde = new Monde(1,0,0,0,0,0,0);
    monde->addFlotte(new Flotte(0, new Point(50,50), new Point(50,50), 0,0,0));
    monde->getFlotte(0)->newPatrouilleur();
    /*monde->getFlotte(0)->getPatrouilleur(0)->setIsSelected(true);
    SDL_Rect DestR;
*/
    while(!terminer){
        //DestR = {0, 0, monde->getFlotte(0)->getPatrouilleur(0)->getCentre()->getAbscisse(), monde->getFlotte(0)->getPatrouilleur(0)->getCentre()->getOrdonnee()};
        
        SDL_Rect DestR = {0,0,32,32};
        SDL_RenderClear(ecran);
        SDL_RenderCopy(ecran, fond, NULL, NULL);
        SDL_RenderCopy(ecran, bateau, NULL, &DestR);

        gestion_evenements(&evenements, monde);
        SDL_RenderPresent(ecran);
        SDL_Delay(20);
    }

    return 0;
}