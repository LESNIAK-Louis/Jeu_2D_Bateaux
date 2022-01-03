#ifndef MENU_HPP
#define MENU_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../definitions.hpp"
#include "fonctions_SDL.hpp"

struct texturesMenu_s{
    TTF_Font* police; /*textures liée a l'image représentant l'affichage du texte*/
    SDL_Texture* fond; /*!< Texture liée à l'image du fond de l'écran. */
};

/**
 * @brief initialise les textures du menu
 * 
 * @param renderer 
 * @param textures 
 */
void init_textures_menu(SDL_Renderer *renderer, texturesMenu_s* textures);

/**
 * @brief permet d'afficher le menu
 */
void afficher_menu();

/**
 * @brief Permet de fermer proprement le menu
 */
void clear_menu();

#endif