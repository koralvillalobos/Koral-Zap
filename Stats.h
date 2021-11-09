#ifndef Stats_H
#define Stats_H

#include <fstream>
#include <iostream>
#include <ctype.h>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>


using namespace std; 

class Stats
{
    private:

    int compMaintenanceLvl;
    int numbVirus;
    int compPartsAvailable;
    bool antiVirusUSB;
    int VPNsAvailable;
    int internetProv;
    int dogeCoinTotal;
    int frustration;
    int carmenProg;
    int hackersKilled;

    public:

    Stats();

    //getters
    bool getantiVirusUSB();
    int getFrustration();
    int getcompMaintenanceLvl();
    int getnumbVirus();
    int getcompPartsAvailable();
    int getinternetProv();
    int getcarmenProg();
    int gethackersKilled();
    int getVPNsAvailable();
    
    //setters
    void setantiVirusUSB(bool);
    void setFrustration(int);
    void setcompMaintenanceLvl(int);
    void setnumbVirus(int);
    void setcompPartsAvailable(int);
    void setinternetProv(int);
    void setcarmenProg(int);
    void sethackersKilled(int);
    void setVPNsAvailable(int);
};