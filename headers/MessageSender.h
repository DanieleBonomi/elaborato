//
// Created by user on 21/06/2023.
//

#ifndef ELABORATO_MESSAGESENDER_H
#define ELABORATO_MESSAGESENDER_H


#include <list>
#include <memory>


#include "Message.h"
#include "MessageReceiver.h"

class MessageSender {
public:
    virtual ~MessageSender();
    virtual void send(std::shared_ptr<Message> message) = 0;
    virtual void send(const std::string & text, User * user) = 0;
    virtual void modify(std::shared_ptr<Message> message) = 0;
    virtual void subscribe(MessageReceiver *user) = 0;
    virtual void unsubscribe(MessageReceiver *user) = 0;

};



#endif //ELABORATO_MESSAGESENDER_H
