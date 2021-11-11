#ifndef Hacker_H
#define Hacker_H

#include <fstream>
#include <iostream>
#include <ctype.h>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>


using namespace std; 

class Hacker{
    private:
        int challegeLevel;
        string hackerName;
        int rows;
        int cols;


    public:
        Hacker();
        string getHacker(); //name
        void setHacker(string);

        int getChallegeLevel();
        void setChallegeLevel(int);

        int getLocationRows();
        int getLocationCols();
        void setLocation(int, int);


};

#endif