/**
 * \file Game.cpp
 * \brief Etat du jeu
 * \author Louis Lesniak & Hugues Steiner
 * \date 22 Dec. 2021
*/

#include "Game.hpp"

Game::Game(Monde* monde)
{
    if(monde == NULL) error("Monde NULL en param : Game - Game");
    this->mouse = new Mouse();
    this->etatJeu = 1;
    this->terminer = false;
    initWindowRenderer(&(this->fenetre), &(this->ecran), LARGEUR_ECRAN, HAUTEUR_ECRAN);
    this->monde = monde;
}

Game::~Game()
{
    delete this->monde;
}

Mouse* Game::getMouse()
{
    return this->mouse;
}

int Game::getEtatJeu()
{
    return this->etatJeu;
}

bool Game::getTerminer()
{
    return this->terminer;
}

SDL_Window* Game::getFenetre()
{
    return this->fenetre;
}

SDL_Event* Game::getEvent()
{
    return &(this->evenements);
}

SDL_Renderer* Game::getEcran()
{
    return this->ecran;
}

Monde* Game::getMonde()
{
    return this->monde;
}

void Game::setTerminer(bool terminer)
{
    this->terminer = terminer;
}

void Game::setMonde(Monde* monde)
{
    if (monde == NULL) error("Monde NULL en param : Game - Game");
    if (this->monde != NULL) delete this->monde;
    this->monde = monde;
}