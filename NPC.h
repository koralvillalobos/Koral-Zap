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
#include <time.h>
#include <stdlib.h>

using namespace std;

class NPC
{
private:


public:
NPC();
bool runNPCMenu(Player&, string, BB&, Map&);
void addRandComputerPart(BB&);
void subRandComputerPart(BB&, Player&);
void completePuzzle(Player&, BB&);
void takeYourChances(Player&, BB&);
void puzzle1();
void puzzle2();
void puzzle3();
void puzzle4();
void puzzle5();


};
#endif
