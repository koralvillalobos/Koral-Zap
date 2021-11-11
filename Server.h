#ifndef Server_H
#define Server_H

#include <fstream>
#include <iostream>
#include <ctype.h>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include "Hacker.h"
#include "Map.h"

using namespace std; //multiple maps array of 5 server maps 

class Server{
    private:
        int room;
        Hacker hackers[4];
        Map maps[5];

        
    public:
        int getRoom();
        void setRoom(int);

};

#endif