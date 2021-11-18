#include <iostream>

#include "Player.h"
#include "Hacker.h"
#include "Map.h"
#include "Action.h"

using namespace std;

void statusUpdate(Player player)
{
    // player.sethackersKilled(0);
    // player.setcarmenProg(0);
    // player.setDogeCoin(0);

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

int fightHacker(Player player, Hacker hacker)
{
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
        player.setDogeCoin(player.getDogeCoin() + 50); //gives player 50 doge for win
        return 0;
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
        return 1;
    }
}

int main()
{
    Player player = Player();
    BB bb = BB();
    Map map = Map();
    Action action = Action();
    Hacker hacker = Hacker();

    player.setDogeCoin(200);

    cout << "doge: "<<player.getDogeCoin() << endl;

    int outcome = fightHacker(player, hacker);
    cout<<"outcome "<<outcome<<endl;
    if (outcome == 0)
    {
        cout << "win"
             << "doge: " << player.getDogeCoin() << endl;
    }
    if (outcome == 1)
    {
        cout << "lose"
             << "doge: " << player.getDogeCoin() << endl;
    }
    // statusUpdate(player);
}
