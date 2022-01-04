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
#include "Input-Output/fichier.hpp"
#include "Input-Output/input.hpp"
#include "Graphique/fonctions_SDL.hpp"
#include "Graphique/jeu.hpp"
#include "definitions.hpp"
#include "Logique/logique.hpp"


class Game
{
    private :

    Mouse* mouse;
    bool terminer; // si le jeu doit s'arrêter
    bool* stop; // on arrete l'application
    SDL_Window* fenetre;
    SDL_Event evenements;
    SDL_Renderer* ecran;
    textures_s* textures;

    Monde* monde;


    public : 

    Game(bool* arreterApplication, bool* newGame);
    ~Game();

    Mouse* getMouse();
    int getEtatJeu();
    bool getTerminer();
    SDL_Window* getFenetre();
    SDL_Event* getEvent();
    SDL_Renderer* getEcran();
    textures_s* getTextures();
    Monde* getMonde();

    void setMonde(Monde* monde);
    void setTerminer(bool terminer);
    std::string getVainqueur();


    void boucleJeu();
};


#endif