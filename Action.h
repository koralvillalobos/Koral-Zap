// CSCI1300 Fall 2021
// Authors: Zaphod Schmidt and Koral Villlalobos
// Recitations: 220 - Pragna Mandadi and 315 - Teo Pice-Broncucia
// Project 3 - Action Class

#ifndef Action_H
#define Action_H

#include <fstream>
#include <iostream>
#include <ctype.h>
#include <vector>
#include "Player.h"
#include "Hacker.h"
#include "BB.h"
#include "NPC.h"
#include "Map.h"
#include <time.h>
#include <stdlib.h>

using namespace std;

class Action
{
private:
    static const int puzzel1Ans = 21;
    static const int puzzel2Ans = 13;
    static const char puzzel3Ans = 'B';
    static const char puzzel4Ans = 'A';
    static const char puzzel5Ans = 'D';
    vector<int> room;
    vector<int>moves;
    vector<vector<int> >both;

public:
    Action();
    string choseRandomHacker();
    void statusUpdate(Player &);
    void displayHackerMenu();
    bool executeHackerMenu(string,Player&,Hacker&,Map&);
    bool fightHacker(Player&,Hacker&, Map&);
    bool forfeit(Player&);
    void virus(Player&);
    void useantiVirus(Player&);

    bool mainMenu(Player&, BB&, NPC&,string);

    
    void RockPaperScissors(Player&);
    static const int getPuzzel1Ans();
    static const int getPuzzel2Ans();
    char getPuzzel3Ans();
    char getPuzzel4Ans();
    char getPuzzel5Ans();
    bool quitGame(string);
    void misfortune(Player &player, NPC &npc, BB &bb);
    void storeMoves(int,int);
    void sortAlg();
    void inFstreamNames(ofstream&, string);
    void outFstreamNames();

};

#endif
