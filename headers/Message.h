//
// Created by user on 21/06/2023.
//

#ifndef ELABORATO_MESSAGE_H
#define ELABORATO_MESSAGE_H


#include <string>
#include <memory>
#include <map>
#include <list>

class MessageReceiver;
class User;

class Message {
public:
    const std::string &getText() const;

    const User * getSender() const;

    int getChannel() const;

    Message(const std::string &text, const User * sender, int channel);

    void setUpRead(const std::list<MessageReceiver *>& users);

    void setRead(const MessageReceiver * user);



private:
    std::string text;
    const User * sender;
    int channel;
    std::map<const MessageReceiver *,bool> read; // user id, read
};


#endif //ELABORATO_MESSAGE_H
