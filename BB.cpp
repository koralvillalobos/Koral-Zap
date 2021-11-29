// CSCI1300 Fall 2021
// Authors: Zaphod Schmidt and Koral Villlalobos
// Recitations: 220 - Pragna Mandadi and 315 - Teo Pice-Broncucia
// Project 3 - Best Buy Implimentation

#include "BB.h"

using namespace std;

string makeLower(string name){

    for(int i = 0; i < name.length(); i++){ //iterate through the string
        if(name[i] >= 65 && name[i] <= 90){ //if uppercase found
            name[i] += 32; //make lower
        }
    }
    return name;
}

BB::BB() //default constructor
{
    computer = false;
    antiVirus = false;
    VPN = 1;
    providerLevel = 0;
    numbCPU = 0;
    numbGPU = 0;
    numbPowerSupplyUnit = 0;
    numbComputerCase = 0;
    numbInternetCard = 0;
    numbKeyboardMouse = 0;
    numbPremadeComp = 1;
}

BB::BB(bool newComputer, bool newAntiVirus, int newVPN, int newproviderLevel) //parameterized constructor
{
    computer = newComputer;
    antiVirus = newAntiVirus;
    VPN = newVPN;
    providerLevel = newproviderLevel;
}

void ::BB::printBBMenu()
{
    cout << "1. Computer Part\n2. Antivirus software\n3. Virtual Private Network (VPN)\n4. Internet Provider" << endl;
}
void ::BB::printStartMenu()
{
    cout<<"- COMPUTER PARTS. If your computer breaks, you need 5\ncomputer parts to make a new one.\n- ANTIVIRUS SOFTWARE. If your computer is infected with a\nvirus, use the antivirus software to get rid of it.\n- VIRTUAL PRIVATE NETWORK (VPN). The more VPNs you have\nthe harder it is for a hacker to infect your computer with\na virus.\n- INTERNET PROVIDER. The better the internet provider, the\nmore reliable your hacking will be.\nYou can spend all of your money here before you start your\njourney, or you can save some to spend on a different\nelectronics site along the way. But beware, some of the\nwebsites online are shady, and they won’t always give you a\nfair price..." <<endl;
}


//Getters
bool ::BB::getComputerStatus()
{
    return computer;
}
bool ::BB::getVirusStatus()
{
    return antiVirus;
}
int ::BB::getVPN()
{
    return VPN;
}
int ::BB::getProviderLevel()
{
    return providerLevel;
}
int ::BB::getCostCPU()
{
    return costCPU;
}
int ::BB::getCostGPU()
{
    return costGPU;
}
int ::BB::getCostPowerSupplyUnit()
{
    return costPowerSupplyUnit;
}
int ::BB::getCostComputerCase()
{
    return costComputerCase;
}
int ::BB::getCostInternetCard()
{
    return costInternetCard;
}
int ::BB::getCostKeyboardMouse()
{
    return costKeyboardMouse;
}
int ::BB::getCostPremadeComp()
{
    return costPremadeComp;
}
int ::BB::getAntiVirusCost()
{
    return antiVirusCost;
}
int ::BB::getVPNCost()
{
    return VPNCost;
}
int ::BB::getPL2()
{
    return level2;
}
int ::BB::getPL3()
{
    return level3;
}
int ::BB::getPL4()
{
    return level4;
}
int ::BB::getPL5()
{
    return level5;
}
int ::BB::getNumbCPU()
{
    return numbCPU;
}
int ::BB::getNumbGPU()
{
    return numbGPU;
}
int ::BB::getNumbPowerSupplyUnit()
{
    return numbPowerSupplyUnit;
}
int ::BB::getNumbComputerCase()
{
    return numbComputerCase;
}
int ::BB::getNumbInternetCard()
{
    return numbInternetCard;
}
int ::BB::getNumbKeyboardMouse()
{
    return numbKeyboardMouse;
}
int ::BB::getNumbPremadeComp()
{
    return numbPremadeComp;
}


//Setters
void ::BB::setNumbCPU(int newNumbCPU)
{
    numbCPU=newNumbCPU;
}
void ::BB::setNumbGPU(int newNumbGPU)
{
    numbGPU=newNumbGPU;
}
void ::BB::setNumbPowerSupplyUnit(int newNumbPowerSupplyUnit)
{
    numbPowerSupplyUnit=newNumbPowerSupplyUnit;
}
void ::BB::setNumbComputerCase(int newNumbComputerCase)
{
    numbComputerCase=newNumbComputerCase;
}
void ::BB::setNumbInternetCard(int newNumbInternetCard)
{
    numbInternetCard=newNumbInternetCard;
}
void ::BB::setNumbKeyboardMouse(int newNumbKeyboardMouse)
{
    numbKeyboardMouse=newNumbKeyboardMouse;
}
void ::BB::setNumbPremadeComp(int newNumbPremadeComp)
{
    numbPremadeComp=newNumbPremadeComp;
}
void ::BB::setComputerStatus(bool newComputer)
{
    computer = newComputer; //is broken
}
void ::BB::setVirusStatus(bool newVirusStatus)
{
    antiVirus = newVirusStatus; //there is a virus
}
void ::BB::setVPN(int newVPN)
{
    VPN = newVPN;
}
void ::BB::setProviderLevel(int newProviderLevel)
{
    providerLevel = newProviderLevel;
}
void ::BB::gameStart(Player &player){
    int bbOption;
    char purchaseAns;

    cout << "Would you like to purchase anything from Best Buy?" << endl;
    cout << "y (yes)" << endl;
    cout << "n (No)" << endl;
    cin >> purchaseAns;

    int i;
    if (purchaseAns == 'y')
    {
        cout << "---Menu---" << endl;
        cout << "1. Computer Parts\n2. Antivirus software\n3. Virtual Private Network (VPN)\n4. Internet Provider" << endl;
        cout << "Please input what you would like to buy." << endl;
        cin >> bbOption;

        switch (bbOption)
        {
        case 1:
            int computerPartChoice;
            int computerPartItem;
            i = 0;
            cout << "Best Buy recommends that the player should purchase at least 1 of each computer part in case your main computer breaks.\nYou can have a maximum of 3 of each computer part and 1 extra premade computer. These are the different parts:" << endl;
            cout << "▪ A CPU costs 10 Dogecoins" << endl;
            cout << "▪ A GPU costs 20 Dogecoins" << endl;
            cout << "▪ A Power Supply Unit costs 5 Dogecoins" << endl;
            cout <<"▪ A Computer Case costs 15 Dogecoins"<<endl;
            cout << "▪ An Internet Card costs 5 Dogecoins" << endl;
            cout << "▪ A Keyboard and Mouse costs 10 Dogecoins" << endl;
            cout << "▪ A Premade Computer costs 100 Dogecoins" << endl;
            cout << "How many parts do you wish to purchase?" << endl;
            cin >> computerPartChoice;

            do
            {
                cout << "Choose what you would like to purchase: " << endl;
                cout << "1. CPU\n2. GPU\n3. Power Supply Unit\n4. Computer Case\n5. Internet card\n6. Keyboard and mouse\n7. Premade computer" << endl;
                cin >> computerPartItem;
                

                switch (computerPartItem)
                {
                case 1:
                    setNumbCPU(getNumbCPU()+1);
                    player.setDogeCoin(player.getDogeCoin() - 10);
                    cout << "DogeCoin: " << player.getDogeCoin() << endl;
                    i++;
                    break;

                case 2:
                    setNumbGPU(getNumbGPU()+1);
                    player.setDogeCoin(player.getDogeCoin() - 20);
                    cout << "DogeCoin: " << player.getDogeCoin() << endl;
                    i++;
                    break;

                case 3:
                    setNumbPowerSupplyUnit(getNumbPowerSupplyUnit()+1);
                    player.setDogeCoin(player.getDogeCoin() - 5);
                    cout << "DogeCoin: " << player.getDogeCoin() << endl;
                    i++;
                    break;
                case 4:
                    setNumbComputerCase(getNumbComputerCase()+1);
                    player.setDogeCoin(player.getDogeCoin() - 15);
                    cout << "DogeCoin: " << player.getDogeCoin() << endl;
                    i++;
                    break;

                case 5:
                    setNumbInternetCard(getNumbInternetCard()+1);
                    player.setDogeCoin(player.getDogeCoin() - 5);
                    cout << "DogeCoin: " << player.getDogeCoin() << endl;
                    i++;
                    break;

                case 6:
                    setNumbKeyboardMouse(getCostKeyboardMouse()+1);
                    player.setDogeCoin(player.getDogeCoin() - 10);
                    cout << "DogeCoin: " << player.getDogeCoin() << endl;
                    i++;
                    break;

                case 7:
                    setNumbPremadeComp(getNumbPremadeComp()+1);
                    player.setDogeCoin(player.getDogeCoin() - 100);
                    cout << "DogeCoin: " << player.getDogeCoin() << endl;
                    i++;
                    break;

                default:
                    cout << "Invalid choice. Try again." << endl;
                    break;
                }
            } while( i != computerPartChoice);
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
            i = 0;
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
    else{
        return;
    }

}
