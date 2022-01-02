/**
 * \file input.cpp
 * \brief Gère les entrées utilisateur
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#include "input.hpp"

void gestion_evenements(Game* jeu)
{
    while(SDL_PollEvent(jeu->getEvent())) 
    {
        if(jeu->getEtatJeu() == 0) // dans le menu
        {

        }
        else // en jeu
        {
            switch(jeu->getEvent()->type)
            {
                case SDL_QUIT : // Si l'utilisateur a cliqué sur le X de la fenêtre
                    jeu->setTerminer(true);
                break;
                case SDL_KEYDOWN :  // Si une touche clavier est appuyée
                    switch (jeu->getEvent()->key.keysym.sym)
                    {
                        case SDLK_RIGHT :
                            break;
                        case SDLK_LEFT :
                            break;
                        case SDLK_UP :
                            break;
                        case SDLK_DOWN :
                            break;
                        case SDLK_ESCAPE : 
                            break;
                        default:
                        break;
                    }
                break;
                case SDL_MOUSEBUTTONDOWN: // Si une touche souris est enfoncée
                    if(jeu->getEvent()->button.button == SDL_BUTTON_LEFT)
                    {
                        jeu->getMonde()->getFlotte(0)->viderListeSelected();
                        jeu->getMouse()->startSelection();
                    }
                    else if(jeu->getEvent()->button.button == SDL_BUTTON_RIGHT) 
                    {
                        if(!isPointingIle(jeu))
                            jeu->getMonde()->getFlotte(0)->deplacerSelected(jeu->getMouse()->getCurrentPosMouse());
                    }
                break;
                case SDL_MOUSEMOTION: // Si la souris subit un mouvement
                    if(jeu->getEvent()->button.button == SDL_BUTTON_LEFT)
                        jeu->getMouse()->updateSelection(); // si on veut ajouter un affichage lors de la selection (rectangle dessiné)
                break;
                case SDL_MOUSEBUTTONUP: // Si une touche souris est relachée
                    if(jeu->getEvent()->button.button == SDL_BUTTON_LEFT)
                    {
                        jeu->getMouse()->endSelection();
                        addNavToSelection(jeu->getMonde()->getFlotte(0), jeu->getMouse());
                    }
                break;
                default:
                break;
            }
        }
    }
}

bool isPointingIle(Game* jeu)
{
    for(int j = 0; j < jeu->getMonde()->getNbIles(); j++)
    {
        if(collisionCercles(jeu->getMonde()->getIle(j)->getCentre(), jeu->getMonde()->getIle(j)->getTaille(), jeu->getMouse()->getCurrentPosMouse(), 5))
            return true;
    }
    return false;
}

void addNavToSelection(Flotte* flotte, Mouse* mouse)
{
    Rectangle* rect = mouse->getRectangleSelection();
    for(int j = 0; j < flotte->getNbPatrouilleurs(); j++)
    {
        if(mouse->isSimpleClick())
        {
            if(flotte->getPatrouilleur(j)->estEnCollisionAvec(1, mouse->getCurrentPosMouse()))
            {
                flotte->addElemListeSelected(flotte->getPatrouilleur(j));
                break;
            }
        }
        else
        {
            if(collisionCercleRectangle(flotte->getPatrouilleur(j)->getCentre(), flotte->getPatrouilleur(j)->getTaille(), rect))
                flotte->addElemListeSelected(flotte->getPatrouilleur(j));
        }
    }
    delete rect;
}