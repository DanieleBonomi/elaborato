//
// Created by user on 21/06/2023.
//

#ifndef ELABORATO_SERVER_H
#define ELABORATO_SERVER_H


#include <map>
#include <memory>
#include <list>

#include "MessageReceiver.h"

class Chat;
class User;

class Server : MessageReceiver {
public:
    virtual ~Server() override;

    //from parent
    virtual std::unique_ptr<Message> onMessageReceived(std::unique_ptr<Message> m) override;
    void addChat(int channel);
    void removeChat(int channel);


    //brand new
    Chat * getChatAtChannel(int channel) const;
    User * getUserAtUsername(std::string & username);
    int getFreeId();
    void addUser(std::string &username); //only called by user c'tor
    void removeUser(User * user);

    void signToChat(std::string & username, int channel);
    void signAllToChat(int channel);

    void printAllChats();

    explicit Server(int maxChats=10);
    std::list<Message *> getMessageFromChat(int channel) const;

private:
    int maxChats;
    int usedID=0;

    std::map<const int,Chat *> chats;
    std::list<User *> users;


    std::map<const int,std::list<Message *>> messageLog; //int represents chat channel

};


#endif //ELABORATO_SERVER_H
