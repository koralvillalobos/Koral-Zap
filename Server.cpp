// CSCI1300 Fall 2021
// Authors: Zaphod Schmidt and Koral Villlalobos
// Recitations: 220 - Pragna Mandadi and 315 - Teo Pice-Broncucia
// Project 3 - Server Implimentation

#include "Server.h"
#include <iostream>


using namespace std;

Server::Server()//default constructor 
{
    room = 0;
}

int::Server::getRoom(){
    return room;
}

void::Server::setRoom(int newRoom){
    room = newRoom;
}

//print out menu in server rooms
void::Server::printMenu(){
    cout << "1. Fight a Hacker\n2. Speak to NPC (non-player character)\n3. Repair your computer\n4. Use your antivirus software \n5. Travel the Server Room\n6. Browse StackOverflow\n7. Quit" << endl;
}

