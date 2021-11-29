// CSCI1300 Fall 2021
// Authors: Zaphod Schmidt and Koral Villlalobos
// Recitations: 220 - Pragna Mandadi and 315 - Teo Pice-Broncucia
// Project 3 - NPC Class

#ifndef NPC_H
#define NPC_H

#include <fstream>
#include <iostream>
#include <ctype.h>
#include "Player.h"
#include "Hacker.h"
#include "BB.h"

using namespace std;

class NPC
{
private:
string puzzel1Ans = "21";
string puzzel2Ans = "13";
string puzzel3Ans = "B";
string puzzel4Ans = "A";
string puzzel5Ans = "D";

public:
NPC();
bool runNPCMenu(Player &, int);
void addRandComputerPart();
void subRandComputerPart();
void completePuzzle(Player&);
void takeYourChances(Player&);
void puzzle1();
void puzzle2();
void puzzle3();
void puzzle4();
void puzzle5();
string getPuzzel1Ans();
string getPuzzel2Ans();
string getPuzzel3Ans();
string getPuzzel4Ans();
string getPuzzel5Ans();

};
#endif