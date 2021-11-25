// CSCI1300 Fall 2021
// Authors: Zaphod Schmidt and Koral Villalobos
// Recitations: 220 - Pragna Mandadi and 315 - Teo Pice-Broncucia
// Project 3 - Action Implimentation

#include "Player.h"
#include "Hacker.h"
#include "BB.h"
#include "Map.h"
#include <fstream>
#include <iostream>
#include <ctype.h>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

//Misfortunes

Action::Action()
{
}

string Action::choseRandomHacker()
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
    cout << "You've encountered a Hacker!" << endl;
    cout << "Valid moves are: " << endl;
    cout << "1. Fight the hacker" << endl;
    cout << "2. Forfeit the fight (lose all computer parts!)" << endl;
}
bool Action::executeHackerMenu(int option, Player &player, Hacker &hacker)
{
    bool stop;
    if (option == 1) //Fight condition for player
    {
        return fightHacker(player, hacker);
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
bool Action::fightHacker(Player &player, Hacker &hacker)
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
        player.setDogeCoin(player.getDogeCoin() + 50); //gives player 50 doge for win
        cout << "Win " << endl;
        cout << "+50 "
             << "Doge: " << player.getDogeCoin() << endl;
        cout << "Computer Maintenance Level: " << player.getcompMaintenanceLvl() << endl;
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
