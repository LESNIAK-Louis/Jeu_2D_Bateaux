#include "jeu.hpp"

void init_textures_jeu(SDL_Renderer *renderer, textures_s* textures){
    textures->fond = charger_image("Ressources/fond.bmp", renderer);
    textures->ile = charger_image("Ressources/ile.bmp", renderer);
    textures->contourPV = charger_image("Ressources/contourBarrePV.bmp", renderer);
    textures->remplissagePV = charger_image("Ressources/remplissageBarrePV.bmp", renderer);
    textures->remplissagePVEnnemis = charger_image("Ressources/remplissageBarrePVEnnemis.bmp", renderer);
    textures->patrouilleur = charger_image("Ressources/patrouilleur.bmp", renderer);
    textures->croiseur = charger_image("Ressources/croiseur.bmp", renderer);
    textures->porteAvion = charger_image("Ressources/porteAvion.bmp", renderer);
    textures->interface = charger_image("Ressources/interface.bmp", renderer);
    textures->bouton = charger_image("Ressources/bouton.bmp", renderer);
    textures->plus = charger_image("Ressources/plus.bmp", renderer);
    textures->point = charger_image("Ressources/point.bmp", renderer);
    textures->tir = charger_image("Ressources/tir.bmp", renderer);
    textures->explosion = charger_image("Ressources/explosion.bmp", renderer);
    textures->police = charger_police("Ressources/arial.ttf", 16);
}

void afficherMonde(SDL_Renderer* ecran, Monde* monde, textures_s* textures){ 
    
    afficherIles(ecran, monde, textures);
    afficherIlesBonus(ecran, monde,textures);
    afficherFlottes(ecran, monde, textures);
    afficherInterface(ecran, monde, textures);
}

void afficherInterface(SDL_Renderer* ecran, Monde* monde, textures_s* textures){
    SDL_Rect DstR = {0, 0, LARGEUR_ECRAN, HAUTEUR_INTERFACE};
    SDL_RenderCopy(ecran, textures->interface, NULL, &DstR);
    afficherInformations(ecran, monde->getFlotte(0), textures);
    afficherTousLesBoutons(ecran, textures);
}

void afficherInformations(SDL_Renderer* ecran, Flotte* flotte, textures_s* textures){
    std::string string = "Or : ";
    int ressource = flotte->getQteRessource();
    string = string + std::to_string(ressource);
    const char* quantiteOr = string.c_str();
    SDL_Color couleurTexteInterface = { 231, 76, 60, 255};
    SDL_Rect DestR = {10 ,10 ,0 ,0};
    afficher_texte(quantiteOr, ecran, DestR, textures->police, couleurTexteInterface, 1);
    afficherSelection(ecran, flotte->getListeSelected(), textures, 0, 0);
}

void afficherSelection(SDL_Renderer* ecran, selectedNavire* liste, textures_s* textures, int decalageHorizontal, int decalageVertical){
    if (!estVide(liste)){
        std::string type = prem(liste)->getType();
        if (type.compare("Patrouilleur") == 0){
            afficherBouton(ecran, textures, ABSCISSE_INITIALE_SELECTION + decalageHorizontal*(10 + TAILLE_BOUTON), 10 + decalageVertical*(TAILLE_BOUTON + 10), 0, 0);
        } else if (type.compare("Croiseur") == 0) {
            afficherBouton(ecran, textures, ABSCISSE_INITIALE_SELECTION + decalageHorizontal*(10 + TAILLE_BOUTON), 10 + decalageVertical*(TAILLE_BOUTON + 10), 1, 0);
        } else if (type.compare("Porte-Avions") == 0) {
            afficherBouton(ecran, textures, ABSCISSE_INITIALE_SELECTION + decalageHorizontal*(10 + TAILLE_BOUTON), 10 + decalageVertical*(TAILLE_BOUTON + 10), 2, 0);
        }
        decalageHorizontal++;
        if (decalageHorizontal > NB_CLASSE_NAVIRE/2) {
            decalageHorizontal = 0;
            decalageVertical++;
        }
        if ( !estVide(rest(liste)) ) {
            afficherSelection(ecran, rest(liste), textures, decalageHorizontal, decalageVertical++);
        }
    }
}

void afficherTousLesBoutons(SDL_Renderer* ecran, textures_s* textures){
    //Affichage des boutons de contruction et d'amélioration des bateaux
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < NB_CLASSE_NAVIRE; i++){
            afficherBouton(ecran, textures, ABSCISSE_INITIALE + i*(10 + TAILLE_BOUTON), 10 + j*(TAILLE_BOUTON + 10), i, j);
        }
    }
    
}

void afficherBouton(SDL_Renderer* ecran, textures_s* textures, int abscisse, int ordonnee, int i, int j){
    SDL_Rect DestR = {abscisse, ordonnee, TAILLE_BOUTON, TAILLE_BOUTON};
    SDL_RenderCopy(ecran, textures->bouton, NULL, &DestR);
    DestR.x = abscisse + 5;
    DestR.y = ordonnee + 5;
    DestR.w = TAILLE_BOUTON - 10;
    DestR.h = TAILLE_BOUTON - 10;
    switch (i) {
        case 0:
            SDL_RenderCopy(ecran, textures->patrouilleur, NULL, &DestR);
            break;
        case 1:
            SDL_RenderCopy(ecran, textures->croiseur, NULL, &DestR);
            break;
        case 2:
            SDL_RenderCopy(ecran, textures->porteAvion, NULL, &DestR);
            break;
    }
    if (j==1) {
        SDL_RenderCopy(ecran, textures->plus, NULL, &DestR);
    }
}


void afficherIles(SDL_Renderer* ecran, Monde* monde, textures_s* textures){
    for (int i = 0; i < monde->getNbIles(); i++) {
        SDL_Rect DestR = {monde->getIle(i)->getAbscisse()-(TAILLE_ILE1/2), monde->getIle(i)->getOrdonnee()-(TAILLE_ILE1/2),TAILLE_ILE1, TAILLE_ILE1};
        SDL_RenderCopy(ecran, textures->ile, NULL, &DestR);
    }

}

void afficherIlesBonus(SDL_Renderer* ecran, Monde* monde, textures_s* textures){
    for (int i = 0; i < monde->getNbIlesBonus(); i++) {
        SDL_Rect DestR = {monde->getIleBonus(i)->getCentre()->getAbscisse()-(TAILLE_ILE2/2), monde->getIleBonus(i)->getCentre()->getOrdonnee()-(TAILLE_ILE2/2),TAILLE_ILE2, TAILLE_ILE2};
        SDL_RenderCopy(ecran, textures->ile, NULL, &DestR);
        for (int p = 0; p < monde->getIleBonus(i)->getNbDefenseur(); p++) {
            SDL_Rect DestR = {monde->getIleBonus(i)->getDefenseur(p)->getAbscisse()-TAILLE_PATROUILLEUR/2, monde->getIleBonus(i)->getDefenseur(p)->getOrdonnee()-TAILLE_PATROUILLEUR/2,TAILLE_PATROUILLEUR, TAILLE_PATROUILLEUR};
            SDL_RenderCopyEx(ecran, textures->patrouilleur, NULL, &DestR, monde->getIleBonus(i)->getDefenseur(p)->getAngle(), NULL, SDL_FLIP_NONE);
            afficherBarreDeVie(monde->getIleBonus(i)->getDefenseur(p), ecran, textures);      
        }
    }
}

void afficherFlottes(SDL_Renderer* ecran, Monde* monde, textures_s* textures){
    for (int f = 0; f < monde->getNbFlottes(); f++){
        afficherNavires(ecran, monde->getFlotte(f), textures);
    }
}

void afficherNavires(SDL_Renderer* ecran, Flotte* flotte, textures_s* textures){
    for (int n = 0; n < flotte->getNbNavires(); n++){
        std::string type = flotte->getNavire(n)->getType();
        if (type.compare("Patrouilleur") == 0) {
            afficherPatrouilleur(ecran, textures, flotte->getNavire(n));
        } else if (type.compare("Croiseur") == 0){
            afficherCroiseur(ecran, textures, flotte->getNavire(n));
        }
    }
}

void afficherPatrouilleur(SDL_Renderer* ecran, textures_s* textures, Navire* navire){
    SDL_Rect DestR = {navire->getAbscisse()-(navire->getTaille()/2), navire->getOrdonnee()-(navire->getTaille()/2),navire->getTaille(), navire->getTaille()};
    SDL_RenderCopyEx(ecran, textures->patrouilleur, NULL, &DestR, navire->getAngle(), NULL, SDL_FLIP_NONE);
    afficherBarreDeVie(navire, ecran, textures);

    //Permet d'afficher un point sur le wayPoint du patrouilleur. A utiliser pour le debuggage
    /*SDL_Texture* texturePoint = charger_image("Ressources/point.bmp", ecran);
    DestR = {flotte->getPatrouilleur(p)->getWayPoint()->getAbscisse(), flotte->getPatrouilleur(p)->getWayPoint()->getOrdonnee(),5, 5};
    SDL_RenderCopy(ecran, texturePoint, NULL, &DestR);*/
}

void afficherCroiseur(SDL_Renderer* ecran, textures_s* textures, Navire* navire){
    SDL_Rect DestR = {navire->getAbscisse()-(navire->getTaille()/2), navire->getOrdonnee()-(navire->getTaille()/2),navire->getTaille(), navire->getTaille()};
    SDL_RenderCopyEx(ecran, textures->croiseur, NULL, &DestR, navire->getAngle(), NULL, SDL_FLIP_NONE);
    afficherBarreDeVie(navire, ecran, textures);

    //Permet d'afficher un point sur le wayPoint du croiseur. A utiliser pour le debuggage
    /*SDL_Texture* texturePoint = charger_image("Ressources/point.bmp", ecran);
    DestR = {flotte->getCroiseur(c)->getWayPoint()->getAbscisse(), flotte->getCroiseur(c)->getWayPoint()->getOrdonnee(),5, 5};
    SDL_RenderCopy(ecran, texturePoint, NULL, &DestR);*/
}


void afficherBarreDeVie(Navire* navire, SDL_Renderer* ecran, textures_s* textures){

    double ratio = (double)navire->getPv() / (double)navire->getPvMax();
    SDL_Rect DestRExt = {navire->getAbscisse()-navire->getTaille()/2, navire->getOrdonnee()-navire->getTaille()/2 - 8, PV_CONT_WIDTH, PV_CONT_HEIGHT};
    SDL_Rect DestRInt = {navire->getAbscisse()-navire->getTaille()/2 +1, navire->getOrdonnee()-navire->getTaille()/2 - 7, (int)round(PV_REMP_WIDTH * ratio), PV_REMP_HEIGHT};

    SDL_RenderCopy(ecran, textures->contourPV, NULL, &DestRExt);
    if (navire->getIdFlotte() == 0) {
        SDL_RenderCopy(ecran, textures->remplissagePV, NULL, &DestRInt);
    } else {
        SDL_RenderCopy(ecran, textures->remplissagePVEnnemis, NULL, &DestRInt);
    }
    
}

void destroy_textures_jeu(textures_s* textures){
    if(textures != NULL)
    {
        if(NULL != textures->bouton) SDL_DestroyTexture(textures->bouton);
        if(NULL != textures->contourPV) SDL_DestroyTexture(textures->contourPV);
        if(NULL != textures->croiseur) SDL_DestroyTexture(textures->croiseur);
        if(NULL != textures->explosion) SDL_DestroyTexture(textures->explosion);
        if(NULL != textures->fond) SDL_DestroyTexture(textures->fond);
        if(NULL != textures->ile) SDL_DestroyTexture(textures->ile);
        if(NULL != textures->interface) SDL_DestroyTexture(textures->interface);
        if(NULL != textures->patrouilleur) SDL_DestroyTexture(textures->patrouilleur);
        if(NULL != textures->plus) SDL_DestroyTexture(textures->plus);
        if(NULL != textures->point) SDL_DestroyTexture(textures->point);
        if(NULL != textures->police) TTF_CloseFont(textures->police);
        if(NULL != textures->porteAvion) SDL_DestroyTexture(textures->porteAvion);
        if(NULL != textures->remplissagePV) SDL_DestroyTexture(textures->remplissagePV);
        if(NULL != textures->remplissagePVEnnemis) SDL_DestroyTexture(textures->remplissagePVEnnemis);
        if(NULL != textures->tir) SDL_DestroyTexture(textures->tir);
    }
}