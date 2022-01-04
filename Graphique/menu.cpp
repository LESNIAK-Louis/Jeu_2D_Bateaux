#include "menu.hpp"

void init_textures_menu(SDL_Renderer *renderer, texturesMenu_s* textures){
    textures->fond = charger_image("Ressources/fond.bmp", renderer);
    textures->police = charger_police("Ressources/arial.ttf", 25);
}

void afficher_menu(Menu* menu)
{
    afficherTextes(menu->getEcran(), menu->getTextures(), menu->getRectTextes(), menu->getNbRectTextes());
}


void afficherTextes(SDL_Renderer* ecran, texturesMenu_s* textures, std::vector<textes_s*>* textes, int nbTextes)
{
    for(int i = 0; i < nbTextes; i++ )
    {
        afficher_texte(textes->at(i)->texte, ecran, &(textes->at(i)->emplacement), textures->police, textes->at(i)->couleur, 1);
    }
}

void destroy_textures_menu(texturesMenu_s* textures)
{
    if(textures != NULL)
    {
        if(NULL != textures->fond) SDL_DestroyTexture(textures->fond);
        if(NULL != textures->police) TTF_CloseFont(textures->police);
    }
}