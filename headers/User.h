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
    explicit User(std::string username, Server* server);

    void openChat(int channel);
    void closeChat(int channel);
    void openChat(Chat *chat);
    void closeChat(Chat *chat);

    void writeMessage(const std::string & text, int channel);
    void onMessageReceived(std::shared_ptr<Message> message) override;
    void onMessageModified(std::shared_ptr<Message> message) override;
    void readAll();

    int getId() const;
    const std::string &getUsername() const;

    bool isVerbose() const;
    void setVerbose(bool verbose);

private:
    int id;
    std::string username;
    bool verbose;
    std::list<std::shared_ptr<Message>> unreadMessages;
    Server* server;
};


#endif //ELABORATO_USER_H
