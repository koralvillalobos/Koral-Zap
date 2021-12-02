// CSCI1300 Fall 2021
// Authors: Zaphod Schmidt and Koral Villlalobos
// Recitations: 220 - Pragna Mandadi and 315 - Teo Pice-Broncucia
// Project 3 - NPC Implimentation

#include "NPC.h"

using namespace std;

NPC::NPC()//default constructs
{
}

bool NPC::runNPCMenu(Player &player, string option, BB &bb, Map &map) //function to run NPC menu puzzles or games
{
    cin >> option; //storing user choice
    if (option == "3") //quit NPC menu
    {
        return true;
    }
    else if (option == "1" && bb.getCompPartsAvailable(bb) > 0) //if user chooses 1 and has computer parts availible then they can complete a puzzle 
    {
        completePuzzle(player, bb); //function chooses random puzzle to give user
        map.removeNPC(); //take NPC off the map
        return true;
    }
    else if (bb.getCompPartsAvailable(bb) == 0) //cannot complete puzzle without computer parts -- if you get wrong answer this takes away parts
    {
        cout << "You have no computer parts & cannot complete a puzzle!" << endl;
    }
    else if (option == "2") //take chances with NPC choice
    {
        takeYourChances(player, bb); //function that calculates a probability to lose parts 
        map.removeNPC(); //take NPC off the map
        return true;
    }
    else //edge case for invalid options
    {
        cout << "Invalid Input" << endl;
        return false;
    }
}
void NPC::addRandComputerPart(BB &bb) //giving user random computer parts
{

    int num = rand() % 7; //calculating random number between 0 -6
    switch (num)
    {
    case 0: //if rand number 0
        bb.setNumbCPU(bb.getNumbCPU() + 1); //adding CPU 
        cout << "+1 CPU" << endl;
        cout << "You have " << bb.getNumbCPU() << " CPUs" << endl;
        break;
    case 1://if rand number 1
        bb.setNumbGPU(bb.getNumbGPU() + 1); //adding GPU
        cout << "+1 GPU" << endl;
        cout << "You have " << bb.getNumbGPU() << " GPUs" << endl;
        break;
    case 2://if rand number 2
        bb.setNumbPowerSupplyUnit(bb.getNumbPowerSupplyUnit() + 1); //adding Power supply unit
        cout << "+1 Power Supply Unit" << endl;
        cout << "You have " << bb.getNumbPowerSupplyUnit() << " Power Supply Units" << endl;
        break;
    case 3://if rand number 3
        bb.setNumbComputerCase(bb.getNumbComputerCase() + 1); //add computer case
        cout << "+1 Computer Case" << endl;
        cout << "You have " << bb.getNumbComputerCase() << " Computer Cases" << endl;
        break;
    case 4://if rand number 4
        bb.setNumbInternetCard(bb.getNumbInternetCard() + 1); //add internet card
        cout << "+1 Internet Card" << endl;
        cout << "You have " << bb.getNumbInternetCard() << " Internet Cards left" << endl;
        break;
    case 5://if rand number 5

        bb.setNumbKeyboardMouse(bb.getNumbKeyboardMouse() + 1); //add keyboard mouse
        cout << "+1 Keyboard and Mouse" << endl;
        cout << "You have " << bb.getNumbKeyboardMouse() << " Keyboards and Mouse left" << endl;
        break;
    case 6://if rand number 6
        bb.setNumbPremadeComp(bb.getNumbPremadeComp() + 1); //add computer
        cout << "+1 Pre-Made Computer" << endl;
        cout << "You have " << bb.getNumbPremadeComp() << " Pre-Made Computers" << endl;
        break;
    }
}

void NPC::subRandComputerPart(BB &bb, Player &player) //function to take away random computer part
{

    bool run = false;
    while (run == false)
    {
        int num = rand() % 7; //calculating random number between 0 -6

        if (player.getcompPartsAvailable() > 0) //must have computer parts to take awat
        {
            switch (num)
            {
            case 0: //if random number 0
                if (bb.getNumbCPU() > 0) //make sure user has CPU 
                {
                    bb.setNumbCPU(bb.getNumbCPU() - 1); //take away CPU
                    cout << "-1 CPU" << endl;
                    cout << "You have " << bb.getNumbCPU() << " CPUs left" << endl;
                    run = true;
                }
                else
                {
                    break;
                }
                break;
            case 1: //if rand number 1
                if (bb.getNumbGPU() > 0) //make sure user has GPU
                {
                    bb.setNumbGPU(bb.getNumbGPU() - 1); //take away GPU
                    cout << "-1 GPU" << endl;
                    cout << "You have " << bb.getNumbGPU() << " GPUs left" << endl;
                    run = true;
                }
                else
                {
                    break;
                }
                break;
            case 2: //rand numb 2
                if (bb.getNumbPowerSupplyUnit() > 0) //make sure user has power supply unit
                {
                    bb.setNumbPowerSupplyUnit(bb.getNumbPowerSupplyUnit() - 1); //take away PSU
                    cout << "-1 Power Supply Unit" << endl;
                    cout << "You have " << bb.getNumbPowerSupplyUnit() << " Power Supply Units left" << endl;
                    run = true;
                }
                else
                {
                    break;
                }
                break;
            case 3: //rand numb 3
                if (bb.getNumbComputerCase() > 0) //make sure user has computer case
                {
                    bb.setNumbComputerCase(bb.getNumbComputerCase() - 1); //take away computer case
                    cout << "-1 Computer Case" << endl;
                    cout << "You have " << bb.getNumbComputerCase() << " Computer Cases left" << endl;
                    run = true;
                }
                else
                {
                    break;
                }
                break;
            case 4: //rand numb 4
                if (bb.getNumbInternetCard() > 0) //make sure user has internet card
                {
                    bb.setNumbInternetCard(bb.getNumbInternetCard() - 1); //take away internet card
                    cout << "-1 Internet Card" << endl;
                    cout << "You have " << bb.getNumbInternetCard() << " Internet Cards left" << endl;
                    run = true;
                }
                else
                {
                    break;
                }
                break;
            case 5: //rand numb 5
                if (bb.getNumbKeyboardMouse() > 0) //make sure user has keyboard mouse
                {
                    bb.setNumbKeyboardMouse(bb.getNumbKeyboardMouse() - 1); //take away keyboard mouse
                    cout << "-1 Keyboard and Mouse" << endl;
                    cout << "You have " << bb.getNumbKeyboardMouse() << " Keyboards and Mouse left" << endl;
                    run = true;
                }
                else
                {
                    break;
                }
                break;
            case 6: //rand numb 6
                if (bb.getNumbPremadeComp() > 0) //make sure computer avaliable
                {
                    bb.setNumbPremadeComp(bb.getNumbPremadeComp() - 1); //take away computer
                    cout << "-1 Pre-Made Computer" << endl;
                    cout << "You have " << bb.getNumbPremadeComp() << " Pre-Made Computers left" << endl;
                    run = true;
                }
                else
                {
                    break;
                }
                break;
            }
        }
        return;
    }
}

void NPC::completePuzzle(Player &player, BB &bb) //function to complete a random puzzle
{

    int rand5 = rand() % 5; //calculate random number
    string playerAnswer;
    string stringAnswer;

    if (rand5 == 0) //if rand 0
    {
        puzzle1(); //output puzzle 1
        cout << "Enter Answer:" << endl;
        cin >> playerAnswer;

        stringAnswer = "21"; 
        if (stringAnswer == playerAnswer) //check correct answer
        {
            cout << "You are correct!" << endl;
            addRandComputerPart(bb); //add computer part 
            return;
        }
        else
        {
            cout << "You are wrong you suck!" << endl;
            subRandComputerPart(bb, player); //wrong answer take away computer part

            return;
        }
    }
    if (rand5 == 1) //rand numb 1
    {
        puzzle2(); //output puzzle 2
        cout << "Enter Answer:" << endl;
        cin >> playerAnswer;
        stringAnswer = "13";
        if (stringAnswer == playerAnswer) //check for correct answer
        {
            cout << "You are correct!" << endl;
            addRandComputerPart(bb); //add part for correct
            return;
        }
        else
        {
            cout << "You are wrong you suck!" << endl;
            subRandComputerPart(bb, player); //take away part for wrong
            return;
        }
    }
    if (rand5 == 2) //rand numb 2
    {
        puzzle3(); //output puzzle 3
        cout << "Enter Answer:" << endl;
        cin >> playerAnswer;
        stringAnswer = "b";
        if (stringAnswer == playerAnswer) //check for right answer
        {
            cout << "You are correct!" << endl;
            addRandComputerPart(bb); //correct answer add part
            return;
        }
        else
        {
            cout << "You are wrong you suck!" << endl;
            subRandComputerPart(bb, player); //wrong answer take away part
            return;
        }
    }
    if (rand5 == 3) //rand numb 3
    {
        puzzle4(); //output puzzle 4
        cout << "Enter Answer:" << endl;
        cin >> playerAnswer;
        stringAnswer = "a";
        if (stringAnswer == playerAnswer) //check if answer correct
        {
            cout << "You are correct!" << endl;
            addRandComputerPart(bb); //correct ans add part
            return;
        }
        else
        {
            cout << "You are wrong you suck!" << endl;
            subRandComputerPart(bb, player); //wrong answer take away part
            return;
        }
    }
    if (rand5 == 4)
    {
        puzzle5(); //ouput puzzle 5
        cout << "Enter Answer:" << endl;
        cin >> playerAnswer;
        stringAnswer = "d";
        if (stringAnswer == playerAnswer)//check if answer correct
        
        {
            cout << "You are correct!" << endl;
            addRandComputerPart(bb); //correct ans add part
            return;
        }
        else
        {
            cout << "You are wrong you suck!" << endl;
            subRandComputerPart(bb, player);//wrong answer take away part
            return;
        }
    }
}
void NPC::takeYourChances(Player &player, BB &bb) //function where user decides to take chances with the NPC
{

    int rand3 = rand() % 3; //calc rand #'s
    int rand6 = rand() % 6;

    if (rand3 == 0) //good outcome
    {
        cout << "The outcome was good nothing happens" << endl;
        addRandComputerPart(bb); //add part
    }
    if (rand3 == 1) //neutral outcome
    {
        cout << "The outcome was neutral nothing happens" << endl;
    }
    if (rand3 == 2) //bad outcome
    {
        cout << "The outcome was bad the NPC steals one of your" << endl;
        subRandComputerPart(bb, player); //take away part
    }
}
void NPC::puzzle1() //output puzzle 1
{
    cout << "****FIND THE ERROR****\nThis code works perfectly except for one pesky bug.\nEnter the number of the line on which the error appears to win this puzzle." << endl;
    cout << endl;
    cout << "1. #include <iostream>\n2. using namespace std;\n3.\n4. double frobenius(double arr1[][3], double arr2[][3]);\n5.\n6. int main() {\n7.     double arr1[3][3];\n8.     double arr2[3][3];\n9.  \n10.   for(int i = 0; i < 3; i++){\n11.       for(int j = 0; j < 3; j++) {\n12.           arr1[i][j] = i + j;\n13.           arr2[i][j] = i * j;\n14.       }\n15.   }\n16.\n17.   cout << frobenius(arr1, arr2) << endl;\n18.   return 0;\n19. }\n20.\n21. double frobenius(arr1[][3], arr2[][3]){\n22.   double innerProduct = 0;   \n23.   for(int i = 0; i < 3; i++){\n24.       for(int j = 0; j < 3; j++){  \n25.           innerProduct += arr1[i][j] * arr2[i][j];\n26.       }\n27.    }\n28.   return innerProduct;\n29. }" << endl;
}
void NPC::puzzle2()//output puzzle 2
{
    cout << "****MULTIPLE CHOICE****\nConsider the following snippet of code. How many times will the sentence inside of the for loop be printed?\n\n#include <iostream>\n\nusing namespace std;\n\nint main(){\n	int begin = 5;\n	int end = 20;\n   for (int i = begin; i <= end; i+=2){\n   cout << \"This code does nothing important\" << endl;\n    }\n	return 0;\n}\n\nA) 15\nB) 8\nC) 7\nD) 10\n}" << endl;
}
void NPC::puzzle3()//output puzzle 3
{
    cout << "****MULTIPLE CHOICE****\nConsider the following snippet of code. How many times will the sentence inside of the for loop be printed?\n\n#include <iostream>\n\nusing namespace std;\n\nint main(){\n	int begin = 5;\n	int end = 20;\n    for (int i = begin; i <= end; i+=2){\n   	 cout << \"This code does nothing important\" << endl;\n    }\n	return 0;\n}\n\nA) 15\nB) 8\nC) 7\nD) 10" << endl;
}
void NPC::puzzle4()//output puzzle 4
{
    cout << "****MULTIPLE CHOICE****\nIn the function below, word double before multiply represents what about the function?  \ndouble multiply(double x, double y)\n{\n	return x*y; \n}\nA) The type of return value\nB) The name of the function\nC) The type of parameter variable\nD) The algorithm within the function" << endl;
}
void NPC::puzzle5()//output puzzle 5
{
    cout << "****MULTIPLE CHOICE****\nTo defeat a hacker you need to use a brute force attack on his account. To do this, you are using a text file that holds words, numbers and other potential password combinations. Sometimes you come up with new word combinations you would like to add to the list. Which of the following streams should you use to both read and write from this file?\n\nA) iofstream\nB) ofstream\nC) ifstream\nD) fstream" << endl;
}
