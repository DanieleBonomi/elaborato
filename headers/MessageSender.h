//
// Created by user on 21/06/2023.
//

#ifndef ELABORATO_MESSAGESENDER_H
#define ELABORATO_MESSAGESENDER_H


#include <list>
#include <memory>
#include "User.h"
#include "Message.h"

class MessageSender {
public:
    virtual void subscribe(std::shared_ptr<User> user) = 0;
    virtual void unsubscribe(std::shared_ptr<User> user) = 0;
    virtual void send(Message m) = 0;


private:
    std::list<std::shared_ptr<User>> users;
};


#endif //ELABORATO_MESSAGESENDER_H
