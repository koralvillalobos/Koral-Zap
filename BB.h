// CSCI1300 Fall 2021
// Authors: Zaphod Schmidt and Koral Villlalobos
// Recitations: 220 - Pragna Mandadi and 315 - Teo Pice-Broncucia
// Project 3 - Best Buy Class

#ifndef BB_H
#define BB_H

#include <fstream>
#include <iostream>
#include "Player.h"
#include <ctype.h>

using namespace std; 

class BB{
    private:
        int computer;
        static const int costCPU = 10;
        static const int costGPU = 20;
        static const int costPowerSupplyUnit = 5;
        static const int costComputerCase = 15;
        static const int costInternetCard = 5;
        static const int costKeyboardMouse = 10;
        static const int costPremadeComp = 100;
        int numbCPU;
        int numbGPU;
        int numbPowerSupplyUnit;
        int numbComputerCase;
        int numbInternetCard;
        int numbKeyboardMouse;
        int numbPremadeComp;

        bool antiVirus;
        static const int antiVirusCost = 10;

        int VPN;
        static const int VPNCost = 20;

        int providerLevel;
        static const int level2 = 10;
        static const int level3 = 25;
        static const int level4 = 40;
        static const int level5 = 50;

    public:
        BB();
        BB(bool computer, bool antiVirus, int VPN, int providerLevel);

        void gameStart(Player&);
        void printBBMenu();
        void printStartMenu();

        //getters
        bool getComputerStatus();
        bool getVirusStatus();
        int getVPN();
        int getProviderLevel();
        int getCostCPU();
        int getCostGPU();
        int getCostPowerSupplyUnit();
        int getCostComputerCase();
        int getCostInternetCard();
        int getCostKeyboardMouse();
        int getCostPremadeComp();
        int getAntiVirusCost();
        int getVPNCost();
        int getPL2();
        int getPL3();
        int getPL4();
        int getPL5();
        int getNumbCPU();
        int getNumbGPU();
        int getNumbPowerSupplyUnit();
        int getNumbComputerCase();
        int getNumbInternetCard();
        int getNumbKeyboardMouse();
        int getNumbPremadeComp();

        //setters
        void setProviderLevel(int);
        void setVirusStatus(bool);
        void setVPN(int);
        void setComputerStatus(bool);
        void setNumbCPU(int);
        void setNumbGPU(int);
        void setNumbPowerSupplyUnit(int);
        void setNumbComputerCase(int);
        void setNumbInternetCard(int);
        void setNumbKeyboardMouse(int);
        void setNumbPremadeComp(int);
};

#endif
