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
    BB bb;

    map.spawnBestBuy(1, 3);
    map.spawnNPC(3, 8);
    map.spawnHacker(1, 1);

    char move;         // for storing user input
    int option;        //KORAL MAKE SURE TO USE THIS FOR ANY MENU OPTIONS THAT USE NUMBERS INSTEAD OF LETTERS AS A SELECTION TOOL
    bool quit = false; //if true stops game
    
    string playerName;
    cout << "Please enter a player name: " << endl;
    cin >> playerName;

    cout << "WHERE IN THE CODE IS CARMEN SANDIEGO?\nWelcome, " << playerName << "! You have 200 dogecoins, 1 computer and 1 VPN. You will need to spend the rest of your money on the following items:\n- COMPUTER PARTS. If your computer breaks, you need 5 computer parts to make a new one.\n- ANTIVIRUS SOFTWARE. If your computer is infected with a virus, use the antivirus software to get rid of it.\n- VIRTUAL PRIVATE NETWORK (VPN). The more VPNs you have the harder it is for a hacker to infect your computer with a virus.\n- INTERNET PROVIDER. The better the internet provider, the more reliable your hacking will be.\nYou can spend all of your money here before you start your journey, or you can save some to spend on a different electronics site along the way. But beware, some of the\nwebsites online are shady, and they won’t always give you a fair price..." << endl;

    bb.gameStart(player);

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

        if (map.isBestBuyLocation()) //Best Buy
        {
            cout << "You're in a Best Buy!" << endl;
            bb.gameStart(player);
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
