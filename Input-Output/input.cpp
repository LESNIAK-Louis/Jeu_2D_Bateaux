/**
 * \file input.cpp
 * \brief Gère les entrées utilisateur
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#include "input.hpp"

void gestion_evenements(SDL_Event *event, Monde* monde)
{
    while(SDL_PollEvent(event)) 
    {
        switch(event->type)
        {
            case SDL_QUIT : // Si l'utilisateur a cliqué sur le X de la fenêtre
                exit(0);
            break;
            case SDL_KEYDOWN :  // Si une touche clavier est appuyée
                switch (event->key.keysym.sym)
                {
                    case SDLK_RIGHT :
                        moveSelectedShips(monde, 8, 0);
                        break;
                    case SDLK_LEFT :
                        moveSelectedShips(monde, -8, 0);
                        break;
                    case SDLK_UP :
                        moveSelectedShips(monde, 0, -8);
                        break;
                    case SDLK_DOWN :
                        moveSelectedShips(monde, 0, 8);
                        break;
                    case SDLK_ESCAPE : 
                        unSelectAll(monde);
                        break;
                    default:
                    break;
                }
            break;
            case SDL_MOUSEBUTTONDOWN: // Si une touche souris est appuyée
                switch(event->button.button)
                {
                    case SDL_BUTTON_LEFT:
                    break;
                    case SDL_BUTTON_RIGHT:
                    break;
                }
            default:
            break;
        }
    }
}