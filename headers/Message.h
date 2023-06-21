//
// Created by user on 21/06/2023.
//

#ifndef ELABORATO_MESSAGE_H
#define ELABORATO_MESSAGE_H


#include <string>
#include <memory>
#include "User.h"
#include "Chat.h"

class Message {
public:
    Message(const std::string &text, const std::shared_ptr<User> &sender, const std::shared_ptr<MessageSender> &chat);

    const std::string &getText() const;

    const std::shared_ptr<User> &getSender() const;

    const std::shared_ptr<MessageSender> &getChat() const;

private:
    std::string text;
    std::shared_ptr<User> sender;
    std::shared_ptr<MessageSender> chat;
};


#endif //ELABORATO_MESSAGE_H
