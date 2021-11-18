// CSCI1300 Fall 2021
// Authors: Zaphod Schmidt and Koral Villlalobos
// Recitations: 220 - Pragna Mandadi and 315 - Teo Pice-Broncucia
// Project 3 - Player Class

#ifndef Player_H
#define Player_H

#include <fstream>
#include <iostream>
#include <ctype.h>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>


using namespace std; 

class Player
{
    private:

    int compMaintenanceLvl;
    int numbVirus;
    int compPartsAvailable;
    bool antiVirusUSBcount;
    int VPNsOwned;
    int internetProv;
    int dogeCoinTotal;
    int frustration;
    int carmenProg;
    int hackersKilled;
    int dogeCoin;

    public:

    Player();

    //getters
    int getantiVirusUSBcount();
    int getFrustration();
    int getcompMaintenanceLvl();
    int getnumbVirus();
    int getcompPartsAvailable();
    int getinternetProv();
    int getcarmenProg();
    int getDogeCoin();
    int gethackersKilled();
    int getVPNsOwned();
    
    //setters
    void setantiVirusUSBcount(int);
    void setFrustration(int);
    void setcompMaintenanceLvl(int);
    void setnumbVirus(int);
    void setcompPartsAvailable(int);
    void setinternetProv(int);
    void setcarmenProg(int);
    void sethackersKilled(int);
    void setVPNsOwned(int);
    void setDogeCoin(int);
};

#endif
