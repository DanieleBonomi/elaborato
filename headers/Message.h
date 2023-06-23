//
// Created by user on 21/06/2023.
//

#ifndef ELABORATO_MESSAGE_H
#define ELABORATO_MESSAGE_H


#include <string>
#include <memory>
class User;

class Message {
public:
    const std::string &getText() const;

    const User * getSender() const;

    Message(const std::string &text, const User * sender);

private:
    std::string text;
    const User * sender;
};


#endif //ELABORATO_MESSAGE_H
