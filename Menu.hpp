/**
 * \file Menu.hpp
 * \brief Le Menu
 * \author Louis Lesniak & Hugues Steiner
 * \date 03 Janv. 2022
*/

#ifndef MENU_C_HPP
#define MENU_C_HPP

#include <SDL2/SDL.h>
#include "Input-Output/fichier.hpp"
#include "Graphique/fonctions_SDL.hpp"
#include "Input-Output/Mouse.hpp"
#include "definitions.hpp"

#ifndef MENU_HPP
struct texturesMenu_s{
    TTF_Font* police; /*textures liée a l'image représentant l'affichage du texte*/
    SDL_Texture* fond; /*!< Texture liée à l'image du fond de l'écran. */
};
#endif

class Menu
{
    private :

    Mouse* mouse;
    bool terminer; // si on quitte le menu
    bool* stopApp; // si on quitte l'application
    bool* newGame; // l'utilisateur decide si il veut lancer une nouvelle partie ou en charger une
    SDL_Window* fenetre;
    SDL_Event evenements;
    SDL_Renderer* ecran;
    texturesMenu_s* textures;
    int selecting;

    public : 

    Menu(bool* arreterApplication, bool* newGame);
    ~Menu();

    Mouse* getMouse();
    int getEtatJeu();
    bool getTerminer();
    int getSelecting();
    SDL_Window* getFenetre();
    SDL_Event* getEvent();
    SDL_Renderer* getEcran();
    texturesMenu_s* getTextures();

    void setTerminer(bool terminer);
    void setSelecting(int selecting);
    void incrementerSelecting();
    void decrementerSelecting();

    void boucleMenu();

    void setNewGame(bool newGame);
    void arreterApplication();
};

/* definition dans Graphique/menu.cpp */
#ifndef MENU_HPP
void init_textures_menu(SDL_Renderer *renderer, texturesMenu_s* textures);
void afficher_menu(Menu* menu);
void destroy_textures_menu(texturesMenu_s* textures);
#endif




/* definition dans Input-Output/input.cpp */
#ifndef INPUT_HPP
void gestion_evenements_menu(Menu* menu);
#endif


#endif