#ifndef Action_H
#define Action_H

#include <fstream>
#include <iostream>
#include <ctype.h>
#include "Player.h"
#include "Action.h"
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
    bool attack();
    void forfeit();
    void virus();
    void useantiVirus();
    void CompletePuzzle(string);
    string RockPaperScissors(int);
    static const int getPuzzel1Ans();
    static const int getPuzzel2Ans();
    char getPuzzel3Ans();
    char getPuzzel4Ans();
    char getPuzzel5Ans();
};
#endif
