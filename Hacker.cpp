#include "Hacker.h"

using namespace std;

Hacker::Hacker(){
    int challegeLevel = 0;
    string hackerName = "";
}

string Hacker::getHacker(){
    return hackerName;
}

void Hacker::setHacker(string newHackerName){
    hackerName = newHackerName;
}

int Hacker::getChallegeLevel(){
    return challegeLevel;
}

void Hacker::setChallegeLevel(int newChallengeLevel){
    challegeLevel = newChallengeLevel;
}

int Hacker::getLocationRows(){
    return rows;
}

int Hacker::getLocationCols(){
    return cols;
}

void Hacker::setLocation(int newRows, int newCols){
    rows = newRows;
    cols = newCols;
}