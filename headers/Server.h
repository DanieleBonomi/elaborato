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

    // for singletom
    static Server * getInstance();

    //from parent
    virtual std::unique_ptr<Message> onMessageReceived(std::unique_ptr<Message> m) override;
    void addChat(Chat *chat);
    void removeChat(int channel);


    //brand new
    Chat * getChatAtChannel(int channel) const;
    int getFreeId();
    void addUser(User * user); //only called by user c'tor
    void removeUser(User * user);


private:
    explicit Server(int maxChats);

private:
    int maxChats;
    int usedID;
    std::map<int,Chat *> chats;
    std::list<User *> users;

    inline static Server * instance = nullptr; // for singleton

};


#endif //ELABORATO_SERVER_H
