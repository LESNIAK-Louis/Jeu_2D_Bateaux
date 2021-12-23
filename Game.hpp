/**
 * \file Game.hpp
 * \brief Etat du jeu
 * \author Louis Lesniak & Hugues Steiner
 * \date 22 Dec. 2021
*/

#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include "Input-Output/Mouse.hpp"
#include "Logique/Class/Monde.hpp"
#include "Graphique/fonctions_SDL.hpp"
#include "definitions.hpp"


class Game
{
    protected :

    Mouse* mouse;
    int etatJeu; // 0 : menu ; 1 : Niveau 1 ....
    bool terminer; // si le jeu doit s'arrêter
    SDL_Window* fenetre;
    SDL_Event evenements;
    SDL_Renderer* ecran;

    Monde* monde;


    public : 

    Game(Monde* monde);
    ~Game();

    Mouse* getMouse();
    int getEtatJeu();
    bool getTerminer();
    SDL_Window* getFenetre();
    SDL_Event* getEvent();
    SDL_Renderer* getEcran();
    Monde* getMonde();

    void setMonde(Monde* monde);
    void setTerminer(bool terminer);
};


#endif