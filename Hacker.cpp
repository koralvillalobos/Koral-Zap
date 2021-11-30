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
string Hacker::pickHackerName(int level)
{
    srand(time(NULL));
    string arr[4][5];
    ifstream file;
    string line = "";
    string name = "hackers.txt";
    string hackerName;
    bool reFind = true;

    file.open(name);

    if (file.is_open()) //open and read puzzel file
    {
        int i = 0;
        int j = 0;
        while (getline(file, line))
        {
            arr[j][i] = line;
            j++;
            if (j == 4)
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
    file.close();

    int randCol = rand() % 4;

    do
    {
        if (level == 1)
        {
            if (hackerName == "q")
            {
                break;
            }
            else
            {
                reFind = false;
                hackerName = arr[randCol][0];
                arr[randCol][0] = "q";
            }
        }
        else if (level == 2)
        {
            if (hackerName == "q")
            {
                break;
            }
            else
            {
                reFind = false;
                hackerName = arr[randCol][1];
                arr[randCol][1] = "q";
            }
        }
        else if (level == 3)
        {
            if (hackerName == "q")
            {
                break;
            }
            else
            {
                reFind = false;
                hackerName = arr[randCol][2];
                arr[randCol][2] = "q";
            }
        }
        else if (level == 4)
        {
            if (hackerName == "q")
            {
                break;
            }
            else
            {
                reFind = false;
                hackerName = arr[randCol][3];
                arr[randCol][3] = "q";
            }
        }
        else if (level == 5)
        {
            if (hackerName == "q")
            {
                break;
            }
            else
            {
                reFind = false;
                hackerName = arr[randCol][4];
                arr[randCol][4] = "q";
            }
        }
    } while (reFind == true);

    return hackerName;
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << endl;
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout << arr[j][i] << endl;
    //     }
    // }
}
