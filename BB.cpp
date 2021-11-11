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
void::BB::printBBMenu(){
    cout <<"1. Computer Part\n2. Antivirus software\n3. Virtual Private Network (VPN)\n4. Internet Provider" << endl;
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

int main(){
    BB BB;
    BB.printBBMenu();
}
