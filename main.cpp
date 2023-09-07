#include <iostream>


#include "headers/User.h"
#include "headers/Chat.h"
#include "headers/Server.h"
#include "headers/Message.h"

int main() {

    Server server;
    server.addChat(0);
    server.addChat(1);
    std::string t = "Tizio";
    std::string c = "Caio";
    std::string s = "Sempronio";
    int id1 = server.addUser(t); //should I create a std::string and assign it char [] instead?
    int id2 = server.addUser(c);
    int id3 = server.addUser(s);

    server.signToChat(id1, 0);
    server.signToChat(id2, 0);
    server.signAllToChat(1);

    User * tizio = server.getUserAtId(id1);

    tizio->writeMessage("Ciao mondo!",1);
    tizio->writeMessage("Ciao chat privata!",0);

    server.printAllChats();



    return 0;
}
