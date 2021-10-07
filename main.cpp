#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Graphique/fonctions_SDL.hpp"

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
    bool terminer = false;
    if(SDL_Init(SDL_INIT_VIDEO) < 0) // Initialisation de la SDL
    {
        printf("Erreur d’initialisation de la SDL: %s",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    
    // Créer la fenêtre
    fenetre = SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_RESIZABLE);
    if(fenetre == NULL) // En cas d’erreur
    {
        printf("Erreur de la creation d’une fenetre: %s",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    if(TTF_Init() < 0) // Initialisation du TTF
    {
        printf("Erreur d’initialisation du TTF: %s",TTF_GetError());
        TTF_Quit();
        return EXIT_FAILURE;
    }

    // Mettre en place un contexte de rendu de l’écran
    SDL_Renderer* ecran;
    ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    // Charger l’image
    SDL_Texture* fond = charger_image("Ressources/fond.bmp", ecran);

    // Charger l’image avec la transparence
    SDL_Texture* obj = charger_image_transparente("Ressources/obj.bmp",ecran,255,255,255);
    SDL_Texture* sprites = charger_image_transparente("Ressources/sprites.bmp",ecran,0,255,255);
    SDL_Rect SrcR;
    SDL_Rect DestR;

    SrcR.x = 0;
    SrcR.y = 0;
    SrcR.w = objW; // Largeur de l’objet en pixels (à récupérer)
    SrcR.h = objH; // Hauteur de l’objet en pixels (à récupérer)
    DestR.x = 350;
    DestR.y = 350;
    DestR.w = objW/3;
    DestR.h = objH/3;

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
    TTF_Font *font = TTF_OpenFont("Ressources/arial.ttf",28);
    SDL_Color color = {0,0,0,0};
    char msg[] = "TP sur Makefile et SDL";
    SDL_Texture* texte = charger_texte(msg,ecran,font,color);
    SDL_Rect text_pos; // Position du texte
    text_pos.x = 10;
    text_pos.y = 100;
    text_pos.w = texteW; // Largeur du texte en pixels (à récupérer)
    text_pos.h = texteH; // Hauteur du texte en pixels (à récupérer)

    // Boucle principale
    while(!terminer)
    {
        SDL_RenderClear(ecran);
        SDL_RenderCopy(ecran, fond, NULL, NULL);
        SDL_RenderCopy(ecran, obj, &SrcR, &DestR);
        for(int i = 0; i < 6;i++)
            SDL_RenderCopy(ecran, sprites, &SrcR_sprite[i], &DestR_sprite[i]);
        //Appliquer la surface du texte sur l’écran
        SDL_RenderCopy(ecran,texte,NULL,&text_pos);
        //SDL_PollEvent ...
        SDL_RenderPresent(ecran);
        
        SDL_PollEvent(&evenements);
        switch(evenements.type)
        {
            case SDL_QUIT:
                terminer = true; 
                break;
            case SDL_KEYDOWN:
                switch(evenements.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                    case SDLK_q:
                        terminer = true;
                        break;
                }
        }
    }

    // Libérer de la mémoire
    SDL_DestroyTexture(fond);
    SDL_DestroyTexture(obj);
    SDL_DestroyTexture(sprites);
    SDL_DestroyTexture(texte);
    SDL_DestroyRenderer(ecran);
    // Fermer la police et SDL_ttf
    TTF_CloseFont(font);
    TTF_Quit() ;
    // Quitter SDL
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return 0;
}