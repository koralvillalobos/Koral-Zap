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
    string playerName;

    cout << "Please enter a player name: " << endl;
    cin >> playerName;

    cout << "WHERE IN THE CODE IS CARMEN SANDIEGO?\nWelcome, " << playerName << "! You have 200 dogecoins, 1 computer and 1 VPN. You will need to spend the rest of your money on the following items:\n- COMPUTER PARTS. If your computer breaks, you need 5 computer parts to make a new one.\n- ANTIVIRUS SOFTWARE. If your computer is infected with a virus, use the antivirus software to get rid of it.\n- VIRTUAL PRIVATE NETWORK (VPN). The more VPNs you have the harder it is for a hacker to infect your computer with a virus.\n- INTERNET PROVIDER. The better the internet provider, the more reliable your hacking will be.\nYou can spend all of your money here before you start your journey, or you can save some to spend on a different electronics site along the way. But beware, some of the\nwebsites online are shady, and they won’t always give you a fair price..." << endl;

    char purchaseAns;

    cout << "Would you like to purchase anything from Best Buy?" << endl;
    cout << "y (yes)" << endl;
    cout << "n (No)" << endl;
    cin >> purchaseAns;

    if (purchaseAns == 'y')
    {
        cout << "---Menu---" << endl;
        cout << "1. Computer Parts\n2. Antivirus software\n3. Virtual Private Network (VPN)\n4. Internet Provider" << endl;
        cout << "Please input what you would like to buy." << endl;
        cin >> option;

        switch (option)
        {
        case 1:
            int computerPartChoice;
            int computerPartItem;
            cout << "Best Buy recommends that the player should purchase at least 1 of each computer part in case your main computer breaks.\nYou can have a maximum of 3 of each computer part and 1 extra premade computer. These are the different parts:" << endl;
            cout << "▪ A CPU costs 10 Dogecoins" << endl;
            cout << "▪ A GPU costs 20 Dogecoins" << endl;
            cout << "▪ A Power Supply Unit costs 5 Dogecoins" << endl;
            cout << "▪ An internet card costs 5 Dogecoins" << endl;
            cout << "▪ A keyboard and mouse costs 10 Dogecoins" << endl;
            cout << "▪ A premade computer costs 100 Dogecoins" << endl;
            cout << "How many parts do you wish to purchase?" << endl;
            cin >> computerPartChoice;

            for (int i = 1; i < computerPartChoice; i++)
            {
                cout << "Choose what you would like to purchase: " << endl;
                cout << "1. CPU\n2. GPU\n3. Power Supply Unit\n4. Internet card\n5. Keyboard and mouse\n6. Premade computer" << endl;
                cin >> computerPartItem;

                switch (computerPartItem)
                {
                case 1:
                    player.setDogeCoin(player.getDogeCoin() - 10);
                    cout << "DogeCoin: " << player.getDogeCoin() << endl;
                    i++;
                    break;

                case 2:
                    player.setDogeCoin(player.getDogeCoin() - 20);
                    cout << "DogeCoin: " << player.getDogeCoin() << endl;
                    i++;
                    break;

                case 3:
                    player.setDogeCoin(player.getDogeCoin() - 5);
                    cout << "DogeCoin: " << player.getDogeCoin() << endl;
                    i++;
                    break;

                case 4:
                    player.setDogeCoin(player.getDogeCoin() - 5);
                    cout << "DogeCoin: " << player.getDogeCoin() << endl;
                    i++;
                    break;

                case 5:
                    player.setDogeCoin(player.getDogeCoin() - 10);
                    cout << "DogeCoin: " << player.getDogeCoin() << endl;
                    i++;
                    break;

                case 6:
                    player.setDogeCoin(player.getDogeCoin() - 100);
                    cout << "DogeCoin: " << player.getDogeCoin() << endl;
                    i++;
                    break;

                default:
                    cout << "Invalid choice. Try again." << endl;
                    break;
                }
            }
            break;

        case 2:
            int antivirusUSBChoice;
            cout << "One USB stick of antivirus software costs 10 Dogecoins and will give you a one-time use to get rid of any viruses on your computer." << endl;

            cout << "How many antivirus USB sticks would you like to purchase?" << endl;
            cin >> antivirusUSBChoice;

            player.setDogeCoin(player.getDogeCoin() - 10 * (antivirusUSBChoice));
            player.setantiVirusUSBcount(player.getantiVirusUSBcount() + antivirusUSBChoice);
            cout << "DogeCoin: " << player.getDogeCoin() << endl;
            cout << "Antivirus: " << player.getantiVirusUSBcount();

            break;

        case 3:
            int VPNChoice;
            cout << "A VPN costs 20 Dogecoins each. VPNs reduce your chances of getting hacked by preventing hackers from tracking down your main computer. The increase in security maxes out at 2 VPNs" << endl;

            cout << "How many VPNs would you like to purchase?" << endl;
            cin >> VPNChoice;

            player.setDogeCoin(player.getDogeCoin() - 20 * (VPNChoice));
            player.setVPNsOwned(player.getVPNsOwned() + VPNChoice);
            cout << "DogeCoin: " << player.getDogeCoin() << endl;
            cout << "VPN: " << player.getVPNsOwned();

            break;

        case 4:
            int internetLevelChoice;
            int i = 0;
            cout << "Internet provider level 2 costs 10 Dogecoins\nInternet provider level 3 costs 25 Dogecoins\nInternet provider level 4 costs 40 Dogecoins\nInternet provider level 5 costs 50 Dogecoins\n Also keep in mind you can upgrade your internet provider at a later time if you so desire" << endl;
            cout << "Choose what you would like to purchase: " << endl;
            cout << "2. Level 2\n 3. Level 3\n4. Level 4\n5. Level 5" << endl;
            cin >> internetLevelChoice;

            do
            {

                switch (internetLevelChoice)
                {
                case 2:
                    player.setDogeCoin(player.getDogeCoin() - 10);
                    player.setinternetProv(internetLevelChoice);
                    i++;
                    break;

                case 3:
                    player.setDogeCoin(player.getDogeCoin() - 25);
                    player.setinternetProv(internetLevelChoice);
                    i++;
                    break;

                case 4:
                    player.setDogeCoin(player.getDogeCoin() - 40);
                    player.setinternetProv(internetLevelChoice);
                    i++;
                    break;

                case 5:
                    player.setDogeCoin(player.getDogeCoin() - 50);
                    player.setinternetProv(internetLevelChoice);
                    i++;
                    break;

                default:
                    cout << "Invalid choice. Try again." << endl;
                    break;
                }
            } while (i < 1);

            cout << "DogeCoin: " << player.getDogeCoin() << endl;
            cout << "Internet Level: " << player.getinternetProv() << endl;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    }

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
