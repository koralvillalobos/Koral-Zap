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
#include <time.h>
#include <stdlib.h>

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

    //getters
    int getChallegeLevel();
    int getLocationRows();
    int getLocationCols();
   

    //setters
    void setLocation(int, int);
    void setChallegeLevel(int);

    string pickHackerName(int);
};

#endif
