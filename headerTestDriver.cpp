// CSCI1300 Fall 2021
// Authors: Zaphod Schmidt and Koral Villlalobos
// Recitations: 220 - Pragna Mandadi and 315 - Teo Pice-Broncucia
// Project 3 - Driver File

#include "Player.h"
#include "Action.h"
#include "Hacker.h"
#include "BB.h"
#include "Map.h"
#include <fstream>
#include <iostream>
#include <ctype.h>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

// int main()
// {
//     Action action;
//     BB bb;
//     Hacker hacker;
//     Player player;
//     Map map;

//     //setters
//     player.setantiVirusUSBcount(1);
//     player.setFrustration(5);
//     player.setcompMaintenanceLvl(5);
//     player.setnumbVirus(5);
//     player.setcompPartsAvailable(5);
//     player.setinternetProv(5);
//     player.setcarmenProg(5);
//     player.sethackersKilled(5);
//     player.setVPNsOwned(5);

//     //Player
//     cout << player.getantiVirusUSBcount() << endl;
//     cout << player.getFrustration() << endl;
//     cout << player.getcompMaintenanceLvl() << endl;
//     cout << player.getnumbVirus() << endl;
//     cout << player.getcompPartsAvailable() << endl;
//     cout << player.getinternetProv() << endl;
//     cout << player.getcarmenProg() << endl;
//     cout << player.gethackersKilled() << endl;
//     cout << player.getVPNsOwned() << endl;

//     //BB

//     bb.printBBMenu();

//     bb.setComputerStatus(true);
//     cout << bb.getComputerStatus() << endl;
//     ;

//     bb.setVirusStatus(true);
//     cout << bb.getVirusStatus() << endl;
//     ;

//     bb.setVPN(5);
//     cout << bb.getVPN() << endl;

//     bb.setProviderLevel(5);
//     cout << bb.getProviderLevel() << endl;

//     bb.setDoge(5);
//     cout << bb.getDoge() << endl;

//     cout << bb.getCPU() << endl;
//     cout << bb.getGPU() << endl;
//     cout << bb.getPowerSupplyUnit() << endl;
//     cout << bb.getComputerCase() << endl;
//     cout << bb.getInternetCard() << endl;
//     cout << bb.getKeyboardMouse() << endl;
//     cout << bb.getPremadeComp() << endl;
//     cout << bb.getAntiVirusCost() << endl;
//     cout << bb.getVPNCost() << endl;
//     cout << bb.getPL2() << endl;
//     cout << bb.getPL3() << endl;
//     cout << bb.getPL4() << endl;
//     cout << bb.getPL5() << endl;

//     //Hacker

//     //name
//     hacker.setHacker("John");
//     cout<<hacker.getHacker()<< endl;

//     hacker.setChallegeLevel(5);
//     cout<<hacker.getChallegeLevel()<< endl;

//     hacker.setLocation(2, 2);
//     cout<<hacker.getLocationRows()<< endl;
//     cout<<hacker.getLocationCols()<< endl;

//     //Action
//     action.attack();
//     action.forfeit();
//     action.virus();
//     action.useantiVirus();
//     action.CompletePuzzle("pizza");
//     action.RockPaperScissors(1);
//     cout<<action.getPuzzel1Ans()<<endl;
//     cout<<action.getPuzzel2Ans()<<endl;
//     cout<<action.getPuzzel3Ans()<<endl;
//     cout<<action.getPuzzel4Ans()<<endl;
//     cout<<action.getPuzzel5Ans()<<endl;

//     //Rock Paper Scissors
//     // srand(time(NULL));
//     // int pick;
//     // string type = "tie";
//     //     cout << "Enter a number for rock paper scissors\n1.Rock\n2.Paper\n3.Scissors" << endl;
//     //     cin >> pick;
//     //     type = action.RockPaperScissors(pick);
//     //     cout<<type<<endl;
// }
