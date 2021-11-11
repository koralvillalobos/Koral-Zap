#ifndef BB_H
#define BB_H

#include <fstream>
#include <iostream>
#include <ctype.h>

using namespace std; 

class BB{
    private:
        int computer;
        static const int CPU = 10;
        static const int GPU = 20;
        static const int powerSupplyUnit = 5;
        static const int computerCase = 15;
        static const int internetCard = 5;
        static const int keyboardMouse = 10;
        static const int premadeComp = 100;

        bool antiVirus;
        static const int antiVirusCost = 10;

        int VPN;
        static const int VPNCost = 20;

        int providerLevel;
        static const int level2 = 10;
        static const int level3 = 25;
        static const int level4 = 40;
        static const int level5 = 50;

        int doge;


    public:
        BB();
        BB(bool computer, bool antiVirus, int VPN, int providerLevel, int doge);

        

        bool getComputerStatus();
        void setComputerStatus(bool);

        bool getVirusStatus();
        void setVirusStatus(bool);

        int getVPN();
        void setVPN(int);

        int getProviderLevel();
        void setProviderLevel(int);

        int getDoge();
        void setDoge(int);

        int getCPU(){
            return CPU;
        }
        int getGPU();
        int getPowerSupplyUnit(){
            return powerSupplyUnit;
        }
        int getComputerCase(){
            return computerCase;
        }
        int getInternetCard(){
            return internetCard;
        }
        int getKeyboardMouse(){
            return keyboardMouse;
        }
        int getPremadeComp(){
            return premadeComp;
        }

        int getAntiVirusCost(){
            return antiVirusCost;
        }
        int getVPNCost(){
        return VPNCost;
        }

        int getPL2(){
            return level2;
        }
        int getPL3(){
            return level3;
        }
        int getPL4(){
            return level4;
        }
        int getPL5(){
            return level5;
        }
};

#endif