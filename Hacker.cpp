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
string Hacker::pickHackerName(int level) //function to pick a random hacker from the hacker.txt file
{
    
    string arr[4][5];
    ifstream file;
    string line = "";
    string name = "hackers.txt";
    string hackerName;
    bool reFind = true;

    file.open(name);

    if (file.is_open()) //open and read file
    {
        int i = 0;
        int j = 0;
        while (getline(file, line))
        {
            arr[j][i] = line; //storing hacker names in 2D array
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

    int randCol = rand() % 4; //get a random number

    do
    {
        if (level == 1) //server 1
        {
            if (hackerName == "q") //replace name in the array with a q to make sure hacker not picked twice later
            {
                break;
            }
            else
            {
                reFind = false; //end while loop
                hackerName = arr[randCol][0]; //getting hacker name
                arr[randCol][0] = "q";
            }
        }
        else if (level == 2) //server 2
        {
            if (hackerName == "q")
            {
                break;
            }
            else
            {
                reFind = false; //end loop
                hackerName = arr[randCol][1];//getting hacker name
                arr[randCol][1] = "q";
            }
        }
        else if (level == 3) //server 3
        {
            if (hackerName == "q")
            {
                break;
            }
            else
            {
                reFind = false; //end loop
                hackerName = arr[randCol][2];//getting hacker name
                arr[randCol][2] = "q";
            }
        }
        else if (level == 4) //server 4
        {
            if (hackerName == "q")
            {
                break;
            }
            else
            {
                reFind = false; //end loop
                hackerName = arr[randCol][3];//getting hacker name
                arr[randCol][3] = "q";
            }
        }
        else if (level == 5) //server 5 
        {
            if (hackerName == "q")
            {
                break;
            }
            else
            {
                reFind = false; //end loop
                hackerName = arr[randCol][4];//getting hacker name
                arr[randCol][4] = "q";
            }
        }
    } while (reFind == true);

    return hackerName; //returning name of hacker
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << endl;
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout << arr[j][i] << endl;
    //     }
    // }
}
