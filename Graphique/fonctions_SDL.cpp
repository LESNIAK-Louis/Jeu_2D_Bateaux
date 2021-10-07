#include "fonctions_SDL.hpp"

SDL_Texture* charger_image(const char* nomfichier, SDL_Renderer*renderer)
{
    // Charger une image
    SDL_Surface* bmp = SDL_LoadBMP(nomfichier) ;
    // Convertir la surface de l’image au format texture avant de l’appliquer
    SDL_Texture* toReturn = SDL_CreateTextureFromSurface(renderer,bmp);
    // Libérer une surface
    SDL_FreeSurface(bmp);
    return toReturn;
}

SDL_Texture* charger_image_transparente(const char* nomfichier, SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b)
{
    // Charger une image
    SDL_Surface* bmp = SDL_LoadBMP(nomfichier);
    // Récupérer la valeur (RGB) du pixel au format donné.
    Uint32 colorKey = SDL_MapRGB(bmp->format, r, g, b);
    // Définir la couleur (pixel transparent) dans une surface.
    SDL_SetColorKey(bmp, SDL_TRUE, colorKey);
    // Convertir la surface de l’image au format texture avant de l’appliquer
    SDL_Texture* toReturn = SDL_CreateTextureFromSurface(renderer,bmp);
    // Libérer une surface
    SDL_FreeSurface(bmp);
    return toReturn;
}

SDL_Texture* charger_texte(const char* message, SDL_Renderer* renderer, TTF_Font* font, SDL_Color color)
{
    // Écrire le texte sur une surface SDL
    SDL_Surface * text = TTF_RenderText_Solid(font, message, color) ;
    // Convertir la surface de l’image au format texture avant de l’appliquer
    SDL_Texture* toReturn = SDL_CreateTextureFromSurface(renderer,text);
    // Libérer une surface
    SDL_FreeSurface(text);
    // Fermer la police
    TTF_CloseFont(font);
    return toReturn;
}