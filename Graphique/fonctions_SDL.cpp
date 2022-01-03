/**
 * \file fonctions_sdl.cpp
 * \brief Fonctions SDL
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#include "fonctions_SDL.hpp"

void initSDL()
{
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0)
        error(("Erreur initialisation de la SDL : %s | initSDL - fonctions_sdl", SDL_GetError()));
    if(TTF_Init()==-1) error(("TTF_Init: %s\n", TTF_GetError()));
}

void initWindowRenderer(SDL_Window** window, SDL_Renderer** renderer, int width, int height)
{
    if(SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN, window, renderer) != 0)
        error(("Erreur lors de la creation de l'image et du renderer : %s | initSDL - fonctions_sdl", SDL_GetError()));
}

SDL_Texture* charger_image(const char* nomfichier, SDL_Renderer*renderer)
{
    if(nomfichier == NULL) error("nomfichier NULL en param | charger_image - fonctions_sdl");
    if(renderer == NULL) error("renderer NULL en param | charger_image - fonctions_sdl");

    // Charger une image
    SDL_Surface* bmp = SDL_LoadBMP(nomfichier);
    if(bmp == NULL) error(("Erreur pendant chargement de l'image image : %s | charger_image - fonctions_sdl", SDL_GetError()));
    // Convertir la surface de l’image au format texture avant de l’appliquer
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,bmp);
    if(texture == NULL) error(("Erreur pendant la creation de la texture liee a l'image chargee : %s | charger_image - fonctions_sdl", SDL_GetError()));
    // Libérer une surface
    SDL_FreeSurface(bmp);
    return texture;
}

SDL_Texture* charger_image_transparente(const char* nomfichier, SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b)
{
    if(nomfichier == NULL) error("nomfichier NULL en param | charger_image_transparente - fonctions_sdl");
    if(renderer == NULL) error("renderer NULL en param | charger_image_transparente - fonctions_sdl")

    // Charger une image
    SDL_Surface* bmp = SDL_LoadBMP(nomfichier);
    if(bmp == NULL) error(("Erreur pendant chargement de l'image image : %s | charger_image_transparente - fonctions_sdl", SDL_GetError()));
    // Récupérer la valeur (RGB) du pixel au format donné.
    Uint32 colorKey = SDL_MapRGB(bmp->format, r, g, b);
    // Définir la couleur (pixel transparent) dans une surface.
    if(SDL_SetColorKey(bmp, SDL_TRUE, colorKey) != 0)
        error(("Erreur pendant le ste de la color key à la surface : %s | charger_image_transparente - fonctions_sdl", SDL_GetError()));
    // Convertir la surface de l’image au format texture avant de l’appliquer
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,bmp);
    if(texture == NULL) error(("Erreur pendant la creation de la texture liee a l'image chargee : %s | charger_image_transparente - fonctions_sdl", SDL_GetError()));
    // Libérer une surface
    SDL_FreeSurface(bmp);
    return texture;
}



TTF_Font* charger_police(const char *path, int font_size)
{
    if(path == NULL) error("path NULL en param | charger_police - fonctions_sdl");
    if(font_size < 0) error("taille de police negative | charger_police - fonctions_sdl");

    TTF_Font* font = TTF_OpenFont(path, font_size);
    if(font == NULL) error(("Erreur pendant chargement font : %s | charger_police - fonctions_sdl", SDL_GetError()));
    return font;
}

void afficher_texte(const char* message, SDL_Renderer* renderer, SDL_Rect DestR, TTF_Font* font, SDL_Color color, bool query)
{
    if(message == NULL) error("message NULL en param | afficher_texte - fonctions_sdl!!!!!!");
    if(renderer == NULL) error("renderer NULL en param | afficher_texte - fonctions_sdl");
    if(font == NULL) error("font NULL en param | afficher_texte - fonctions_sdl");

    // Écrire le texte sur une surface SDL
    SDL_Surface* text = TTF_RenderText_Solid(font, message, color);
    if(text == NULL) error(("Erreur pendant la creation de la surface visant a creer un text  : %s | afficher_texte - fonctions_sdl", SDL_GetError()));
    // Convertir la surface de l’image au format texture avant de l’appliquer
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,text);
    if(texture == NULL) error((("Erreur pendant la creation de la texture liee au texte charge  : %s | afficher_texte - fonctions_sdl", SDL_GetError())));
    if(query)
    {
        int w, h;
        if(SDL_QueryTexture(texture, NULL, NULL, &w, &h) == -1) error((("Erreur pendant le query de la texture : %s | afficher_texte - fonctions_sdl", SDL_GetError())));
        DestR.w = w;
        DestR.h = h;
    }
    
    if(SDL_RenderCopy(renderer, texture, NULL, &DestR) == -1) error((("Erreur pendant l'ajout de la texture au renderer' : %s | afficher_texte - fonctions_sdl", SDL_GetError())));
    // Destruction de la texture
    SDL_DestroyTexture(texture);
    // Libérer une surface
    SDL_FreeSurface(text);
}

void cleanTextures(std::vector<SDL_Texture*>* textures)
{
    if(textures == NULL) error("textures NULL | cleanTextures - fonctions_sdl");

    while(textures->size() != 0)
    {
        if(textures->back() != NULL)
            SDL_DestroyTexture(textures->back());
        textures->pop_back();
    }
    textures->shrink_to_fit(); // Réduit la taille en mémoire au minimum
}

void cleanPolices(std::vector<TTF_Font*>* fonts)
{
    if(fonts == NULL) error("fonts NULL | cleanPolice - fonctions_sdl");

    while(fonts->size() != 0)
    {
        if(fonts->back() != NULL)
            TTF_CloseFont(fonts->back());
        fonts->pop_back();
    }
    fonts->shrink_to_fit(); // Réduit la taille en mémoire au minimum
}

void cleanSDL(SDL_Renderer* renderer, SDL_Window* window, std::vector<SDL_Texture*>* textures, std::vector<TTF_Font*>* fonts)
{
    cleanTextures(textures);
    cleanPolices(fonts);

    if(NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if(NULL != window)
        SDL_DestroyWindow(window);
}

void quitSDL()
{
    TTF_Quit();
    SDL_Quit();    
}