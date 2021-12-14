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

Point* readPoint(std::string *line)
{
    try{
        int x = std::stoi(line->substr(line->find_first_of("<")+1, line->find_first_of(";") - line->find_first_of("<") -1));
        int y = std::stoi(line->substr(line->find_first_of(";")+1, line->find_first_of(">") - line->find_first_of(";") -1));
        if(line->find_first_of(">")+2 < line->length() && line->find_first_of(">")+2 > 0) // Verification si on est pas en fin de ligne
            *line = line->substr(line->find_first_of(">")+2);

        return new Point(x, y);
    }catch(std::invalid_argument &e){error("Format incorrect du fichier de sauvegarde | readSave - fichier ");}
}


int readNextNumber(std::string *line)
{
    try{
        int number = std::stoi(line->substr(0, line->find_first_of(";")));
        if(line->find_first_of(";")+1 < line->length() && line->find_first_of(";")+1 > 0) // Verification si on est pas en fin de ligne
            *line = line->substr(line->find_first_of(";")+1);

        return number;
    }catch(std::invalid_argument &e){error("Format incorrect du fichier de sauvegarde | readSave - fichier ");}
}

void addPatrouilleurs(std::string *line, Flotte* flotte, int nbPatrouilleurs)
{
    line->substr(1);
    for(int i = 0; i < nbPatrouilleurs; i++)
    {
        flotte->addPatrouilleur(new Patrouilleur(flotte->getNumero(), i, readPoint(line), readPoint(line), readNextNumber(line),readNextNumber(line),readNextNumber(line),readNextNumber(line),readNextNumber(line)));
        flotte->getPatrouilleur(i)->setPv(readNextNumber(line));
    }
    line->substr(2);
}

Monde* readSave(std::string path)
{
    std::ifstream fileSave(path.c_str());
    if(!fileSave.good()) error("Erreur dans la lecture du fichier de sauvegarde | readSave - fichier ");

    std::string line;
    getline(fileSave, line);

    int nbIles = readNextNumber(&line);
    int nbIlesBonus = readNextNumber(&line);
    int time = readNextNumber(&line);
    int difficulte = readNextNumber(&line);
    
    Monde* monde = new Monde(nbIles, nbIlesBonus, time, difficulte);
    
    while(getline(fileSave, line))
    {
        switch(line[0])
        {
            case 'F':
            {
                int numero = std::stoi(line.substr(1, line.find_first_of("{")-1));
                Point* Coord = readPoint(&line);
                Point* Spawn = readPoint(&line);
                int ressource = readNextNumber(&line);
                int gain = readNextNumber(&line);
                int pv = readNextNumber(&line);
                Flotte* flotte = new Flotte(numero, Coord, Spawn, ressource, gain, pv);
                int nbPatrouilleurs = readNextNumber(&line);
                addPatrouilleurs(&line, flotte, nbPatrouilleurs);
                monde->addFlotte(flotte);
            }
            break;
            case 'I':
            {
                line.substr(line.find_first_of("{")+1);
                Point* Pos = readPoint(&line);
                int taille = readNextNumber(&line);
                int forme = readNextNumber(&line);
                Ile* ile = new Ile(Pos, taille, forme);
                monde->setIle(nbIles-1, ile); 
                nbIles--;
            }
            break;
            case 'B':
            break;
            case 'M':
            break;
            case 'T':
            break;
            default:
                error("Erreur de format | readSave - fichier ");
            break;
        }
    }
    fileSave.close();
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

void writeMonde(std::string path, Monde* monde)
{
    std::ofstream fileSave(path.c_str(), std::ios::out | std::ios::app);
    if(!fileSave.is_open())  error("Erreur dans l'ouverture du fichier | sauvegarder - fichier");

    fileSave << monde->formattedInfo();

    fileSave.close();
    SDL_Delay(50);
}

bool isFileExist(std::string fileName)
{
    std::ifstream infile(fileName.c_str());
    bool exist = infile.good();
    SDL_Delay(50);
    return exist;
}

void save(std::string path, Monde* monde)
{
    if(monde == NULL) error("Monde null en param | sauvegarder - fichier");
    if(isFileExist(path.c_str()))
    {
        if(remove(path.c_str()) != 0)
            error("Erreur, un fichier porte deja le nom de la sauvegarde et est impossible a supprimer | sauvegarder - fichier");
    }
    writeMonde(path, monde);
}