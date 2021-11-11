#include "BB.h"

using namespace std;

BB::BB()
{
    computer = false; 
    antiVirus = false;
    VPN = 1;
    providerLevel = 0;
    doge = 200;
}

BB::BB(bool newComputer, bool newAntiVirus, int newVPN, int newproviderLevel, int newDoge)
{
    computer = newComputer;
    antiVirus = newAntiVirus;
    VPN = newVPN;
    providerLevel = newproviderLevel;
    doge = newDoge;

}

bool::BB::getComputerStatus()
{
    return computer;
}
void::BB::setComputerStatus(bool newComputer)
{
    computer = newComputer; //is broken
}

bool::BB::getVirusStatus()
{
    return antiVirus;
}

void ::BB::setVirusStatus(bool newVirusStatus)
{
    antiVirus = newVirusStatus; //there is a virus 
}

int ::BB::getVPN()
{
    return VPN;
}

void ::BB::setVPN(int newVPN)
{
    VPN = newVPN;
}

int ::BB::getProviderLevel()
{
    return providerLevel;
}
void ::BB::setProviderLevel(int newProviderLevel)
{
    providerLevel = newProviderLevel;
}
int ::BB::getDoge()
{
    return doge;
}
void::BB::setDoge(int newDoge)
{
    doge = newDoge;
}