// CSCI1300 Fall 2021
// Authors: Zaphod Schmidt and Koral Villlalobos
// Recitations: 220 - Pragna Mandadi and 315 - Teo Pice-Broncucia
// Project 3 - Hacker Class

#ifndef Hacker_H
#define Hacker_H

#include <fstream>
#include <iostream>
#include <ctype.h>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

class Hacker
{
private:
    int challegeLevel;
    string hackerName;
    int rows;
    int cols;

public:
    Hacker();
    string getHacker(); //name
    void setHacker(string);

    int getChallegeLevel();
    void setChallegeLevel(int);

    int getLocationRows();
    int getLocationCols();
    void setLocation(int, int);
    void pickHackerName(int);
};

#endif
