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
};

#endif
