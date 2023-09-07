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
    [[nodiscard]] Chat * getChatAtChannel(int channel) const;
    [[nodiscard]] User * getUserAtUsername(const std::string & username) const;
    User * getUserAtId(int id) const;

    int getFreeId();
    int addUser(std::string &username); //only called by user c'tor
    void removeUser(int id);

    void signToChat(int id, int channel);
    void signAllToChat(int channel);

    void printAllChats();

    explicit Server(int maxChats=10);
    [[nodiscard]] std::list<Message *> getMessageFromChat(int channel) const;

private:
    int maxChats;
    int usedID=0;

    std::map<const int,Chat *> chats;
    std::list<User *> users;


    std::map<const int,std::list<Message *>> messageLog; //int represents chat channel

};


#endif //ELABORATO_SERVER_H
