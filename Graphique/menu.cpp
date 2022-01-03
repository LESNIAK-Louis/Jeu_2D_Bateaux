#include "menu.hpp"

void init_textures_menu(SDL_Renderer *renderer, textures_s* textures){
    textures->fond = charger_image("Ressources/fond.bmp", renderer);
    textures->police = charger_police("Ressources/arial.ttf", 16);
}

void afficher_menu()
{
    /*if(SDL_CreateWindowAndRenderer(LARGEUR_ECRAN_MENU, HAUTEUR_ECRAN_MENU, SDL_WINDOW_SHOWN, window, renderer) != 0)
        error(("Erreur lors de la creation de l'image et du renderer : %s | initSDL - fonctions_sdl", SDL_GetError()));*/
}