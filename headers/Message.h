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
    const std::string &getText() const;

    const std::shared_ptr<MessageReceiver> &getSender() const;

    Message(const std::string &text, const std::shared_ptr<MessageReceiver> &sender);

private:
    std::string text;
    std::shared_ptr<MessageReceiver> sender;
};


#endif //ELABORATO_MESSAGE_H
