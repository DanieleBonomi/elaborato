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
    virtual void onMessageReceived(std::shared_ptr<Message> message) override;
    void addChat(int channel);
    void removeChat(int channel);


    //brand new
    Chat * getChatAtChannel(int channel) const;
    User * getUserAtUsername(const std::string & username) const;
    User * getUserAtId(int id) const;

    int getFreeId();
    int addUser(std::string &username); //only called by user c'tor
    void removeUser(int id);

    void signToChat(int id, int channel);
    void signAllToChat(int channel);

    void printAllChats();

    void setVerbose(bool verbose);

    bool isVerbose() const;

    explicit Server(int maxChats=10, bool verbose = true);

    const Server & operator=(const Server & rigth) = delete; //FIXME Here I break the rule of 3
    Server(const Server & other) = delete;

    std::list<std::shared_ptr<Message>> getMessageFromChat(int channel) const;

private:
    int maxChats;
    int usedID=0;
    bool verbose;

    std::map<const int,Chat *> chats;
    std::list<User *> users;


    std::map<const int,std::list<std::shared_ptr<Message>>> messageLog; //int represents chat channel
//FIXME aggiungere unreadMessages (server-side, int)
//DONE togliere [[nodiscard]] , unique_ptr in messageLog and pass by value in onMessageReceived

};


#endif //ELABORATO_SERVER_H
