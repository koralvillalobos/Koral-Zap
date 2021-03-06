#include "Action.h"
// CSCI1300 Fall 2021
// Authors: Zaphod Schmidt and Koral Villlalobos
// Recitations: 220 - Pragna Mandadi and 315 - Teo Pice-Broncucia
// Project 3 - Driver

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
    ifstream File; //make sure the file that gets written to is empty 
    string filepath = "KoralSux.txt";

    File.open(filepath.c_str(), std::ifstream::out | std::ifstream::trunc);
    if (!File.is_open() || File.fail())
    {
        File.close();
        printf("\nError : failed to erase file content !");
    }
    File.close();

    srand(time(NULL));

    Map map;       // create object called map of type Map
    Player player; // create object called map of type Player
    Hacker hacker; // create object called map of type Hacker
    Action action; // create object called map of type Action
    Server server; // create object called map of type server
    BB bb;
    NPC npc;

    string move;       //KORAL MAKE SURE TO USE THIS FOR ANY MENU OPTIONS THAT USE NUMBERS INSTEAD OF LETTERS AS A SELECTION TOOL
    bool quit = false; //if true stops game

    string playerName;

    cout << "Please enter a player name: " << endl;
    cin >> playerName;

    cout << "WHERE IN THE CODE IS CARMEN SANDIEGO?\nWelcome, " << playerName << "! You have 200 dogecoins, 1 computer and 1 VPN. You will need to spend the rest of your money on the following items:\n- COMPUTER PARTS. If your computer breaks, you need 5 computer parts to make a new one.\n- ANTIVIRUS SOFTWARE. If your computer is infected with a virus, use the antivirus software to get rid of it.\n- VIRTUAL PRIVATE NETWORK (VPN). The more VPNs you have the harder it is for a hacker to infect your computer with a virus.\n- INTERNET PROVIDER. The better the internet provider, the more reliable your hacking will be.\nYou can spend all of your money here before you start your journey, or you can save some to spend on a different electronics site along the way. But beware, some of the\nwebsites online are shady, and they won???t always give you a fair price..." << endl;

    bb.gameStart(player, server, map, bb); //this is the best buy menu where the user can buy different things for their computer 


    for (int i = 0; i < 5; i++) //for loop for 5 server rooms
    {
        int moveCount = 0;
        server.setRoom(server.getRoom() + 1); //incrementing the server room at each loop
        player.sethackersKilled(0); //setting hackers killed to 0
        map.setHackerCount(0); //hackers places to 0
        map.setNPCCount(0); //NPC placed to 0

        cout << "You are in server room: " << server.getRoom() << endl;

        //randomly spawning Best buy, hackers, NPC at each server loop
        map.randomSpawnBB();
        map.randomSpawnHackers();
        map.randomSpawnNPC();

        //quit bool runs the game
        quit = false;
        while (quit == false)
        {
            //Option Quit
            if (move == "q")
            {
                quit = action.quitGame(move);
                if (quit == true) //Option to quit game
                {
                    action.sortAlg(); //finds # of server rooms attended at sorts based off # of moves executed
                    return 0;
                }
            }
            if (move == "c" && player.gethackersKilled() == map.getHackerCount()) //change server room and exit loop
            {
                quit = true;
            }
            if (player.getcompMaintenanceLvl() < 0) //if computer maintenance reaches 0, player loses
            {
                cout << "You suck your Computer Maintenance Level reached 0 and you lost" << endl;
                action.sortAlg();
                return 0;
            }
            if (player.getFrustration() > 100) //if frustration level reaches 100, player loses
            {
                cout << "You suck you got really frustated and rage quit.\nYour Frustration Level reached 100 so you lost\nGet Gud Scrub" << endl;
                action.sortAlg();
                return 0;
            }
            if(player.getcarmenProg() > 100){
                cout << "The hackers succeed in stealing all of the information out of the servers.\n This means Carmens progress level is equal to or greater than 100! You lose!" << endl;
                action.sortAlg();
                return 0;
            }
            map.displayMap(); // pretty print map_data in terminal
            action.virus(player); //runs the virus function that determines if the player gets a virus or not 
            cout << "Valid moves are: " << endl;
            map.displayMoves(player); // give user a menu of valid moves to pick from

            cout << "Input a move: ";
            cin >> move;
            cout << endl;

            if (move == "m") //this dispays the menu for status updates repairing etc
            {
                bool stop = false; //bool to contiuously display the menu

                do
                {
                    cout << "---MENU---" << endl;
                    cout << "1. Status Update\n2. Repair your Computer\n3. Use your antivirus software\n4. Browse StackOverflow\n5. Check Kill List\n6. Quit" << endl;
                    cin >> move;
                    stop = action.mainMenu(player, bb, npc, move); //calling the main menu function to complete each action of the menu
                } while (stop == false);
            }

            map.executeMove(move); // move the player on map based on user input
            action.misfortune(player, npc, bb); //decide if misfortune happens after each move
            moveCount++; //count number of moves in the server room

            //doge coin increase 5 per move
            player.setDogeCoin(player.getDogeCoin() + 5);
            cout << "+5 DogeCoin added for executed move" << endl;
            cout << "DogeCoin: " << player.getDogeCoin() << endl;

            //frustration increase 2 per move
            player.setFrustration(player.getFrustration() + 2);
            cout << "+2 Frustration level added for executed move" << endl;
            cout << "Frustration level: " << player.getFrustration() << endl;

            if (bb.getNumbGPU() > 0) //each move will incease doge depending on GPU amount
            {
                player.setDogeCoin(player.getDogeCoin() + (bb.getNumbGPU() * 5));
                cout << "You have " << bb.getNumbGPU() << " GPU(s), and there for have recieved +" << bb.getNumbGPU() * 5 << " dogecoin." << endl;
                cout << "DogeCoin: " << player.getDogeCoin() << endl;
            }
            if (map.isBestBuyLocation()) //Best Buy
            {
                cout << "You're in a Best Buy!" << endl;
                bb.gameStart(player, server, map, bb); //call best buy function to purchase items if in BB location
            }
            if (map.isHackerLocation()) //Starts Hacker Action
            {
                string name = hacker.pickHackerName(server.getRoom()); //function to randomly pick a hacker based on the server room
                cout << "You just ran into " << name << "! Think you can beat this hacker???s skills?" << endl;
                bool stop = false;
                action.displayHackerMenu(); //display hackermenu to fight or forefit

                while (stop == false)
                {
                    cout << "Input an option: " << endl;
                    cin >> move;
                    cout << endl;
                    stop = action.executeHackerMenu(move, player, hacker, map); //execute hacker menu of fighting hacker that involves probablity
                    cout << endl;
                }

                ofstream file;
                file.open("KoralSux.txt", ios::app); //write hacker names to a file to keep track of those defeated

                action.inFstreamNames(file, name);

                cout << "Hackers killed: " << player.gethackersKilled() << endl;
                if (player.gethackersKilled() == map.getHackerCount()) //seeing if the player can move to next server room or not
                {
                    cout << "Now you need to move onto the next server room bc the number of hackers in this room has been defeated" << endl; //somehow right here the server room needs to change
                }
            }

            if (map.isNPCLocation()) //Starts NPC Action
            {
                bool start = false; //bool runs the NPC menu
                cout << "You've encountered an NPC!" << endl;
                do
                {
                    cout << "1. Complete Puzzle" << endl;
                    cout << "2. Take Your Chances" << endl;
                    cout << "3. Quit" << endl;
                    start = npc.runNPCMenu(player, move, bb, map); //NPC menu to complete puzzle or take chances with the NPC 
                } while (start == false);
            }
        }
        action.storeMoves(server.getRoom(),moveCount); //stores the moves for the sorting algoritm
    }
    cout << "You Win! You beat the final Hacker in the final server room good job!" << endl;
    action.sortAlg();
}
