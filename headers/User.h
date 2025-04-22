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

    void onMessageModified(std::shared_ptr<Message> message) override;

    int getId() const;

    const std::string &getUsername() const;

    virtual void onMessageReceived(std::shared_ptr<Message> message) override;

private:
    int id;
    std::string username;
    bool verbose;
    std::list<std::shared_ptr<Message>> unreadMessages;

public:
    bool isVerbose() const;
    void setVerbose(bool verbose);

    void readAll();

private:
    Server* server;
};


#endif //ELABORATO_USER_H
