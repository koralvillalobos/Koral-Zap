// CSCI1300 Fall 2021
// Authors: Zaphod Schmidt and Koral Villlalobos
// Recitations: 220 - Pragna Mandadi and 315 - Teo Pice-Broncucia
// Project 3 - Best Buy Implimentation

#include "BB.h"

using namespace std;

BB::BB() //default constructor
{
    computer = false;
    antiVirus = false;
    VPN = 1;
    providerLevel = 0;
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
bool ::BB::getComputerStatus()
{
    return computer;
}
void ::BB::setComputerStatus(bool newComputer)
{
    computer = newComputer; //is broken
}

bool ::BB::getVirusStatus()
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
int ::BB::getCPU()
{
    return CPU;
}
int ::BB::getGPU()
{
    return GPU;
}
int ::BB::getPowerSupplyUnit()
{
    return powerSupplyUnit;
}
int ::BB::getComputerCase()
{
    return computerCase;
}
int ::BB::getInternetCard()
{
    return internetCard;
}
int ::BB::getKeyboardMouse()
{
    return keyboardMouse;
}
int ::BB::getPremadeComp()
{
    return premadeComp;
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
