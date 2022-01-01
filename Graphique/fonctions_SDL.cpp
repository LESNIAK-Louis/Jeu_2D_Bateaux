/**
 * \file fonctions_sdl.cpp
 * \brief Fonctions SDL
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#include "fonctions_SDL.hpp"


void  init_textures(SDL_Renderer *renderer, textures_s* textures){
    textures->fond = charger_image("Ressources/fond.bmp", renderer);
    textures->ile = charger_image("Ressources/ile.bmp", renderer);
    textures->contourPV = charger_image("Ressources/contourBarrePV.bmp", renderer);
    textures->remplissagePV = charger_image("Ressources/remplissageBarrePV.bmp", renderer);
    textures->patrouilleur = charger_image("Ressources/patrouilleur.bmp", renderer);
    textures->interface = charger_image("Ressources/interface.bmp", renderer);
    textures->bouton = charger_image("Ressources/bouton.bmp", renderer);
    textures->police = charger_police("Ressources/arial.ttf", 16);
}

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

/*
void afficherMonde(SDL_Renderer* ecran, Monde* monde, textures_s* textures){ 
    afficherIles(ecran, monde, textureIle);
    //afficherNavires(ecran, monde ,texturePatrouilleur, textureContourPV, textureRemplissagePV);    
}*/

void afficherInterface(SDL_Renderer* ecran, Monde* monde, textures_s* textures){
    SDL_Rect DstR = {0, 0, LARGEUR_ECRAN, HAUTEUR_INTERFACE};
    SDL_RenderCopy(ecran, textures->interface, NULL, &DstR);
    afficherInformations(ecran, monde->getFlotte(0), textures);
    afficherBoutons(ecran, textures);
}

void afficherInformations(SDL_Renderer* ecran, Flotte* flotte, textures_s* textures){
    std::string string = "Or : ";
    int ressource = flotte->getQteRessource();
    string = string + std::to_string(ressource);
    const char* quantiteOr = string.c_str();
    SDL_Color couleurTexteInterface = { 231, 76, 60, 255};
    SDL_Texture* qteOr = charger_texte(quantiteOr, ecran, textures->police, couleurTexteInterface);
    int w, h;
    SDL_QueryTexture(qteOr, NULL, NULL, &w, &h);
    SDL_Rect DestR = {10,10, w, h};
    SDL_RenderCopy(ecran, qteOr, NULL, &DestR);
}

void afficherBoutons(SDL_Renderer* ecran, textures_s* textures){

}

void afficherIles(SDL_Renderer* ecran, Monde* monde, textures_s* textures){
    for (int i = 0; i < monde->getNbIles(); i++) {
        SDL_Rect DestR = {monde->getIle(i)->getAbscisse()-(TAILLE_ILE1/2), monde->getIle(i)->getOrdonnee()-(TAILLE_ILE1/2),TAILLE_ILE1, TAILLE_ILE1};
        SDL_RenderCopy(ecran, textures->ile, NULL, &DestR);
    }

}

void afficherNavires(SDL_Renderer* ecran, Monde* monde, textures_s* textures){
    for (int f = 0; f < monde->getNbFlottes(); f++){
        afficherPatrouilleurs(ecran, monde->getFlotte(f), textures);
    }
}

void afficherPatrouilleurs(SDL_Renderer* ecran, Flotte* flotte, textures_s* textures){
    for (int p = 0; p < flotte->getNbPatrouilleurs(); p++) {
        SDL_Rect DestR = {flotte->getPatrouilleur(p)->getAbscisse()-TAILLE_PATROUILLEUR/2, flotte->getPatrouilleur(p)->getOrdonnee()-TAILLE_PATROUILLEUR/2,TAILLE_PATROUILLEUR, TAILLE_PATROUILLEUR};
        SDL_RenderCopyEx(ecran, textures->patrouilleur, NULL, &DestR, flotte->getPatrouilleur(p)->getAngle(), NULL, SDL_FLIP_NONE);
        afficherBarreDeVie(flotte->getPatrouilleur(p), ecran, textures);

        //Permet d'afficher un point sur le wayPoint du patrouilleur. A utiliser pour le debuggage
        SDL_Texture* texturePoint = charger_image("Ressources/point.bmp", ecran);
        DestR = {flotte->getPatrouilleur(p)->getWayPoint()->getAbscisse(), flotte->getPatrouilleur(p)->getWayPoint()->getOrdonnee(),5, 5};
        SDL_RenderCopy(ecran, texturePoint, NULL, &DestR);
    }
}


void afficherBarreDeVie(Navire* navire, SDL_Renderer* ecran, textures_s* textures){

    double ratio = (double)navire->getPv() / (double)navire->getPvMax();
    SDL_Rect DestRExt = {navire->getAbscisse()-navire->getTaille()/2, navire->getOrdonnee()-navire->getTaille()/2 - 8, PV_CONT_WIDTH, PV_CONT_HEIGHT};
    SDL_Rect DestRInt = {navire->getAbscisse()-navire->getTaille()/2 +1, navire->getOrdonnee()-navire->getTaille()/2 - 7, (int)round(PV_REMP_WIDTH * ratio), PV_REMP_HEIGHT};

    SDL_RenderCopy(ecran, textures->contourPV, NULL, &DestRExt);
    SDL_RenderCopy(ecran, textures->remplissagePV, NULL, &DestRInt);
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
    if(message == NULL) error("message NULL en param | charger_texte - fonctions_sdl!!!!!!");
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