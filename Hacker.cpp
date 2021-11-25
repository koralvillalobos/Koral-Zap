// CSCI1300 Fall 2021
// Authors: Zaphod Schmidt and Koral Villlalobos
// Recitations: 220 - Pragna Mandadi and 315 - Teo Pice-Broncucia
// Project 3 - Hacker Implimentation

#include "Hacker.h"

using namespace std;

Hacker::Hacker()
{ //default constructor
    challegeLevel = 10;
    hackerName = "";
}

string Hacker::getHacker()
{
    return hackerName;
}

void Hacker::setHacker(string newHackerName)
{
    hackerName = newHackerName;
}

int Hacker::getChallegeLevel()
{
    return challegeLevel;
}

void Hacker::setChallegeLevel(int newChallengeLevel)
{
    challegeLevel = newChallengeLevel;
}

int Hacker::getLocationRows()
{
    return rows;
}

int Hacker::getLocationCols()
{
    return cols;
}

void Hacker::setLocation(int newRows, int newCols)
{
    rows = newRows;
    cols = newCols;
}
void Hacker::pickHackerName(int level)
{
    string arr[5][4];
    ifstream file;
    string line = "";
    string name="hackers.txt";

    file.open(name);

    if (file.is_open()) //open and read puzzel file
    {
        int i = 0;
        int j = 0;
        while (getline(file, line))
        {
            arr[i][j] = line;
            j++;
            if (j == 3)
            {
                i++;
                j = 0;
            }
        }
    }
    else
    {
        cout << "File did not open!" << endl;
    }
    for (int i = 0; i < 4; i++)
    {
        cout<<endl;
        for (int j = 0; j < 5; j++)
        {
            cout << arr[j][i] << endl;
        }
    }
}
