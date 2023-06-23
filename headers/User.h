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
    explicit User(const std::string &username);
    void openChat(int channel);
    void closeChat(int channel);
    void openChat(Chat *chat);
    void closeChat(Chat *chat);
    void writeMessage(const std::string & text, Chat *chat);

    int getId() const;

    const std::string &getUsername() const;

    virtual std::unique_ptr<Message> onMessageReceived(std::unique_ptr<Message> message) override;

private:
    int id;
    std::string username;
};


#endif //ELABORATO_USER_H
