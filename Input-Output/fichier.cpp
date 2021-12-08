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

int ctoi(char x)
{
    return (int)x -49;
}

void lirePoint(std::string *line, int *x, int *y)
{
    *x = std::stoi(line.substr(line->find_first_of("<")+1, line->find_first_of(";") - line->find_first_of("<") -1));
    *y = std::stoi(line.substr(line->find_first_of(";")+1, line->find_first_of(">") - line->find_first_of(";") -1));
    *line = line->substr(line.find_first_of(";")+2);
}

Monde* lireSauvegarde(std::string path)
{
    std::ifstream fichierSauvegarde(path.c_str());
    if(!fichierSauvegarde.good()) error("Erreur dans la lecture du fichier de sauvegarde | lireSauvegarde - fichier ");

    std::string line;
    getline(fichierSauvegarde, line);
    //std::cout << line << "\n";
    if(line.length() != 7) error("Format incorrect : donnees du monde | lireSauvegarde - fichier ");
    Monde* monde = new Monde(ctoi(line[0]), ctoi(line[2]), ctoi(line[4]), ctoi(line[6]));
    while(getline(fichierSauvegarde, line))
    {
        switch(line[0])
        {
            case 'F':
            { // int numero, Point* coord, Point* spawn, int ressource, int gain, int pv){
                int numero = std::stoi(line.substr(1, line.find_first_of("{")-1));
                int CoordX;
                int CoordY;
            
                Point* Coord = new Point(CoordX, CoordY);
                lirePoint(&CoordX, &CoordY);
                 std::cout << CoordX << "  " << CoordY << "\n";
                //monde = new FlotteS
            }
            break;
            case 'I':
            break;
            case 'B':
            break;
            case 'M':
            break;
            case 'T':
            break;
            default:
                error("Erreur de format | lireSauvegarde - fichier ");
            break;
        }
    }
    return monde;
}

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

    fichierSauvegarde << monde->formattedInfo() + '\n';

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