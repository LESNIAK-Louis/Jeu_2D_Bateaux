/**
 * \file Menu.cpp
 * \brief Le Menu
 * \author Louis Lesniak & Hugues Steiner
 * \date 03 Janv. 2022
*/

#include "Menu.hpp"

Menu::Menu(bool* arreterApplication, bool* newGame)
{
    if(arreterApplication == NULL || newGame == NULL) error("pointeurs null en param de constructeur | Menu");
    this->mouse = new Mouse();
    this->stopApp = arreterApplication;
    this->newGame = newGame;
    this->terminer = false;
    this->selecting = 0;
    initWindowRenderer(&(this->fenetre), &(this->ecran), LARGEUR_ECRAN_MENU, HAUTEUR_ECRAN_MENU);
    this->textures = (texturesMenu_s*)malloc(sizeof(texturesMenu_s));
    init_textures_menu(this->getEcran(), this->textures);
    this->boucleMenu();
}

Menu::~Menu()
{
    if(this->mouse != NULL)
        delete this->mouse;
    destroy_textures_menu(this->textures);
    if(this->textures != NULL)
        free(this->textures);
    cleanSDL(this->ecran, this->fenetre);
}

Mouse* Menu::getMouse()
{
    return this->mouse;
}

bool Menu::getTerminer()
{
    return this->terminer;
}

int Menu::getSelecting()
{
    return this->selecting;
}

SDL_Window* Menu::getFenetre()
{
    return this->fenetre;
}

SDL_Event* Menu::getEvent()
{
    return &(this->evenements);
}

SDL_Renderer* Menu::getEcran()
{
    return this->ecran;
}

texturesMenu_s* Menu::getTextures()
{
    return this->textures;
}

void Menu::setTerminer(bool terminer)
{
    this->terminer = terminer;
}

void Menu::setSelecting(int selecting)
{
    this->selecting = selecting;
}

void Menu::incrementerSelecting()
{
    this->setSelecting((this->getSelecting()+1)%NB_CATEG_MENU);
    if(this->getSelecting() == CATEG_SAUVEGARDE && !isFileExist("Save.txt"))
        this->incrementerSelecting();
}

void Menu::decrementerSelecting()
{
    this->setSelecting((this->getSelecting()-1 < 0)?(NB_CATEG_MENU-1):this->getSelecting()-1);
    if(this->getSelecting()== CATEG_SAUVEGARDE && !isFileExist("Save.txt"))
        this->decrementerSelecting();
}

void Menu::boucleMenu()
{
    while(!this->getTerminer()){
        
        SDL_RenderClear(this->getEcran());
        SDL_RenderCopy(this->getEcran(), this->getTextures()->fond, NULL, NULL);
        afficher_menu(this);
        gestion_evenements_menu(this);
        SDL_RenderPresent(this->getEcran());
        SDL_Delay(10);
    }
}

void Menu::setNewGame(bool newGame)
{
    *(this->newGame) = newGame;
}

void Menu::arreterApplication()
{
    *(this->stopApp) = true;
    this->setTerminer(true);
}