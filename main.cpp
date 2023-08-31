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
    server.addUser(t); //should I create a std::string and assign it char [] instead?
    server.addUser(c);
    server.addUser(s);

    server.signToChat(t, 0);
    server.signToChat(c, 0);
    server.signAllToChat(1);

    User * tizio = server.getUserAtUsername(t);

    tizio->writeMessage("Ciao mondo!",1);
    tizio->writeMessage("Ciao chat privata!",0);

    server.printAllChats();



    return 0;
}
