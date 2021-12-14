/**
 * \file fonctions_sdl.cpp
 * \brief Fonctions SDL
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#include "fonctions_SDL.hpp"

void initSDL(SDL_Window** window, SDL_Renderer** renderer, int width, int height)
{
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0)
        error(("Erreur initialisation de la SDL : %s | initSDL - fonctions_sdl", SDL_GetError()));
    if(SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN, window, renderer) != 0)
        error(("Erreur lors de la creation de l'image et du renderer : %s | initSDL - fonctions_sdl", SDL_GetError()));
    if(TTF_Init()==-1) error(("TTF_Init: %s\n", TTF_GetError()));
}

SDL_Texture* charger_image(const char* nomfichier, SDL_Renderer*renderer)
{
    if(nomfichier == NULL) error("nomfichier NULL en param | charger_police - fonctions_sdl");
    if(renderer == NULL) error("renderer NULL en param | charger_texte - fonctions_sdl");

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
    if(nomfichier == NULL) error("nomfichier NULL en param | charger_police - fonctions_sdl");
    if(renderer == NULL) error("renderer NULL en param | charger_texte - fonctions_sdl")

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

void afficherMonde(SDL_Renderer* ecran, Monde* monde, SDL_Texture* textureIle, SDL_Texture* texturePatrouilleur){ 
    afficherIles(ecran, monde, textureIle);
    afficherNavires(ecran, monde ,texturePatrouilleur);
}

void afficherIles(SDL_Renderer* ecran, Monde* monde, SDL_Texture* textureIle){
    for (int i = 0; i < monde->getNbIles()-1; i++) {
        SDL_Rect DestR = {monde->getIle(i)->getAbscisse()-TAILLE_ILE1/2, monde->getIle(i)->getOrdonnee()-TAILLE_ILE1/2,TAILLE_ILE1, TAILLE_ILE1};
        SDL_RenderCopy(ecran, textureIle, NULL, &DestR);
    }

}

void afficherNavires(SDL_Renderer* ecran, Monde* monde, SDL_Texture* texturePatrouilleur){
    for (int f = 0; f < monde->getNbFlottes(); f++){
        afficherPatrouilleurs(ecran, monde->getFlotte(f), texturePatrouilleur);
    }
}

void afficherPatrouilleurs(SDL_Renderer* ecran, Flotte* flotte, SDL_Texture* texturePatrouilleur){
    for (int p = 0; p < flotte->getNbPatrouilleurs(); p++) {
        SDL_Rect DestR = {flotte->getPatrouilleur(p)->getAbscisse()-TAILLE_PATROUILLEUR/2, flotte->getPatrouilleur(p)->getOrdonnee()-TAILLE_PATROUILLEUR/2,TAILLE_PATROUILLEUR, TAILLE_PATROUILLEUR};
        SDL_RenderCopyEx(ecran, texturePatrouilleur, NULL, &DestR, flotte->getPatrouilleur(p)->getAngle(), NULL, SDL_FLIP_NONE);
    }
}

TTF_Font* charger_police(const char *path, int font_size)
{
    if(path == NULL) error("path NULL en param | charger_police - fonctions_sdl");
    if(font_size < 0) error("taille de police negative | charger_police - fonctions_sdl");

    TTF_Font* font = TTF_OpenFont(path, font_size);
    if(font == NULL) error(("Erreur pendant chargement font : %s | charger_police - fonctions_sdl", SDL_GetError()));
    return font;
}

SDL_Texture* charger_texte(const char* message, SDL_Renderer* renderer, TTF_Font* font, SDL_Color color)
{
    if(message == NULL) error("message NULL en param | charger_texte - fonctions_sdl");
    if(renderer == NULL) error("renderer NULL en param | charger_texte - fonctions_sdl");
    if(font == NULL) error("font NULL en param | charger_texte - fonctions_sdl");

    // Écrire le texte sur une surface SDL
    SDL_Surface* text = TTF_RenderText_Solid(font, message, color);
    if(text == NULL) error(("Erreur pendant la creation de la surface visant a creer un text  : %s | charger_texte - fonctions_sdl", SDL_GetError()));
    // Convertir la surface de l’image au format texture avant de l’appliquer
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,text);
    if(texture == NULL) error((("Erreur pendant la creation de la texture liee au texte charge  : %s | charger_texte - fonctions_sdl", SDL_GetError())));
    // Libérer une surface
    SDL_FreeSurface(text);
    return texture;
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
    TTF_Quit();
    SDL_Quit();    
}