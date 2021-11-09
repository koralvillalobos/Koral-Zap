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