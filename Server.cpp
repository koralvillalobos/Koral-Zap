#include "Server.h"

using namespace std;

Server::Server(){
    int room = 0;
}

int Server::getRoom(){
    return room;
}

void Server::setRoom(int newRoom){
    room = newRoom;
}

void::Server::printMenu(){
    cout << "1. Fight a Hacker\n2. Speak to NPC (non-player character)\n3. Repair your computer\n4. Use your antivirus software \n5. Travel the Server Room\n6. Browse StackOverflow\n7. Quit" << endl;
}

int main(){
    Server server;
    server.printMenu();
    
}
