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
        static const int CPU = 10;
        static const int GPU = 20;
        static const int powerSupplyUnit = 5;
        static const int computerCase = 15;
        static const int internetCard = 5;
        static const int keyboardMouse = 10;
        static const int premadeComp = 100;

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

        bool getComputerStatus();
        void setComputerStatus(bool);

        bool getVirusStatus();
        void setVirusStatus(bool);

        int getVPN();
        void setVPN(int);

        int getProviderLevel();
        void setProviderLevel(int);

        int getDoge();
        void setDoge(int);

        int getCPU();
        int getGPU();
        int getPowerSupplyUnit();
        int getComputerCase();
        int getInternetCard();
        int getKeyboardMouse();
        int getPremadeComp();
        int getAntiVirusCost();
        int getVPNCost();
        int getPL2();
        int getPL3();
        int getPL4();
        int getPL5();
};

#endif
