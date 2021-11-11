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



int main()
{
    Action action;
    BB bb;
    Hacker hacker;
    Player player;

    srand(time(NULL));
    int pick;
    string type = "tie";

    while (type == "tie")
    {
        cout << "Enter a number for rock paper scissors\n1.Rock\n2.Paper\n3.Scissors" << endl;
        cin >> pick;
        type = action.RockPaperScissors(pick);
        cout<<type<<endl;
    }
}
