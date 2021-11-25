#include "Action.h"
#include "BB.h"
#include "Hacker.h"
#include "Map.h"
#include "Player.h"
#include "Server.h"

using namespace std;

int main()
{

    Map map;       // create object called map of type Map
    Player player; // create object called map of type Player
    Hacker hacker; // create object called map of type Hacker
    Action action; // create object called map of type Action
    Server server; // create object called map of type server

    map.spawnBestBuy(1, 3);
    map.spawnNPC(3, 8);
    map.spawnHacker(1, 1);

    char move;         // for storing user input
    int option;        //KORAL MAKE SURE TO USE THIS FOR ANY MENU OPTIONS THAT USE NUMBERS INSTEAD OF LETTERS AS A SELECTION TOOL
    bool quit = false; //if true stops game

    while (quit == false)
    {
        map.displayMap(); // pretty print map_data in terminal
        action.virus(player);
        cout << "Valid moves are: " << endl;
        map.displayMoves(); // give user a menu of valid moves to pick from

        cout << "Input a move: ";
        cin >> move;
        cout << endl;
        map.executeMove(move); // move the player on map based on user input

        if (map.isBestBuyLocation())//Best Buy
        {
            cout << "You're in a Best Buy!" << endl;
        }
        if (map.isHackerLocation()) //Starts Hacker Action
        {
            bool stop = false;
            action.displayHackerMenu();

            while (stop == false)
            {
                cout << "Input an option: " << endl;
                cin >> option;
                cout << endl;
                stop = action.executeHackerMenu(option, player, hacker);
                cout << endl;
            }
        }
        if (map.isNPCLocation()) //Starts NPC Action
        {
            cout << "You've encountered an NPC!" << endl;
        }

        //Option Quit
        if (move == 'q')
        {
            quit = action.quitGame(move); //Option to quit game
        }
    }
}
