/// CSCI1300 Fall 2021
// Authors: Zaphod Schmidt and Koral Villlalobos
// Recitations: 220 - Pragna Mandadi and 315 - Teo Pice-Broncucia
// Project 3 - Player Implimentation

#include <fstream>
#include <iostream>
#include <ctype.h>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include "Player.h"

using namespace std;

Player::Player() //default constructor initializing variables to zero or other values accordingly
{
    compMaintenanceLvl = 100;
    numbVirus = 0;
    compPartsAvailable = 1;
    antiVirusUSBcount = false;
    VPNsOwned = 1;
    internetProv = 10;
    dogeCoinTotal = 1;
    frustration = 1;
    carmenProg = 1;
    hackersKilled = 0;
    dogeCoin = 200;
}

//getters
int Player::getantiVirusUSBcount()
{
    return antiVirusUSBcount;
}
int Player::getFrustration()
{
    return frustration;
}
int Player::getcompMaintenanceLvl()
{
    return compMaintenanceLvl;
}
int Player::getnumbVirus()
{
    return numbVirus;
}
int Player::getcompPartsAvailable()
{

    return compPartsAvailable;
}
int Player::getinternetProv()
{
    return internetProv;
}
int Player::getcarmenProg()
{
    return carmenProg;
}
int Player::gethackersKilled()
{
    return hackersKilled;
}
int Player::getVPNsOwned()
{
    return VPNsOwned;
}
int Player::getDogeCoin(){
    return dogeCoin;
}


//setters
void Player::setantiVirusUSBcount(bool NewAntiVirusUSBcount)
{
    antiVirusUSBcount = NewAntiVirusUSBcount;
}

void Player::setFrustration(int newFrustration)
{
    frustration = newFrustration;
}
void Player::setcompMaintenanceLvl(int NewCompMaintenanceLvl)
{
    compMaintenanceLvl = NewCompMaintenanceLvl;
}
void Player::setnumbVirus(int newNumbVirus)
{
    numbVirus = newNumbVirus;
}
void Player::setcompPartsAvailable(int NewCompPartsAvailable)
{
    compPartsAvailable = NewCompPartsAvailable;
}
void Player::setinternetProv(int newInternetProv)
{
    internetProv = newInternetProv;
}
void Player::setcarmenProg(int newCarmenProg)
{
    carmenProg = newCarmenProg;
}
void Player::sethackersKilled(int newHackersKilled)
{
    hackersKilled = newHackersKilled;
}
void Player::setVPNsOwned(int newVPNsOwned)
{
    VPNsOwned = newVPNsOwned;
}

void Player::setDogeCoin(int newDoge){
    dogeCoin = newDoge;
}
