#include <fstream>
#include <iostream>
#include <ctype.h>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include "Stats.h"

using namespace std;

Stats::Stats()
{
    int compMaintenanceLvl = 0;
    int numbVirus = 0;
    int compPartsAvailable = 0;
    bool antiVirusUSB = false;
    int VPNsAvailable = 0;
    int internetProv = 0;
    int dogeCoinTotal = 0;
    int frustration = 0;
    int carmenProg = 0;
    int hackersKilled = 0;
}
bool Stats::getantiVirusUSB()
{
    return antiVirusUSB;
}
int Stats::getFrustration()
{
    return frustration;
}
int Stats::getcompMaintenanceLvl()
{
    return compMaintenanceLvl;
}
int Stats::getnumbVirus()
{
    return numbVirus;
}
int Stats::getcompPartsAvailable()
{
    return compPartsAvailable;
}
int Stats::getinternetProv()
{
    return internetProv;
}
int Stats::getcarmenProg()
{
    return carmenProg;
}
int Stats::gethackersKilled()
{
    return hackersKilled;
}
int Stats::getVPNsAvailable()
{
    return VPNsAvailable;
}

//setters
void Stats::setantiVirusUSB(bool NewAntiVirusUSB)
{
    antiVirusUSB = NewAntiVirusUSB;
}
void Stats::setFrustration(int newFrustration)
{
    frustration = newFrustration;
}
void Stats::setcompMaintenanceLvl(int NewCompMaintenanceLvl)
{
    compMaintenanceLvl = NewCompMaintenanceLvl;
}
void Stats::setnumbVirus(int newNumbVirus)
{
    numbVirus = newNumbVirus;
}
void Stats::setcompPartsAvailable(int NewCompPartsAvailable)
{
    compPartsAvailable = NewCompPartsAvailable;
}
void Stats::setinternetProv(int newInternetProv)
{
    internetProv = newInternetProv;
}
void Stats::setcarmenProg(int newCarmenProg)
{
    carmenProg = newCarmenProg;
}
void Stats::sethackersKilled(int newHackersKilled)
{
    hackersKilled = newHackersKilled;
}
void Stats::setVPNsAvailable(int newVPNsAvailable)
{
    VPNsAvailable = newVPNsAvailable;
}