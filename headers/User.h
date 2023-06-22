//
// Created by user on 21/06/2023.
//

#ifndef ELABORATO_USER_H
#define ELABORATO_USER_H


#include <string>
#include "MessageReceiver.h"
#include "Server.h"

class User : public MessageReceiver {
public:
    explicit User(const std::string &username);
    void openChat(int channel);
    void closeChat(int channel);
    void openChat(std::shared_ptr<Chat> chat);
    void closeChat(std::shared_ptr<Chat> chat);
    void writeMessage(const std::string & text, const Chat &chat) const;

private:
    int id;
    std::string username;
};


#endif //ELABORATO_USER_H
