#include "Player.h"
#include "Action.h"
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
bool Action::attack()
{
    BB bb = BB();
    Player player = Player();
    Hacker hacker = Hacker();

    int r1 = rand() % 6;
    int r2 = rand() % 6;
    int virusChance = rand() % 10;
    int internetProviderLvl = player.getinternetProv();
    int VPN = player.getVPNsOwned();
    int ChallegeLevel = hacker.getChallegeLevel();
    double v = (1 / VPN);

    int result = (r1 * internetProviderLvl) - ((r2 * ChallegeLevel) * v);

    if (result > 0) //if result is more than palyer wins
    {
        bb.setDoge(bb.getDoge() + 50); //gives player 50 doge for win
        return true;
    }
    else //if result is less than 0 or 0 palyer loses
    {
        //loses 20 maintenanceLvl
        player.setcompMaintenanceLvl(player.getcompMaintenanceLvl() - 20);

        //there is a 10% chance of getting a virus
        if (virusChance == 0)
        {
            player.setnumbVirus(player.getnumbVirus() + 1);
        }
        return false;
    }
}
int Action::forfeit()
{
    Player player = Player();

    //player loses all spare computer parts
    player.setcompPartsAvailable(0);
}
int Action::virus()
{
    Map map = Map();
    Player player = Player();
    BB bb = BB();

    if (player.getnumbVirus() > 0)
    {
        //Need to fix this gota figure out how to tell if an action was made
        if (map.executeMove(char 'w' || char 'a' || char 's' || char 'd') == 0) //if player moves -10 Computer Maintenance
        {
            player.setcompMaintenanceLvl(player.getcompMaintenanceLvl() - (10 * player.getnumbVirus()));
        }
    }
}
int Action::useantiVirus()
{
    Player player = Player();

    if (player.getantiVirusUSBcount() > 0)
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

    if (file.is_open())
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

int main()
{
    //"puzzle.txt"
    Action action = Action();
    action.CompletePuzzle("puzzle.txt");
}
