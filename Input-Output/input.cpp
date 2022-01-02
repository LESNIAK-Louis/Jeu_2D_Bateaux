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
                            for (int i = 0; i < jeu->getMonde()->getFlotte(0)->getNbNavires(); i++){
                               std::cout << "Patrouilleur : " << jeu->getMonde()->getFlotte(0)->getPatrouilleur(i)->getId() << " Flotte :  " << jeu->getMonde()->getFlotte(0)->getPatrouilleur(i)->getIdFlotte() << std::endl;
                            }
                            printf("\n");
                            break;
                        case SDLK_DOWN :
                            break;
                        case SDLK_DELETE :
                            jeu->getMonde()->getFlotte(0)->deleteSelected();
                            break;
                        case SDLK_BACKSPACE:
                            jeu->getMonde()->getFlotte(0)->stopSelected();
                            break;
                        case SDLK_ESCAPE : 
                            jeu->setTerminer(true);
                            break;
                        default:
                        break;
                    }
                break;
                case SDL_MOUSEBUTTONDOWN: // Si une touche souris est enfoncée
                    if(jeu->getEvent()->button.button == SDL_BUTTON_LEFT)
                    {
                        if (jeu->getMouse()->getOrdonnee() > HAUTEUR_INTERFACE) {
                            // On clique sur le terrain
                            jeu->getMonde()->getFlotte(0)->viderListeSelected();
                            jeu->getMouse()->startSelection();
                        } else {
                            //On clique dans l'interface
                            int j = 0, i = 0;
                            bool appuieSurBouton = 0;
                            while (j < 2 && !appuieSurBouton) {
                                while (i < NB_CLASSE_NAVIRE && !appuieSurBouton){
                                    SDL_Rect bouton = {ABSCISSE_INITIALE + i*(10 + TAILLE_BOUTON), 10 + j*(TAILLE_BOUTON + 10), TAILLE_BOUTON, TAILLE_BOUTON};
                                    if (jeu->getMouse()->estEnCollisionAvec(bouton)) {
                                        appuieSurBouton = 1;
                                        appliquerEffetBouton(jeu->getMonde()->getFlotte(0), i, j);
                                    } else {
                                        i++;
                                    }
                                }
                                i = 0;
                                j++;
                            }
                        }
                       
                    }
                    else if(jeu->getEvent()->button.button == SDL_BUTTON_RIGHT) 
                    {
                        if(!isPointingIle(jeu) && jeu->getMouse()->getOrdonnee()>= HAUTEUR_INTERFACE) 
                        {
                            //si le joueur ne clique pas sur une ile ou dans l'interface, le clic est pris en compte
                            jeu->getMonde()->getFlotte(0)->deplacerSelected(jeu->getMouse()->getCurrentPosMouse());
                        }
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
    for(int j = 0; j < flotte->getNbNavires(); j++)
    {
        if(mouse->isSimpleClick())
        {
            if(flotte->getNavire(j)->estEnCollisionAvec(5, mouse->getCurrentPosMouse()))
                flotte->addElemListeSelected(flotte->getNavire(j));
        }
        else
        {
            if(collisionCercleRectangle(flotte->getNavire(j)->getCentre(), flotte->getNavire(j)->getTaille(), rect))
                flotte->addElemListeSelected(flotte->getNavire(j));
        }
    }
    delete rect;
}


void appliquerEffetBouton(Flotte* flotte, int i, int j){
    switch (j){
        case 0:
            switch (i){
                case 0:
                    if (flotte->getQteRessource() < COUT_PATROUILLEUR) {

                    } else {
                        flotte->newPatrouilleur();
                        flotte->addRessource(-COUT_PATROUILLEUR);
                    }
                    
                break;
                case 1:

                break;
                case 2:
                
                break;

            }
        break;

        case 1:
            switch (i){
                case 0:
                    if (flotte->getCaracPatrouilleur(5) < NB_AMELIO_MAX && flotte->getQteRessource() > COUT_AMELIORATION_PATROUILLEUR ) { //on vérifie si les navires ont déjà été améliorés au maximum et que la flotte a suffsiament de ressources
                        flotte->ameliorerPatrouilleurs();
                        flotte->addRessource(-COUT_AMELIORATION_PATROUILLEUR);
                    }
                break;
                case 1:

                break;
                case 2:
                    
                break;
            }
                
        break;
    }
}