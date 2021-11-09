#ifndef NPC_H
#define NPC_H

#include <fstream>
#include <iostream>
#include <ctype.h>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std; 

class NPC{ //actions class frustration level etc.
    private:
        static const int puzzel1Ans = 21;
        static const int puzzel2Ans = 13;
        const char puzzel3Ans = 'B';
        const char puzzel4Ans = 'A';
        const char puzzel5Ans = 'D';

    public:
        int getPuzzel1Ans(){
            return puzzel1Ans;
        }
        int getPuzzel2Ans(){
            return puzzel2Ans;
        }
        char getPuzzel3Ans(){
            return puzzel3Ans;
        }
        char getPuzzel4Ans(){
            return puzzel4Ans;
        }
        char getPuzzel5Ans(){
            return puzzel5Ans;
        }
        

};
#endif
    