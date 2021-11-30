// CSCI1300 Fall 2021
// Authors: Zaphod Schmidt and Koral Villalobos
// Recitations: 220 - Pragna Mandadi and 315 - Teo Pice-Broncucia
// Project 3 - Action Implimentation

#include "Player.h"
#include "Hacker.h"
#include "BB.h"
#include "Map.h"
#include "NPC.h"
#include "Action.h"
#include <fstream>
#include <iostream>
#include <ctype.h>
#include <iomanip>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;

//Misfortunes

Action::Action()
{
}

void Action::statusUpdate(Player &player)
{
    cout << "Computer Maintenance Level: " << player.getcompMaintenanceLvl() << endl;
    cout << "# computer viruses: " << player.getnumbVirus() << endl;
    cout << "# computer parts avaliable: " << player.getcompPartsAvailable() << endl;
    cout << "Antivirus USB sticks available: " << player.getantiVirusUSBcount() << endl;
    cout << "VPNs available: " << player.getVPNsOwned() << endl;
    cout << "Internet provider level: " << player.getinternetProv() << endl;
    cout << "Doge coin available: " << player.getDogeCoin() << endl;
    cout << "Player frustration level: " << player.getFrustration() << endl;
    cout << "Carmen’s progress: " << player.getcarmenProg() << endl;
    cout << "Hackers defeated: " << player.gethackersKilled() << endl;
}
void Action::displayHackerMenu()
{
    cout << "Valid moves are: " << endl;
    cout << "1. Fight the hacker" << endl;
    cout << "2. Forfeit the fight (lose all computer parts!)" << endl;
}
bool Action::executeHackerMenu(int option, Player &player, Hacker &hacker, Map &map)
{
    bool stop;
    if (option == 1) //Fight condition for player
    {
        return fightHacker(player, hacker, map);
    }
    else if (option == 2) //Forfeit option for player
    {
        return forfeit(player);
    }
    else //Edge case for Invalid key
    {
        cout << "Invalid Input" << endl;
        return false;
    }
}
bool Action::fightHacker(Player &player, Hacker &hacker, Map &map)
{
    int r1 = rand() % 6;
    int r2 = rand() % 6;
    int virusChance = rand() % 10;
    int internetProviderLvl = player.getinternetProv();
    int VPN = player.getVPNsOwned();
    int ChallegeLevel = hacker.getChallegeLevel();
    double v = (1 / VPN);

    if (VPN < 1)
    {
        v = 0;
    }
    int result = (r1 * internetProviderLvl) - ((r2 * ChallegeLevel) * v);

    if (result > 0) //if result is more than palyer wins
    {
        int tempRow;
        int tempCol;

        player.sethackersKilled(player.gethackersKilled() + 1);
        player.setDogeCoin(player.getDogeCoin() + 50); //gives player 50 doge for win
        cout << "Win " << endl;
        cout << "+50 "
             << "Doge: " << player.getDogeCoin() << endl;
        cout << "Computer Maintenance Level: " << player.getcompMaintenanceLvl() << endl;
        tempRow = map.getPlayerRowPosition();
        tempCol = map.getPlayerColPosition();

        map.removeHacker();
        return true;
    }
    else //if result is less than 0 or 0 palyer loses
    {
        //loses 20 maintenanceLvl
        player.setcompMaintenanceLvl(player.getcompMaintenanceLvl() - 20);
        cout << "Lose" << endl;
        cout << "Doge: " << player.getDogeCoin() << endl;
        cout << "-20 "
             << "Computer Maintenance Level: " << player.getcompMaintenanceLvl() << endl;

        //there is a 10% chance of getting a virus
        if (virusChance == 0)
        {
            player.setnumbVirus(player.getnumbVirus() + 1);
            cout << "+1 Virus" << endl;
            cout << "Virus: " << player.getnumbVirus() << endl;
        }
        return false;
    }
}
bool Action::forfeit(Player &player)
{
    //player loses all spare computer parts
    player.setcompPartsAvailable(0);
    cout << "Lose all Computer Parts!" << endl;
    cout << "Computer parts: " << player.getcompPartsAvailable() << endl;
    return true;
}

void Action::virus(Player &player)
{
    if (player.getnumbVirus() > 0)
    {
        //subtracts computer maintenance -10 per virus
        player.setcompMaintenanceLvl(player.getcompMaintenanceLvl() - (10 * player.getnumbVirus()));

        cout << "-" << (10 * player.getnumbVirus()) << " Computer Maintenace" << endl;
        cout << " Computer Maintenace Level: " << player.getcompMaintenanceLvl() << endl;
    }
}
//The player can choose to use a USB stick of antivirus software to rid their computer of viruses. See the section on Viruses for more information.
void Action::useantiVirus(Player &player)
{
    if (player.getantiVirusUSBcount() > 0) //using sets number of virus' to zero
    {
        player.setnumbVirus(0);
        player.setantiVirusUSBcount(player.getantiVirusUSBcount() - 1);
    }
}

void Action::CompletePuzzle(string name)
{
    ifstream file;
    string line = "";
    vector<string> question;

    file.open(name);

    if (file.is_open()) //open and read puzzel file
    {
        while (getline(file, line))
        {
            int i = 0;
            if (line == "---")
            {
                break;
            }
            question[i] = line;
            i++;
        }
    }
    else
    {
        cout << "File did not open!" << endl;
    }
    for (int i = 0; i < question.size(); i++)
    {
        cout << question[i] << endl;
    }
}
string Action::RockPaperScissors(int numb)
{
    //1.Rock
    //2.Paper
    //3.Scissors
    //true means win
    //false means loss

    string win = "Win";
    string loss = "Loss";
    string tie = "Tie";
    int computerPick = rand() % 3;
    bool end = false;
    cout << "compPick" << computerPick << endl;

    while (end == false)
    {
        switch (numb)
        {
        //1.Rock
        case 1:

            if (computerPick == 1)
            {
                end = true;
                return tie;
                break;
            }
            if (computerPick == 2)
            {
                end = true;
                return loss;
                break;
            }
            if (computerPick == 3)
            {
                end = true;
                return win;
                break;
            }
        //2.Paper
        case 2:
            if (computerPick == 1)
            {
                end = true;
                return win;
                break;
            }
            if (computerPick == 2)
            {

                end = true;
                return tie;
                break;
            }
            if (computerPick == 3)
            {
                end = true;
                return loss;
                break;
            }
        //3.Scissors
        case 3:
            if (computerPick == 1)
            {
                end = true;
                return loss;
                break;
            }
            if (computerPick == 2)
            {
                return win;
                end = true;
                break;
            }
            if (computerPick == 3)
            {
                end = true;
                return tie;
                break;
            }
        default:
            cout << "Invald input, please enter a number from 1-3" << endl;
            break;
        }
    }
    return 0;
}

const int Action::getPuzzel1Ans()
{
    return puzzel1Ans;
}
const int Action::getPuzzel2Ans()
{
    return puzzel2Ans;
}
char Action::getPuzzel3Ans()
{
    return puzzel3Ans;
}
char Action::getPuzzel4Ans()
{
    return puzzel4Ans;
}
char Action::getPuzzel5Ans()
{
    return puzzel5Ans;
}
bool Action::quitGame(char move)
{

    bool n = false;
    char quit;
    while (n == false)
    {
        //print menu for quit
        cout << "Are you sure you want to quit the game?" << endl;
        cout << "y (yes)" << endl;
        cout << "n (No)" << endl;
        cout << endl;
        cin >> quit;

        quit = tolower(quit);
        if (quit == 'y') //if yes return true
        {
            cout << "You quit and lost better luck next time!" << endl;
            return true;
        }
        else if (quit == 'n') //if no continue while loop
        {
            n = true;
            break;
        }
        else //edge case for invalid input
        {
            cout << "Invalid Input" << endl;
            cout << endl;
        }
    }
}

void Action::mainMenu(Player &player, BB &bb, NPC npc)
{
    int choice;

    int count = 0;
    int puzzorgame;
    int randPuzz = rand() % 5;
    int RPS;

    int compparttorepair;

    do
    {
        cout << "---MENU---" << endl;
        cout << "1. Status Update\n2. Repair your Computer\n3. Use your antivirus software\n4. Browse StackOverflow\n5. Quit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            statusUpdate(player);
            break;

        case 2:
            do
            {
                if (player.getnumbVirus() > 0)
                {
                    cout << "You cannot repair your computer because you have " << player.getnumbVirus() << " viruses :(" << endl;
                }
                else if (player.getcompPartsAvailable() > 0 && player.getnumbVirus() == 0)
                {

                    cout << "You have " << player.getcompPartsAvailable() << " computer part(s)! You can select up to 5 parts to repair. These include: " << endl;
                    cout << "1.CPU: " << bb.getNumbCPU() << endl
                         << "2.GPU: " << bb.getNumbGPU() << endl
                         << "3.Power Supply Unit: " << bb.getNumbPowerSupplyUnit() << endl
                         << "4.Computer Case: " << bb.getNumbComputerCase() << endl
                         << "5.Internet Card: " << bb.getNumbInternetCard() << endl
                         << "6.Keyboard and Mouse: " << bb.getNumbKeyboardMouse() << endl
                         << "7.DONE REPAIRING" << endl
                         << "Enter the number of the computer part you would like to use or 7 to finish:" << endl;

                    cin >> compparttorepair;

                    switch (compparttorepair)
                    {
                    case 1:
                        if (bb.getNumbCPU() > 0)
                        {
                            bb.setNumbCPU(bb.getNumbCPU() - 1);
                            count++;
                        }
                        else
                        {
                            cout << "No CPU to repair with" << endl;
                        }

                        break;
                    case 2:
                        if (bb.getNumbGPU() > 0)
                        {
                            bb.setNumbGPU(bb.getNumbGPU() - 1);
                            count++;
                        }
                        else
                        {
                            cout << "No gpu to repair with" << endl;
                        }

                        break;
                    case 3:
                        if (bb.getNumbPowerSupplyUnit() > 0)
                        {
                            bb.setNumbPowerSupplyUnit(bb.getNumbPowerSupplyUnit() - 1);
                            count++;
                        }
                        else
                        {
                            cout << "no power supply unit to repair with" << endl;
                        }

                        break;
                    case 4:
                        if (bb.getNumbComputerCase() > 0)
                        {
                            bb.setNumbComputerCase(bb.getNumbComputerCase() - 1);
                            count++;
                        }
                        else
                        {
                            cout << "no computer case to repair with" << endl;
                        }

                        break;
                    case 5:
                        if (bb.getNumbInternetCard() > 0)
                        {
                            bb.setNumbInternetCard(bb.getNumbInternetCard() - 1);
                            count++;
                        }
                        else
                        {
                            cout << "no internet card to repair with" << endl;
                        }
                        break;
                    case 6:
                        if (bb.getNumbKeyboardMouse() > 0)
                        {
                            bb.setNumbKeyboardMouse(bb.getNumbKeyboardMouse() - 1);
                            count++;
                        }
                        else
                        {
                            cout << "no keyboard /mouse to repair with" << endl;
                        }

                        break;
                    case 7:
                        cout << "GOODBYE!" << endl;
                        break;

                    default:
                        cout << "invalid option" << endl;
                    }
                }
                if (count == 5)
                {
                    break;
                }
            } while (compparttorepair != 7);

            switch (count)
            {
            case 1:
                player.setcompMaintenanceLvl(player.getcompMaintenanceLvl() + 20);
                cout << "Computer Maintenance Level: " << player.getcompMaintenanceLvl() << endl;
                break;

            case 2:
                player.setcompMaintenanceLvl(player.getcompMaintenanceLvl() + 40);
                cout << "Computer Maintenance Level: " << player.getcompMaintenanceLvl() << endl;
                break;

            case 3:
                player.setcompMaintenanceLvl(player.getcompMaintenanceLvl() + 60);
                cout << "Computer Maintenance Level: " << player.getcompMaintenanceLvl() << endl;
                break;

            case 4:
                player.setcompMaintenanceLvl(player.getcompMaintenanceLvl() + 80);
                cout << "Computer Maintenance Level: " << player.getcompMaintenanceLvl() << endl;
                break;

            case 5:
                player.setcompMaintenanceLvl(player.getcompMaintenanceLvl() + 100);
                cout << "Computer Maintenance Level: " << player.getcompMaintenanceLvl() << endl;
                break;
            }
            break;

        case 3:
            if (player.getantiVirusUSBcount() > 0 && player.getnumbVirus() > 0)
            {
                player.setantiVirusUSBcount(player.getantiVirusUSBcount() - 1);
                player.setnumbVirus(0);
                cout << "You have used one stick of USB antivirus software to get ridof all viruses on your computer!" << endl;
            }
            else if (player.getnumbVirus() == 0)
            {
                cout << "You have no viruses" << endl;
            }
            else if (player.getantiVirusUSBcount() == 0)
            {
                cout << "You have no antivirus USB sticks to use :(" << endl;
            }
            break;

        case 4:
            cout << "Would you like to solve a puzzel(1) or attempt a game(2)?" << endl;
            cin >> puzzorgame;

            switch (puzzorgame)
            {
            case 1:
                npc.completePuzzle(player, bb);
                break;

            case 2:
                cout << "ROCK PAPER SCISSORS: " << endl;
                cout << "1.Rock\n2.Paper\n3.Scissors" << endl;
                cin >> RPS;
                RockPaperScissors(RPS);
                break;

            default:
                cout << "Invalid choice." << endl;
                break;
            }
        case 5:
            cout << "You chose to quit the menu! GOODBYE!" << endl;
            break;

        default:
            cout << "Invalid option" << endl;
            break;
        }
    } while (choice != 5);
}
