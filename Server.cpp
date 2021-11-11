#include "Server.h"
#include <iostream>


using namespace std;

Server::Server(){
    int room = 0;
}

int::Server::getRoom(){
    return room;
}

void::Server::setRoom(int newRoom){
    room = newRoom;
}

void::Server::printMenu(){
    cout << "1. Fight a Hacker\n 2. Speak to NPC (non-player character)\n 3. Repair your computer\n 4. Use your antivirus software \n 5. Travel the Server Room\n 6. Browse StackOverflow\n 7. Quit" << endl;
}

int main(){
    Server server();
    server.printMenu();
    
}