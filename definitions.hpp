/** 
* \file definitions.hpp
* \brief Definition des constantes du programme
* \author Louis Lesniak & Hugues Steiner
* \date 10 Nov. 2021
*/

#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#define error(s) {\
        perror(s);\
        exit(EXIT_FAILURE); }

#endif


#define PI 3.14159


#define HAUTEUR_ECRAN 800
#define LARGEUR_ECRAN 800

#define HAUTEUR_INTERFACE 90
#define TAILLE_BOUTON 30
#define TAILLE_ILE1 64

#define PV_CONT_WIDTH 32
#define PV_CONT_HEIGHT 6
#define PV_REMP_WIDTH 30
#define PV_REMP_HEIGHT 4

//Flotte
#define OR_INITIAL 200
#define GAIN_INITIAL 10
#define OR_MAX 9999
#define PV_MAX_FLOTTE 5000

//Bateau
#define NB_CARAC_PATROUILLEUR 5 
#define TAILLE_PATROUILLEUR 24
#define PV_MAX_PATROUILLEUR 20
#define VITESSE_PATROUILLEUR 2
#define DEGAT_PATROUILLEUR 4
#define CADENCE_TIR_PATROUILLEUR 2
#define PORTEE_PATROUILLEUR 60