//
// Created by user on 21/06/2023.
//

#ifndef ELABORATO_USER_H
#define ELABORATO_USER_H


#include <string>
#include "MessageReceiver.h"
#include "Server.h"
#include "Chat.h"

class User : public MessageReceiver {
public:
    explicit User(const std::string username, Server* server);
    void openChat(int channel);
    void closeChat(int channel);
    void openChat(Chat *chat);
    void closeChat(Chat *chat);
    void writeMessage(const std::string & text, int channel);

    int getId() const;

    const std::string &getUsername() const;

    virtual void onMessageReceived(Message &m) override;

private:
    int id;
    std::string username;
    bool verbose;
    std::list<Message *> unreadMessages; // using normal pointers because we can't use references in list
    // (no need to call destructor because the memory is managed by the server)
public:
    bool isVerbose() const;

    void setVerbose(bool verbose);

    void readAll();

private:
    Server* server;
};


#endif //ELABORATO_USER_H
