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
#include <ctype.h>
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
bool Action::executeHackerMenu(string option, Player &player, Hacker &hacker, Map &map)
{
    bool stop;
    if (option == "1") //Fight condition for player
    {
        return fightHacker(player, hacker, map);
    }
    else if (option == "2") //Forfeit option for player
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

        map.removeHacker();
        return true;
    }
    else //if result is less than 0 or 0 palyer loses
    {
        //loses 20 maintenanceLvl
        player.setcompMaintenanceLvl(player.getcompMaintenanceLvl() - 20);
        player.setcarmenProg(player.getcarmenProg() + 10);
        cout << "Lose" << endl;
        cout << "Doge: " << player.getDogeCoin() << endl;
        cout << "-10 Computer Maintenance Level: " << player.getcompMaintenanceLvl() << endl;

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

void Action::RockPaperScissors(Player &player)
{

    //1.Rock
    //2.Paper
    //3.Scissors
    //true means win
    //false means loss

    string win = "Win";
    string loss = "Loss";
    string tie = "Tie";
    string numb;
    int computerPick = rand() % 3;
    bool end = false;
    cout << "ROCK PAPER SCISSORS: " << endl;
    cout << "1.Rock\n2.Paper\n3.Scissors" << endl;
    while (end == false)
    {
        cin >> numb;
        //1.Rock
        if (numb == "1")
        {

            if (computerPick == 1)
            {
                cout << "Tie" << endl;
                end = true;
            }
            if (computerPick == 2)
            {
                cout << "Loss" << endl;
                end = true;
            }
            if (computerPick == 0)
            {
                player.setFrustration(player.getFrustration() - 10); //subtracts frustration level

                cout << endl;
                cout << "Win" << endl;
                cout << endl;
                cout << "-10 Frustration Level" << endl;
                cout << "Frustration Level: " << player.getFrustration() << endl;
                end = true;
            }
        }
        //2.Paper
        else if (numb == "2")
        {
            if (computerPick == 1)
            {
                player.setFrustration(player.getFrustration() - 10);
                cout << "Win" << endl;
                cout << endl;
                cout << "-10 Frustration Level" << endl;
                cout << "Frustration Level: " << player.getFrustration() << endl;
                end = true;
            }
            if (computerPick == 2)
            {
                cout << "Tie" << endl;
                end = true;
            }
            if (computerPick == 0)
            {
                cout << "Loss" << endl;
                end = true;
            }
        }
        //3.Scissors
        else if (numb == "3")
        {
            if (computerPick == 1)
            {
                cout << "Loss" << endl;
                end = true;
            }
            if (computerPick == 2)
            {
                player.setFrustration(player.getFrustration() - 10);
                cout << "Win" << endl;
                cout << endl;
                cout << "-10 Frustration Level" << endl;
                cout << "Frustration Level: " << player.getFrustration() << endl;
                end = true;
            }
            if (computerPick == 0)
            {
                cout << "Tie" << endl;
                end = true;
            }
        }
        else
        {
            cout << "Invald input, please enter a number from 1-3" << endl;
            end = false;
        }
    }
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
bool Action::quitGame(string move)
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
            return false;
        }
        else //edge case for invalid input
        {
            cout << "Invalid Input" << endl;
            cout << endl;
        }
    }
}

bool Action::mainMenu(Player &player, BB &bb, NPC &npc, string choice)
{
    string rps;
    int count = 0;
    string puzzorgame;
    int randPuzz = rand() % 5;
    bool shit = false;
    string compparttorepair;

    if (choice == "1")
    {
        statusUpdate(player);
    }
    else if (choice == "2")
    {

        while (compparttorepair != "7")
        {
            if (player.getnumbVirus() > 0)
            {
                cout << "You cannot repair your computer because you have " << player.getnumbVirus() << " viruses :(" << endl;
                break;
            }
            else if (player.getcompPartsAvailable() > 0 && player.getnumbVirus() == 0)
            {

                cout << "You can select up to 5 parts to repair. These include: " << endl;
                cout << "1.CPU: " << bb.getNumbCPU() << endl
                     << "2.GPU: " << bb.getNumbGPU() << endl
                     << "3.Power Supply Unit: " << bb.getNumbPowerSupplyUnit() << endl
                     << "4.Computer Case: " << bb.getNumbComputerCase() << endl
                     << "5.Internet Card: " << bb.getNumbInternetCard() << endl
                     << "6.Keyboard and Mouse: " << bb.getNumbKeyboardMouse() << endl
                     << "7.DONE REPAIRING" << endl
                     << "Enter the number of the computer part you would like to use or 7 to finish:" << endl;

                cin >> compparttorepair;

                if (compparttorepair == "1")
                {
                    if (bb.getNumbCPU() > 0)
                    {
                        bb.setNumbCPU(bb.getNumbCPU() - 1);
                        count++;
                    }
                    else
                    {
                        cout << "No CPU to repair with" << endl;
                    }
                }
                else if (compparttorepair == "2")
                {
                    if (bb.getNumbGPU() > 0)
                    {
                        bb.setNumbGPU(bb.getNumbGPU() - 1);
                        count++;
                    }
                    else
                    {
                        cout << "No gpu to repair with" << endl;
                    }
                }
                else if (compparttorepair == "3")
                {
                    if (bb.getNumbPowerSupplyUnit() > 0)
                    {
                        bb.setNumbPowerSupplyUnit(bb.getNumbPowerSupplyUnit() - 1);
                        count++;
                    }
                    else
                    {
                        cout << "no power supply unit to repair with" << endl;
                    }
                }
                else if (compparttorepair == "4")
                {
                    if (bb.getNumbComputerCase() > 0)
                    {
                        bb.setNumbComputerCase(bb.getNumbComputerCase() - 1);
                        count++;
                    }
                    else
                    {
                        cout << "no computer case to repair with" << endl;
                    }
                }
                else if (compparttorepair == "5")
                {
                    if (bb.getNumbInternetCard() > 0)
                    {
                        bb.setNumbInternetCard(bb.getNumbInternetCard() - 1);
                        count++;
                    }
                    else
                    {
                        cout << "no internet card to repair with" << endl;
                    }
                }
                else if (compparttorepair == "6")
                {
                    if (bb.getNumbKeyboardMouse() > 0)
                    {
                        bb.setNumbKeyboardMouse(bb.getNumbKeyboardMouse() - 1);
                        count++;
                    }
                    else
                    {
                        cout << "no keyboard /mouse to repair with" << endl;
                    }
                }
                else if (compparttorepair == "7")
                {
                    cout << "GOODBYE!" << endl;
                }
                else
                {
                    cout << "Invalid Option" << endl;
                }
            }
            if (count == 5)
            {
                count=0;
                break;
            }
        }

        switch (count)
        {
        case 1:
            player.setcompMaintenanceLvl(player.getcompMaintenanceLvl() + 20);
            cout << "+20 Computer Maintenance Level" << endl;
            cout << "Computer Maintenance Level: " << player.getcompMaintenanceLvl() << endl;
            break;

        case 2:
            player.setcompMaintenanceLvl(player.getcompMaintenanceLvl() + 40);
            cout << "+40 Computer Maintenance Level" << endl;
            cout << "Computer Maintenance Level: " << player.getcompMaintenanceLvl() << endl;
            break;

        case 3:
            player.setcompMaintenanceLvl(player.getcompMaintenanceLvl() + 60);
            cout << "+60 Computer Maintenance Level" << endl;
            cout << "Computer Maintenance Level: " << player.getcompMaintenanceLvl() << endl;
            break;

        case 4:
            player.setcompMaintenanceLvl(player.getcompMaintenanceLvl() + 80);
            cout << "+80 Computer Maintenance Level" << endl;
            cout << "Computer Maintenance Level: " << player.getcompMaintenanceLvl() << endl;
            break;

        case 5:
            player.setcompMaintenanceLvl(player.getcompMaintenanceLvl() + 100);
            cout << "+100 Computer Maintenance Level" << endl;
            cout << "Computer Maintenance Level: " << player.getcompMaintenanceLvl() << endl;
            break;
        }
    }
    else if (choice == "3")
    {
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
    }
    else if (choice == "4")
    {
        cout << "Would you like to solve a puzzel(1) or attempt a game(2)?" << endl;
        cin >> puzzorgame;

        if (puzzorgame == "1")
        {
            npc.completePuzzle(player, bb);
        }
        else if (puzzorgame == "2")
        {
            RockPaperScissors(player);
        }
        else
        {
            cout << "Invalid choice." << endl;
        }
    }
    else if (choice == "5")
    {
        cout << "You have killed: " << endl;
        cout << endl;
        outFstreamNames();
    }
    else if (choice == "6")
    {
        cout << "You chose to quit the menu! GOODBYE!" << endl;
        return true;
    }
    else
    {
        cout << "Invalid option" << endl;
    }
}
void Action::misfortune(Player &player, NPC &npc, BB &bb)
{

    int randnumb = rand() % 10;
    //cout << "rand num for misfortune:" << randnumb << endl;

    if (randnumb > -1 && randnumb < 4)
    {
        if (randnumb == 0)
        {
            if (player.getcompPartsAvailable() > 0)
            {
                cout << "UH OH! You lost a computer part due to a misfortune. You suck" << endl;
                npc.subRandComputerPart(bb, player);
            }

            else if (player.getcompPartsAvailable() == 0)
            {
                cout << "OH NO! Your computer was damaged!" << endl;
                player.setcompMaintenanceLvl(player.getcompMaintenanceLvl() - 10);
            }
        }
        else if (randnumb == 1)
        {
            cout << "OH NO! Your team was robbed by Carmen’s dastardly hackers! You have no computer parts/antivirus software left!" << endl;
            player.setcompPartsAvailable(0);
            player.setantiVirusUSBcount(0);
        }
        else if (randnumb == 2 || randnumb == 3)
        {
            cout << "OH NO! Why won’t my code work!!!! Your frustration level was increased." << endl;
            player.setFrustration(player.getFrustration() + 10);
            if (player.getFrustration() >= 100)
            {
                cout << "OH NO! You have rage quit! Looks like you couldn’t handle Carmen’s hackers. BItch" << endl;
            }
        }
    }
    else
    {
        cout << "No misfortunes occured!" << endl;
    }
}
void Action::storeMoves(int numRooms, int numMoves)
{
    room.push_back(numRooms);
    moves.push_back(numMoves);
}
void Action::sortAlg()
{
    both.push_back(room);
    both.push_back(moves);

    bool change = true;
    while (change)
    {
        change = false;
        for (int i = 0; i < room.size(); i++)
        {
            if (both[1][i] > both[1][i + 1])
            {
                //changes index 1
                both[1][i] += both[1][i + 1];
                both[1][i + 1] = both[1][i] - both[1][i + 1];
                both[1][i] -= both[1][i + 1];

                //changes index 0
                both[0][i] += both[0][i + 1];
                both[0][i + 1] = both[0][i] - both[0][i + 1];
                both[0][i] -= both[0][i + 1];

                change = true;
            }
        }
    }
    for (int j = 0; j < room.size(); j++)
    {
        cout << "Room: " << both[0][j];
        cout << " Number of Moves: " << both[1][j] << endl;
    }
}
void Action::inFstreamNames(ofstream &file, string name)
{

    if (!file.is_open())
    {
        cout << "Unable to Open File" << endl;
    }
    else
    {
        file << name << endl;
        file.close();
    }
}
void Action::outFstreamNames()
{
    ifstream file;
    string line = "";

    file.open("KoralSux.txt");

    if (!file.is_open()) //open and read puzzel file
    {
        cout << "File did not open!" << endl;
    }
    else
    {
        while (getline(file, line))
        {
            cout << line << endl;
        }
        cout << endl;
    }
    file.close();
}
