#ifndef MENU_HPP
#define MENU_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../definitions.hpp"
#include "fonctions_SDL.hpp"
#include <string>


#ifndef MENU_C_HPP
struct texturesMenu_s{
    TTF_Font* police; /*textures liée a l'image représentant l'affichage du texte*/
    SDL_Texture* fond; /*!< Texture liée à l'image du fond de l'écran. */
};
#endif

#include "../Menu.hpp"

void afficherTextes(SDL_Renderer *renderer ,texturesMenu_s* textures, std::vector<textes_s*>*  textes, int nbTextes);

#endif