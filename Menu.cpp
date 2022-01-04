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
    this->rectTexte = new std::vector<textes_s*>();
    this->pos = 0; 
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
    this->viderRectTextes();
    if(this->rectTexte != NULL)
        delete rectTexte;
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

int Menu::getNbRectTextes()
{
    return this->rectTexte->size();
}

std::vector<textes_s*>* Menu::getRectTextes()
{
    return this->rectTexte;
}

int Menu::getPos()
{
    return this->pos;
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
    if(this->getSelecting() == CATEG_SAUVEGARDE && !isFileExist(NOM_SAUVEGARDE))
        this->incrementerSelecting();
}

void Menu::decrementerSelecting()
{
    this->setSelecting((this->getSelecting()-1 < 0)?(NB_CATEG_MENU-1):this->getSelecting()-1);
    if(this->getSelecting()== CATEG_SAUVEGARDE && !isFileExist(NOM_SAUVEGARDE))
        this->decrementerSelecting();
}

void Menu::addRectTextes(textes_s* text)
{
    this->rectTexte->push_back(text);
}

void Menu::viderRectTextes()
{
    while(this->getNbRectTextes() != 0)
    {
        textes_s* text = this->rectTexte->back();
        if(text != NULL) free(text);
        this->rectTexte->pop_back();
    }
}

void Menu::setPos(int pos)
{
    this->pos = pos;
}

void Menu::updatePos()
{
    int margeBordVertical = HAUTEUR_ECRAN_MENU/15;
    switch (this->getPos())
    {
        case 0:
        {
            this->viderRectTextes();
            int espacementTextes = (HAUTEUR_ECRAN_MENU-2*margeBordVertical) / NB_CATEG_MENU;
            const char* tabTextes[NB_CATEG_MENU] = {
                "Nouvelle Partie",
                "Charger Sauvegarde",
                "Quitter"
            };
            SDL_Color tabCouleurTextes[NB_CATEG_MENU] = {
                COULEUR_TEXTE_MENU,
                COULEUR_TEXTE_MENU,
                COULEUR_TEXTE_MENU
            };
            SDL_Rect emplacements[NB_CATEG_MENU];
            for(int i = 0; i < NB_CATEG_MENU; i++ )
            {
                SDL_Rect rect = {LARGEUR_ECRAN_MENU/2, margeBordVertical + espacementTextes/2 +(espacementTextes)*i, 1, 1};
                emplacements[i] = rect;
            }

            tabCouleurTextes[this->getSelecting()] = COULEUR_SELECTING;
            if(!isFileExist(NOM_SAUVEGARDE))
                tabCouleurTextes[CATEG_SAUVEGARDE] = COULEUR_SAUVEGARDE_MANQUANTE;

            for(int i = 0; i < NB_CATEG_MENU; i++ )
            {
                textes_s* texteToAdd = (textes_s*)malloc(sizeof(textes_s));
                texteToAdd->id = i;
                texteToAdd->texte = tabTextes[i];
                texteToAdd->couleur = tabCouleurTextes[i];
                texteToAdd->emplacement = emplacements[i];
                this->addRectTextes(texteToAdd);
            }
            break;
        }
        case 1:
            /* code */
            break;
    default:
        break;
    }
}


void Menu::boucleMenu()
{
    while(!this->getTerminer()){
        
        SDL_RenderClear(this->getEcran());
        SDL_RenderCopy(this->getEcran(), this->getTextures()->fond, NULL, NULL);
        this->updatePos();
        afficher_menu(this);
        gestion_evenements_menu(this);
        SDL_RenderPresent(this->getEcran());
        SDL_Delay(1);
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