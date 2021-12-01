// CSCI1300 Fall 2021
// Authors: Zaphod Schmidt and Koral Villlalobos
// Recitations: 220 - Pragna Mandadi and 315 - Teo Pice-Broncucia
// Project 3 - Server Class

#ifndef Server_H
#define Server_H

#include <fstream>
#include <iostream>
#include <ctype.h>
#include <iomanip>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "Hacker.h"
#include "Map.h"

using namespace std; //multiple maps array of 5 server maps 

class Server{
    private:
        int room;
        int hackersDefeated;
        Map maps;

        
    public:
        Server();
        int getRoom();
        void setRoom(int);

        int getHackerDefeatCount();
        void setHackerDefeatCount(int);

        

        void printMenu();



};

#endif
