#include "NPC.h"

using namespace std;

NPC::NPC()
{
    
}
bool NPC::runNPCMenu(Player &player, string option,BB &bb)
{
    cin >> option;
    if (option == "1" && player.getcompPartsAvailable() > 0)
    {
        completePuzzle(player, bb);
        return true;
    }
    else if(player.getcompPartsAvailable() == 0){
        cout << "You have no computer parts & cannot complete a puzzle!" << endl;
    }
    else if (option == "2")
    {
        takeYourChances(player,bb);
        return true;
    }
    else
    {
        cout << "Invalid Input" << endl;
        return false;
    }

}
void NPC::addRandComputerPart(BB &bb)
{
    srand(time(NULL));
    int num = rand() % 7;
    switch (num)
    {
    case 0:
        bb.setNumbCPU(bb.getNumbCPU() + 1);
        cout << "+1 CPU" << endl;
        cout << "You have " << bb.getNumbCPU() << " CPUs" << endl;
        break;
    case 1:
        bb.setNumbGPU(bb.getNumbGPU() + 1);
        cout << "+1 GPU" << endl;
        cout << "You have " << bb.getNumbGPU() << " GPUs" << endl;
        break;
    case 2:
        bb.setNumbPowerSupplyUnit(bb.getNumbPowerSupplyUnit() + 1);
        cout << "+1 Power Supply Unit" << endl;
        cout << "You have " << bb.getNumbPowerSupplyUnit() << " Power Supply Units" << endl;
        break;
    case 3:
        bb.setNumbComputerCase(bb.getNumbComputerCase() + 1);
        cout << "+1 Computer Case" << endl;
        cout << "You have " << bb.getNumbComputerCase() << " Computer Cases" << endl;
        break;
    case 4:
        bb.setNumbInternetCard(bb.getNumbInternetCard() + 1);
        cout << "+1 Internet Card" << endl;
        cout << "You have " << bb.getNumbInternetCard() << " Internet Cards left" << endl;
        break;
    case 5:

        bb.setNumbKeyboardMouse(bb.getNumbKeyboardMouse() + 1);
        cout << "+1 Keyboard and Mouse" << endl;
        cout << "You have " << bb.getNumbKeyboardMouse() << " Keyboards and Mouse left" << endl;
        break;
    case 6:
        bb.setNumbPremadeComp(bb.getNumbPremadeComp() + 1);
        cout << "+1 Pre-Made Computer" << endl;
        cout << "You have " << bb.getNumbPremadeComp() << " Pre-Made Computers" << endl;
        break;
    }
}
void NPC::subRandComputerPart(BB &bb, Player &player)
{
    srand(time(NULL));
    bool run = false;
    while (run == false)
    {
        int num = rand() % 7;

        

    if(player.getcompPartsAvailable() > 0){
        switch (num)
        {
        case 0:
            if (bb.getNumbCPU() > 0)
            {
                bb.setNumbCPU(bb.getNumbCPU() - 1);
                cout << "-1 CPU" << endl;
                cout << "You have " << bb.getNumbCPU() << " CPUs left" << endl;
                run = true;
            }
            else
            {
                break;
            }
            break;
        case 1:
            if (bb.getNumbGPU() > 0)
            {
                bb.setNumbGPU(bb.getNumbGPU() - 1);
                cout << "-1 GPU" << endl;
                cout << "You have " << bb.getNumbGPU() << " GPUs left" << endl;
                run = true;
            }
            else
            {
                break;
            }
            break;
        case 2:
            if (bb.getNumbPowerSupplyUnit() > 0)
            {
                bb.setNumbPowerSupplyUnit(bb.getNumbPowerSupplyUnit() - 1);
                cout << "-1 Power Supply Unit" << endl;
                cout << "You have " << bb.getNumbPowerSupplyUnit() << " Power Supply Units left" << endl;
                run = true;
            }
            else
            {
                break;
            }
            break;
        case 3:
            if (bb.getNumbComputerCase() > 0)
            {
                bb.setNumbComputerCase(bb.getNumbComputerCase() - 1);
                cout << "-1 Computer Case" << endl;
                cout << "You have " << bb.getNumbComputerCase() << " Computer Cases left" << endl;
                run = true;
            }
            else
            {
                break;
            }
            break;
        case 4:
            if (bb.getNumbInternetCard() > 0)
            {
                bb.setNumbInternetCard(bb.getNumbInternetCard() - 1);
                cout << "-1 Internet Card" << endl;
                cout << "You have " << bb.getNumbInternetCard() << " Internet Cards left" << endl;
                run = true;
            }
            else
            {
                break;
            }
            break;
        case 5:
            if (bb.getNumbKeyboardMouse() > 0)
            {
                bb.setNumbKeyboardMouse(bb.getNumbKeyboardMouse() - 1);
                cout << "-1 Keyboard and Mouse" << endl;
                cout << "You have " << bb.getNumbKeyboardMouse() << " Keyboards and Mouse left" << endl;
                run = true;
            }
            else
            {
                break;
            }
            break;
        case 6:
            if (bb.getNumbPremadeComp() > 0)
            {
                bb.setNumbPremadeComp(bb.getNumbPremadeComp() - 1);
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
void NPC::completePuzzle(Player &player, BB &bb)
{
    srand(time(NULL));
    int rand5 = rand() % 5;
    string playerAnswer;
    string stringAnswer;
    

    if (rand5 == 0)
    {
        puzzle1();
        cout<<"Enter Answer:"<<endl;
        cin >> playerAnswer;

        stringAnswer = "21";
        if (stringAnswer == playerAnswer)
        {
            cout << "You are correct!" << endl;
            addRandComputerPart(bb);
            return;
        }
        else
        {
            cout << "You are wrong you suck!" << endl;
            subRandComputerPart(bb, player);
            
            return;
        }
    }
    if (rand5 == 1)
    {
        puzzle2();
        cout<<"Enter Answer:"<<endl;
        cin >> playerAnswer;
        stringAnswer = "13";
        if (stringAnswer == playerAnswer)
        {
            cout << "You are correct!" << endl;
            addRandComputerPart(bb);
            return;
        }
        else
        {
            cout << "You are wrong you suck!" << endl;
            subRandComputerPart(bb,player);
            return;
        }
    }
    if (rand5 == 2)
    {
        puzzle3();
        cout<<"Enter Answer:"<<endl;
        cin >> playerAnswer;
        stringAnswer = "b";
        if (stringAnswer == playerAnswer)
        {
            cout << "You are correct!" << endl;
            addRandComputerPart(bb);
            return;
        }
        else
        {
            cout << "You are wrong you suck!" << endl;
            subRandComputerPart(bb, player);
            return;
        }
    }
    if (rand5 == 3)
    {
        puzzle4();
        cout<<"Enter Answer:"<<endl;
        cin >> playerAnswer;
        stringAnswer = "a";
        if (stringAnswer == playerAnswer)
        {
            cout << "You are correct!" << endl;
            addRandComputerPart(bb);
            return;
        }
        else
        {
            cout << "You are wrong you suck!" << endl;
            subRandComputerPart(bb, player);
            return;
        }
    }
    if (rand5 == 4)
    {
        puzzle5();
        cout<<"Enter Answer:"<<endl;
        cin >> playerAnswer;
        stringAnswer = "d";
        if (stringAnswer == playerAnswer)
        {
            cout << "You are correct!" << endl;
            addRandComputerPart(bb);
            return;
        }
        else
        {
            cout << "You are wrong you suck!" << endl;
            subRandComputerPart(bb,player);
            return;
        }
    }
}
void NPC::takeYourChances(Player &player, BB &bb)
{
    srand(time(NULL));
    int rand3 = rand() % 3;
    int rand6 = rand() % 6;

    if (rand3 == 0) //good outcome
    {
        cout << "The outcome was good nothing happens" << endl;
        addRandComputerPart(bb);
    }
    if (rand3 == 1) //neutral outcome
    {
        cout << "The outcome was neutral nothing happens" << endl;
    }
    if (rand3 == 2) //bad outcome
    {
        cout << "The outcome was bad the NPC steals one of your" << endl;
        subRandComputerPart(bb,player);
    }
}
void NPC::puzzle1()
{
    cout << "****FIND THE ERROR****\nThis code works perfectly except for one pesky bug.\nEnter the number of the line on which the error appears to win this puzzle." << endl;
    cout << endl;
    cout << "1. #include <iostream>\n2. using namespace std;\n3.\n4. double frobenius(double arr1[][3], double arr2[][3]);\n5.\n6. int main() {\n7.     double arr1[3][3];\n8.     double arr2[3][3];\n9.  \n10.   for(int i = 0; i < 3; i++){\n11.       for(int j = 0; j < 3; j++) {\n12.           arr1[i][j] = i + j;\n13.           arr2[i][j] = i * j;\n14.       }\n15.   }\n16.\n17.   cout << frobenius(arr1, arr2) << endl;\n18.   return 0;\n19. }\n20.\n21. double frobenius(arr1[][3], arr2[][3]){\n22.   double innerProduct = 0;   \n23.   for(int i = 0; i < 3; i++){\n24.       for(int j = 0; j < 3; j++){  \n25.           innerProduct += arr1[i][j] * arr2[i][j];\n26.       }\n27.    }\n28.   return innerProduct;\n29. }" << endl;
}
void NPC::puzzle2()
{
    cout << "****MULTIPLE CHOICE****\nConsider the following snippet of code. How many times will the sentence inside of the for loop be printed?\n\n#include <iostream>\n\nusing namespace std;\n\nint main(){\n	int begin = 5;\n	int end = 20;\n   for (int i = begin; i <= end; i+=2){\n   cout << \"This code does nothing important\" << endl;\n    }\n	return 0;\n}\n\nA) 15\nB) 8\nC) 7\nD) 10\n}" << endl;
}
void NPC::puzzle3()
{
    cout << "****MULTIPLE CHOICE****\nConsider the following snippet of code. How many times will the sentence inside of the for loop be printed?\n\n#include <iostream>\n\nusing namespace std;\n\nint main(){\n	int begin = 5;\n	int end = 20;\n    for (int i = begin; i <= end; i+=2){\n   	 cout << \"This code does nothing important\" << endl;\n    }\n	return 0;\n}\n\nA) 15\nB) 8\nC) 7\nD) 10" << endl;
}
void NPC::puzzle4()
{
    cout << "****MULTIPLE CHOICE****\nIn the function below, word double before multiply represents what about the function?  \ndouble multiply(double x, double y)\n{\n	return x*y; \n}\nA) The type of return value\nB) The name of the function\nC) The type of parameter variable\nD) The algorithm within the function" << endl;
}
void NPC::puzzle5()
{
    cout << "****MULTIPLE CHOICE****\nTo defeat a hacker you need to use a brute force attack on his account. To do this, you are using a text file that holds words, numbers and other potential password combinations. Sometimes you come up with new word combinations you would like to add to the list. Which of the following streams should you use to both read and write from this file?\n\nA) iofstream\nB) ofstream\nC) ifstream\nD) fstream" << endl;
}
