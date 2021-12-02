/// CSCI1300 Fall 2021
// Authors: Zaphod Schmidt and Koral Villlalobos
// Recitations: 220 - Pragna Mandadi and 315 - Teo Pice-Broncucia
// Project 3 - Server Implimentation

#include "Server.h"
#include <iostream>


using namespace std;

Server::Server()//default constructor 
{
    room = 0; //set room number to 0
}

int::Server::getRoom(){
    return room; //return server room number
}

void::Server::setRoom(int newRoom){ //change the server room number
    room = newRoom;
}

