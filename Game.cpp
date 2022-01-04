/**
 * \file Game.cpp
 * \brief Etat du jeu
 * \author Louis Lesniak & Hugues Steiner
 * \date 22 Dec. 2021
*/

#include "Game.hpp"
Monde* temporaire();

Game::Game(bool* arreterApplication, bool* newGame)
{
        if(arreterApplication == NULL || newGame == NULL) error("pointeurs null en param de constructeur | Game");
        this->stop = arreterApplication;

        if((*arreterApplication))
        {
            this->monde = NULL;
            this->mouse = NULL;
            this->textures = NULL;
            this->ecran = NULL;
            this->fenetre = NULL;
            return;
        }
        
        if(*newGame)
            /*this->monde = readSave("carteInitiale.txt");*/ this->monde = temporaire();
        else
            this->monde = readSave("Save.txt");

        this->mouse = new Mouse();
        this->terminer = false;
        initWindowRenderer(&(this->fenetre), &(this->ecran), LARGEUR_ECRAN, HAUTEUR_ECRAN);
        this->monde = monde;
        this->textures = (textures_s*)malloc(sizeof(textures_s));
        init_textures_jeu(this->getEcran(), this->textures);
        this->boucleJeu();
}

Game::~Game()
{
    if(this->monde != NULL)
        delete this->monde;
    if(this->mouse != NULL)
        delete this->mouse;
    destroy_textures_jeu(this->textures);
    if(this->textures != NULL)
        free(this->textures);
    cleanSDL(this->ecran, this->fenetre);
}

Mouse* Game::getMouse()
{
    return this->mouse;
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

textures_s* Game::getTextures()
{
    return this->textures;
}

Monde* Game::getMonde()
{
    return this->monde;
}

std::string Game::getVainqueur()
{
    return monde->getVainqueur();
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

void Game::boucleJeu()
{
    this->getMonde()->setTimer(SDL_GetTicks());
    while(!this->getTerminer() && getVainqueur().compare("Non") == 0){
        Uint32 currentTime = SDL_GetTicks();
        SDL_RenderClear(this->getEcran());
        SDL_RenderCopy(this->getEcran(), this->getTextures()->fond, NULL, NULL);
        afficherMonde(this->getEcran(), this->getMonde(), this->getTextures());
        moveShips(this->getMonde());
        tirsBateaux(this->getMonde(), currentTime);
        this->getMonde()->updateControleIleBonus();
        this->getMonde()->getFlotte(0)->addRessource();
        getMonde()->actionBot();
        gestion_evenements_jeu(this->getEvent(), this->getMouse(), this->getMonde(), &(this->terminer), this->stop);
        SDL_RenderPresent(this->getEcran());
        SDL_Delay(50);
    }
    if (getVainqueur().compare("Non") == 0) {
        save("Save.txt", this->getMonde());
    }
    std::cout << "Vainqueur : " << getVainqueur() << std::endl;
    
}
