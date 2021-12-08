/**
 * \file fichier.cpp
 * \brief Fonctions qui gèrent la communication les fichiers
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#include "fichier.hpp"

unsigned int getNombreLignesFichier(char* path) {
    unsigned int nombreDeLigne = 0;
    FILE *fichier = fopen(path, "r");
    int c;
    if(fichier == NULL)  error("Erreur dans l'ouverture du fichier | getNombreLignesFichier - fichier");
    while ((c=getc(fichier)) != EOF)
        if ('\n' == c)
             ++nombreDeLigne;
    return nombreDeLigne;
}

unsigned int getLongueurMaxColonne(char* path) {
    unsigned int nombreMaxColonne = 0;
    unsigned int nombreMaxTemp = 0;
    FILE *fichier = fopen(path, "r");
    int c;
    if(fichier == NULL)  error("Erreur dans l'ouverture du fichier | getLongueurMaxColonne - fichier");
    while ((c=getc(fichier)) != EOF)
    {
        if ('\n' != c)
            ++nombreMaxTemp;
        else
        {
            if(nombreMaxTemp > nombreMaxColonne)
                nombreMaxColonne = nombreMaxTemp;
            nombreMaxTemp = 0;
        }
    }
    fclose(fichier);
    return nombreMaxColonne;
}

char** lireSauvegarde(char* path){}/*
{
    
    unsigned int nbLigne = getNombreLignesFichier(path);
    unsigned int nbColonne = getLongueurMaxColonne(path);
    char** tab =  allouerTab2D(nbLigne, nbColonne);

    FILE *fichier = fopen(path, "r");
    if (fichier == NULL)  error("Erreur dans l'ouverture du fichier | lireSauvegarde - fichier");
    for(unsigned int i = 0; i < nbLigne; i++)
    {
        for(unsigned int j = 0; j < nbColonne; j++)
        {
            tab[i][j] = 0 ;
        }
    }
    fclose(fichier);
    return tab;
}*/

char** allouerTab2D(int n, int m)
{
    char** tab = (char**)malloc(n*sizeof(char*));
    for(int i =0; i< n; i++)
    {
        tab[i] = (char*)malloc(m*sizeof(char));
        for(int j=0; j < m; j++)
            tab[i][j] = ' ';
    }
    return tab;
}

void desallouerTab2D(char** tab, int n)
{
    for(int i = 0; i < n; i++)
        free(tab[i]);
    free(tab);
}

void afficherTab2D(char** tab, int n, int m)
{
    for(int i = 0; i < n; i++) 
    {
       for(int j = 0; j < m; j++) 
       {
            if(j == (m-1)) 
                std::cout << " " << (*(*(tab+i)+j)) << " \n";             
            else
                std::cout << " " << (*(*(tab+i)+j)) << " \n"; 
          }
     } 
}

void ecrireMonde(std::string path, Monde* monde)
{
    std::ofstream fichierSauvegarde(path.c_str(), std::ios::out | std::ios::app);
    if(!fichierSauvegarde.is_open())  error("Erreur dans l'ouverture du fichier | sauvegarder - fichier");

    for(int i = 0 ; i < monde->getNbFlottes(); i++)
        fichierSauvegarde << monde->getFlotte(i)->formattedInfo() + '\n';

    for(int i = 0 ; i < monde->getNbIles(); i++)
        fichierSauvegarde << monde->getIle(i)->formattedInfo() + '\n';
/*
    for(int i = 0 ; i < monde->getNbIlesBonus(); i++)
    {
        fichierSauvegarde << "Flotte" + std::to_string(i) + "{" + "" +"}" + '\n';
    }

    for(int i = 0 ; i < monde->getNbMines(); i++)
    {
        fichierSauvegarde << "Flotte" + std::to_string(i) + "{" + "" +"}" + '\n';
    }

    for(int i = 0 ; i < monde->getNbTorpilles(); i++)
    {
        fichierSauvegarde << "Flotte" + std::to_string(i) + "{" + "" +"}" + '\n';
    }*/

    fichierSauvegarde.close();
}

bool isFileExist(std::string fileName)
{
    std::ifstream infile(fileName.c_str());
    return infile.good();
}

void sauvegarder(std::string path, Monde* monde)
{
    if(monde == NULL) error("Monde null en param | sauvegarder - fichier");
    if(isFileExist(path.c_str()))
    {
        if(remove(path.c_str()) != 0)
            error("Erreur, un fichier porte deja le nom de la sauvegarde et est impossible a supprimer | sauvegarder - fichier");
    }
    ecrireMonde(path, monde);
}