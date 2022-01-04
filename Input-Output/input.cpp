/**
 * \file input.cpp
 * \brief Gère les entrées utilisateur
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#include "input.hpp"

void gestion_evenements_jeu(SDL_Event* event, Mouse* mouse, Monde* monde, bool* terminer, bool* arreterApplication)
{
    while(SDL_PollEvent(event)) 
    {
        switch(event->type)
        {
            case SDL_QUIT : // Si l'utilisateur a cliqué sur le X de la fenêtre
                *terminer = true;
                *arreterApplication = true;
            break;
            case SDL_KEYDOWN :  // Si une touche clavier est appuyée
                switch (event->key.keysym.sym)
                {
                    case SDLK_RIGHT :
                        break;
                    case SDLK_LEFT :
                        break;
                    case SDLK_UP :
                        for (int i = 0; i < monde->getFlotte(0)->getNbNavires(); i++){
                            std::cout << "ID " << monde->getFlotte(0)->getNavire(i)->getType() <<" : " << monde->getFlotte(0)->getNavire(i)->getId() << std::endl;
                        }
                        printf("\n");
                        break;
                    case SDLK_DOWN :
                        break;
                    case SDLK_DELETE :
                        monde->getFlotte(0)->deleteSelected();
                        break;
                    case SDLK_BACKSPACE:
                        monde->getFlotte(0)->stopSelected();
                        break;
                    case SDLK_ESCAPE : 
                        *terminer = true;
                        break;
                    default:
                    break;
                }
            break;
            case SDL_MOUSEBUTTONDOWN: // Si une touche souris est enfoncée
                if(event->button.button == SDL_BUTTON_LEFT)
                {
                    if (mouse->getOrdonnee() > HAUTEUR_INTERFACE) {
                        // On clique sur le terrain
                        monde->getFlotte(0)->viderListeSelected();
                        mouse->startSelection();
                    } else {
                        //On clique dans l'interface
                        int j = 0, i = 0;
                        bool appuieSurBouton = 0;
                        while (j < 2 && !appuieSurBouton) {
                            while (i < NB_CLASSE_NAVIRE && !appuieSurBouton){
                                SDL_Rect bouton = {ABSCISSE_INITIALE + i*(10 + TAILLE_BOUTON), 10 + j*(TAILLE_BOUTON + 10), TAILLE_BOUTON, TAILLE_BOUTON};
                                if (mouse->estEnCollisionAvec(bouton)) {
                                    appuieSurBouton = 1;
                                    appliquerEffetBouton(monde->getFlotte(0), i, j);
                                } else {
                                    i++;
                                }
                            }
                            i = 0;
                            j++;
                        }
                    }
                    
                }
                else if(event->button.button == SDL_BUTTON_RIGHT) 
                {
                    if(!isPointingIle(monde, mouse) && mouse->getOrdonnee()>= HAUTEUR_INTERFACE) 
                    {
                        //si le joueur ne clique pas sur une ile ou dans l'interface, le clic est pris en compte
                        monde->getFlotte(0)->deplacerSelected(mouse->getCurrentPosMouse());
                    }
                }
            break;
            case SDL_MOUSEMOTION: // Si la souris subit un mouvement
                if(event->button.button == SDL_BUTTON_LEFT){}
                    mouse->updateSelection(); // si on veut ajouter un affichage lors de la selection (rectangle dessiné)
            break;
            case SDL_MOUSEBUTTONUP: // Si une touche souris est relachée
                if(event->button.button == SDL_BUTTON_LEFT)
                {
                    if(mouse->isSelecting())
                    {
                        mouse->endSelection();
                        addNavToSelection(monde->getFlotte(0), mouse);
                    }
                }
            break;
            default:
            break;
        }
    }
}

void gestion_evenements_menu(Menu* menu)
{
    while(SDL_PollEvent(menu->getEvent())) 
    {
        switch(menu->getEvent()->type)
        {
            case SDL_QUIT : // Si l'utilisateur a cliqué sur le X de la fenêtre
                menu->arreterApplication();
            break;
            case SDL_KEYDOWN :  // Si une touche clavier est appuyée
                switch (menu->getEvent()->key.keysym.sym)
                {
                    case SDLK_UP :
                    {
                        menu->decrementerSelecting();
                        break;
                    }
                    case SDLK_DOWN :
                    {
                        menu->incrementerSelecting();
                        break;
                    }
                    case SDLK_RETURN :
                    {
                        switch (menu->getSelecting())
                        {
                            case 0:
                                menu->setTerminer(true);
                                menu->setNewGame(true);
                                break;
                            case 1:
                                menu->setTerminer(true);
                                menu->setNewGame(false);
                                break;
                            case 2:
                                menu->arreterApplication();
                                break;
                            
                            default: error("erreur selection menu | gestion_evenements_menu - input");
                        }
                        break;
                    }
                    case SDLK_ESCAPE :
                    {
                        menu->arreterApplication();
                        break;
                    }
                    default:
                    break;
                }
            break;
            case SDL_MOUSEBUTTONDOWN: // Si une touche souris est enfoncée
                if(menu->getEvent()->button.button == SDL_BUTTON_LEFT)
                {
                    switch (menu->getSelecting())
                        {
                            case 0:
                                menu->setTerminer(true);
                                menu->setNewGame(true);
                                break;
                            case 1:
                                menu->setTerminer(true);
                                menu->setNewGame(false);
                                break;
                            case 2:
                                menu->arreterApplication();
                                break;
                            
                            default: break;
                        }
                        break;
                }
            break;
            case SDL_MOUSEMOTION: // Si une touche souris est enfoncée
            {

            }
            default: break;
        }
    }
}

bool isPointingIle(Monde* monde, Mouse* mouse)
{
    for(int j = 0; j < monde->getNbIles(); j++)
    {
        if(collisionCercles(monde->getIle(j)->getCentre(), monde->getIle(j)->getTaille(), mouse->getCurrentPosMouse(), TAILLE_POINTEUR_SOURIS))
            return true;
    }
    for(int j = 0; j < monde->getNbIlesBonus(); j++)
    {
        if(collisionCercles(monde->getIleBonus(j)->getCentre(), monde->getIleBonus(j)->getTaille(), mouse->getCurrentPosMouse(), TAILLE_POINTEUR_SOURIS)){
            return true;
        }
            
    }
    for(int j = 0; j < monde->getNbFlottes(); j++)
    {
        if(collisionCercles(monde->getFlotte(j)->getCoordBase(), TAILLE_BASE, mouse->getCurrentPosMouse(), TAILLE_POINTEUR_SOURIS)) {
            return true;
        }
    }
    return false;  
}

void addNavToSelection(Flotte* flotte, Mouse* mouse)
{
    if (mouse->getOrdonnee() > HAUTEUR_INTERFACE) { 
        int nbNavireSelectionnes = 0;
        for(int j = 0; j < flotte->getNbNavires(); j++)
        {
            if (nbNavireSelectionnes < NB_SELECTION_MAX) {
                if(mouse->isSimpleClick())
                {
                    if(flotte->getNavire(j)->estEnCollisionAvec(1, mouse->getCurrentPosMouse()))
                    {
                        flotte->addElemListeSelected(flotte->getNavire(j));
                        nbNavireSelectionnes ++;
                        break;
                    }
                }
                else
                {
                    if (mouse->collisionAvecSelection(flotte->getNavire(j)->getCentre()) && flotte->getNavire(j)->getType().compare("Base") != 0)
                    {
                        flotte->addElemListeSelected(flotte->getNavire(j));
                        nbNavireSelectionnes ++;
                    }   
                }
            }

        }
    }    
}

void appliquerEffetBouton(Flotte* flotte, int i, int j){
    switch (j){
        case 0:
            switch (i){
                case 0:
                    if (!(flotte->getQteRessource() < COUT_PATROUILLEUR) ) {
                        flotte->newPatrouilleur();
                        flotte->addRessource(-COUT_PATROUILLEUR);
                    }
                    
                break;
                case 1:
                    if (!(flotte->getQteRessource() < COUT_CROISEUR)) {
                        flotte->newCroiseur();
                        flotte->addRessource(-COUT_CROISEUR);
                    }
                break;
                case 2:
                
                break;

            }
        break;

        case 1:
            switch (i){
                case 0:
                    if (flotte->getCaracPatrouilleur(5) < NB_AMELIO_MAX && flotte->getQteRessource() >= COUT_AMELIORATION_PATROUILLEUR ) { //on vérifie si les navires ont déjà été améliorés au maximum et que la flotte a suffsiament de ressources
                        flotte->ameliorerPatrouilleurs();
                        flotte->addRessource(-COUT_AMELIORATION_PATROUILLEUR);
                    }
                break;
                case 1:
                    if (flotte->getCaracCroiseur(5) < NB_AMELIO_MAX && flotte->getQteRessource() >= COUT_AMELIORATION_CROISEUR ) { //on vérifie si les navires ont déjà été améliorés au maximum et que la flotte a suffsiament de ressources
                        flotte->ameliorerCroiseurs();
                        flotte->addRessource(-COUT_AMELIORATION_CROISEUR);
                    }
                break;
                case 2:
                    
                break;
            }
                
        break;
    }
}