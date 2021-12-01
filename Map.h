// CSCI1300 Fall 2021
// Authors: Zaphod Schmidt and Koral Villlalobos
// Recitations: 220 - Pragna Mandadi and 315 - Teo Pice-Broncucia
// Project 3 - Map Class

#ifndef MAP_H
#define MAP_H

#include <fstream>
#include <iostream>
#include <ctype.h>
#include "Player.h"
#include <time.h>
#include <stdlib.h>

using namespace std;

class Map
{
private:
     static const int num_rows = 5;
     static const int num_cols = 9;
     static const int num_npcs = 3;
     static const int num_hackers = 3;

     int playerPosition[2];
     int bestBuyPosition[2];
     int npcPositions[num_npcs][2];
     int hackerPositions[num_hackers][2];
     char mapData[num_rows][num_cols];

     int npc_count;
     int hacker_count;
     bool best_buy_on_map;

public:
     Map();

     void resetMap();
     string makeLower(string);

     // getters
     int getPlayerRowPosition();
     int getPlayerColPosition();
     int getNPCCount();
     int getHackerCount();

     // setters
     void setPlayerRowPosition(int);
     void setPlayerColPosition(int);
     void setNPCCount(int);
     void setHackerCount(int);

     bool spawnNPC(int, int);
     bool spawnBestBuy(int, int);
     bool spawnHacker(int, int);

     void displayMap();
     void displayMoves();
     bool executeMove(string);

     bool isBestBuyLocation();
     bool isNPCLocation();
     bool isHackerLocation();
     bool isBestBuyOnMap();
     void removeHacker();



     void randomSpawnHackers(Map&);
     void randomSpawnNPC(Map&);
     void randomSpawnBB(Map&);
};

#endif
