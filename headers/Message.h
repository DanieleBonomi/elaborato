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
    [[nodiscard]] const std::string &getText() const;

    [[nodiscard]] const User * getSender() const;

    [[nodiscard]] int getChannel() const;

    Message(const std::string &text, const User * sender, int channel);


private:
    std::string text;
    const User * sender;
    int channel;
};


#endif //ELABORATO_MESSAGE_H
