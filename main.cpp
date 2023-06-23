#include <iostream>


#include "headers/User.h"
#include "headers/Chat.h"
#include "headers/Server.h"
#include "headers/Message.h"

int main() {

    Server::getInstance()->addChat(0);
    Server::getInstance()->addChat(1);
    std::string t = "Tizio";
    std::string c = "Caio";
    std::string s = "Sempronio";
    Server::getInstance()->addUser(t); //should I create a std::string and assign it char [] instead?
    Server::getInstance()->addUser(c);
    Server::getInstance()->addUser(s);

    Server::getInstance()->signToChat(t, 0);
    Server::getInstance()->signToChat(c, 0);
    Server::getInstance()->signAllToChat(1);

    User * tizio = Server::getInstance()->getUserAtUsername(t);

    tizio->writeMessage("Ciao mondo!",1);
    tizio->writeMessage("Ciao chat privata!",0);




    return 0;
}
