#include "Menu.hpp"
#include "Game.hpp"

int main()
{
    initSDL();
    bool arreterApplication = false;
    bool newGame =  true;
    while(!arreterApplication)
    {
        Menu* menu = new Menu(&arreterApplication, &newGame); delete menu;
        Game* jeu = new Game(&arreterApplication, &newGame); delete jeu;
    }

    quitSDL();
    return 0;
}