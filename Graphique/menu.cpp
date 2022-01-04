#include "menu.hpp"

void init_textures_menu(SDL_Renderer *renderer, texturesMenu_s* textures){
    textures->fond = charger_image("Ressources/fond.bmp", renderer);
    textures->police = charger_police("Ressources/arial.ttf", 25);
}

void afficher_menu(Menu* menu)
{
    afficherTextes(menu->getEcran(), menu->getTextures(), menu->getSelecting(), isFileExist("Save.txt"));
}


void afficherTextes(SDL_Renderer* ecran, texturesMenu_s* textures, int selecting, bool isSaveAvailiable)
{
    int margeBordVertical = HAUTEUR_ECRAN_MENU/15;
    int espacementTextes = (HAUTEUR_ECRAN_MENU-2*margeBordVertical) / NB_CATEG_MENU;
    
    
    std::string tabTextes[NB_CATEG_MENU] = {
        "Nouvelle Partie",
        "Charger Sauvegarde",
        "Quitter"
    };
    SDL_Color tabCouleurTextes[NB_CATEG_MENU] = {
        COULEUR_TEXTE_MENU,
        COULEUR_TEXTE_MENU,
        COULEUR_TEXTE_MENU
    };

    tabCouleurTextes[selecting] = COULEUR_SELECTING;
    if(!isSaveAvailiable)
        tabCouleurTextes[CATEG_SAUVEGARDE] = COULEUR_SAUVEGARDE_MANQUANTE;

    for(int i = 0; i < NB_CATEG_MENU; i++ )
    {
        SDL_Rect emplacementTexte = {LARGEUR_ECRAN_MENU/2, margeBordVertical + espacementTextes/2 +(espacementTextes)*i, 1, 1};
        afficher_texte(tabTextes[i].c_str(), ecran, emplacementTexte, textures->police, tabCouleurTextes[i], 1);
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