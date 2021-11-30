#include "Action.h"
#include "BB.h"
#include "Hacker.h"
#include "Map.h"
#include "Player.h"
#include "Server.h"
#include "NPC.h"

using namespace std;

string makeLower(string name)
{

    for (int i = 0; i < name.length(); i++)
    { //iterate through the string
        if (name[i] >= 65 && name[i] <= 90)
        {                  //if uppercase found
            name[i] += 32; //make lower
        }
    }
    return name;
}

int main()
{

    Map map;       // create object called map of type Map
    Player player; // create object called map of type Player
    Hacker hacker; // create object called map of type Hacker
    Action action; // create object called map of type Action
    Server server; // create object called map of type server
    BB bb;
    NPC npc;

    player.sethackersKilled(0);

    char move;         // for storing user input
    int option;        //KORAL MAKE SURE TO USE THIS FOR ANY MENU OPTIONS THAT USE NUMBERS INSTEAD OF LETTERS AS A SELECTION TOOL
    bool quit = false; //if true stops game

    string playerName;
    cout << "Please enter a player name: " << endl;
    cin >> playerName;

    cout << "WHERE IN THE CODE IS CARMEN SANDIEGO?\nWelcome, " << playerName << "! You have 200 dogecoins, 1 computer and 1 VPN. You will need to spend the rest of your money on the following items:\n- COMPUTER PARTS. If your computer breaks, you need 5 computer parts to make a new one.\n- ANTIVIRUS SOFTWARE. If your computer is infected with a virus, use the antivirus software to get rid of it.\n- VIRTUAL PRIVATE NETWORK (VPN). The more VPNs you have the harder it is for a hacker to infect your computer with a virus.\n- INTERNET PROVIDER. The better the internet provider, the more reliable your hacking will be.\nYou can spend all of your money here before you start your journey, or you can save some to spend on a different electronics site along the way. But beware, some of the\nwebsites online are shady, and they won’t always give you a fair price..." << endl;

    bb.gameStart(player,server);

    //need random seed

    for (int i = 0; i < 5; i++)
    {
        server.setRoom(server.getRoom() + 1);
        cout << "You are in server room: " << server.getRoom() << endl;

        int spawnNumb = rand() % 3;
        for (int k = 0; k < spawnNumb; k++) //i = numb NPC
        {
            int NPCNumbRow = rand() % 5;
            int NPCNumbCols = rand() % 9;
            map.spawnNPC(NPCNumbRow, NPCNumbCols);
        }

        spawnNumb = rand() % 3;
        for (int j = 0; j < spawnNumb; j++) // j = numb hackers
        {
            int hackerNumbRow = rand() % 5;
            int hackerNumbCol = rand() % 9;
            map.spawnHacker(hackerNumbRow, hackerNumbCol);
        }
        int BBNumbRow = rand() % 5;
        int BBNumbCol = rand() % 9;

        map.spawnBestBuy(BBNumbRow, BBNumbCol);

        cout << "number hackers and NPC placed:" << spawnNumb << endl;

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

            player.setDogeCoin(player.getDogeCoin() + 5);
            cout << "+5 DogeCoin added for executed move" << endl;
            cout << "DogeCoin: " << player.getDogeCoin() << endl;
            
            if(bb.getNumbGPU() > 0){
                player.setDogeCoin(player.getDogeCoin() + (bb.getNumbGPU() * 5));
                cout << "You have " << bb.getNumbGPU() << " GPU(s), and there for have recieved +" << bb.getNumbGPU() * 5 << "dogecoin." << endl;
                cout << "DogeCoin: " << player.getDogeCoin() << endl;
            }
            if (map.isBestBuyLocation()) //Best Buy
            {
                cout << "You're in a Best Buy!" << endl;
                bb.gameStart(player,server);
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
                    stop = action.executeHackerMenu(option, player, hacker,map);
                     //hackers killed need to be removed from map
                    cout << endl;
                }
                cout << "Hackers killed: " << player.gethackersKilled() << endl;
                if(player.gethackersKilled() == spawnNumb){
                    
                    cout << "Now you need to move onto the next server room bc the number of hackers in this room has been defeated" << endl; //somehow right here the server room needs to change 
                    i++;
                    break;
                }
            }
            
            if (map.isNPCLocation()) //Starts NPC Action
            {
                bool start = false;
                cout << "You've encountered an NPC!" << endl;
                while (start == false)
                {
                    cout << "1. Complete Puzzle" << endl;
                    cout << "2. Take Your Chances" << endl;
                    start = npc.runNPCMenu(player, option, bb);
                }
            }
            

            //Option Quit
            if (move == 'q')
            {
                quit = action.quitGame(move); //Option to quit game
            }
        }
    }
}
