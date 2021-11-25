// CSCI1300 Fall 2021
// Authors: Zaphod Schmidt and Koral Villlalobos
// Recitations: 220 - Pragna Mandadi and 315 - Teo Pice-Broncucia
// Project 3 - Action Class

#ifndef Action_H
#define Action_H

#include <fstream>
#include <iostream>
#include <ctype.h>
#include "Player.h"
#include "Hacker.h"
#include "BB.h"

using namespace std;

class Action
{
private:
    static const int puzzel1Ans = 21;
    static const int puzzel2Ans = 13;
    static const char puzzel3Ans = 'B';
    static const char puzzel4Ans = 'A';
    static const char puzzel5Ans = 'D';

public:
    Action();
    string choseRandomHacker();
    void statusUpdate(Player &);
    void displayHackerMenu();
    bool executeHackerMenu(int,Player&,Hacker&);
    bool fightHacker(Player&,Hacker&);
    bool forfeit(Player&);
    void virus(Player&);
    void useantiVirus(Player&);

    void CompletePuzzle(string);
    string RockPaperScissors(int);
    static const int getPuzzel1Ans();
    static const int getPuzzel2Ans();
    char getPuzzel3Ans();
    char getPuzzel4Ans();
    char getPuzzel5Ans();

    bool quitGame(char);
};
#endif
