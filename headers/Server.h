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
    explicit Server(int maxChats=10, bool verbose = true);
    const Server & operator=(const Server & rigth) = delete;
    Server(const Server & other) = delete;
    ~Server();

    void onMessageModified(std::shared_ptr<Message> message) override;
    void onMessageReceived(std::shared_ptr<Message> message) override;

    void addChat(int channel);
    void removeChat(int channel);

    Chat * getChatAt(int channel) const;
    User * getUserAt(const std::string & username) const;
    User * getUserAtId(int id) const;

    int getFreeId();
    int addUser(std::string &username); //only called by user c'tor
    void removeUser(int id);

    void signToChat(int id, int channel);
    void signAllToChat(int channel);
    void printAllChats();

    void setVerbose(bool verbose);
    bool isVerbose() const;

    std::list<std::shared_ptr<Message>> getMessageFromChat(int channel) const;

private:
    int maxChats;
    int usedID=0;
    bool verbose;

    std::map<const int,Chat *> chats;
    std::list<User *> users;

    std::map<const int,std::list<std::shared_ptr<Message>>> messageLog; //int represents chat channel

};


#endif //ELABORATO_SERVER_H
