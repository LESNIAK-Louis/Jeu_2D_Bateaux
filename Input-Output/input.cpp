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
                            moveSelectedShips(jeu->getMonde(), 8, 0);
                            break;
                        case SDLK_LEFT :
                            moveSelectedShips(jeu->getMonde(), -8, 0);
                            break;
                        case SDLK_UP :
                            moveSelectedShips(jeu->getMonde(), 0, -8);
                            break;
                        case SDLK_DOWN :
                            moveSelectedShips(jeu->getMonde(), 0, 8);
                            break;
                        case SDLK_ESCAPE : 
                            //unSelectAll(monde);
                            break;
                        default:
                        break;
                    }
                break;
                case SDL_MOUSEBUTTONDOWN: // Si une touche souris est enfoncée
                    if(jeu->getEvent()->button.button == SDL_BUTTON_LEFT)
                    {
                        jeu->getMouse()->startSelection();
                    }
                break;
                case SDL_MOUSEMOTION: // Si la souris subit un mouvement
                    if(jeu->getEvent()->button.button == SDL_BUTTON_LEFT)
                    {
                        jeu->getMouse()->updateSelection(); // si on veut ajouter un affichage lors de la selection (rectangle dessiné)
                    }
                break;
                case SDL_MOUSEBUTTONUP: // Si une touche souris est relachée
                    if(jeu->getEvent()->button.button == SDL_BUTTON_LEFT)
                    {
                        jeu->getMouse()->endSelection();

                        if(jeu->getMouse()->isSimpleClick())
                        {
                            bool isPointingEntity = false;
                            for(int j = 0; j < jeu->getMonde()->getFlotte(0)->getNbPatrouilleurs(); j++)
                            {
                                if(jeu->getMonde()->getFlotte(0)->getPatrouilleur(j)->estEnCollisionAvec(5,jeu->getMouse()->getEndPosMouse()))
                                {
                                    unSelectAll(jeu->getMonde());
                                    jeu->getMonde()->getFlotte(0)->getPatrouilleur(j)->setIsSelected(true);
                                    isPointingEntity = true;
                                    break;
                                }
                            }
                            if(!isPointingEntity)
                            {
                                for(int j = 0; j < jeu->getMonde()->getNbIles(); j++)
                                {
                                    if(collisionCercles(jeu->getMonde()->getIle(j)->getCentre(), /*jeu->getMonde()->getIle(j)->getTaille()*/64, jeu->getMouse()->getCurrentPosMouse(), 5))
                                    {
                                        isPointingEntity = true;
                                        break;
                                    }
                                }
                            }

                            if(!isPointingEntity)
                            {
                                for(int j = 0; j < jeu->getMonde()->getFlotte(0)->getNbPatrouilleurs(); j++)
                                {
                                    if(jeu->getMonde()->getFlotte(0)->getPatrouilleur(j)->getIsSelected())
                                        jeu->getMonde()->getFlotte(0)->getPatrouilleur(j)->setDestination(jeu->getMouse()->getEndPosMouse());
                                }
                            }
                        }
                        else
                        {
                            unSelectAll(jeu->getMonde());
                            Rectangle* rect = jeu->getMouse()->getRectangleSelection();
                            for(int j = 0; j < jeu->getMonde()->getFlotte(0)->getNbPatrouilleurs(); j++)
                            {
                                if(collisionCercleRectangle(jeu->getMonde()->getFlotte(0)->getPatrouilleur(j)->getCentre(), jeu->getMonde()->getFlotte(0)->getPatrouilleur(j)->getTaille(), rect))
                                {
                                    jeu->getMonde()->getFlotte(0)->getPatrouilleur(j)->setIsSelected(true);
                                }
                            }
                            delete rect;
                        }
                    }
                break;
                default:
                break;
            }
        }
    }
}